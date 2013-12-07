#ifndef BLCreature
#define BLCreature
#include <string>
#include <fstream>

struct Creature
	{
		int cid;
		char name[32];
		int posz;
		int posy;
		int posx;
		int pixelOffsetNS; // Goes +32 or -32 when walking ^ or v, reduces to 0 in time
		int pixelOffsetEW; // Goes +32 or -32 when walking < or >, reduces to 0 in time
		int direction; // Direction creature is facing
		int var8;
		int var9;
		int var10;
		int var11;
		int var12; // 800 on Quentin, 350 on me, 250 on random noob
		int isWalking;
		int lastDirectionWalked; // 0, 1, 2, 3 depending on which direction you last walked. Doesn't work for "turn"
		int var13;
		int var14; // Always 2147483647 (maybe lastSeen?)
		int outfitId;
		int headColour;
		int bodyColour;
		int bodySecondColour;
		int footColour;
		int addons;
		int mountId; // ID of mount. 1 crashes, as does 72.
		int nameColour; // Colour of nameplate changes with this var
		int var15;
		int var16;
		int var17;
		int hpPc; // Health percentage
		int var18;
		int var19;
		int skullType; // 1 to 6, 7 debugs.
		int shieldType; // Shield type for guild membership
		int warType; // Cup type for warmode
		int var20;
		int var21;
		int var22;
		int var23;
		int greenSquare;
		int guildMembersOnline; // 5+ gives the red lightning bolt
		int var24;
	};

class Core;

class BattleList
{
public:
	// Constr
	BattleList::BattleList(Core * coar);

	// Destr
	BattleList::~BattleList(void);

	// Methods
	void DumpBattleList(char* fileName);

	// Variables
	Creature *(battleList[1300]);

private:
	Core * core;
};
#endif