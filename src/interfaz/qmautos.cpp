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

#include "qmautos.h"
#include <QDebug>
QMAutos::QMAutos(Empresa *empresa,QWidget *parent) :
    QMantenimiento(empresa,parent)
{
    this->setWindowTitle( QString(NAME) + " - Mantenimiento Autos");
    this->actualizar();
    connect(&button,SIGNAL(clicked()),this,SLOT(eliminar()));
}

void QMAutos::eliminar(){
    int index = this->selected();
    if( index != -1 ){
        Auto aux = listAutos.at(index);
        empresa->eliminarAuto(aux.getId());
        this->actualizar();
    }else{
        //qDebug() << "no seleccionó fila";
    }
}

void QMAutos::actualizar(){
    this->listAutos = empresa->listarAutos();
    this->list.clear();
    int n = listAutos.size();
    for(int i = 0; i < n; i++){
        Auto aux = listAutos.at(i);
        this->list.addItem(aux.getNombre() + " - " + aux.getPlaca());
    }
}
