#pragma once
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35

#include <string>
#include <utility>
#include <tuple>
#include "piece.h"
#include <vector>
#include <iostream>
#include <memory>
#include <string>



//using namespace std;

namespace model {

	class Board
	{
	private:
		const int nbRows_ = 8;
		const int nbColumns = 8;

		std::vector<std::vector<std::shared_ptr<Piece>>> board_;

	public:
		Board() : board_(nbRows_, std::vector<std::shared_ptr<Piece>>(nbColumns, nullptr)) {}

		void addPiece(std::pair<int, int> pos, std::shared_ptr<Piece> piece);

		void deletePiece(std::pair<int, int> pos);

		bool isOccupied(std::pair<int, int> pos);

		void movePiece(std::pair<int, int> posStart, std::pair<int, int> posEnd);


		std::shared_ptr<Piece> getPiecePtr(std::pair<int, int> pos);
		//variant<shared_ptr<King> ,shared_ptr<Tower>, shared_ptr<Bishop> > getPiecePtr(std::pair<int, int> pos);

		int getNbRows() const { return nbRows_; }

		int getNbColumns() const { return nbColumns; }

		bool isEnemyPiece(std::pair<int, int> pos, std::string color);

		std::vector<std::vector<std::shared_ptr<Piece>>> getBoard();

		void clearBoard();


		std::pair<int, int> findPiece(std::string color, std::string type);
	};

}