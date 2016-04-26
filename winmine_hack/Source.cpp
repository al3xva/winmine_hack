#include <Windows.h>
#include <iostream>

// Macroses
#define WINDOW_NAME L"Сапер"

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