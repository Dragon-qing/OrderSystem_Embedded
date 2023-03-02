#include "customermenu.h"
#include "ui_customermenu.h"

customermenu::customermenu(QWidget *parent, int uid) :
    QWidget(parent),
    ui(new Ui::customermenu)
{
    this->uid = uid;
    historyWnd = new history(this,uid);
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&tableWnd);
    ui->stackedWidget->addWidget(historyWnd);
    ui->stackedWidget->addWidget(&xiangWnd);
    ui->stackedWidget->addWidget(&eWnd);
    ui->stackedWidget->addWidget(&drinkWnd);

    btnGroup.addButton(ui->choosetable,0);
    btnGroup.addButton(ui->history,1);
    btnGroup.addButton(ui->xiang,2);
    btnGroup.addButton(ui->e,3);
    btnGroup.addButton(ui->drink,4);
    connect(&btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
}

customermenu::~customermenu()
{
    delete ui;
}
