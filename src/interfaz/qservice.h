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

#ifndef QSERVICE_H
#define QSERVICE_H

#include <QDialog>
#include <QList>
#include <QMessageBox>
#include "empresa.h"
#include "auto.h"

namespace Ui {
    class QService;
}

class QService : public QDialog
{
    Q_OBJECT

public:
    QService(Empresa *_empresa, QWidget *parent);
    ~QService();

private slots:
    void guardar();
private:
    int validarCajas();

private:
    Ui::QService *ui;
    Empresa *empresa;
    QList<Auto> list;

    int idAutoSelected();
};

#endif // QSERVICE_H
