#include "main_header.h"
HMENU hMenus;
HWND hEdit;


//CREATE MENU BUTTONS ON THE WINDOWS
void AddMenu(HWND hWnd)
{
    hMenus = CreateMenu();
    HMENU hFileMenu = CreateMenu();

    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, "New");
    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, "Open");
    AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL); // Separator
    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

    AppendMenu(hMenus, MF_POPUP, (UINT_PTR)hFileMenu, "File");
    SetMenu(hWnd, hMenus);
}
