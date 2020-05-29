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
#include "division.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "constante.h"
#include "interactionutilisateur.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    InteractionUtilisateur *getInteractionUtilisateur(){return _interactionUtilisateur;}
private slots:
    void valider();
    void suivante();
    void ajouter();

private:
    QLabel *_resultat;
    QLabel *_classique;
    QLabel *_polonaise;
    QTextEdit *_champ;
    QTextEdit *_variableValeur;
    QTextEdit *_variableNom;
    QList<QString> _elements;
    InteractionUtilisateur *_interactionUtilisateur;
    Symboletable *_table;
signals:


};

#endif // WINDOW_H
