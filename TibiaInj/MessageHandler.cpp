#include "stdafx.h"
#include "MessageHandler.h"
#include <Windows.h>
#include <socketapi.h>
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>


MessageHandler::MessageHandler(Core * coar)
{
	// Information for reading sockets
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1"); // BindTo IP
	service.sin_port = htons(port); // BindTo Port
	logging = true;
	core = coar;
	sock = INVALID_SOCKET;
	int iResult;
	WSADATA wsaData = {0};
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		MessageBox(NULL, (LPCWSTR)"Error initialising WinSock",
			(LPCWSTR)"Your client may not be able to connect", NULL);
	}

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == INVALID_SOCKET)
	{
		MessageBox(NULL, (LPCWSTR)"Error in socket definition",
			(LPCWSTR)"Your client may not be able to connect", NULL);
	}

	if (bind(sock, (SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR)
	{
		MessageBox(NULL, (LPCWSTR)"Error binding socket",
			(LPCWSTR)WSAGetLastError(), NULL);
		closesocket(sock);
		WSACleanup();
	}
}

MessageHandler::~MessageHandler(void)
{
	int iResult;
	iResult = closesocket(sock);
	if (iResult == SOCKET_ERROR)
	{
		MessageBox(NULL, (LPCWSTR)"Socket closed in error",
			(LPCWSTR)WSAGetLastError(), NULL);
	}
	WSACleanup();
}
