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

