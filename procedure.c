#include "main_header.h"

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    int before;

    switch (msg)
    {
    case WM_CREATE:
        AddMenu(hWnd);
        AddControls(hWnd);
        break;

    case WM_COMMAND:
        switch (wp)
        {
        case FILE_MENU_NEW:
            MessageBox(hWnd, "New Clicked", "Message", MB_OK);
            break;
        case FILE_MENU_OPEN:
            MessageBox(hWnd, "Open Clicked", "Message", MB_OK);
            break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;

        // BOTOES DE SOBREMESAS
        case BUTTON_CASQUINHA:
            showType(hWnd, 1, value_casq);
            break;
        case BUTTON_SUNDAE:
            showType(hWnd, 2, value_sund);
            break;
        case BUTTON_TOPSUNDAE:
            MessageBox(hWnd, "Tu clicou no TopSundae", "Message", MB_OK);
            break;
        case BUTTON_COLOSSO:
            MessageBox(hWnd, "Tu clicou no Colosso", "Message", MB_OK);
            break;
        case BUTTON_FLURRY:
            MessageBox(hWnd, "Tu clicou no Flurry", "Message", MB_OK);
            break;
        case BUTTON_SHAKE:
            MessageBox(hWnd, "Tu clicou no Shake", "Message", MB_OK);
            break;

        // MASSA CASQUINHA
        case BUTTON_CREME:
            printf("creme clicada");
            switch(selectedId)
            {
                case 1:
                    AddCasq("creme");
                    break;
            }
            break;

        case BUTTON_MISTA:
            printf("mista clicada");
            switch(selectedId)
            {
                case 1:
                    AddCasq("mista");
                    break;
            }
            break;
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }

    return 0;
}

void AddCasq(char massName[20])
{
    int before = listaSobremesas[ordem].quant;
    char productName[20] = "casquinha-";
    strcat(productName, massName);
    strcpy(listaSobremesas[ordem].name, productName);
    listaSobremesas[ordem].quant += 1;  // Aumenta a quantidade em 1
    listaSobremesas[ordem].price += value_casq;

    // Atualize o total antes de exibir o novo produto
    if (before != listaSobremesas[ordem].quant)
        calculateTotal();

    // Adicione o produto à caixa de edição
    char displayText[100];  // Ajuste o tamanho conforme necessário
    sprintf(displayText, "Name: %s, Quantity: %d, Price: %.2f\n", listaSobremesas[ordem].name, listaSobremesas[ordem].quant, listaSobremesas[ordem].price);

    // Defina o texto da caixa de edição
    SetWindowText(hEditProductDetails, displayText);
    //selectedId=0;
}
