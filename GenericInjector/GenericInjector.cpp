// GenericInjector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <strsafe.h>
#include <iostream>

using namespace std;

BOOL InjectRemoteThread(DWORD);

#define DLL_NAME "C:\\Users\\Debug\\Desktop\\TibiaInj.dll"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		DWORD processID;
		HWND hwnd = FindWindow(L"TibiaClient", NULL);
		GetWindowThreadProcessId(hwnd, &processID);
		cout << "HWND: " << hwnd << endl;
		cout << "PID : " << processID << endl;
		cout << "INJECTING!" << endl;
		InjectRemoteThread(processID);
		cin.get();
	}
	catch (exception ex)
	{
		cout << "Error injecting into target process." << endl;
		cin.get();
		return 1;
	}
	return 0;
}



BOOL InjectRemoteThread(DWORD ProcessID)
{
    HANDLE RemoteProc;
    char buf[50]        =   {0};
    LPVOID MemAlloc;
    LPVOID LoadLibAddress;

    // Process ID does show correctly!
    WCHAR id[100];
    StringCbPrintf(id, 100, L"%d", ProcessID); // id contains the process ID... is confirmed in comparing ID shown in tasklist and the messagebox.
    MessageBox(NULL, id, L"Process ID", MB_ICONINFORMATION);
    // Process ID does show correctly!

    if ( !ProcessID )
    {
        MessageBox(NULL, (LPCWSTR)GetLastError(), L"An error occured", NULL);
        return 0;
    }
    RemoteProc = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, ProcessID);
    if ( !RemoteProc )
    {
        MessageBox(NULL, (LPCWSTR)GetLastError(), L"An error occured opening the target process.", NULL);
        return 0;
    }
    LoadLibAddress      =   (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    MemAlloc            =   (LPVOID)VirtualAllocEx(RemoteProc, NULL, strlen(DLL_NAME)+1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    WriteProcessMemory(RemoteProc, (LPVOID)MemAlloc, DLL_NAME, strlen(DLL_NAME)+1, NULL);
    CreateRemoteThread(RemoteProc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddress, (LPVOID)MemAlloc, NULL, NULL);

    CloseHandle(RemoteProc);
    VirtualFreeEx(RemoteProc, (LPVOID)MemAlloc, 0, MEM_RELEASE | MEM_DECOMMIT);
    return 1;
}