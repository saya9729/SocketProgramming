#include<string>
#include<vector>
#include<time.h>
#include<fstream>
#include<iostream>

using namespace std;

class Puzzle {
private:
	string keyword;
	string hint;
	vector<bool> correctGuess;
public:
	Puzzle(string,string);
	bool MakeAGuess(string);
};

class Player {
private:
	string name;
	int point;
public:
	Player(string);
	string registerName();
	bool checkName(string);
	void retryName();
	string MakeGuess();

};

class Database {
private:
	vector<Puzzle> puzzleList;
	//bool* usedPuzzle;
	void LoadPuzzleFromFile(string);
public:
	Database(string);
	Puzzle getRandomPuzzle();
};

class GameCordinator {
private:
	int playerLimit;
	vector<Player> playerList;
	Database* database;
public:
	GameCordinator();
	~GameCordinator();
	void loadDatabase(string);
	void startGame();
	void Update();
};

