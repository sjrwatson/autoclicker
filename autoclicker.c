#include <stdio.h>
#include <windows.h>
#include <timeapi.h>

#define CLICK_DELAY_MS 1

int main(void) {
    printf("=== Autoclicker ===\n");
    printf("Press the key you want to use as the autoclick toggle...\n");

    // Wait for user to press a key and capture its virtual key code
    int toggleKey = 0;
    while (toggleKey == 0) {
        for (int vk = 1; vk < 256; vk++) {
            if (GetAsyncKeyState(vk) & 0x8000) {
                // Ignore common modifier keys so they don't accidentally get picked
                if (vk == VK_LSHIFT || vk == VK_RSHIFT ||
                    vk == VK_LCONTROL || vk == VK_RCONTROL ||
                    vk == VK_LMENU || vk == VK_RMENU ||
                    vk == VK_SHIFT || vk == VK_CONTROL || vk == VK_MENU) {
                    continue;
                }
                toggleKey = vk;
                break;
            }
        }
        Sleep(10);
    }

    // Wait for the key to be released before starting
    while (GetAsyncKeyState(toggleKey) & 0x8000) {
        Sleep(10);
    }

    // Get a display name for the key
    char keyName[64] = {0};
    UINT scanCode = MapVirtualKey(toggleKey, MAPVK_VK_TO_VSC);
    // Extended key flag for certain keys
    LONG lParam = (scanCode << 16);
    if (toggleKey == VK_RIGHT || toggleKey == VK_LEFT ||
        toggleKey == VK_UP || toggleKey == VK_DOWN ||
        toggleKey == VK_INSERT || toggleKey == VK_DELETE ||
        toggleKey == VK_HOME || toggleKey == VK_END ||
        toggleKey == VK_PRIOR || toggleKey == VK_NEXT) {
        lParam |= (1 << 24);  // extended key bit
    }
    GetKeyNameTextA(lParam, keyName, sizeof(keyName));

    printf("Toggle key set to: %s (VK code: 0x%02X)\n", keyName, toggleKey);
    printf("Hold that key to autoclick. Press Ctrl+C to exit.\n\n");

    // Set timer resolution to 1ms for accurate Sleep()
    timeBeginPeriod(1);

    BOOL wasClicking = FALSE;
    unsigned long clickCount = 0;

    // Pre-build the input events once
    INPUT inputs[2] = {0};
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    while (1) {
        if (GetAsyncKeyState(toggleKey) & 0x8000) {
            if (!wasClicking) {
                printf("Autoclicking started...\n");
                wasClicking = TRUE;
                clickCount = 0;
            }

            SendInput(2, inputs, sizeof(INPUT));
            clickCount++;

            Sleep(CLICK_DELAY_MS);
        } else {
            if (wasClicking) {
                printf("Stopped. Total clicks: %lu\n", clickCount);
                wasClicking = FALSE;
            }
            Sleep(50);
        }
    }

    timeEndPeriod(1);
    return 0;
}
