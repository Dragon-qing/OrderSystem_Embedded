#include "adminmenu.h"
#include "ui_adminmenu.h"

adminmenu::adminmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminmenu)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&tableWnd);
    ui->stackedWidget->addWidget(&orderWnd);
    ui->stackedWidget->addWidget(&menuWnd);
    ui->stackedWidget->addWidget(&managerWnd);
    ui->stackedWidget->addWidget(&clientlistWnd);
    ui->stackedWidget->addWidget(&consumeWnd);

    btnGroup.addButton(ui->table,0);
    btnGroup.addButton(ui->order,1);
    btnGroup.addButton(ui->menu,2);
    btnGroup.addButton(ui->manager,3);
    btnGroup.addButton(ui->clientlist,4);
    btnGroup.addButton(ui->consume,5);


//    connect(&btnGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(&btnGroup,SIGNAL(buttonClicked(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
    btnGroup.button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
}

adminmenu::~adminmenu()
{
    delete ui;
}
