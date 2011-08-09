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

#ifndef QTOTALRECAUDADO_HPP
#define QTOTALRECAUDADO_HPP

#include <QDialog>
#include <QSqlQueryModel>
#include "empresa.h"

namespace Ui {
    class QTotalRecaudado;
}

class QTotalRecaudado : public QDialog
{
    Q_OBJECT

public:
    explicit QTotalRecaudado(Empresa *_empresa,QWidget *parent = 0);
    ~QTotalRecaudado();
private slots:
    void mostrarLista();

private:
    Ui::QTotalRecaudado *ui;
    Empresa *empresa;
    //QSqlQueryModel qmodel;
};

#endif // QTOTALRECAUDADO_HPP
