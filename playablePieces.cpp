#include "playablePieces.h"
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35


namespace model {

    int King::instanceCount = 0;

    King::~King() { instanceCount = 0; }

    King::King(std::string couleur) : Piece(couleur, "King")

    {

        if (instanceCount >= 2)
        {
            throw std::runtime_error("Il ne peut pas avoir plus de deux rois");
        }

        ++instanceCount;

        if (color_ == "white")
        {
            icon_ = QIcon("icon_CHESS/white_king.png");
        }
        else
        {
            icon_ = QIcon("icon_CHESS/black_king.png");
        }

    }

    Tower::Tower(std::string couleur) : Piece(couleur, "Tower")
    {
        if (color_ == "white")
        {
            icon_ = QIcon("icon_CHESS/white_tower.png");
            // icon_ = QIcon("icon_CHESS/memeJeromeCollin.PNG");

        }
        else
        {
            icon_ = QIcon("icon_CHESS/black_tower.png");
        }

    }
    Bishop::Bishop(std::string couleur) : Piece(couleur, "Bishop")
    {
        if (color_ == "white")
        {
            icon_ = QIcon("icon_CHESS/white_bishop.png");
        }
        else
        {
            icon_ = QIcon("icon_CHESS/black_bishop.png");
        }

    }


    std::vector<std::pair<int, int>> King::possibleMoves(std::shared_ptr<Board> board)
    {
        std::vector<std::pair<int, int>> possibleMoves;
        std::pair<int, int> pos = board->findPiece(color_, "King");

        std::vector<std::pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        for (auto& dir : directions)
        {
            std::pair<int, int> newPos = { pos.first + dir.first, pos.second + dir.second };


            if (newPos.first >= 0 && newPos.first < board->getNbRows() && newPos.second >= 0 && newPos.second < board->getNbColumns()) {
                if (board->isEnemyPiece(newPos, color_) || !board->isOccupied(newPos)) {
                    possibleMoves.push_back(newPos);
                }
            }
        }

        return possibleMoves;
    }



    std::vector<std::pair<int, int>> Tower::possibleMoves(std::shared_ptr<Board> board)
    {
        std::vector<std::pair<int, int>> possibleMoves;  // vecteur avec la liste des mouvements possibles
        std::pair<int, int> pos = board->findPiece(color_, "Tower"); // position actuelle de la tour
        std::string color = color_;

        std::vector<std::pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (auto& dir : directions)
        {
            for (int i = 1; i < board->getNbRows(); i++)
            {
                std::pair<int, int> newPos = { pos.first + i * dir.first, pos.second + i * dir.second };

                if (newPos.first >= 0 && newPos.first < board->getNbRows() && newPos.second >= 0 && newPos.second < board->getNbColumns())
                {
                    if (board->isOccupied(newPos))
                    {
                        if (board->isEnemyPiece(newPos, color))
                        {
                            possibleMoves.push_back(newPos);
                        }
                        break;
                    }
                    possibleMoves.push_back(newPos);
                }
            }
        }

        return possibleMoves;
    }

    std::vector<std::pair<int, int>> Bishop::possibleMoves(std::shared_ptr<Board> board)
    {
        std::vector<std::pair<int, int>> possibleMoves;  // vecteur avec la liste des mouvements possibles
        std::pair<int, int> pos = board->findPiece(color_, "Bishop"); // position actuelle du fou
        std::string color = color_;

        std::vector<std::pair<int, int>> directions = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

        for (auto& dir : directions)
        {
            for (int i = 1; i < board->getNbRows(); i++)
            {
                std::pair<int, int> newPos = { pos.first + i * dir.first, pos.second + i * dir.second };

                if (newPos.first >= 0 && newPos.first < board->getNbRows() && newPos.second >= 0 && newPos.second < board->getNbColumns())
                {
                    if (board->isOccupied(newPos))
                    {
                        if (board->isEnemyPiece(newPos, color))
                        {
                            possibleMoves.push_back(newPos);
                        }
                        break;
                    }
                    possibleMoves.push_back(newPos);
                }
            }
        }

        return possibleMoves;
    }

    std::string Player::inverseColor(std::string color) const
    {

        if (color_ == "white")
        {
            return "black";
        }
        else
        {
            return "white";
        }
    }

