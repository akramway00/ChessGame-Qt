#include "plateau.h"
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35

namespace model {
    void Board::addPiece(std::pair<int, int> pos, std::shared_ptr<Piece> piece)
    {
        if (pos.first >= 0 && pos.first < nbRows_ && pos.second >= 0 && pos.second < nbColumns)
        {
            //if (!isOccupied(pos))
            //{
            board_[pos.first][pos.second] = piece;
            //}
        }
        else
        {
            std::cout << "HEY The position is not on the board" << std::endl;
        }
    }

    bool Board::isOccupied(std::pair<int, int> pos) // retourne true si la case est occuper
    {
        if (pos.first >= 0 && pos.first < nbRows_ && pos.second >= 0 && pos.second < nbColumns)
        {
            return board_[pos.first][pos.second] != nullptr;
        }
        return false;
    }

    void Board::movePiece(std::pair<int, int> posStart, std::pair<int, int> posEnd)
    {
        if (posEnd.first >= 0 && posEnd.first < nbRows_ && posEnd.second >= 0 && posEnd.second < nbColumns)
        {
            board_[posEnd.first][posEnd.second] = board_[posStart.first][posStart.second];
            board_[posStart.first][posStart.second] = nullptr;
        }
        else
        {
            std::cout << "The position is not on the board" << std::endl;
        }
    }

    void Board::deletePiece(std::pair<int, int> pos)
    {
        if (pos.first >= 0 && pos.first < nbRows_ && pos.second >= 0 && pos.second < nbColumns)
        {
            board_[pos.first][pos.second] = nullptr;
        }
        else
        {
            std::cout << "The position is not on the board" << std::endl;
        }
    }


    std::shared_ptr<Piece> Board::getPiecePtr(std::pair<int, int> pos)         // retourne le pointeur de la piece a la position pos
    {
        if (pos.first >= 0 && pos.first < nbRows_ && pos.second >= 0 && pos.second < nbColumns)
        {
            return board_[pos.first][pos.second];
        }
        else
        {
            return nullptr;
        }
    }

    bool Board::isEnemyPiece(std::pair<int, int> pos, std::string color) // retourne true si cest une case ennemi ou case vide sinon retourne false
    {
        if (pos.first >= 0 && pos.first < nbRows_ && pos.second >= 0 && pos.second < nbColumns)
        {
            if (board_[pos.first][pos.second] != nullptr)
            {
                return board_[pos.first][pos.second]->getPiece().second != color;
            }
        }
        return false;
    }

    std::pair<int, int> Board::findPiece(std::string color, std::string type)// retourne la position du roi de la couleur color
    {
        for (int i = 0; i < nbRows_; i++)
        {
            for (int j = 0; j < nbColumns; j++)
            {
                if (board_[i][j] != nullptr)
                {
                    if (board_[i][j]->getPiece().first == type && board_[i][j]->getPiece().second == color)
                    {
                        return { i, j };
                    }
                }
            }
        }
        return { -1,-1 };
    }


    std::vector<std::vector<std::shared_ptr<Piece>>> Board::getBoard()
    {
        return board_;
    }


    void Board::clearBoard()
    {
        for (int row = 0; row < nbRows_; ++row) {
            for (int col = 0; col < nbColumns; ++col) {
                board_[row][col] = nullptr;
            }
        }

    }
}



