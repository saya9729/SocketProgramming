#include"Header.h"

Player::Player(string inputName) {
	if (checkName(inputName)) {
		name = inputName;
	}
	else {
		retryName();
	}
}
bool Player::checkName(string inputName) {
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