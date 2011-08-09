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

#ifndef AUTO_H
#define AUTO_H

#include <QString>

class Auto
{
public:
    Auto();
    void setNombre(QString nombre);
    void setPlaca(QString placa);
    void setId(int id);

    QString getNombre();
    QString getPlaca();
    int getId();

private:
    int id;
    QString nombre;
    QString placa;
};

#endif // AUTO_H
