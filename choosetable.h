#ifndef CHOOSETABLE_H
#define CHOOSETABLE_H

#include <QWidget>

namespace Ui {
class choosetable;
}

class choosetable : public QWidget
{
    Q_OBJECT

public:
    explicit choosetable(QWidget *parent = 0);
    ~choosetable();

private:
    Ui::choosetable *ui;
};

#endif // CHOOSETABLE_H
