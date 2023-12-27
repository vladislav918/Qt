#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <QVector>
#include <QString>

QVector<int> boyerMooreSearch(const QString &text, const QString &pattern);
void measureTime(const QString &text, const QString &pattern);

#endif // BOYERMOORE_H
