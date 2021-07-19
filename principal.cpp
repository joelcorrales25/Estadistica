#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Crear el lienzo
    lienzo = QPixmap(500,500);

    //invocar al metodo dibuar
    this->dibujar();

    //Mostrar el lienzo en el cuadro
    ui->cuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //Rellenar el lienzo de color blanco
    lienzo.fill(Qt::white);

    //Crear el pintor
    QPainter painter(&lienzo);

    int x = 50;
    int y = 50;
    int ancho = 100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Crear un pincel para el borde
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    //Establecer el pincel al pintor
   painter.setPen(pincel);

   //Dibujar primera barra
   painter.drawRect(x,y+(400-alto_1),ancho,alto_1);

   //Crear un nuevo color para el borde y el relleno
   QColor colorBorde2(78,3,48);
   QColor colorRelleno2(190,120,162);

   //Establecer color al pincel
   pincel.setColor(colorBorde2);

   //Volver a establecer el pincel al objeto painter
   painter.setPen(pincel);

   //Establecer el color de la brocha del objeto painter
   painter.setBrush(colorRelleno2);

   //Dibujar la segunda barra (rellena)
   painter.drawRect(x+150,y+(400-alto_2),ancho,alto_2);

   //Creando los colores de la tercera barra
   QColor colorRelleno3(253,253,115);
   QColor colorBorde3(174,174,51);

    //Establecer nuevo color al pincel
   pincel.setColor(colorBorde3);

   //Establecer nuevo color al pincel
   painter.setPen(pincel);

   //Establecer el color de la brocha del objeto painter
   painter.setBrush(colorRelleno3);

   //Dibujar la tercera barra (rellena)
   painter.drawRect(x+300,y+(400-alto_3),ancho,alto_3);

   //Mostrar el lienzo en el "cuadro"
   ui->cuadro->setPixmap(lienzo);

}

void Principal::on_cmdGraficar_clicked()
{
    dibujar();
}

void Principal::on_actionGuardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();

    //Agregar al path absoluto del objeto un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath();

    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar Imagen",pathArchivo,"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar","Imagen Guardada en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar","No hubo como Guardar la Imagen");
    }
}
void Principal::on_actionSalir_triggered()
{
    this->close();
}
