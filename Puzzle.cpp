#include"Header.h"

Puzzle::Puzzle(string inputKeyword,string inputHint) {
	keyword = inputKeyword;
	hint = inputHint;
	for (int i = 0; i < keyword.length(); i++) {
		correctGuess.emplace_back(false);
	}
}

bool Puzzle::MakeAGuess(string guessChar) {
	bool isCorrect = false;
	for (int index = 0; index = keyword.find(guessChar, index); index++) {
		isCorrect = true;
		correctGuess[index] = true;
	}
	return isCorrect;
}