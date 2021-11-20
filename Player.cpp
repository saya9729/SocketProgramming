#include"Header.h"

Player::Player(string inputName) {
	name = inputName;
	point = 0;
	qualify = true;
}

string Player::GetName() {
	return name;
}

void Player::Disqualify() {
	qualify = false;
}
void Player::AddPoint(int increasePoint) {
	point += increasePoint;
}
bool Player::IsQualify() {
	return qualify;
}