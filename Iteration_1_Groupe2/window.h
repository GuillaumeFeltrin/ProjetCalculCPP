#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QFont>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <QList>
#include "Division.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Constante.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    QList<QString> getElements();

private slots:
    void valider();
    void suivante();

private:
    QLabel *resultat;
    QLabel *classique;
    QLabel *polonaise;
    QTextEdit *_champ;
    QList<QString> _elements;

signals:


};

#endif // WINDOW_H
