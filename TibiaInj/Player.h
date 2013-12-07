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
private:
	Core * core;
};
#endif