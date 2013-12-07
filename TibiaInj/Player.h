#ifndef PLAYERSTRUCTURE
#define PLAYERSTRUCTURE
// DO NOT INCLUDE CORE IN THIS FILE

class Core;

struct PlayerMem
{
	int cid;
	int y, x, z;
};

class Player
{
public:
	Player::Player(Core * coar);
	Player::Player(void);
	Player::~Player(void);
	void Player::GoTo(int x, int y, int z);
	int Player::getMyBLPos();
	int* Player::getCID();
private:
	Core * core;
};
#endif