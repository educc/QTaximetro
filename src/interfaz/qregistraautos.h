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

#ifndef QREGISTRAAUTOS_H
#define QREGISTRAAUTOS_H

#include <QDialog>
#include <QList>
#include <QMessageBox>
#include "empresa.h"


namespace Ui {
    class QRegistraAutos;
}

class QRegistraAutos : public QDialog
{
    Q_OBJECT

public:
    explicit QRegistraAutos(Empresa *_empresa, QWidget *parent);
    ~QRegistraAutos();

private slots:
    void guardar();
private:
    int validarCajas();

private:
    Ui::QRegistraAutos *ui;
    Empresa *empresa;
};

#endif // QREGISTRAAUTOS_H
