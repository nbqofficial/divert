#pragma once

#include <Windows.h>
#include <iostream>

namespace helper
{
	void* get_module(const char* module_name);										// get module base address

	void* get_module_export(const char* module_name, const char* function_name);	// get module export address

	bool wpm_safe(void* address, void* buffer, size_t size);						// write to protected memory region

	bool memset_safe(void* address, int buffer, size_t size);						// set memory in protected region
}