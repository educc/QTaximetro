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

#include "conexionbd.hpp"
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>

conexionBD::conexionBD(QString rutabd)
{
    this->rutabd = rutabd;
}

void conexionBD::query(QString strquery, QSqlQueryModel *qmodel)
{
    //if( open() == 0)
        qmodel->setQuery(strquery);
    //bd.close();
}

QString conexionBD::open()
{
    QString error("");
    if( !QFile::exists(rutabd) ){
        error = "No existe la base de datos.\n"
                "Intente reinstalando el software.";
    }else{
        bd = QSqlDatabase::addDatabase("QSQLITE");
        bd.setDatabaseName(rutabd);
        if (!bd.open()){
            QSqlError sqlerror = bd.lastError();
            error = sqlerror.text();
        }
    }
    return error;
}

void conexionBD::execQuery(QString strquery)
{
    this->open();
    QSqlQuery query;
    query.exec(strquery);
    bd.close();
}
