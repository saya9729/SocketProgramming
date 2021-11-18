#include"Header.h"

GameCordinator::GameCordinator() {

}

void GameCordinator::loadDatabase(string path) {
	database = new Database(path);
}

void GameCordinator::startGame() {
	for (int i = 0; i < playerLimit; i++) {
		playerList.emplace_back("name");//handle diffently
	}
}

void GameCordinator::Update() {
	//not quite done
}

GameCordinator::~GameCordinator() {
	delete database;
}