    bool Player::isCheck(std::shared_ptr<Board> board) const
    {
        std::pair<int, int> pos = board->findPiece(color_, "King");

        std::string newColor = inverseColor(color_);

        std::pair<int, int> posBishopTemp = board->findPiece(newColor, "Bishop");
        Bishop bishopTemp(newColor);
        //board->addPiece(posBishopTemp, std::make_shared<Bishop>(bishopTemp));
        std::vector<std::pair<int, int>> bishopMoves = bishopTemp.possibleMoves(board);



        std::pair<int, int> posTowerTemp = board->findPiece(newColor, "Tower");
        Tower towerTemp(newColor);
        //board->addPiece(posTowerTemp, std::make_shared<Tower>(towerTemp));
        std::vector<std::pair<int, int>> towerMoves = towerTemp.possibleMoves(board);





        for (auto& move : bishopMoves)
        {
            if (move == pos)
            {
                return true;
            }
        }

        for (auto& move : towerMoves)
        {
            if (move == pos)
            {
                return true;
            }
        }

        return false;
    }

    std::vector<std::pair<int, int>> Player::possibleValidsMoves(std::shared_ptr<Board> board, std::string typePiece) const
    {
        std::vector<std::pair<int, int>> possibleValidsMoves;

        if (!isCheck(board))
        {
            if (typePiece == "Tower")
            {
                std::pair<int, int> towerPos = board->findPiece(color_, "Tower");
                Tower tower(color_);
                
                std::vector<std::pair<int, int>> tempTowerMoves = tower.possibleMoves(board);
                for (auto& move : tempTowerMoves)
                {
                    board->movePiece(towerPos, move);
                    if (!isCheck(board))
                    {
                        possibleValidsMoves.push_back(move);
                    }
                    board->movePiece(move, towerPos);
                }
                
                return possibleValidsMoves;
            }


            if (typePiece == "Bishop")
            {
                std::pair<int, int> bishopPos = board->findPiece(color_, "Bishop");
                Bishop bishop(color_);
                //board->addPiece(bishopPos, std::make_shared<Bishop>(bishop));
                std::vector<std::pair<int, int>> tempBishopMoves = bishop.possibleMoves(board);
                for (auto& move : tempBishopMoves)
                {
                    board->movePiece(bishopPos, move);
                    if (!isCheck(board))
                    {
                        possibleValidsMoves.push_back(move);
                    }
                    board->movePiece(move, bishopPos);
                }

                return possibleValidsMoves;
            }

            if (typePiece == "King")
            {
                std::pair<int, int> posKing = board->findPiece(color_, "King");
                King king(color_);
                //board->addPiece(posKing, std::make_shared<King>(king));

                const std::vector<std::pair<int, int>> kingMoves = king.possibleMoves(board);
                std::string ennemyColor = inverseColor(color_);

                Tower towerE(ennemyColor);
                const std::vector<std::pair<int, int>> ennemyTower = towerE.possibleMoves(board);

                Bishop bishopE(ennemyColor);
                const std::vector<std::pair<int, int>> ennemyBishop = bishopE.possibleMoves(board);

                for (auto& move : kingMoves)
                {
                    if (!contains(ennemyTower, move) && !contains(ennemyBishop, move))
                    {
                        possibleValidsMoves.push_back(move);
                    }

                }
                return possibleValidsMoves;
            }

        }
        else if (isCheck(board))
        {
            if (typePiece == "Tower")
            {
                Tower tower(color_);
                const std::vector<std::pair<int, int>> tempTowerMoves = tower.possibleMoves(board);
                std::pair<int, int> posT = board->findPiece(color_, "Tower");


                for (auto& move : tempTowerMoves)
                {

                    board->movePiece(posT, move);
                    

                    if (!isCheck(board))
                    {

                        std::cout << move.first << "," << move.second << std::endl;
                        possibleValidsMoves.push_back(move);

                    }
                    board->movePiece(move, posT);
                    
                }

            }

            if (typePiece == "Bishop")
            {
                Bishop bishop(color_);
                const std::vector<std::pair<int, int>> tempBishopMoves = bishop.possibleMoves(board);
                std::pair<int, int> posT = board->findPiece(color_, "Bishop");

                for (auto& move : tempBishopMoves)
                {
                    //cout << move.first << "," << move.second << endl;
                    board->movePiece(posT, move);
                    if (!isCheck(board))
                    {
                        possibleValidsMoves.push_back(move);
                    }
                    board->movePiece(move, posT);
                }

            }

            if (typePiece == "King")
            {
                King king(color_);
                const std::vector<std::pair<int, int>> tempKingMoves = king.possibleMoves(board);

                std::pair<int, int> pos = board->findPiece(color_, "King");


                for (auto& move : tempKingMoves)
                {
                    //cout << move.first << "," << move.second << endl;
                    board->movePiece(pos, move);

                    if (!isCheck(board))
                    {
                        possibleValidsMoves.push_back(move);
                    }
                    board->movePiece(move, pos);
                }


            }


        }

        return possibleValidsMoves;
    }



    bool Player::contains(const std::vector<std::pair<int, int>>& vec, const std::pair<int, int>& x) const
    {
        for (const auto& item : vec) {
            if (item == x) {
                return true;
            }
        }
        return false;
    }

}