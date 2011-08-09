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


#include "qaboutme.hpp"
#include "ui_qaboutme.h"
#include "defines.hpp"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>


QAboutMe::QAboutMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAboutMe)
{
    ui->setupUi(this);  
    ui->labelAppName->setText( tr(
            "<font size = 5 ><b>" NAME "</font></b>"
            "<br>version: " VERSION  " build:" BUILD));

    ui->labelCont->setText( tr("<br>" DESCRIPTION "<br>"

        "<br><b>Desarrollador:</b> "  AUTOR
        "<br><b>Fecha:</b> "  DATE
        "<br><b>Dirección:</b> "  EMAIL
        "<br><b>Página web:</b> <font color=blue>" WEB "</font>"));

    this->setWindowTitle( tr("Acerca de " NAME));

    //QDesktopServices::openUrl( QUrl( tr(WEB) ) );
    connect(ui->buttonWeb,SIGNAL(clicked()),this,SLOT(toWeb()));

}


void QAboutMe::toWeb(){
    QDesktopServices::openUrl( QUrl( tr(WEB) ) );
}

QAboutMe::~QAboutMe()
{
    delete ui;
}
