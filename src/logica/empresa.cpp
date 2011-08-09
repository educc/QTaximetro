// Este archivo es parte de QTaximetro
//
//QTaximetro is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//QTaximetro is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with QTaximetro.  If not, see <http://www.gnu.org/licenses/>.

#include "empresa.h"
#include <QDir>
#include <QApplication>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>

Empresa::Empresa()
{
    QString ruta = QApplication::applicationDirPath();
    QDir dir(ruta);
#ifdef Q_MAC
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
#endif
    ruta = dir.absolutePath() + "/bdmovil.sqlite";
    bd = new conexionBD(ruta);
}

QList<Auto> Empresa::listarAutos()
{
    QSqlQueryModel *qmodel = new QSqlQueryModel;
    QList<Auto> lista;
    bd->query("select * from auto where estado_aut != 0",qmodel);
    int n = qmodel->rowCount();
    for(int i = 0; i < n; i++){
        Auto miauto;
        int id = qmodel->record(i).value("id_aut").toInt();
        miauto.setId( id );
        miauto.setNombre( qmodel->record(i).value("nombre_aut").toString());
        miauto.setPlaca( qmodel->record(i).value("placa_aut").toString() );
        lista.append(miauto);
    }
    delete qmodel;
    return lista;
}

void Empresa::temp(QString strquery, QSqlQueryModel *qmodel)
{
    bd->query(strquery,qmodel);
}

void Empresa::agregarServicio(QString origen, QString destino, qreal precio, QDateTime time, int idAuto)
{
    QString strquery = "INSERT INTO servicio(precio_ser,origen_ser,destino_ser,fecha_ser,id_aut) values(";
    strquery += QString::number(precio) + ",";
    strquery += comillas(origen) + ",";
    strquery += comillas(destino) + ",";
    strquery += comillas(time.toString("yyyy/MM/dd hh:mm")) + ",";
    strquery += QString::number(idAuto) + ")";
    //qDebug() << strquery;
    bd->execQuery(strquery);
}

QString Empresa::comillas(QString str)
{
    return "'" + str + "'";
}

void Empresa::agregarAuto(QString nombre, QString placa)
{
    QString strquery = "INSERT INTO auto(nombre_aut,placa_aut,estado_aut) values(";
    strquery += comillas(nombre) + ",";
    strquery += comillas(placa) + ",1)";
    bd->execQuery(strquery);
}

qreal Empresa::totalRecaudado(QDate fecha, int tipo)
{
    qreal recaudo  = -1;
    QString strquery = "SELECT SUM(precio_ser) as suma FROM servicio ";
    strquery += "WHERE " + tsqlFechas(fecha,tipo);
    QSqlQueryModel *qmodel = new QSqlQueryModel;
    bd->query(strquery,qmodel);
    int n = qmodel->rowCount();
    if( n != 0){
        recaudo = qmodel->record(0).value("suma").toReal();
    }
    //qDebug() << strquery;
    delete qmodel;
    return recaudo;
}

qreal Empresa::totalRecaudado(QDate ini, QDate fin, int idauto)
{
    qreal recaudo = -1;
    QString strquery = "SELECT SUM(precio_ser) as suma FROM servicio WHERE ";
    if( idauto != -1 ){
        strquery += "id_aut =" + QString::number(idauto) + " and ";
    }
    strquery += tsqlFechas(ini,fin);

    QSqlQueryModel *qmodel = new QSqlQueryModel;
    bd->query(strquery,qmodel);
    int n = qmodel->rowCount();
    if( n != 0){
        recaudo = qmodel->record(0).value("suma").toReal();
    }
    //qDebug() << strquery;
    delete qmodel;
    return recaudo;
}

qreal Empresa::totalRecaudado(QDate ini, QDate fin, int idauto, qreal precioMayorA)
{
    qreal recaudo = -1;
    QString strquery = "SELECT SUM(precio_ser) as suma FROM servicio WHERE ";
    if( idauto != -1 ){
        strquery += "id_aut =" + QString::number(idauto) + " and ";
    }
    strquery += tsqlFechas(ini,fin);

    if( precioMayorA > 0){
        strquery += " and precio_ser >= " +  QString::number(precioMayorA);
    }

    QSqlQueryModel *qmodel = new QSqlQueryModel;
    bd->query(strquery,qmodel);
    int n = qmodel->rowCount();
    if( n != 0){
        recaudo = qmodel->record(0).value("suma").toReal();
    }
    //qDebug() << strquery;
    delete qmodel;
    return recaudo;
}

