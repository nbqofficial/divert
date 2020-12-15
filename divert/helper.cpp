#include "helper.h"

void* helper::get_module(const char* module_name)
{
    return GetModuleHandleA(module_name);                                          // returns base address of the module
}

void* helper::get_module_export(const char* module_name, const char* function_name)
{
    void* module = get_module(module_name);                                        // get module base address

    if (!module) { return 0; }                                                     // if it doesnt exists return 0

    return GetProcAddress(reinterpret_cast<HMODULE>(module), function_name);       // otherwise return function address
}

bool helper::wpm_safe(void* address, void* buffer, size_t size)
{
    if (!address || !buffer || !size) { return false; }                            // check if address, buffer and size are correct

    DWORD op;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &op);                    // set page protection to RWX

    memcpy(address, buffer, size);                                                 // write the buffer to address

    VirtualProtect(address, size, op, &op);                                        // reset the old protection rights

    return true;
}

bool helper::memset_safe(void* address, int buffer, size_t size)
{
    if (!address || !buffer || !size) { return false; }                            // check if address, buffer and size are correct

    DWORD op;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &op);                    // set page protection to RWX

    memset(address, buffer, size);                                                 // write the buffer to address

    VirtualProtect(address, size, op, &op);                                        // reset the old protection rights

    return true;
}