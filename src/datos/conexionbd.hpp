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

#ifndef CONEXIONBD_HPP
#define CONEXIONBD_HPP

#include <QString>
#include <QSqlQueryModel>

class conexionBD
{
public:
    conexionBD(QString rutabd);
    void query(QString query,QSqlQueryModel *qmodel);
    void execQuery(QString query);
    QString open();

private:
    QString rutabd;
    QSqlDatabase bd;
};

#endif // CONEXIONBD_HPP
