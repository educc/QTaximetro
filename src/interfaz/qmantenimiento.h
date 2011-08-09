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

#ifndef QMANTENIMIENTO_H
#define QMANTENIMIENTO_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPushButton>
#include <QListWidget>
#include <QModelIndexList>
#include "empresa.h"

class QMantenimiento : public QDialog
{
    Q_OBJECT
public:
    QMantenimiento(Empresa *_empresa, QWidget *parent);

signals:

public slots:
    int selected();
    void eliminar();
    void actualizar();

protected:
    Empresa *empresa;
    QListWidget list;
    QPushButton button;

};

#endif // QMANTENIMIENTO_H
