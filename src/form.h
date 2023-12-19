#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    QLineEdit* getTextLineEdit() const;
    QLineEdit* getSubStringLineEdit() const;
    QPushButton* getSearchButton() const;
    QLabel* getResultLabel() const;

public slots:
    void start();

private slots:
    QVector<int> boyerMooreSearch(const QString &text, const QString &pattern);

private:
    Ui::Form *ui;
};

#endif // FORM_H
