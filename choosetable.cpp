#include "choosetable.h"
#include "ui_choosetable.h"

choosetable::choosetable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosetable)
{
    ui->setupUi(this);
}

choosetable::~choosetable()
{
    delete ui;
}
