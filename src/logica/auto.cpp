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

#include "auto.h"

Auto::Auto()
{
    id = -1;
    nombre = "";
    placa = "";
}

QString Auto::getNombre()
{
    return this->nombre;
}

QString Auto::getPlaca()
{
    return this->placa;
}

int Auto::getId()
{
    return this->id;
}

void Auto::setNombre(QString xnombre)
{
    this->nombre = xnombre;
}

void Auto::setPlaca(QString xplaca)
{
    this->placa = xplaca;
}

void Auto::setId(int _id)
{
    this->id = _id;
}
