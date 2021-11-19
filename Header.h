#include<string>
#include<vector>
#include<time.h>
#include<fstream>
#include<iostream>

#include <chrono>

using namespace std;

using namespace chrono_literals;

class Puzzle {
private:
	string keyword;
	string unknownKeyword;
	string hint;
	vector<bool> correctGuess;	
public:
	Puzzle(string,string);
	bool GuessACharacter(string);
	bool GuessKeyword(string);
	void UpdateUnknownKeyword();
};

class Player {
private:
	string name;
	int point;
public:
	Player(string);
	string RegisterName();
	string MakeGuess();
	void SendAnnouncement(string);
	string GetName();
};

class Database {
private:
	vector<Puzzle> puzzleList;
	void LoadPuzzleFromFile(string);
public:
	Database(string);
	Puzzle GetRandomPuzzle();
};

class GameCordinator {
private:
	int playerLimit;
	vector<Player> playerList;
	Database* database;
	string state;
public:
	GameCordinator();
	~GameCordinator();
	void LoadDatabase(string);
	bool IsLegalName(string);
	bool IsUniqueName(string);
	void AddNewPlayer(string);
	void ProcessInput();
	void Update();
	void CheckPlayerRegister();
	void UpdateGameEvent();
};

