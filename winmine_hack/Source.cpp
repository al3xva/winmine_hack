#include <Windows.h>
#include <iostream>
#include "hack_commands.h"

// Macroses
#define WINDOW_NAME L"Сапер"

// Namespaces
using namespace std;

// Global variables
HANDLE process_handle;

// Functions' prototypes
bool get_process();

// Entry point
int main()
{

}

// Return true if process got
bool get_process()
{
	DWORD process_id;
	HWND window_handle = FindWindow(NULL, WINDOW_NAME);
	GetWindowThreadProcessId(window_handle, &process_id);
	CloseHandle(window_handle);
	process_handle = OpenProcess(PROCESS_ALL_ACCESS, false, process_id);
	if (process_handle == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool do_command(char *command)
{
	if (command == "exit")
	{
		command::exit(0);
		return true;
	}
	if (command == "info")
	{
		command::info();
		return true;
	}
}