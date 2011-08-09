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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qservice.h"
#include "qregistraautos.h"
#include "qreportes.h"
#include "defines.hpp"
#include "qmservicio.h"
#include "qmautos.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    empresa = new Empresa;

    //abrir la conexion con la base de datos
    QString error = empresa->open();
    if( !error.isEmpty() ){
        QMessageBox::critical(this,QString(NAME),error);
        exit(1);
    }
    ui->setupUi(this);
    this->setWindowTitle( QString(NAME) + " - " + QString(VERSION) );

    this->frmAboutMe = new QAboutMe(this);
    this->frmAboutMe->setModal(true);

    ui->mainlayout->addWidget(this->frmAboutMe);
    this->loadStyleSheet();

    connect(ui->actionAgregar_Servicio,SIGNAL(triggered()),this,SLOT(registraServicio()));
    connect(ui->actionAgregar_Auto,SIGNAL(triggered()),this,SLOT(registraAuto()));
    connect(ui->actionRVehiculo,SIGNAL(triggered()),this,SLOT(mostrarReportes()));
    ///connect(ui->actionAcerca_de_este_programa,SIGNAL(triggered()),this,SLOT(mostrarAyuda()));
    connect(ui->actionTotal_Recaudado,SIGNAL(triggered()),this,SLOT(mostrarReportesTotal()));
    connect(ui->actionAuto,SIGNAL(triggered()),this,SLOT(mantenimientoAutos()));
    connect(ui->actionServicios,SIGNAL(triggered()),this,SLOT(mantenimientoServicios()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete empresa;
}

void MainWindow::registraServicio()
{
    QService frm(empresa,this);
    frm.setModal(true);
    frm.exec();
}

void MainWindow::registraAuto()
{
    QRegistraAutos frm(empresa,this);
    frm.setModal(true);
    frm.exec();
}

void MainWindow::mostrarReportes()
{
    QReportes frm(empresa, this);
    frm.setModal(true);
    frm.exec();
}

void MainWindow::mostrarAyuda()
{
   // this->frmAboutMe->show();
}

void MainWindow::mantenimientoServicios()
{
    qmservicio frm(empresa,this);
    frm.exec();
}

void MainWindow::mantenimientoAutos(){
    QMAutos frm(empresa,this);
    frm.exec();
}

void MainWindow::mostrarReportesTotal()
{
    QTotalRecaudado frm(empresa,this);
    frm.exec();
    frm.deleteLater();
}

void MainWindow::loadStyleSheet()
{
    QFile file(":/qss/coffee.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    //ui.styleTextEdit->setPlainText(styleSheet);
    qApp->setStyleSheet(styleSheet);
    qApp->setStyle("Cleanlooks");
    //ui.applyButton->setEnabled(false);
}
