#include "window.h"

// Version 1 pour addition

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 350);

    // Consigne
    QLabel *consigne = new QLabel(this);
    consigne->setText("Entrez dans le champ un nombre ou un opérateur. \nCliquez sur Suivant pour entrer un nouvel élément. \nCliquez sur Valider pour valider la saisie de la relation complète.");
    consigne->setFont(QFont("Arial", 10));
    consigne->setGeometry(10, 5, 500, 60);

    // Bouton quitter pour quitter la fenêtre proprement
    QPushButton *quit = new QPushButton(tr("Quitter"), this);
    quit->setFont(QFont("Arial", 10, QFont::Bold));
    quit->setGeometry(495, 5, 100, 30);

    // Pour associer le bouton quitter au fait de quitter l'application
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Champs de récupération des caractères entrés
    _champ = new QTextEdit(this);
    _champ->setGeometry(250, 85, 100, 30);

    // Bouton suivant
    QPushButton *suivant = new QPushButton(tr("Suivant"), this);
    suivant->setFont(QFont("Arial", 10, QFont::Bold));
    suivant->setGeometry(250, 150, 100, 30);

    // Pour associer le bouton suivant au fait de vouleur faire une nouvelle saisie
    connect(suivant, SIGNAL(clicked()), this, SLOT(suivante()));

    // Bouton valider pour valider la saisie
    QPushButton *valid = new QPushButton(tr("Valider"), this);
    valid->setFont(QFont("Arial", 10, QFont::Bold));
    valid->setGeometry(250, 200, 100, 30);

    // Pour associer le bouton valider au fait de valider la saisie totale
    connect(valid, SIGNAL(clicked()), this, SLOT(valider()));

    // Resultat
    _resultat = new QLabel(this);
    _resultat->setVisible(false);
    _resultat->setFont(QFont("Arial", 12));
    _resultat->setAlignment(Qt::AlignHCenter);
    _resultat->setGeometry(0, 250, 600, 30);

    // Notation classique
    _classique = new QLabel(this);
    _classique->setVisible(false);
    _classique->setFont(QFont("Arial", 12));
    _classique->setAlignment(Qt::AlignHCenter);
    _classique->setGeometry(0, 285, 600, 30);

    // Notation polonaise inversée
    _polonaise = new QLabel(this);
    _polonaise->setVisible(false);
    _polonaise->setFont(QFont("Arial", 12));
    _polonaise->setAlignment(Qt::AlignHCenter);
    _polonaise->setGeometry(0, 315, 600, 30);

}

void Window::valider() {
    if (_elements.size() != 0){
        // On ajoute p à la fin
        QString fin = "p";
        _elements.append(fin);

        // On efface le champ
        _champ->clear();

        // On efface les entrées affichées
        _resultat->clear();

        // Travail du groupe 1=
        _interactionUtilisateur = new InteractionUtilisateur(&_elements);

        // On affiche le résultat, la notation classique et la notation polonaise inversée
        // Resultat
        QString result;
        result.setNum(_interactionUtilisateur->getExpression()->calcul());
        _resultat->setVisible(true);
        _resultat->setText(result);

        // Notation classique
        QString cla = QString::fromStdString(_interactionUtilisateur->getExpression()->affichageClassiqueStr());
        _classique->setVisible(true);
        _classique->setText(cla);

        // Notation polonaise inversée
        QString pol = QString::fromStdString(_interactionUtilisateur->getExpression()->affichagePolonaiseInverseeStr());
        _polonaise->setVisible(true);
        _polonaise->setText(pol);
    }
}

void Window::suivante() {
    if(_elements.size() != 0){
        if(_elements.last().compare("p") == 0) { // c'est une nouvelle saisie
            // On n'affiche plus les notations classique, polonaise inversée et le résultat
            if(_polonaise->isVisible()) {
                _polonaise->setVisible(false);
                _polonaise->clear();
            }
            if(_classique->isVisible()) {
                _classique->setVisible(false);
                _classique->clear();
            }
            if(_resultat->isVisible()) {
                _resultat->setVisible(false);
                _resultat->clear();
            }

            // On vide _elements
            _elements.clear();
        }
    }

    // On ajoute l'élément saisi par l'utilisateur dans la liste
    QString strChamp = _champ->toPlainText();
    if(_champ->toPlainText().toFloat() || _champ->toPlainText().compare("+") == 0
            || _champ->toPlainText().compare("-") == 0 || _champ->toPlainText().compare("/") == 0
            || _champ->toPlainText().compare("*") == 0) {
        _elements.append(strChamp);

        //Affichage des saisies
        _resultat->setVisible(true);
        QString result;

        for (int i=0; i<_elements.size(); i++) {
            result = result + "  " + _elements[i];
        }

        _resultat->setText(result);
    }

    // On efface le champ pour permetrte une nouvelle saisie
    _champ->clear();

}
