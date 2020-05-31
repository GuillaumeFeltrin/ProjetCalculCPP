#ifndef MAINWINDOWGEN_H
#define MAINWINDOWGEN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QtWidgets>


class MainWindowGen : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT                    // Nécessaire pour créer un slot maison
    QWidget fenetre;

    public:
    MainWindowGen();                // Constructeur (forcément pubic)

    public slots:               // Slots maison
    void Redirect();
    void ouvrirFonctionSaisie();
    void ouvrirFonctionShowVal();
    void ouvrirFonctionShowExpress();
    void ouvrirFonctionSimplify();
    void ouvrirExpClassique();
    void ouvrirExpPolo();
    // page 2
    void ouvrirGraph2D();
    void ouvrirGraph3D();
    // page 2
    void ouvrirSauvegarde();
    void ouvrirEnregistrerSauvegarde();

    private:

    QTabWidget *onglets = new QTabWidget(&fenetre);

    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    // page 1
    QLineEdit *saisie = new QLineEdit("Entrez votre expression");
    QPushButton *showExpress = new QPushButton("Afficher l'expression");
    QPushButton *showVal = new QPushButton("Afficher la valeur");
    QPushButton *simplify = new QPushButton("Simplifier l'expression");
    QPushButton *classique = new QPushButton("Afficher l'expression classique");
    QPushButton *polo = new QPushButton("Afficher l'expression polonaise inversée");


    // page 2

    QPushButton *deud = new QPushButton("Graphique 2D");
    QPushButton *troid = new QPushButton("Graphique 3D");

    // page 3

    QPushButton *acces = new QPushButton("Ouvrir une sauvegarde");
    QPushButton *sauv = new QPushButton("Sauvegarder");

    QVBoxLayout *vbox1 = new QVBoxLayout;
    QVBoxLayout *vbox2 = new QVBoxLayout;
    QVBoxLayout *vbox3 = new QVBoxLayout;
    QPushButton *m_bouton;      // Attribut (forcément privé)
                                // pointeur --> il faudra le construire dynamiquement (new)

};

#endif
