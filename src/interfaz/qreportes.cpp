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

#include "qreportes.h"
#include "ui_qreportes.h"
#include <QDate>
#include <QDebug>
#include "defines.hpp"

QReportes::QReportes(Empresa *_empresa, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QReportes)
{
    ui->setupUi(this);
    empresa = _empresa;
    ui->dateFechaIni->setDate( QDate::currentDate() );
    ui->dateFechaFin->setDate( QDate::currentDate().addDays(1));
    this->reportes();
    this->setWindowTitle( QString(NAME) + " - Reportes");

    listAutos.clear();
    listAutos = empresa->listarAutos();
    int n = listAutos.size();
    for(int i = 0; i < n; i++){
        Auto miauto =  listAutos.at(i);
        QString nombre = miauto.getNombre();
        ui->qlistAutos->addItem( nombre );
    }

    connect(ui->cmdSalir,SIGNAL(clicked()),this,SLOT(close()));
    //connect(ui->dateFecha,SIGNAL(dateChanged(QDate)),this,SLOT(reportes()));
    connect(ui->cmdDetalles,SIGNAL(clicked()),this,SLOT(mostrarDetalles()));
    connect(ui->dsbPorcentaje,SIGNAL(valueChanged(double)),this,SLOT(actualizaComision(double)));
    connect(ui->qlistAutos,SIGNAL(currentRowChanged(int)),this,SLOT(reportes()));
}

QReportes::~QReportes()
{
    delete ui;
}

void QReportes::reportes()
{
    QDate fechaini = ui->dateFechaIni->date();
    QDate fechafin = ui->dateFechaFin->date();
    int autoid = this->autoSelected();
    qreal filtro = ui->dsbFiltro->value();
    if( autoid != -1 ){
        qreal recaudo = empresa->totalRecaudado(fechaini,fechafin,autoid,filtro);
        ui->txtRecaudado->setText( QString::number(recaudo));
        this->actualizaComision( ui->dsbPorcentaje->value() );
    }

    //QDate fecha = ui->dateFecha->date();
    //int opt = this->optionSelected();
    //table = empresa->tableTotalRecaudado(fecha,opt);
    //qreal recaudo = empresa->totalRecaudado(fecha,opt);
    //qreal per = ui->dsbPorcentaje->value();
    //qreal comision = recaudo*per/100;
    //ui->txtComision->setText( QString::number(comision));
    //ui->txtRecaudado->setText( QString::number(recaudo) );
}

int QReportes::optionSelected()
{
    return 0;
}

void QReportes::mostrarDetalles()
{
    QDialog frm(this);// = new QDialog(this);
    QHBoxLayout layout;// = new QHBoxLayout;

    QSqlQueryModel qmodel;// = new QSqlQueryModel;
    QTableView mitable; // = new QTableView;

    QDate fechaini = ui->dateFechaIni->date();
    QDate fechafin = ui->dateFechaFin->date();
    int autoid = this->autoSelected();
    qreal filtro = ui->dsbFiltro->value();

    empresa->recaudoAuto(fechaini,fechafin,autoid,filtro,&qmodel);
    mitable.setModel(&qmodel);
    layout.addWidget(&mitable);
    frm.setWindowTitle("Detalles");
    frm.setLayout(&layout);
    frm.setMinimumWidth(500);
    frm.exec();
}

void QReportes::actualizaComision(double per)
{
    QString total = ui->txtRecaudado->text();
    bool bol;
    double recaudo = total.toDouble(&bol);
    qreal comision = recaudo*per/100;
    //QString strcomision;
    //strcomision.sprintf()
    //strcomision.setNum(comision);
    ui->txtComision->setText( QString::number(comision) );
}

int QReportes::autoSelected()
{
    int autoid = -1;
    int index = ui->qlistAutos->currentRow();
    if( index != -1 ){
        Auto aux = listAutos.at(index);
        autoid = aux.getId();
    }

    return autoid;
}
