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

#include "qregistraautos.h"
#include "ui_qregistraautos.h"
#include "defines.hpp"

QRegistraAutos::QRegistraAutos(Empresa *_empresa, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRegistraAutos)
{
    empresa = _empresa;
    ui->setupUi(this);
    this->setWindowTitle(QString(NAME) + " - Registrar vehículos");
    connect(ui->cmdGuardar,SIGNAL(clicked()),this,SLOT(guardar()));
    connect(ui->cmdCancelar,SIGNAL(clicked()),this,SLOT(close()));
}

QRegistraAutos::~QRegistraAutos()
{
    delete ui;
}

void QRegistraAutos::guardar()
{
    if( this->validarCajas() == 0){
        QString nombre = ui->txtNumero->text();
        QString placa = ui->txtPlaca->text();
        empresa->agregarAuto(nombre,placa);
        this->close();
    }
}

int QRegistraAutos::validarCajas()
{
    int errores = 0;
    QString strerrores;
    if( ui->txtNumero->text().isEmpty() ){
        errores++;
        strerrores += "El campo 'Nombre' está vacío<br>";
    }
    if( ui->txtPlaca->text().isEmpty()){
        errores++;
        strerrores += "El campo 'Placa' está vacío<br>";
    }
    if( errores != 0)
        QMessageBox::warning(this,QString(NAME),strerrores,QMessageBox::Ok);
    return errores;
}
