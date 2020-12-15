#pragma once

#include "helper.h"

class divert
{
	private:

		void* function_address = 0;									// original function address
		void* hook_address = 0;										// hook/detour function address
		bool is_hooked = false;										// is the function already hooked
		byte* original_shellcode = 0;								// original function bytes
		size_t original_size = 0;									// size of overwritten original function

	public:

		divert();													// simple class constructor

		bool hook(void* function_address, void* hook_address);		// diverts the original function to our hook

		bool unhook();												// removes the detour
};
