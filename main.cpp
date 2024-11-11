// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35


#include "CHESS.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QPixmap>
//
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"




int main(int argc, char *argv[])

{
    QApplication a(argc, argv);

    model::Board board1;

    view::CHESS w(board1);
    
    w.setWindowTitle("Chess by Ramkinho");
    w.setWindowIcon(QIcon("icon_CHESS/logo.jpg"));
    w.show();
    return a.exec();


}
