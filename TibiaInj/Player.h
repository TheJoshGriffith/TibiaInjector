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
	Player(Core * coar);
	~Player(void);
	// Setters
	void Player::GoTo(int x, int y, int z);
	void setOutfit();

	// Getters
	void Player::getMyBLPos();
	int* Player::getCID();
	int* Player::getExp();
	int blPos;
private:
	Core * core;
};
#endif