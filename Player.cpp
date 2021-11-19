#include"Header.h"

Player::Player(string inputName) {
	name = inputName;
	point = 0;
}

string Player::GetName() {
	return name;
}