#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "cuerpo.h"
#include "cuerpograf.h"
#include <QGraphicsScene>
#include <iostream>
#include<string>
#include <sstream>
#include <fstream>
#include <QImage>
#include <QPixmap>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actualizar();
    void on_Iniciar_simulacion_clicked();

    void on_Crear_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    float dt;
    int alto;
    int ancho;
    QList<cuerpograf*>cuerpos;
};
#endif // MAINWINDOW_H
