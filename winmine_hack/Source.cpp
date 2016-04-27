#include <Windows.h>
#include <iostream>
#include "hack_header.h"

// Namespaces
using namespace std;

// Functions' prototypes
bool get_process();
bool do_command(int command);

// Entry point
int main()
{
	while (true)
	{
		system("color 0A");
		command::main_menu();
		int command;
		cin >> command;
		cout << endl;
		do_command(command);
	}
	return 0;
}

bool do_command(int command)
{
	if (command == 0)
	{
		command::hack_exit(0);
		return true;
	}
	if (command == 1)
	{
		command::info();
		return true;
	}
	if (command == 2)
	{
		command::inject();
		return true;
	}
}