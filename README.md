# autoclicker
An open-source autoclicker free for anyone to use on Windows.

Support the project: [Buy Me a Coffee](https://buymeacoffee.com/sjrwatson)

## What this app does
This app repeatedly sends **left mouse clicks** while you hold a key on your keyboard.

- Hold your chosen key -> autoclicking runs
- Release the key -> autoclicking stops

---

## Before you start (important)
This project is **Windows-only**.

It uses Windows APIs (`windows.h`, `SendInput`, `GetAsyncKeyState`) and will not compile or run on Linux/macOS.

---

## Quick start (for beginners)

### 1) Open a terminal in this folder
You can use either:
- **Command Prompt**
- **PowerShell**
- **Developer Command Prompt for Visual Studio** (if using MSVC)

### 2) Compile the program
Choose **one** of the options below.

#### Option A: MSVC (Visual Studio tools)
```bat
cl /O2 /W4 /EHsc autoclicker.c /link winmm.lib
```

#### Option B: MinGW-w64 GCC
```bat
gcc -O2 -Wall -Wextra -o autoclicker.exe autoclicker.c -lwinmm
```

If compilation succeeds, you should see `autoclicker.exe` in this folder.

### 3) Run it
```bat
autoclicker.exe
```

---

## How to use the application
When the app starts, it prints:

`Press the key you want to use as the autoclick toggle...`

Follow these steps:

1. Press the key you want to use (example: `F6`, `Q`, `]`).
2. The app confirms your key selection.
3. Hold that key to start autoclicking.
4. Release the key to stop autoclicking.
5. Press `Ctrl + C` in the terminal to close the app.

### Important behavior notes
- You must **hold** the selected key.  
  This is not an on/off toggle switch.
- Modifier-only keys are ignored when selecting a key  
  (Shift, Ctrl, Alt by themselves).
- Clicking speed is very fast (about 1 ms delay between clicks).

---

## Example session
```text
=== Autoclicker ===
Press the key you want to use as the autoclick toggle...
Toggle key set to: F6 (VK code: 0x75)
Hold that key to autoclick. Press Ctrl+C to exit.

Autoclicking started...
Stopped. Total clicks: 1248
```

---

## Safety and practical tips
- Test in a safe place first (for example, a blank text editor or simple app).
- Start with a key that is easy to press and release quickly.
- Keep the terminal visible so you can stop with `Ctrl + C` at any time.

---

## Troubleshooting
### Nothing happens when I run compile commands
- Make sure you are on **Windows**.
- Make sure your compiler is installed and available in your terminal.

### App runs but does not click
- Make sure you are **holding** the selected key.
- Try a different key (for example `F6` or `F8`).
- Some apps/games may block synthetic input.
