#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();


private slots:
    void on_cmdGraficar_clicked();
    void on_actionGuardar_triggered();
    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
    //Declarar el objeto sobre el cual se va a dibujar
    QPixmap lienzo;
    void dibujar();
};
#endif // PRINCIPAL_H
