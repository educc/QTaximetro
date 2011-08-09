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

#ifndef QREPORTES_H
#define QREPORTES_H

#include <QDialog>
#include <QtGui>
#include "empresa.h"
#include "auto.h"

namespace Ui {
    class QReportes;
}

class QReportes : public QDialog
{
    Q_OBJECT

public:
    explicit QReportes(Empresa *_empresa, QWidget *parent);
    ~QReportes();

private slots:
    void reportes();
    void mostrarDetalles();
    void actualizaComision(double per);

private:
    Ui::QReportes *ui;
    Empresa *empresa;
    QTableView *table;
    QList<Auto> listAutos;

    int optionSelected();
    int autoSelected();
};

#endif // QREPORTES_H
