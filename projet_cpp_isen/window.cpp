#include "window.h"

// Version 1 pour addition

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 330);

    // Consigne
    QLabel *consigne = new QLabel(this);
    consigne->setText("Entrer dans les champs un nombre et cliquer sur valider votre saisie");
    consigne->setFont(QFont("Arial", 10));
    consigne->setGeometry(10, 5, 500, 30);

    // Bouton quitter pour quitter la fenêtre proprement
    QPushButton *quit = new QPushButton(tr("Quitter"), this);
    quit->setFont(QFont("Arial", 10, QFont::Bold));
    quit->setGeometry(495, 5, 100, 30);

    // Pour associer le bouton quitter au fait de quitter l'application
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Champs de récupération des caractères entrés
    _champ1 = new QTextEdit(this);
    _champ2 = new QTextEdit(this);
    _champ1->setGeometry(120, 85, 100, 30);
    _champ2->setGeometry(370, 85, 100, 30);

    // Signe plus
   /* QLabel *plus = new QLabel(this);
    plus->setText("+");
    plus->setFont(QFont("Arial", 10));
    plus->setAlignment(Qt::AlignHCenter);
    plus->setGeometry(250, 85, 100, 30);*/

    // Group Box contenant les opérateurs
    _choixOperateur = new QGroupBox(tr("Choix de l'opérateur"), this);
    _choixOperateur->setGeometry(235, 55, 120, 95);

    // Choix de l'addition
    _plus = new QRadioButton(tr("+"));
    _plus->setChecked(true);

    // Choix de la soustraction
    _moins= new QRadioButton(tr("-"));
    _moins->setChecked(false);

    // Choix de la multiplication
    _multiplicateur = new QRadioButton(tr("*"));
    _multiplicateur->setChecked(false);

    // Choix de la division
    _diviseur = new QRadioButton(tr("/"));
    _diviseur->setChecked(false);

    // Layout Verticale pour aligner les bouton verticalement
    _operateur = new QVBoxLayout();
    _operateur->addWidget(_plus);
    _operateur->addWidget(_moins);
    _operateur->addWidget(_multiplicateur);
    _operateur->addWidget(_diviseur);
    _operateur->addStretch(1);
    _choixOperateur->setLayout(_operateur);

//    QGridLayout *grille = new QGridLayout;
//    grille->addWidget(_choixOperateur, 0, 1);
//    grille->setOriginCorner(Qt::BottomLeftCorner);
//    resize(100, 100);
//    setLayout(grille);

    // Bouton valider pour valider la saisie
    QPushButton *valid = new QPushButton(tr("Valider"), this);
    valid->setFont(QFont("Arial", 10, QFont::Bold));
    valid->setGeometry(250, 165, 100, 30);

    // Pour associer le bouton valider au fait de valider la saisie
    connect(valid, SIGNAL(clicked()), this, SLOT(valider()));

    // Resultat
    _resultat = new QLabel(this);
    _resultat->setVisible(false);

    // Notation classique
    _classique = new QLabel(this);
    _classique->setVisible(false);

    // Notation polonaise inversée
    _polonaise = new QLabel(this);
    _polonaise->setVisible(false);
}

void Window::valider() {
    // Récupération du contenu des champs
    QString strChamp1 = _champ1->toPlainText();
    QString strChamp2 = _champ2->toPlainText();

    if (!strChamp1.isNull() && !strChamp2.isNull() && strChamp1.toFloat() && strChamp2.toFloat()){
        // Création de deux constantes pour l'addition simple
        Constante *c1 = new Constante(strChamp1.toFloat());
        Constante *c2 = new Constante(strChamp2.toFloat());

        if(_plus->isChecked()) {
            _addition = new Addition(c1, c2);

            // Affichage du résultat
            QString result;
            result.setNum(_addition->calcul());
            _resultat->setText(result);

            // Affichage de la notation classique
            _classique->setText(" ( " + strChamp1 + " + " + strChamp2 + " ) ");

            // Affichage de la polonaise inversée
            _polonaise->setText(strChamp1 + " " + strChamp2 + " + ");
        }
        else if(_moins->isChecked()) {
            _soustraction = new Soustraction(c1, c2);

            // Affichage du résultat
            QString result;
            result.setNum(_soustraction->calcul());
            _resultat->setText(result);

            // Affichage de la notation classique
            _classique->setText(" ( " + strChamp1 + " - " + strChamp2 + " ) ");

            // Affichage de la polonaise inversée
            _polonaise->setText(strChamp1 + " " + strChamp2 + " - ");
        }
        else if(_multiplicateur->isChecked()) {
            _multiplication = new Multiplication(c1, c2);

            // Affichage du résultat
            QString result;
            result.setNum(_multiplication->calcul());
            _resultat->setText(result);

            // Affichage de la notation classique
            _classique->setText(" ( " + strChamp1 + " * " + strChamp2 + " ) ");

            // Affichage de la polonaise inversée
            _polonaise->setText(strChamp1 + " " + strChamp2 + " * ");
        }
        else if(_diviseur->isChecked()) {
            _division = new Division(c1, c2);

            // Affichage du résultat
            QString result;
            result.setNum(_division->calcul());
            _resultat->setText(result);

            // Affichage de la notation classique
            _classique->setText(" ( " + strChamp1 + " / " + strChamp2 + " ) ");

            // Affichage de la polonaise inversée
            _polonaise->setText(strChamp1 + " " + strChamp2 + " / ");
        }

        // Affichage du résultat
        _resultat->setVisible(true);
        _resultat->setFont(QFont("Arial", 12));
        _resultat->setAlignment(Qt::AlignHCenter);
        _resultat->setGeometry(0, 215, 600, 30);

        // Affichage de la notation classique
        _classique->setVisible(true);
        _classique->setFont(QFont("Arial", 12));
        _classique->setAlignment(Qt::AlignHCenter);
        _classique->setGeometry(0, 250, 600, 30);

        // Affichage de la polonaise inversée
        _polonaise->setVisible(true);
        _polonaise->setFont(QFont("Arial", 12));
        _polonaise->setAlignment(Qt::AlignHCenter);
        _polonaise->setGeometry(0, 285, 600, 30);
    }

    // On efface le contenu des champs
    _champ1->clear();
    _champ2->clear();
}
