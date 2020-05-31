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


    /* SAISIE DE L'EXPRESSION */

    // Champs de récupération des caractères entrés
    _champ = new QTextEdit(this);
    _champ->setGeometry(150, 100, 100, 30);

    // Bouton suivant
    QPushButton *suivant = new QPushButton(tr("Suivant"), this);
    suivant->setFont(QFont("Arial", 10, QFont::Bold));
    suivant->setGeometry(150, 150, 100, 30);

    // Pour associer le bouton suivant au fait de vouleur faire une nouvelle saisie
    connect(suivant, SIGNAL(clicked()), this, SLOT(suivante()));

    // Bouton valider pour valider la saisie
    QPushButton *valid = new QPushButton(tr("Valider"), this);
    valid->setFont(QFont("Arial", 10, QFont::Bold));
    valid->setGeometry(150, 200, 100, 30);

    // Pour associer le bouton valider au fait de valider la saisie totale
    connect(valid, SIGNAL(clicked()), this, SLOT(valider()));


    /* GESTION DE VARIABLE */

    // Variable
    QLabel *variableTitre = new QLabel(this);
    variableTitre->setText("Ajout Variable :");
    variableTitre->setFont(QFont("Arial", 10));
    variableTitre->setGeometry(350, 60, 150, 30);

    // Champ pour écrire le nom
    QLabel *nom = new QLabel(this);
    nom->setText("Nom : ");
    nom->setFont(QFont("Arial", 10));
    nom->setGeometry(350, 100, 40, 30);
    _variableNom = new QTextEdit(this);
    _variableNom->setGeometry(410, 100, 40, 30);

    // Champ pour écrire la valeur
    QLabel *valeur = new QLabel(this);
    valeur->setText("Valeur : ");
    valeur->setFont(QFont("Arial", 10));
    valeur->setGeometry(350, 150, 40, 30);
    _variableValeur = new QTextEdit(this);
    _variableValeur->setGeometry(410, 150, 40, 30);

    // Bouton pour ajouter la variable dans la table
    QPushButton *ajout = new QPushButton(tr("Ajouter"), this);
    ajout->setFont(QFont("Arial", 10, QFont::Bold));
    ajout->setGeometry(350, 200, 100, 30);

    // Pour associer le bouton ajouter au fait d'e quitter l'application d'ajouter une variable
    connect(ajout, SIGNAL(clicked()), this, SLOT(ajouter()));

    // Initialisation de la table de symboles
     _table = new Symboletable();

    /* AFFICHAGE DES RESULTATS ET NOTATIONS */

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
        // On ajoute *p à la fin
        QString fin = "*p";
        _elements.append(fin);

        // On efface le champ
        _champ->clear();

        // On efface les entrées affichées
        _resultat->clear();

        // Travail du groupe 1=
        _interactionUtilisateur = new InteractionUtilisateur(&_elements, _table);

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
        if(_elements.last().compare("*p") == 0) { // c'est une nouvelle saisie
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
    if(!_champ->toPlainText().isEmpty()) {
        QString strChamp = _champ->toPlainText();
        _elements.append(strChamp);

        //Affichage des saisies
        _resultat->setVisible(true);
        QString result;

        for (int i=0; i<_elements.size(); i++) {
            result = result + "  " + _elements[i];
        }

        _resultat->setText(result);
    }
    
    QString strChamp = _champ->toPlainText();
    if(_champ->toPlainText().toFloat() || _champ->toPlainText().compare("+") == 0
            || _champ->toPlainText().compare("-") == 0 || _champ->toPlainText().compare("/") == 0
            || _champ->toPlainText().compare("*") == 0) {
        _elements.append(strChamp);
    // On ajoute l'élément saisi par l'utilisateur dans la liste

        //Affichage des saisies
        resultat->setVisible(true);
        QString result;

        for (int i=0; i<_elements.size(); i++) {
            result = result + "  " + _elements[i];
        }

        resultat->setText(result);

    // On efface le champ pour permetrte une nouvelle saisie
    _champ->clear();

}

void Window::ajouter() {
    if(!_variableValeur->toPlainText().isEmpty() && _variableValeur->toPlainText().toFloat()
            && _variableNom->toPlainText().toStdString().size() == 1 && !_variableNom->toPlainText().isEmpty()) {

       // On convertit le nom en char
       std::string nom = _variableNom->toPlainText().toStdString();
       char cNom = nom.c_str()[0];

       // On convertit la valeur en float
       float valeur = _variableValeur->toPlainText().toFloat();

       // Ajout de la variable dans la table
       _table->insert(cNom, valeur);
    }

    _variableNom->clear();
    _variableValeur->clear();
}

    