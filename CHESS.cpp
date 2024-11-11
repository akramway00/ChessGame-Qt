// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35
// TP4

#include "CHESS.h"
#include <QPushButton>
#include <QGridLayout>


namespace view {

    void CHESS::resetAllButtonColors() {
        for (int row = 0; row < board_.getNbRows(); ++row) {
            for (int col = 0; col < board_.getNbColumns(); ++col) {
                QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());
                if (button) {
                    QString color = ((row + col) % 2 == 0) ? "#c6a46f" : "#7a532e";  // Les couleurs par defaut
                    changeButtonColor(button, color);
                }
            }
        }
    }

    void CHESS::InitGames()
    {



        board_.clearBoard();

        historyTextEdit->clear();

        resetAllButtonColors();

        clickNumber_ = 0;

        try {
            model::Tower tower("white");
            model::Bishop bishop("white");
            model::King king("white");

            model::Tower tower2("black");
            model::Bishop bishop2("black");
            model::King king2("black");

            //King king3("white");     // ligne a decommenter pour tester lexception


            board_.addPiece({ 7,2 }, std::make_shared<model::Piece>(bishop));
            board_.addPiece({ 7,3 }, std::make_shared<model::Piece>(king));
            board_.addPiece({ 7,4 }, std::make_shared<model::Piece>(tower));


            board_.addPiece({ 0,2 }, std::make_shared<model::Piece>(bishop2));
            board_.addPiece({ 0,3 }, std::make_shared<model::Piece>(king2));
            board_.addPiece({ 0,4 }, std::make_shared<model::Piece>(tower2));

            currentState_ = State::init_Player1;

            updateUI();
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << e.what() << std::endl;
            textePartie->setText("ERREUR");
            texteErreurs->setText("Erreur: Plus de 2 rois ");

        }

    }

    void CHESS::InitGames2()
    {
        InitGames();
        board_.movePiece({ 7,2 }, { 7,0 });
        board_.movePiece({ 7,4 }, { 7,7 });
        board_.movePiece({ 7,3 }, { 7,4 });
        board_.movePiece({ 0,2 }, { 0,0 });
        board_.movePiece({ 0,4 }, { 0,7 });
        board_.movePiece({ 0,3 }, { 0,4 });

        updateUI();

    }

    void CHESS::InitGames3()
    {
        InitGames();
        board_.movePiece({ 7,2 }, { 1,2 });
        board_.movePiece({ 7,3 }, { 1,3 });
        board_.movePiece({ 7,4 }, { 1,4 });

        board_.movePiece({ 0,2 }, { 7,2 });
        board_.movePiece({ 0,3 }, { 7,3 });
        board_.movePiece({ 0,4 }, { 7,4 });

        board_.movePiece({ 1,2 }, { 0,2 });
        board_.movePiece({ 1,3 }, { 0,3 });
        board_.movePiece({ 1,4 }, { 0,4 });

        updateUI();
    }

    void CHESS::initGrid()

    {
        QWidget* centralWidget = new QWidget();
        centralWidget->setStyleSheet("background-color: #F5E2C9;");
        setCentralWidget(centralWidget);

        QHBoxLayout* layoutPrincipal = new QHBoxLayout(centralWidget);


        
        gridLayout->setSpacing(0);

        QWidget* chessBoardContainer = new QWidget(centralWidget);
        chessBoardContainer->setLayout(gridLayout);

        layoutPrincipal->addWidget(chessBoardContainer, 2);
        layoutPrincipal->setSpacing(0);

        QFrame* line = new QFrame();
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutPrincipal->addWidget(line);

        QVBoxLayout* layoutTexte = new QVBoxLayout();

        textePartie = new QLabel("En Attente...");
        textePartie->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        textePartie->setAlignment(Qt::AlignCenter);
        textePartie->setStyleSheet("QLabel { color: black; font-family: 'Courier New'; font-size: 25pt; font-weight: 1000; }");
        layoutTexte->addWidget(textePartie);


        QLabel* texts = new QLabel("Liste des Mouvements");
        texts->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        texts->setAlignment(Qt::AlignCenter);
        texts->setStyleSheet("QLabel { background-color: #7a532e; color: white; font-family: 'Courier New'; font-size: 15pt; font-weight: 700; }");
        layoutTexte->addWidget(texts);




        layout = new QVBoxLayout();
        layout->setContentsMargins(0, 0, 0, 0);

        historyTextEdit = new QTextEdit();
        historyTextEdit->setReadOnly(true);
        //historyTextEdit->setStyleSheet("background-color: white; border: 5px solid #7a532e;");

        historyTextEdit->setStyleSheet(
            "QTextEdit {"
            "  background-color: white;"
            "  border: 5px solid #7a532e;"
            "  color: #7a532e;"
            "  font-family: 'Courier New';"
            "  font-size: 16pt;"
            "  font-weight: 1000;"
            "}"
        );

        //historyTextEdit->setMaximumHeight(400);
        layout->addWidget(historyTextEdit);



        layoutTexte->addWidget(historyTextEdit);


        texteErreurs = new QLabel("");
        texteErreurs->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        texteErreurs->setAlignment(Qt::AlignCenter);
        texteErreurs->setStyleSheet("QLabel { color: black; font-family: 'Courier New'; font-size: 10pt; font-weight: 1000; }");
        layoutTexte->addWidget(texteErreurs);







        QHBoxLayout* layoutComboBox = new QHBoxLayout();



        QComboBox* comboBox = new QComboBox();



        comboBox->setStyleSheet(
            "QComboBox {"
            "  background-color: #7a532e;"
            "  color: white;"
            "  font-family: 'Courier New';"
            "  text-align: center;"
            "  font-size: 15pt;"
            "  font-weight: 1000;"
            "  border: 1px solid gray;"
            "  padding: 1px 18px 1px 3px;"
            "}"
        );
        comboBox->addItem("          Partie 1");
        comboBox->addItem("          Partie 2");
        comboBox->addItem("          Partie 3");

        layoutComboBox->addWidget(comboBox);



        connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onGameSelected(int)));
        layoutTexte->addLayout(layoutComboBox);

        QWidget* textContainer = new QWidget();  // Conteneur pour le texte et les controles
        textContainer->setLayout(layoutTexte);
        layoutPrincipal->addWidget(textContainer, 1);  // 1 part pour le texte

        // Configuration des boutons d'echecs

        // #7a532e
        for (int row = 0; row < board_.getNbRows(); ++row) {
            for (int col = 0; col < board_.getNbColumns(); ++col) {
                QPushButton* button = new QPushButton();
                //button->setFixedSize(buttonSize, buttonSize);
                button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                QString color = ((row + col) % 2 == 0) ? "#c6a46f" : "#7a532e";
                changeButtonColor(button, color);
                connect(button, &QPushButton::clicked, this, [this, row, col]()
                    {
                        chessClicked(row, col);
                    });
                gridLayout->addWidget(button, row, col);
            }
        }

        // configuration pour boutton restart
        QHBoxLayout* layoutRestartButton = new QHBoxLayout();
        QPushButton* restartButton = new QPushButton("Recommencer");

        restartButton->setStyleSheet("QPushButton { background-color: #7a532e; color: white; font-family: 'Courier New'; font-size: 15pt; font-weight: 700; }");
        connect(restartButton, &QPushButton::clicked, this, &CHESS::InitGames);
        layoutRestartButton->addWidget(restartButton);
        layoutTexte->addLayout(layoutRestartButton);

        // configuration pour boutton musique

        QPushButton* playPauseButton = new QPushButton("Allumer/Eteindre musique");
        playPauseButton->setStyleSheet("QPushButton { background-color: #7a532e; color: white; font-family: 'Courier New'; font-size: 15pt; font-weight: 700; }");
        connect(playPauseButton, &QPushButton::clicked, this, &CHESS::playPauseButton_clicked);
        layoutTexte->addWidget(playPauseButton);


    }

    void CHESS::changeButtonColor(QPushButton* button, const QString& color) {
        button->setStyleSheet("QPushButton { background-color: " + color + "; }");
    }

    void CHESS::onGameSelected(int index) {
        switch (index) {
        case 0: // Partie 1 
            InitGames();
            break;
        case 1: // Partie 2
            InitGames2();
            break;
        case 2: // Partie 3 
            InitGames3();
            break;
        default:

            break;
        }
    }

    void CHESS::resetButtonColor(QPushButton* button, int row, int col) {
        QString initialColor = ((row + col) % 2 == 0) ? "#c6a46f" : "#7a532e";
        changeButtonColor(button, initialColor);
    }






    CHESS::CHESS(model::Board board, QWidget* parent)
        : board_(board), QMainWindow(parent), gridLayout(new QGridLayout())
    {
        ui.setupUi(this);

        initGrid();
        InitGames();

        playerMusic_ = new QMediaPlayer;
        output_ = new QAudioOutput;


        playerMusic_->setAudioOutput(output_);
        playerMusic_->setSource(QUrl("icon_CHESS/outro_music.mp3"));


        //playerMusic_->setSource(QUrl("icon_CHESS/instru.mp3"));


        output_->setVolume(0.5);





        updateUI();

    }

    void CHESS::playPauseButton_clicked() {
        if (playerMusic_->playbackState() == QMediaPlayer::PlayingState) {
            playerMusic_->pause();
        }
        else {
            playerMusic_->play();
        }
    }



    void CHESS::chessClicked(int row, int col)
    {
        clickNumber_++;

        auto ptrBoard = std::make_shared<model::Board>(board_);

        switch (currentState_)
        {
        case State::init_Player1:

            textePartie->setText("Tour: BLANC");

            if (clickNumber_ == 1)
            {

                firstClick_ = { row,col };



                piecePlayer1 = board_.getPiecePtr(firstClick_);

                if (piecePlayer1)
                {

                    std::string colorClick1 = piecePlayer1->getColor();


                    if (colorClick1 == player1_.getColor())
                    {
                        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());
                        if (player1_.isCheck(ptrBoard))
                        {
                            std::pair<int, int> posK = board_.findPiece(player1_.getColor(), "King");
                            QPushButton* button15 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(posK.first, posK.second)->widget());
                            changeButtonColor(button15, "red");
                            clickNumber_ = 0;
                            textePartie->setText("blancs en ECHEC");
                            updateUI();
                            //break;
                        }
                        else
                        {
                            changeButtonColor(button, "green");

                        }

                        updateUI();
                        typePieceClick1 = piecePlayer1->getType();

                        movesAvailablesPlayer1 = player1_.possibleValidsMoves(ptrBoard, typePieceClick1);

                        if (movesAvailablesPlayer1.empty())
                        {
                            clickNumber_ = 0;
                            break;
                        }
                        else
                        {
                            clickNumber_ = 1;
                        }
                        updateUI();
                        for (auto& move : movesAvailablesPlayer1)
                        {
                            //std::cout << move.first << "," << move.second << std::endl;
                            //board_.movePiece(firstClick_, move);
                            //if (!player1_.isCheck(ptrBoard))
                            //{

                            //}
                            QPushButton* button1 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(move.first, move.second)->widget());
                            changeButtonColor(button1, "#FFFF8F ");
                        }



                        currentState_ = State::SecondClick_Player1;

                    }

                    else
                    {
                        clickNumber_ = 0;
                    }
                }
                else
                {
                    clickNumber_ = 0;
                }

            }

            break;

        case State::SecondClick_Player1:


            updateUI();

            if (clickNumber_ == 2)
            {

                secondClick_ = { row,col };



                for (auto& move : movesAvailablesPlayer1)
                {
                    QPushButton* button2 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(move.first, move.second)->widget());
                    resetButtonColor(button2, move.first, move.second);
                }


                bool possibleMovePlayer1 = player1_.contains(movesAvailablesPlayer1, secondClick_);

                if (possibleMovePlayer1 == true)
                {

                    board_.movePiece(firstClick_, secondClick_);


                    std::pair<int, int> posK = board_.findPiece(player1_.getColor(), "King");
                    QPushButton* button12 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(posK.first, posK.second)->widget());
                    resetButtonColor(button12, posK.first, posK.second);





                    QString hisText = QString::fromStdString(typePieceClick1) + "(" + QString::number(firstClick_.first) + "," + QString::number(firstClick_.second) + ")" + "-->" + "(" + QString::number(secondClick_.first) + "," + QString::number(secondClick_.second) + ")" + "\n";

                    historyTextEdit->append(hisText);

                    QPushButton* button3 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(firstClick_.first, firstClick_.second)->widget());

                    resetButtonColor(button3, firstClick_.first, firstClick_.second);
                    textePartie->setText("Tour: NOIR");
                    updateUI();
                    clickNumber_ = 0;

                    currentState_ = State::init_Player2;


                }
                else
                {
                    //std::cout << "Mouvement invalide" << std::endl;
                    clickNumber_ = 0;
                    currentState_ = State::init_Player1;
                    QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(firstClick_.first, firstClick_.second)->widget());
                    resetButtonColor(button, firstClick_.first, firstClick_.second);

                }

            }

            break;

        case State::init_Player2:

            textePartie->setText("Tour: NOIR");

            if (clickNumber_ == 1)
            {

                firstClick_ = { row,col };

                piecePlayer2 = board_.getPiecePtr(firstClick_);

                if (piecePlayer2)
                {

                    std::string colorClick2 = piecePlayer2->getColor();


                    if (colorClick2 == player2_.getColor())
                    {
                        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());

                        if (player2_.isCheck(ptrBoard))
                        {
                            std::pair<int, int> posK2 = board_.findPiece(player2_.getColor(), "King");
                            QPushButton* buttonK2 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(posK2.first, posK2.second)->widget());
                            changeButtonColor(buttonK2, "red");
                            textePartie->setText("noirs en ECHEC");
                            updateUI();
                            clickNumber_ = 0;
                            //break;
                        }

                        else
                        {
                            changeButtonColor(button, "green");
                        }

                        updateUI();
                        typePieceClick2 = piecePlayer2->getType();

                        movesAvailablesPlayer2 = player2_.possibleValidsMoves(ptrBoard, typePieceClick2);

                        if (movesAvailablesPlayer2.empty())
                        {
                            clickNumber_ = 0;
                            break;
                        }

                        else
                        {
                            clickNumber_ = 1;
                        }



                        for (auto& move : movesAvailablesPlayer2)
                        {
                            QPushButton* button6 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(move.first, move.second)->widget());
                            changeButtonColor(button6, "#FFFF8F ");
                        }

                        currentState_ = State::SecondClick_Player2;
                    }

                    else
                    {
                        clickNumber_ = 0;
                    }
                }
                else
                {
                    clickNumber_ = 0;
                }

            }

            break;

        case State::SecondClick_Player2:

            if (clickNumber_ == 2)
            {
                secondClick_ = { row,col };

                for (auto& move : movesAvailablesPlayer2)
                {
                    QPushButton* button2 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(move.first, move.second)->widget());
                    resetButtonColor(button2, move.first, move.second);
                }

                bool possibleMovePlayer2 = player2_.contains(movesAvailablesPlayer2, secondClick_);

                if (possibleMovePlayer2)
                {

                    board_.movePiece(firstClick_, secondClick_);

                    std::pair<int, int> posK = board_.findPiece(player2_.getColor(), "King");
                    QPushButton* button12 = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(posK.first, posK.second)->widget());
                    resetButtonColor(button12, posK.first, posK.second);


                    QString hisText = QString::fromStdString(typePieceClick2) + "(" + QString::number(firstClick_.first) + "," + QString::number(firstClick_.second) + ")" + "-->" + "(" + QString::number(secondClick_.first) + "," + QString::number(secondClick_.second) + ")" + "\n";

                    historyTextEdit->append(hisText);


                    QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(firstClick_.first, firstClick_.second)->widget());
                    resetButtonColor(button, firstClick_.first, firstClick_.second);
                    clickNumber_ = 0;
                    textePartie->setText("Tour: BLANC");
                    updateUI();
                    currentState_ = State::init_Player1;
                }
                else
                {
                    //std::cout << "Mouvement invalide" << std::endl;
                    clickNumber_ = 0;
                    currentState_ = State::init_Player2;
                    QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(firstClick_.first, firstClick_.second)->widget());
                    resetButtonColor(button, firstClick_.first, firstClick_.second);

                }

            }
            break;

        }
        updateUI();

    }



    void CHESS::updateUI()  // permet dactualiser le plateau (interface) avec letat du plateau(board)
    {
        for (int row = 0; row < board_.getNbRows(); ++row) {
            for (int col = 0; col < board_.getNbColumns(); ++col) {
                QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());
                if (button) {
                    std::shared_ptr<model::Piece> piece = board_.getPiecePtr({ row,col });

                    if (piece) {

                        button->setIcon(piece->getIcon());
                        button->setIconSize(QSize(50, 50));


                    }
                    else {
                        // Si la case est vide, reinitialiser l'icone du bouton
                        button->setIcon(QIcon());

                    }
                }
            }
        }



    }



    CHESS::~CHESS()
    {

        delete playerMusic_;
        playerMusic_ = nullptr;

        delete output_;
        output_ = nullptr;

        delete gridLayout;
        gridLayout = nullptr;

        delete textePartie;
        textePartie = nullptr;

        delete texteErreurs;
        texteErreurs = nullptr;

        delete historyTextEdit;
        historyTextEdit = nullptr;

        delete layout;
        layout = nullptr;

    }

}

