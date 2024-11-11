#include "piece.h"
// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35

namespace model{
Piece::Piece(std::string couleur, std::string type) : color_(couleur), typePiece_(type) {}




std::pair<std::string, std::string> Piece::getPiece()
{
	return { typePiece_ ,color_ };
}

std::string Piece::getColor()
{
	return color_;
}


std::string Piece::getType()
{
	return typePiece_;
}


}
