#include <iostream>
using namespace std;

//Variables
#define WIN 1
#define LOSE -1
#define DRAW 0

//the class that defines the grid
class tictac
{
	char grid[3][3];	//x is cross, o is circle, null is empty
public:
	tictac();	//constructor, makes all empty
	char isLeaf();	//checks if state is a leaf, and returns the winner
	tictac *nuevo(int i,int j,char val);	//returns a new grid with added value at i,j
	void set(int i,int j,char val);		//set value at position
	char at(int i,int j);			//get value at position
};

class game
{
	char first;	//first player
public:
	game(char val);
	char next();
};

game::game(char val)
{
	first = val;
}

char game::next()
{
	first = (first=='o')?'x':'o';	//if 'x', return 'o', else otherwise
	return first;
}

tictac::tictac()
{
	for(int i = 0;i<9;i++)grid[i/3][i%3] = 0;
}

void tictac::set(int i,int j,char val)
{
	grid[i][j] = val;	//no additional protection, assume this function is called only after checking the position
}

char tictac::at(int i,int j)
{
	return grid[i][j];
}

char tictac::isLeaf()
{
	//must check across all positions, and return value of winner accordingly
	if(grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2])
		return grid[0][0];
	if(grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2])
		return grid[1][0];
	if(grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2])
		return grid[2][0];
	if(grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0])
		return grid[0][0];
	if(grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1])
		return grid[0][1];
	if(grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])
		return grid[0][2];
	if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
		return grid[0][0];
	if(grid[2][0]==grid[1][1] && grid[1][1]==grid[0][2])
		return grid[2][0];		
}

tictac *tictac::nuevo(int i,int j,char val)
{
	tictac* neuer = new tictac();
	if(!grid[i][j])
	{
		neuer->set(i,j,val);
		return neuer;
	}
	else return 0;
}

int main()
{
	game foo('x');	//start a game with x;
	tictac fop;
	//run minimax on fop to return what?, I probably need some more data structures
	//I need to build tree and find a way to know current state, traverse based on opponent's move et cetera
	//Also, now I wonder about the memory contraints
	//Would it be a good move to make the program use multi-processing since this stage?
	return 0;
}
