# divert - Detour library (x64 and x86 compatible)

## About
Lightweight, simple to use detour library compatible with x64 and x86 architecture.
Uses a different shellcode than your standard jmp instruction.

### x64 shellcode
**movabs rax, [address]**  
**push rax**  
**ret**  

### x86 shellcode
**mov eax, [address]**  
**push eax**  
**ret**  

![divert](https://imgur.com/js0W7FN.png)
