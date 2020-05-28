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
#include "interactionutilisateur.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private slots:
    void valider();
    void suivante();

private:
    QLabel *_resultat;
    QLabel *_classique;
    QLabel *_polonaise;
    QTextEdit *_champ;
    QList<QString> _elements;
    InteractionUtilisateur * _interactionUtilisateur;

signals:


};

#endif // WINDOW_H
