#pragma once
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35

#include <string>
#include <utility>
#include <tuple>
#include <QIcon>

//using namespace std;

namespace model {
class Piece
{
protected:
	//int x_ = 0;
	//int y_ = 0;
	std::string color_;
	std::string typePiece_;
	QIcon icon_;

public :

	Piece() = default;
	//virtual ~Piece() {}

	//std::vector<std::pair<int, int>> possibleMoves(std::shared_ptr<Board> board);

	//virtual std::vector<std::pair<int, int>> possibleMoves(std::shared_ptr<Board> board);

	Piece(std::string couleur, std::string type);

	/*pair<int, int> getPosition();*/

	std::pair<std::string, std::string> getPiece();
	
	std::string getColor();

	std::string getType();

	QIcon getIcon() const
	{
		return icon_;
	}


};

}





