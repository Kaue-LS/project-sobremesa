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

// Fun��o para verificar se o nome da sobremesa j� existe na lista
int findSobremesaIndex(char massName[20])
{
    printf("\n ordem: %d \n",ordem);
    for (int i = 0; i < ordem; ++i)
    {
        if (strcmp(listaSobremesas[i].name, massName) == 0)
        {
            printf("\ntem\n");
            return i; // Retorna o �ndice se o nome j� existir
        }
    }
     printf("\nnao tem\n");
    return -1; // Retorna -1 se o nome n�o existir na lista
}

void AddCasq(char massName[20])
{
    int before = listaSobremesas[ordem].quant;
    char productName[20] = "casquinha-";

    int index = findSobremesaIndex(massName);

    if (index != -1)
    {
        // O nome j� existe na lista, apenas aumente a quantidade
        listaSobremesas[index].quant += 1;
        listaSobremesas[index].price += value_casq;
    }
    else
    {

        // O nome n�o existe, adicione um novo objeto � lista
        strcpy(listaSobremesas[ordem].name, massName);
        listaSobremesas[ordem].quant = 1;
        listaSobremesas[ordem].price = value_casq;

        // Incrementa o �ndice para a pr�xima posi��o livre na lista
        ordem++;
    }
printf("\n ordem: %d \n",ordem);
    // Atualize o total antes de exibir o novo produto
    if (before != listaSobremesas[ordem - 1].quant)
        calculateTotal();

   // Construa o texto da caixa de edi��o
    char displayText[500] = "";  // Ajuste o tamanho conforme necess�rio

    for (int i = 0; i < ordem; ++i)
    {
        char productText[100];
         sprintf(productText, "Name: %s, Quantity: %d, Price: %.2f \t\t\n", listaSobremesas[i].name, listaSobremesas[i].quant, listaSobremesas[i].price);
    strcat(displayText, productText);
   SetWindowText(hEditProductDetails, displayText);
    }


    // Defina o texto da caixa de edi��o
  //  SetWindowText(hEditProductDetails, displayText);
    //selectedId=0;
}
