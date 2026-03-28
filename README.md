# autoclicker
An open-source autoclicker free for anyone to use

Support the project: [Buy Me a Coffee](https://buymeacoffee.com/sjrwatson)

## Platform limitation
This project is **Windows-only**. It uses Win32 APIs (`windows.h`, `SendInput`, `GetAsyncKeyState`) and will not compile or run on Linux/macOS.

## Compilation (Windows)

### Option 1: MSVC (Developer Command Prompt)
```bat
cl /O2 /W4 /EHsc autoclicker.c /link winmm.lib
```

### Option 2: MinGW-w64 GCC
```bat
gcc -O2 -Wall -Wextra -o autoclicker.exe autoclicker.c -lwinmm
```

## Execution (Windows)
Run from Command Prompt or PowerShell:

```bat
autoclicker.exe
```

Program flow:
1. Press a key to set your toggle/hold key.
2. Hold that key to autoclick.
3. Release the key to stop clicking.
4. Press `Ctrl+C` to exit.
