#pragma once
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// Équipe 35
// TP4
#include "plateau.h"
#include <utility>


namespace model {
class TemporaryPieceMove
{

private:

    Board* board_;
    std::pair<int, int> originalPos_;
    std::pair<int, int> newPos_;



public:
    TemporaryPieceMove(Board* board, const std::pair<int, int>& originalPos, const std::pair<int, int>& newPos)
        : board_(board), originalPos_(originalPos), newPos_(newPos) {

        // Deplacement temporaire de la piece a la position initial vers la nouvelle position
        board_->movePiece(originalPos, newPos);
    }

    ~TemporaryPieceMove() {
        // Remet la piece a sa position initiale
        board_->movePiece(newPos_, originalPos_);
    }

    TemporaryPieceMove(const TemporaryPieceMove&) = delete;
    TemporaryPieceMove& operator=(const TemporaryPieceMove&) = delete;


};

}