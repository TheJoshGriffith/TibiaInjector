struct Item
{
public:
	int data;//0x0
	int id;//0x4
	int dataEx;//0x8
	int padding[0x6];//0xC
	//structsize = 0x24

	//The padding isn't actually just unknown stuff it contains some RGB shit and IsVisible, TODO
};