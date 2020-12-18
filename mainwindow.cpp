#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alto =400;//h_limit
    ancho = 300;//v_limit
    dt = 0.3;

    timer =new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-alto/2,-ancho/2,alto,ancho);
   // scene->setBackgroundBrush(QBrush(QImage(":/new/espacio/espaciof.jpg")));
    scene->setBackgroundBrush(QPixmap(":/new/espacio/espaciof.jpg").scaledToWidth(ui->graphicsView->width()));

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();


    timer->stop();
    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{
    for (int i = 0; i<cuerpos.size();i++  ) {
        for (int j = 0; j<cuerpos.size();j++ ) {
            if (i != j){
                cuerpos.at(i)->getEsf()->acelerar(cuerpos.at(j)->getEsf()->getPX(),cuerpos.at(j)->getEsf()->getPY(),cuerpos.at(j)->getEsf()->getMasa());
                cuerpos.at(i)->actualizar(dt);
            }
        }
    }
}

void MainWindow::on_Iniciar_simulacion_clicked()
{
    timer->start(dt);
}

void MainWindow::on_Crear_clicked()
{
    float posx=ui->Posicionx->text().toFloat();
    float posy=ui->Posiciony->text().toFloat();
    float masa=ui->Masa->text().toFloat();
    float radio=ui->Radio->text().toFloat();
    float velx=ui->Velocidadx->text().toFloat();
    float vely=ui->Velocidady->text().toFloat();
    cuerpos.append(new cuerpograf(posx,posy,velx,vely,masa,radio));
    scene->addItem(cuerpos.back());
    cuerpos.back()->actualizar(dt);
    ui->Posicionx->clear();
    ui->Posiciony->clear();
    ui->Masa->clear();
    ui->Radio->clear();
    ui->Velocidadx->clear();
    ui->Velocidady->clear();
}
