#include "main_header.h"


//VERIFY DESTROY ALL MASS AND SAUCE BUTTONS BEFORE SHOWING THE NEW BUTTONS
void destroyPastButtons()
{
    if(hButtonCreme && hButtonChocolate && hButtonMista)
        {
            DestroyWindow(hButtonChocolate);
            DestroyWindow(hButtonMista);
            DestroyWindow(hButtonCreme);

            //IF THERE IS ANY SAUCE BUTTONS PRESENT
            if( hButtonCaldaCa && hButtonCaldaCh && hButtonCaldaMo)
            {
                DestroyWindow(hButtonCaldaCa);
                DestroyWindow(hButtonCaldaCh);
                DestroyWindow(hButtonCaldaMo);
            }

        }
}


// SHOW THE BUTTONS ON THE SCREEN
void AddControls(HWND hWnd)
{

    // ADD WINDOWS'S BUTTONS FUNCTIONS, SIZES AND OTHERS ATTRIBUTES AND PUT THEM ON THE SCREEN

    hButtonCasquinha = CreateWindowW(L"BUTTON", L"Casquinha", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100, 30, hWnd, (HMENU)BUTTON_CASQUINHA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

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



// BUTTON THAT WILL SHOW UP RELATED TO THE PRODUCT
void showType(HWND hWnd, const int selected, const float price)
{

    switch(selected)
    {
        //casquinha
        case 1:

        destroyPastButtons();

        selectedId = selected;

        hButtonCreme = CreateWindowW(L"BUTTON", L"Creme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 10, 100, 30, hWnd, (HMENU)BUTTON_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonMista = CreateWindowW(L"BUTTON", L"Mista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 10, 100, 30, hWnd, (HMENU)BUTTON_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
        hButtonChocolate = CreateWindowW(L"BUTTON", L"Chocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 350, 10, 100, 30, hWnd, (HMENU)BUTTON_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

        if (!hButtonCreme && !hButtonMista && !hButtonChocolate)
        {
            MessageBox(hWnd, "Button creation failed!", "Error", MB_ICONERROR);
        }
        break;
        //sundae
        case 2:

            destroyPastButtons();

            selectedId = selected;

            //calda
            hButtonCaldaCh = CreateWindowW(L"BUTTON", L"Calda\nCreme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 10, 150, 30, hWnd, (HMENU)BUTTON_CALD_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
            hButtonCaldaCa = CreateWindowW(L"BUTTON", L"Calda\nMista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 10, 150, 30, hWnd, (HMENU)BUTTON_CALD_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
            hButtonCaldaMo = CreateWindowW(L"BUTTON", L"Calda\nChocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 400, 10, 150, 30, hWnd, (HMENU)BUTTON_CALD_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);

            //massa
            hButtonCreme = CreateWindowW(L"BUTTON", L"Creme", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 650, 10, 100, 30, hWnd, (HMENU)BUTTON_CREME, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
            hButtonMista = CreateWindowW(L"BUTTON", L"Mista", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 750, 10, 100, 30, hWnd, (HMENU)BUTTON_MISTA, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
            hButtonChocolate = CreateWindowW(L"BUTTON", L"Chocolate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 850, 10, 100, 30, hWnd, (HMENU)BUTTON_CHOCOLATE, (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE), NULL);
             if (!hButtonCreme && !hButtonMista && !hButtonChocolate && hButtonCaldaCa && hButtonCaldaCh && hButtonCaldaMo)
            {
                MessageBox(hWnd, "Button creation failed!", "Error", MB_ICONERROR);
            }
        break;
        default:
            destroyPastButtons();
    }
}


