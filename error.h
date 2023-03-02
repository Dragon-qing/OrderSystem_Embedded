#ifndef ERROR_H
#define ERROR_H

#include <QWidget>

namespace Ui {
class error;
}

class error : public QWidget
{
    Q_OBJECT

public:
    explicit error(QWidget *parent = 0);
    ~error();

private:
    Ui::error *ui;
};

#endif // ERROR_H
