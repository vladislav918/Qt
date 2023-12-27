#include "form.h"
#include "ui_Form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    QVector<int> result = boyerMooreSearch(str, sub_str);

    if (result.isEmpty()) {
        ui->result->setText("Substring not found");
    } else {
        QString resultString;
        for (int i : result) {
            resultString.append(QString::number(i) + " ");
        }
        ui->result->setText(resultString);
    }
}


QLineEdit* Form::getTextLineEdit() const{
    return ui->str;
}

QLineEdit* Form::getSubStringLineEdit() const{
    return ui->sub_str;
}

QPushButton* Form::getSearchButton() const{
    return ui->pushButton;
}

QLabel* Form::getResultLabel() const{
    return ui->result;
}
