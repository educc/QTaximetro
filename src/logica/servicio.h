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

#ifndef SERVICIO_H
#define SERVICIO_H

#include <QString>
#include <QDateTime>

class Servicio
{
public:
    Servicio();
    void setIdAuto(int id);
    void setPrecio(float _precio);
    void setOrigen(QString _origen);
    void setDestino(QString _destino);
    void setNombreAuto(QString _nombre);
    void setFecha(QString _time);
    void setId(int id);

    QString getOrigen();
    QString getDestino();
    QString getNombreAuto();
    qreal getPrecio();
    QString getFecha();
    QString toString();

    int getIdAuto();
    int getId();

private:
    int idAuto;
    int idServicio;
    QString nombre;
    qreal precio;
    QString origen;
    QString destino;
    QString strtime;
};

#endif // SERVICIO_H
