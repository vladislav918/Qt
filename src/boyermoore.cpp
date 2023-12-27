#include "boyerMoore.h"
#include <QElapsedTimer>
#include <QDebug>
QVector<int> boyerMooreSearch(const QString &text, const QString &pattern) {
    QVector<int> indices;
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n) {
        return indices;
    }

    QVector<int> badChar(256, -1);

    for (int i = 0; i < m; ++i) {
        badChar[pattern[i].toLatin1()] = i;
    }

    int s = 0;

    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }

        if (j < 0) {
            indices.append(s);
            s += m;
        } else {
            s += std::max(1, j - badChar[text[s + j].toLatin1()]);
        }
    }

    return indices;
}

void measureTime(const QString &text, const QString &pattern) {
    QElapsedTimer timer;
    timer.start();

    boyerMooreSearch(text, pattern);

    qint64 time = timer.nsecsElapsed();
    qDebug() << "Time taken: " << time << "ns";

}