QTableView* Empresa::tableTotalRecaudado(QDate date, int tipo)
{
    QString strquery = "select auto.nombre_aut as Auto,"
            "auto.placa_aut as placa,"
            "servicio.precio_ser as precio,"
            "servicio.origen_ser as origen,"
            "servicio.destino_ser as destino,"
            "servicio.fecha_ser as fecha "
            "from auto, servicio where auto.id_aut = servicio.id_aut and ";
    strquery += tsqlFechas(date,tipo);
    QSqlQueryModel *qmodel = new QSqlQueryModel;
    QTableView* table = new QTableView;
    bd->query(strquery,qmodel);
    table->setModel(qmodel);
    return table;
}

QString Empresa::tsqlFechas(QDate date, int tipo)
{
    QString strquery = "fecha_ser BETWEEN ";
    strquery += comillas(date.toString("yyyy/MM/dd")) + " and ";
    switch(tipo){
        case DIA: date = date.addDays(1);break;
        case SEMANA: date = date.addDays(7);break;
        case MES: date = date.addMonths(1);break;
    }
    strquery += comillas(date.toString("yyyy/MM/dd"));
    return strquery;
}

QString Empresa::tsqlFechas(QDate date1, QDate date2)
{
    QString strquery = "fecha_ser BETWEEN ";
    strquery += comillas(date1.toString("yyyy/MM/dd")) + " and ";
    strquery += comillas(date2.toString("yyyy/MM/dd"));
    return strquery;
}

void Empresa::eliminarAuto(int idauto)
{
    QString strquery = "DELETE FROM auto WHERE id_aut=" + QString::number(idauto);
    bd->execQuery(strquery);
}

void Empresa::eliminarServicio(int idserv)
{
    QString strquery = "DELETE FROM servicio WHERE id_ser=" + QString::number(idserv);
    bd->execQuery(strquery);
}

QList<Servicio> Empresa::listarServicios()
{
    QSqlQueryModel *qmodel = new QSqlQueryModel;
    QString strquery = "SELECT servicio.id_ser,"
            "servicio.fecha_ser,"
            "servicio.precio_ser,"
            "auto.nombre_aut,"
            "servicio.origen_ser,"
            "servicio.destino_ser "
            "FROM auto,servicio WHERE servicio.id_aut = auto.id_aut";
    //qDebug() << strquery;
    QList<Servicio> lista;
    bd->query(strquery,qmodel);
    int n = qmodel->rowCount();
    for(int i = 0; i < n; i++){
        Servicio servicio;
        int id = qmodel->record(i).value("id_ser").toInt();
        QString strtime = qmodel->record(i).value("fecha_ser").toString();
        QString name = qmodel->record(i).value("nombre_aut").toString();
        qreal precio = qmodel->record(i).value("precio_ser").toReal();
        QString origen = qmodel->record(i).value("origen_ser").toString();
        QString destino = qmodel->record(i).value("destino_ser").toString();
        servicio.setId(id);
        servicio.setDestino(destino);
        servicio.setOrigen(origen);
        servicio.setNombreAuto(name);
        servicio.setPrecio(precio);
        servicio.setFecha(strtime);
        lista.append(servicio);
    }
    delete qmodel;
    return lista;
}

qreal Empresa::recaudoTotal(QDate ini, QDate fin, QSqlQueryModel *qmodel)
{
    QString strquery = "SELECT servicio.fecha_ser as Fecha,"
            "servicio.precio_ser as Precio,"
            "auto.nombre_aut as Auto,"
            "servicio.origen_ser as Origen,"
            "servicio.destino_ser as Destino "
            "FROM auto,servicio WHERE servicio.id_aut = auto.id_aut and ";
    strquery += this->tsqlFechas(ini,fin);
    //qDebug() << strquery;
    bd->query(strquery,qmodel);
    return this->totalRecaudado(ini,fin,-1);
}

qreal Empresa::recaudoAuto(QDate ini, QDate fin, int idauto, qreal precioMayorA, QSqlQueryModel *qmodel)
{
    QString strquery = "SELECT servicio.fecha_ser as Fecha,"
            "servicio.precio_ser as Precio,"
            "auto.nombre_aut as Auto,"
            "servicio.origen_ser as Origen,"
            "servicio.destino_ser as Destino "
            "FROM auto,servicio WHERE servicio.id_aut = auto.id_aut and ";
    strquery += "servicio.id_aut=" + QString::number(idauto) + " and ";
    strquery += this->tsqlFechas(ini,fin);

    if( precioMayorA > 0){
        strquery += " and precio_ser>=" + QString::number(precioMayorA);
    }
    //qDebug() << strquery;
    bd->query(strquery,qmodel);
    return this->totalRecaudado(ini,fin,idauto);
}

QString Empresa::open()
{
    return bd->open();
}

