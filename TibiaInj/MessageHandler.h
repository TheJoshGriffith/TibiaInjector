#pragma once
#include <Windows.h>
#include <socketapi.h>
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>

class Core;

class MessageHandler
{
public:
	MessageHandler(Core * coar);
	~MessageHandler(void);
	SOCKET sock;
	int port;
	Core * core;
	BOOL logging;
};

