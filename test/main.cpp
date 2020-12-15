#include <Windows.h>
#include <iostream>

// simple test program that just calls Beep() every second
// we will inject our divert.dll in here to detour the Beep() function

int main()
{
	while (1)
	{
		Beep(400, 400);
		Sleep(1000);
	}
	return 0;
}