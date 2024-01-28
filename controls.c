#include "main_header.h"



// SHOW THE BUTTONS ON THE SCREEN
void AddControls(HWND hWnd)
{


   // Adiciona um botão Casquinha
    hButtonCasquinha = CreateWindowW(L"BUTTON", L"Casquinha", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100, 30, hWnd, (HMENU)BUTTON_CASQUINHA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
    // Adiciona um botão Sundae
    hButtonSundae = CreateWindowW(L"BUTTON", L"Sundae", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 50, 100, 30, hWnd, (HMENU)BUTTON_SUNDAE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    hButtonTopSundae = CreateWindowW(L"BUTTON",L"TopSundae", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 90, 100, 30, hWnd, (HMENU)BUTTON_TOPSUNDAE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    hButtonColosso = CreateWindowW(L"BUTTON",L"Colosso", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 130, 100, 30, hWnd, (HMENU)BUTTON_COLOSSO, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    hButtonFlurry = CreateWindowW(L"BUTTON",L"Flurry", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 170, 100, 30, hWnd, (HMENU)BUTTON_FLURRY, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    hButtonShake = CreateWindowW(L"BUTTON",L"Shake", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 210, 100, 30, hWnd, (HMENU)BUTTON_SHAKE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

    if (!hButtonCasquinha && !hButtonSundae && !hButtonTopSundae && !hButtonFlurry && !hButtonShake && !hButtonColosso)
    {
        MessageBox(hWnd, "Button creation failed!", "Error", MB_ICONERROR);
    }


}


// BOTOES QUE IRAO SURGIR A RESPEITO DO PRODUTO
// BUTTON THAT WILL SHOW UP RELATED TO THE PRODUCT
void showType(HWND hWnd, const int selected, const float price)
{

    switch(selected)
    {
        //casquinha
        case 1:
        selectedId = selected;
        hButtonCreme = CreateWindowW(L"BUTTON", L"Creme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 10, 100, 30, hWnd, (HMENU)BUTTON_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonMista = CreateWindowW(L"BUTTON", L"Mista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 10, 100, 30, hWnd, (HMENU)BUTTON_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonChocolate = CreateWindowW(L"BUTTON", L"Chocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 350, 10, 100, 30, hWnd, (HMENU)BUTTON_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        if (!hButtonCreme && !hButtonMista && !hButtonChocolate)
        {
            MessageBox(hWnd, "Button creation failed!", "Error", MB_ICONERROR);
        }
        break;
        //sundae
    case 2:
         selectedId = selected;
        if(hButtonCreme && hButtonChocolate && hButtonMista)
        {
            DestroyWindow(hButtonChocolate);
            DestroyWindow(hButtonMista);
            DestroyWindow(hButtonCreme);
        }
        //calda
        hButtonCaldaCh = CreateWindowW(L"BUTTON", L"caldaCreme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 10, 100, 30, hWnd, (HMENU)BUTTON_CALD_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonCaldaCa = CreateWindowW(L"BUTTON", L"caldaMista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 10, 100, 30, hWnd, (HMENU)BUTTON_CALD_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonCaldaMo = CreateWindowW(L"BUTTON", L"caldaChocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 350, 10, 100, 30, hWnd, (HMENU)BUTTON_CALD_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        //massa
        hButtonCreme = CreateWindowW(L"BUTTON", L"Creme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 10, 100, 30, hWnd, (HMENU)BUTTON_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonMista = CreateWindowW(L"BUTTON", L"Mista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 10, 100, 30, hWnd, (HMENU)BUTTON_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonChocolate = CreateWindowW(L"BUTTON", L"Chocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 350, 10, 100, 30, hWnd, (HMENU)BUTTON_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        break;
        default:
            DestroyWindow(hButtonChocolate);
            DestroyWindow(hButtonMista);
            DestroyWindow(hButtonCreme);
    }
}
