#ifndef PLAYERSTRUCTURE
#define PLAYERSTRUCTURE
struct PlayerMem
{
	int cid;
	int y, x, z;
};
#endif

class Player
{
public:
	Player(void);
	~Player(void);
};