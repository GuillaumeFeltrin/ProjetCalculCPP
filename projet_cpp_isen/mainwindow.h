#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>


class MainWindow : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT                    // Nécessaire pour créer un slot maison

    public:
    MainWindow();                // Constructeur (forcément pubic)

    public slots:               // Slots maison
    void Dialogue();

    private:
    QPushButton *m_bouton;      // Attribut (forcément privé)
                                // pointeur --> il faudra le construire dynamiquement (new)

};

#endif
