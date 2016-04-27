#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

// Namespaces
using namespace std;

// Macroses
#define WINDOW_NAME L"Сапер"

// Global variables
HANDLE process_handle;

// Namespace command funcions' prototypes
void main_menu();
void hack_exit(int code);
void info();
// Funcions' prototypes
bool get_process();

// Enums

namespace command
{
	void main_menu()
	{
		system("cls");
		cout << "WINMINE HACK" << endl;
		cout << "Status: ";
		if (process_handle != NULL)
		{
			cout << "Injected" << endl;
		}
		else
		{
			cout << "Not injected" << endl;
		}
		cout << "1. Info" << endl;
		cout << "2. Inject" << endl;
		cout << "0. Exit" << endl;
		cout << "Type number: ";
	}

	void hack_exit(int code)
	{
		system("cls");
		cout << "Hack will terminate after 3 seconds..." << endl;
		Sleep(3000);
		exit(code);
	}

	void info()
	{
		system("cls");
		cout << "Hack created by Al3xva." << endl;
		cout << "Spring 2016" << endl;
		_getch();
	}

	void inject()
	{
		system("cls");
		if (process_handle == NULL)
		{
			cout << "Start winmine.exe!" << endl;
			cout << "Finding window..." << endl;
			while (!get_process())
			{
				Sleep(500);
			}
			cout << "Inject successful!" << endl;
			Sleep(2000);
		}
		else
		{
			cout << "Already injected..." << endl;
			cout << "Going to main menu..." << endl;
			Sleep(2000);
		}
	}
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
