#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()  // spécification du constructeur
{
    setFixedSize(300,400); // setFixedSize appartient à classe MaFenetre (héritage de QWidget
                           // Largeur / Hauteur

    /* Construction du bouton */
    m_bouton = new QPushButton("open", this); // this = pointeur vers le widget parent, pointeur vers 'moi'
    m_bouton->move(100, 100);   // RePositionnement Absolu

    saisie->setToolTip("Entrez votre expression");
    showExpress->setToolTip("Afficher l'expression");
    showVal->setToolTip("Afficher la valeur");
    simplify->setToolTip("Simplifier l'expression");

    // page 1
    vbox1->addWidget(saisie);
    vbox1->addWidget(classique);
    vbox1->addWidget(polo);
    vbox1->addWidget(showVal);
    vbox1->addWidget(simplify);
    page1->setLayout(vbox1);


    // page 2
    vbox2->addWidget(deud);
    vbox2->addWidget(troid);
    page2->setLayout(vbox2);

    // page 2
    vbox3->addWidget(acces);
    vbox3->addWidget(sauv);
    page3->setLayout(vbox3);




    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent

    onglets->setGeometry(50,50, 500, 400);
    onglets->addTab(page1, "Affichage de l'expression ");
    onglets->addTab(page2, "Graphique 2D et 3D");
    onglets->addTab(page3, "Sauvegarde");


    /* Connexions Signal - Slot */
    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(Redirect())); // this = SLOT de MyWindow (SLOT MAISON)
    QObject::connect(saisie, SIGNAL(clicked()), this, SLOT(ouvrirFonctionSaisie()));
    QObject::connect(showVal, SIGNAL(clicked()), this, SLOT(ouvrirFonctionShowVal()));
    //QObject::connect(showExpress, SIGNAL(clicked()), this, SLOT(ouvrirFonctionShowExpress()));
    QObject::connect(simplify, SIGNAL(clicked()), this, SLOT(ouvrirFonctionSimplify()));
    QObject::connect(classique, SIGNAL(clicked()), this, SLOT(ouvrirExpClassique()));
    QObject::connect(polo, SIGNAL(clicked()), this, SLOT(ouvrirExpPolo()));

    // page 2
    QObject::connect(deud, SIGNAL(clicked()), this, SLOT(ouvrirGraph2D()));
    QObject::connect(troid, SIGNAL(clicked()), this, SLOT(ouvrirGraph3D()));

    // page 3
    QObject::connect(acces, SIGNAL(clicked()), this, SLOT(ouvrirSauvegarde()));
    QObject::connect(sauv, SIGNAL(clicked()), this, SLOT(ouvrirEnregistrerSauvegarde()));

    fenetre.show();
}
//==========================================================================================
void MainWindow::Redirect()
{
    QMessageBox::information(this, "Titre de la fenêtre", "Hello");
    // REM : information / warning / critical / question
    // int reponse =  QMessageBox::question(this, "Titre de la fenêtre", "vraiment ?", QMessageBox::Yes | QMessageBox::No);
    // (OU LOGIQUE)

}

void MainWindow::ouvrirExpClassique()
{
    QMessageBox::information(this, "Classique", "Classique");

}

void MainWindow::ouvrirExpPolo()
{
    QMessageBox::information(this, "Polonaise inversée", "Polonaise inversée");
}

void MainWindow::ouvrirFonctionSaisie()
{
    QMessageBox::information(this, "Saisie", "Saisie");

}

void MainWindow::ouvrirFonctionShowExpress()
{
    QMessageBox::information(this, "Expression Classique", "Expression Classique");


}

void MainWindow::ouvrirFonctionSimplify()
{
    QMessageBox::information(this, "Simplifier", "Simplifier");
}

void MainWindow::ouvrirFonctionShowVal()
{
    QMessageBox::information(this, "Valeur", "Valeur");
}

void MainWindow::ouvrirGraph2D()
{
    QMessageBox::information(this, "2D", "2D");
}

void MainWindow::ouvrirGraph3D()
{
    QMessageBox::information(this, "3D", "3D");
}


void MainWindow::ouvrirSauvegarde()
{
    QMessageBox::information(this, "Sauvegarde", "Sauvegarde");
}

void MainWindow::ouvrirEnregistrerSauvegarde()
{
    QMessageBox::information(this, "Sauvegarde", "Sauvegarde");
}


