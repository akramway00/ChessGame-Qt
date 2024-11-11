#include "plateau.h"
//#include "classRAII.h"
#include <iostream>
#include <string>
#include <QIcon>
#include <stdexcept> 

// Akram Lourhmati 2287991 - Chems-Eddine Kardoussi 2300027
// equipe 35



//using namespace std;

namespace model{

class King : public Piece
{
public:
	King() = default;
	King(std::string couleur);
	~King();

	std::vector<std::pair<int, int>> possibleMoves(std::shared_ptr<Board> board) ;

private:
	static int instanceCount;



};


class Tower : public Piece
{
public:
	Tower() = default;
	Tower(std::string couleur);

	std::vector<std::pair<int, int>> possibleMoves(std::shared_ptr<Board> board) ;
	
};

class Bishop : public Piece
{
public:
	Bishop() = default;
	Bishop(std::string couleur);


	std::vector<std::pair<int, int>> possibleMoves(std::shared_ptr<Board> board) ;
	
};

class Player
{
public:

	Player() = default;
	Player(std::string color) : color_(color) {}

	std::string getColor() { return color_; }

	bool isCheck(std::shared_ptr<Board> board) const ;
	std::vector<std::pair<int, int>> possibleValidsMoves(std::shared_ptr<Board> board, std::string  typePiece) const;

	//std::vector<std::pair<int, int>> validsMovesAfterChess(std::shared_ptr<Board> board, std::string  typePiece) const;

	bool contains(const std::vector<std::pair<int, int>>& vec, const std::pair<int, int>& x) const;

	std::string inverseColor(std::string color) const;



private:
	std::string color_;
};
}
