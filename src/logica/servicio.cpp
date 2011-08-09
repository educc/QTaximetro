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

#include "servicio.h"

Servicio::Servicio()
{
    precio = -1;
    origen = "";
    destino = "";
}

void Servicio::setPrecio(float _precio)
{
    this->precio = _precio;
}

void Servicio::setOrigen(QString _origen)
{
    this->origen = _origen;
}

void Servicio::setDestino(QString _destino)
{
    this->destino = _destino;
}

qreal Servicio::getPrecio()
{
    return this->precio;
}

QString Servicio::getOrigen()
{
    return origen;
}

QString Servicio::getDestino()
{
    return destino;
}

void Servicio::setIdAuto(int id)
{
    this->idAuto = id;
}

int Servicio::getIdAuto()
{
    return idAuto;
}

QString Servicio::getNombreAuto()
{
    return this->nombre;
}

void Servicio::setNombreAuto(QString _nombre){
    this->nombre = _nombre;
}

QString Servicio::getFecha()
{
    return this->strtime;
}

void Servicio::setFecha(QString _time)
{
    strtime = _time;
}

QString Servicio::toString()
{
    QString str = this->getFecha();
    str += " - " + this->getNombreAuto() + " - ";
    str += "S/. " + QString::number(precio) + " - ";
    str += "Origen: " + this->getOrigen() + " - ";
    str += "Destino: " + this->getDestino();
    return str;
}

void Servicio::setId(int id)
{
    idServicio = id;
}

int Servicio::getId()
{
    return this->idServicio;
}

