#include"Header.h"

Puzzle::Puzzle(string inputKeyword,string inputHint) {
	keyword = inputKeyword;
	unknownKeyword = "";
	hint = inputHint;
	for (int i = 0; i < keyword.length(); i++) {
		correctGuess.emplace_back(false);
		unknownKeyword += "*";
	}
}

bool Puzzle::GuessACharacter(string guessChar) {
	bool isCorrect = false;
	for (int index = 0; index = keyword.find(guessChar, index); index++) {
		isCorrect = true;
		correctGuess[index] = true;
	}
	return isCorrect;
}

bool Puzzle::GuessKeyword(string guessKeyword) {
	if (keyword.compare(guessKeyword) == 0) {
		return true;
	}
	return false;
}

void Puzzle::UpdateUnknownKeyword() {
	unknownKeyword = "";
	for (int i = 0; i < keyword.length(); i++) {
		if (correctGuess[i]) {
			unknownKeyword += keyword[i];
		}
		else {
			unknownKeyword += "*";
		}
	}
}