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


#ifndef QABOUTME_HPP
#define QABOUTME_HPP

#include <QDialog>

namespace Ui {
    class QAboutMe;
}

class QAboutMe : public QDialog
{
    Q_OBJECT

public:
    explicit QAboutMe(QWidget *parent = 0);
    ~QAboutMe();

public slots:
    void toWeb();

private:
    Ui::QAboutMe *ui;
};

#endif // QABOUTME_HPP
