#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QFont>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QLayout>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    QList<QString> getElements();

private slots:
    void valider();

private:
    // Choix de l'opérateur
    QGroupBox *_choixOperateur; // group box
    QVBoxLayout *_operateur; // layout
        // radio boutton
    QRadioButton *_plus;
    QRadioButton *_moins;
    QRadioButton *_diviseur;
    QRadioButton *_multiplicateur;
    // Label d'affichage
    QLabel *_resultat;
    QLabel *_classique;
    QLabel *_polonaise;
    // Champs d'entrée des constantes
    QTextEdit *_champ1;
    QTextEdit *_champ2;
    // Opération simple
    Addition *_addition;
    Division *_division;
    Multiplication *_multiplication;
    Soustraction *_soustraction;

signals:


};

#endif // WINDOW_H
