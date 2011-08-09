#ifndef EMPRESA_H
#define EMPRESA_H

#include "conexionbd.hpp"
#include "auto.h"
#include "servicio.h"
#include <QString>
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

#include <QSqlQueryModel>
#include <QDateTime>
#include <QDate>
#include "defines.hpp"
#include <QTableView>

class Empresa
{
public:
    Empresa();
    QString open();
    QList<Auto> listarAutos();
    QList<Servicio> listarServicios();
    qreal totalRecaudado(QDate fecha,int tipo);
    qreal totalRecaudado(QDate ini, QDate fin, int idauto);
    qreal totalRecaudado(QDate ini, QDate fin, int idauto, qreal precioMayorA);
    qreal recaudoTotal(QDate ini,QDate fin, QSqlQueryModel *qmodel);
    qreal recaudoAuto(QDate ini, QDate fin, int idauto, qreal precioMayorA, QSqlQueryModel *qmodel);
    QTableView* tableTotalRecaudado(QDate date, int tipo);
    void agregarServicio(QString origen, QString destino, qreal precio, QDateTime time, int idAuto);
    void agregarAuto(QString nombre,QString placa);
    void eliminarAuto(int idauto);
    void eliminarServicio(int idserv);
    void temp(QString strquery, QSqlQueryModel *qmodel);

private:
    conexionBD *bd;

    QString comillas(QString str);
    QString tsqlFechas(QDate date, int tipo);
    QString tsqlFechas(QDate date1, QDate date2);
};

#endif // EMPRESA_H
