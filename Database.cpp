#include"Header.h"

Database::Database(string path) {
	srand(time(NULL));
	LoadPuzzleFromFile(path);
}

void Database::LoadPuzzleFromFile(string path) {
	fstream databaseFile;
	databaseFile.open(path);
	if (databaseFile.is_open()) {
		int puzzleLen;
		string inputLen;
		string inputKeyword;
		string inputHint;
		getline(databaseFile, inputLen);
		puzzleLen = stoi(inputLen);
		for (int i = 0; i < puzzleLen; i++) {
			getline(databaseFile, inputKeyword);
			getline(databaseFile, inputHint);
			//Puzzle* tempPuzzle = new Puzzle(inputKeyword, inputHint);
			//puzzleList.push_back(*tempPuzzle);
			puzzleList.emplace_back(inputKeyword, inputHint);
		}
		databaseFile.close();
	}
	else {
		cout << "Database file not found at " << path << "\n";
	}
}

Puzzle Database::GetRandomPuzzle() {
	int index = rand() & puzzleList.size();
	Puzzle randomPuzzle = puzzleList[index];
	return randomPuzzle;
}