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

#include "qtotalrecaudado.hpp"
#include "ui_qtotalrecaudado.h"
//#include <QItemSelectionModel>

QTotalRecaudado::QTotalRecaudado(Empresa *_empresa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTotalRecaudado)
{
    empresa = _empresa;
    ui->setupUi(this);

    QDate date = QDate::currentDate();
    ui->dateFechaIni->setDate(date);
    ui->dateFechaFin->setDate( date.addDays(1) );
    this->setWindowTitle( QString(NAME) + " - Total Recaudado");
    connect(ui->cmdSalir,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->cmdMostrar,SIGNAL(clicked()),this,SLOT(mostrarLista()));
}

QTotalRecaudado::~QTotalRecaudado()
{
    delete ui;
}

void QTotalRecaudado::mostrarLista()
{
    QSqlQueryModel *qmodel = new QSqlQueryModel;
    //qmodel.~QSqlQueryModel();
    //qmodel = QSqlQueryModel;

    QDate fechaini = ui->dateFechaIni->date();
    QDate fechafin = ui->dateFechaFin->date();
    qreal total = empresa->recaudoTotal(fechaini,fechafin,qmodel);
    QString strlabel = "Total recaudado: S/. " + QString::number(total);
    ui->lblRecaudado->setText(strlabel);

    QItemSelectionModel *m = ui->tableView->selectionModel();
    ui->tableView->setModel(qmodel);
    delete m;

}
