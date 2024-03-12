// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int scrWidth;
int scrHeight;
int interval;

LRESULT CALLBACK Melt(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            HDC desktop = GetDC(HWND_DESKTOP);
            HDC window = GetDC(hWnd);
            BitBlt(window, 0, 0, scrWidth, scrHeight, desktop, 0, 0, SRCCOPY);
            ReleaseDC(hWnd, window);
            ReleaseDC(HWND_DESKTOP, desktop);
            SetTimer(hWnd, 0, interval, 0);
            ShowWindow(hWnd, SW_SHOW);
            break;
        }


        case WM_PAINT: {
            ValidateRect(hWnd, 0);
            break;
        }
        case WM_TIMER: {
            HDC wndw = GetDC(hWnd);
            int x = (rand() % scrWidth) - (200 / 2);
            int y = (rand() % 15);

            int width = (rand() % 200);

            BitBlt(wndw, x, y, width, scrHeight, wndw, x, 0, SRCCOPY);
            break;
        }
        case WM_DESTROY: {
            KillTimer(hWnd, 0);
            PostQuitMessage(0);

            break;
        }
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
int APIENTRY main(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int showCmd)
{
    std::cout << "Hello World!\n";
    scrWidth = GetSystemMetrics(SM_CXSCREEN);
    scrHeight = GetSystemMetrics(SM_CYSCREEN);

    WNDCLASS wndClass = { 0, Melt, 0, 0, inst, 0, LoadCursorW(0, IDC_ARROW), 0, 0, L"ScreenMelting" };

    if (RegisterClass(&wndClass)) {
        HWND hWnd = CreateWindowExA(WS_EX_TOPMOST, "ScreenMelting", 0, WS_POPUP, 0, 0, scrWidth, scrHeight, HWND_DESKTOP, 0, inst, 0);

        if (hWnd) {
            srand(GetTickCount());
            MSG msg = { 0 };
             
            while (msg.message != WM_QUIT) {
                if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        }
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
