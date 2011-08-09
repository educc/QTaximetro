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

#include "qmservicio.h"

qmservicio::qmservicio(Empresa *_empresa,QWidget *parent) :
    QMantenimiento(empresa,parent)
{
    empresa = _empresa;
    this->setWindowTitle( QString(NAME) + " - Mantenimiento de servicios");
    //this->button.setEnabled(false);
    actualizar();
    connect(&button,SIGNAL(clicked()),this,SLOT(eliminar()));
}

void qmservicio::eliminar()
{
    int index = this->selected();
    if( index != -1){
        Servicio ser = this->listServicios.at(index);
        int id = ser.getId();
        empresa->eliminarServicio(id);
        this->actualizar();
    }
}

void qmservicio::actualizar(){
    this->listServicios = empresa->listarServicios();
    this->list.clear();
    int n = listServicios.size();
    for(int i = 0; i < n; i++){
        Servicio ser = listServicios.at(i);
        this->list.addItem(ser.toString());
    }
}
