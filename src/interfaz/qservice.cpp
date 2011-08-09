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

#include "qservice.h"
#include "ui_qservice.h"
#include "QDateTime"
#include "QListWidgetItem"

QService::QService(Empresa *_empresa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QService)
{
    this->empresa = _empresa;
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();
    ui->txtOrigen->setFocus();
    ui->dteFecha->setDateTime(time);

    list.clear();
    list = empresa->listarAutos();
    int n = list.size();
    for(int i = 0; i < n; i++){
        Auto miauto =  list.at(i);
        QString nombre = miauto.getNombre();
        ui->listAutos->addItem( nombre );
    }
    this->setWindowTitle( QString(NAME) + " - Registrar servicio");

    connect(ui->cmdGuardar,SIGNAL(clicked()),this,SLOT(guardar()));
    connect(ui->cmdCancelar,SIGNAL(clicked()),this,SLOT(close()));
}

QService::~QService()
{
    delete ui;
}

void QService::guardar()
{
    if( this->validarCajas() == 0){
        QString origen = ui->txtOrigen->text();
        QString destino = ui->txtDestino->text();
        qreal precio = ui->dsbPrecio->value();
        QDateTime time = ui->dteFecha->dateTime();
        int id = this->idAutoSelected();
        empresa->agregarServicio(origen,destino,precio,time,id);
        this->close();
    }
}

int QService::idAutoSelected()
{
    int id = -1;
    int index = ui->listAutos->currentRow();
    if (index != -1){
        Auto miauto = list.at(index);
        id = miauto.getId();
    }
    return id;
}

int QService::validarCajas()
{
    int errores = 0;
    QString strerrores;
    if( ui->txtOrigen->text().isEmpty() ){
        errores++;
        strerrores += "Falta agregar el 'Origen'<br>";
    }
    if( ui->txtDestino->text().isEmpty() ){
        errores++;
        strerrores += "Falta agregar el 'Destino'<br>";
    }
    if( this->idAutoSelected() == -1){
        errores++;
        strerrores += "No ha seleccionado ningún vehículo<br>";
    }
    if(errores != 0)
        QMessageBox::warning(this,QString(NAME),
                             strerrores,QMessageBox::Ok);
    /*if( ui->dsbPrecio->value() < 2.5 && errores == 0){
        if( QMessageBox::No == QMessageBox::question(
                    this,QString(NAME),
                    "¿Está seguro que desea cobrar menos de S/ 2.50?",
                    QMessageBox::Yes,
                    QMessageBox::No))
        {
            errores++;
        }
    }else{
        QMessageBox::warning(this,QString(NAME),
                             strerrores,QMessageBox::Ok);
    }*/
    return errores;
}
