#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QColor>
#include <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->spinBoxRed, SIGNAL(valueChanged(int)), this, SLOT(on_rgbChanged()));
    connect(ui->spinBoxGreen, SIGNAL(valueChanged(int)), this, SLOT(on_rgbChanged()));
    connect(ui->spinBoxBlue, SIGNAL(valueChanged(int)), this, SLOT(on_rgbChanged()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_rgbChanged()
{
    QPalette pal = QPalette();
    QColor color;
    //分别设置R,G,B,透明度
    color.setRgb(ui->spinBoxRed->value(), ui->spinBoxGreen->value(), ui->spinBoxBlue->value(), 255);
    //QPalette::Base
    //Used mostly as the background color for text entry widgets, It is usually white or another light color.
    pal.setColor(QPalette::Base, color);
    ui->graphicsView->setPalette(pal);
}
