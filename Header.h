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
	int CountOccurenceOfChar(string);
};

class Player {
private:
	string name;
	int point;
	bool qualify;
public:
	Player(string);
	string RegisterName();
	string MakeGuess();
	void SendAnnouncement(string);
	string GetName();
	void Disqualify();
	void AddPoint(int);
	bool IsQualify();
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
	int currentPlayerIndex;
	Player* currentPlayer;
	int disqualifyCount;
	int isWaiting;
	string guessCharacter;
	string guessKeyword;
	int currentTurn;
	Puzzle* currentPuzzle;
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
	void SendPuzzle();
	bool CheckAnswerBuffer();
	void NextPlayer();
	void AddPointCorrectCharacter();
	void AddPointCorrectKeyword();
	void StartGame();
	void DisqualifyPlayer();
	bool IsAllDisqualified();
	bool CheckGuessCharacter();
	bool CheckGuessKeyword();
	void SendCharacterIsCorrect();
	void ResetGuess();
};

