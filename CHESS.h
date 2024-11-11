#pragma once
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35

#include <QtWidgets/QMainWindow>
#include "ui_CHESS.h"
#include <QApplication>
#include "playablePieces.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QComboBox>
#include <QGroupBox>
#include <QTextEdit>
#include <QResizeEvent>
#include <QMediaPlayer>  // include pour la musique
#include <QAudioOutput>  // include pour la musique


namespace view {

enum class State
{
    init_Player1,
    SecondClick_Player1,
    init_Player2,
    SecondClick_Player2,
    

};

class CHESS : public QMainWindow
{
    Q_OBJECT

public:
    CHESS(model::Board board, QWidget* parent = nullptr);

    
    void InitGames();
    void InitGames2();
    void InitGames3();

    void resetAllButtonColors();

    ~CHESS();


private slots:
    void chessClicked(int row, int col);
    void initGrid();
    void changeButtonColor(QPushButton* button, const QString& color);
    void resetButtonColor(QPushButton* button, int row, int col);
    void onGameSelected(int index);

    void playPauseButton_clicked();





private:

    Ui::CHESSClass ui;
    QGridLayout* gridLayout = nullptr;
    QLabel* textePartie = nullptr;
    QLabel* texteErreurs = nullptr;
    QTextEdit* historyTextEdit = nullptr;
    QVBoxLayout* layout = nullptr;         
    model::Board board_;
    void updateUI();
    model::Player player1_ = model::Player("white");
    model::Player player2_ = model::Player("black");

    QMediaPlayer* playerMusic_; // rajouter pour la musique
    QAudioOutput* output_;  // permet de stopper la musique
    




    State currentState_ = State::init_Player1;

    int clickNumber_ = 0;
    std::pair<int, int> firstClick_;
    std::pair<int, int> secondClick_;

    std::string typePieceClick1;
    std::shared_ptr<model::Piece> piecePlayer1 = nullptr;
    std::vector<std::pair<int, int>> movesAvailablesPlayer1;
    std::vector<std::pair<int, int>> movesPlayer1AfterChess;

   
    std::string typePieceClick2;
    std::shared_ptr<model::Piece> piecePlayer2 = nullptr;
    std::vector<std::pair<int, int>> movesAvailablesPlayer2;




};
}