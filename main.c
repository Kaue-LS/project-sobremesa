#include "main_header.h"
#include "controls.c"
#include "menu.c"
#include "procedure.c"
#include "total.c"


// CREATE WINDOW WITH WINAPI
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;


    if (!RegisterClassW(&wc)) return -1;

    // Obtém informações sobre o monitor principal
    HMONITOR hMonitor = MonitorFromWindow(NULL, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO mi = { sizeof(mi) };
    GetMonitorInfo(hMonitor, &mi);

    // Cria a janela em tela cheia
    HWND hWnd = CreateWindowW(L"myWindowClass", L"Cardapio de Sobremesas", WS_POPUP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, NULL, NULL, hInst, NULL);

    if (!hWnd) return -1;

    ShowWindow(hWnd, ncmdshow);
    UpdateWindow(hWnd);

    MSG msg = {0};


    // Criar caixa de listagem com fundo branco
     RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    hEditProductDetails = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE | ES_READONLY,
    clientRect.right - 200, 0, 200, clientRect.bottom-200, hWnd, (HMENU)EDIT_PRODUCT_DETAILS,
    (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    hEditProductTotal = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE | ES_READONLY,
        clientRect.right - 200, clientRect.bottom - 200, 200, 100, hWnd, (HMENU)EDIT_PRODUCT_DETAILS,
        (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);


    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}












