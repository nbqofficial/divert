#include "divert.h"

int cnt = 0;															// simple counter for testing purposes
void* address = 0;														// address of the function we are going to hook
divert div_hook;														// our hook var

BOOL hook_Beep()														// hook function
{
	printf("Hooked: %d\n", cnt);										// prints our the counter
	cnt++;																// increment the counter every time the divert is performed
	if (cnt == 5)														// once the counter reaches 5 we unhook
	{
		div_hook.unhook();												// unhook
	}
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hmodule, DWORD reason, LPVOID lp_reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		address = helper::get_module_export("kernel32.dll", "Beep");	// get function address
		if (address)													// if found perform hook
		{
			printf("%p\n", address);
			system("pause");
			div_hook.hook(address, &hook_Beep);							// hook
		}
	}
	return TRUE;
}