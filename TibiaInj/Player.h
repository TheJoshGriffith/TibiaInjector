/*#ifndef PLAYERSTRUCTURE
#define PLAYERSTRUCTURE
struct PlayerMem
{
	int cid;
	int y, x, z;
};
#endif*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player(Core *core);
	~Player(void);
	DWORD GetZ();
private:
	Core *core;
};

#endif