#include"Header.h"

GameCordinator::GameCordinator() {
	state = "waitingPlayer";
}

void GameCordinator::LoadDatabase(string path) {
	database = new Database(path);
}

void GameCordinator::Update() {
	if (state == "waitingPlayer") {
		CheckPlayerRegister();
	}
	else if (state == "runningGame") {
		UpdateGameEvent();
	}
	else if (state == "gameEnd") {

	}
}

GameCordinator::~GameCordinator() {
	delete database;
}

bool GameCordinator::IsLegalName(string inputName) {
	if (inputName.length() > 10 || inputName.length() == 0) {
		return false;
	}

	bool isCorrect = true;
	for (int i = 0; i < inputName.length(); i++) {
		if (!((inputName[i] >= 'a' && inputName[i] <= 'z') ||
			(inputName[i] >= 'A' && inputName[i] <= 'Z') ||
			(inputName[i] >= '0' && inputName[i] <= '9') ||
			inputName[i] == '_')) {
			isCorrect = false;
		}
	}
	return isCorrect;
}

void GameCordinator::AddNewPlayer(string inputName) {
	playerList.emplace_back(inputName);
}

bool GameCordinator::IsUniqueName(string inputName) {
	bool isUnique = true;
	for (int i = 0; i < playerList.size(); i++) {
		if (inputName.compare(playerList[i].GetName()) == 0) {
			isUnique = false;
		}
	}
	return isUnique;
}

void GameCordinator::UpdateGameEvent() {
	if (!isWaiting) {
		SendPuzzle();
		SendIsYourTurn();
		isWaiting = true;
	}
	else {
		if (CheckAnswerBuffer()) {
			isWaiting = false;
			if (currentTurn > 2) {
				if (guessKeyword.length() != 0) {
					if (CheckGuessKeyword()) {
						AddPointCorrectKeyword();
						SendKeywordIsCorrect();
						EndGame();
						isWaiting = false;
						return;
					}
					else {
						DisqualifyPlayer();
						NextPlayer();
						SendIsYourTurn();
						isWaiting = true;
						return;
					}
				}
			}
			if (CheckGuessCharacter()) {
				AddPointCorrectCharacter();
				SendCharacterIsCorrect();
				UpdatePuzzle();
				SendPuzzle();
				SendIsYourTurn();
				isWaiting = true;
			}
			else {
				if (!IsAllDisqualified()) {
					NextPlayer();
					SendIsYourTurn();
					isWaiting = true;
				}
				else {
					EndGame();
					isWaiting = false;
				}
			}
		}
	}
}

void GameCordinator::StartGame() {
	currentPlayer = &playerList[currentPlayerIndex];
	state = "runningGame";
	currentPlayerIndex = 0;
	isWaiting = false;
	currentTurn = 1;
	currentPuzzle = &((*database).GetRandomPuzzle());
}

void GameCordinator::DisqualifyPlayer() {
	(*currentPlayer).Disqualify();
	disqualifyCount++;
}

void GameCordinator::AddPointCorrectCharacter() {
	(*currentPlayer).AddPoint(1);
}

void GameCordinator::AddPointCorrectKeyword() {
	(*currentPlayer).AddPoint(5);
}

bool GameCordinator::IsAllDisqualified() {
	if (disqualifyCount == playerList.size()) {
		return true;
	}
	return false;
}

void GameCordinator::NextPlayer() {
	int index;
	for (int i = 1; i < playerList.size()+1; i++) {
		index = (currentPlayerIndex + i) % playerList.size();
		if (playerList[index].IsQualify()) {
			if (index <= currentPlayerIndex) {
				currentTurn++;
			}
			currentPlayerIndex = index;
			currentPlayer = &playerList[currentPlayerIndex];
			return;
		}
	}
}

bool GameCordinator::CheckGuessCharacter() {
	return (*currentPuzzle).GuessACharacter(guessCharacter);
}
bool GameCordinator::CheckGuessKeyword() {
	return (*currentPuzzle).GuessKeyword(guessKeyword);
}
bool GameCordinator::CheckAnswerBuffer() {
	ResetGuess();
	//more
}
void GameCordinator::ResetGuess() {
	guessCharacter = "";
	guessKeyword = "";
}
