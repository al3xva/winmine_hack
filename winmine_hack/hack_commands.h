#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

namespace command
{
	void exit(int code)
	{
		system("cls");
		cout << "Will exit hack after 3 seconds..." << endl;
		Sleep(3000);
		exit(code);
	}
	void info()
	{
		system("cls");
		cout << "Hack created by Al3xva." << endl;
		cout << "Spring 2016" << endl;
		getchar();
	}
}
