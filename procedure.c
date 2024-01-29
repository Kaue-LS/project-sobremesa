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

            switch(selectedId)
            {
                case 1:
                    AddCasq("creme");
                break;
                case 2:
                    AddSund("creme");
                break;
            }
            break;

        case BUTTON_MISTA:

            switch(selectedId)
            {
                case 1:
                    AddCasq("mista");
                break;
                case 2:
                    AddSund("mista");
                break;
            }
            break;
         case BUTTON_CHOCOLATE:

            switch(selectedId)
            {
                case 1:
                    AddCasq("chocolate");
                break;
                case 2:
                    AddSund("chocolate");
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

// Função para verificar se o nome da sobremesa já existe na lista
int findSobremesaIndex(char massName[20])
{

    for (int i = 0; i < ordem; ++i)
    {
        if (strcmp(listaSobremesas[i].name, massName) == 0)
        {

            return i; // Retorna o índice se o nome já existir
        }
    }

    return -1; // Retorna -1 se o nome não existir na lista
}

void AddCasq(char massName[20])
{

    int before = listaSobremesas[ordem].quant;
    char productName[20] = "casquinha-";
    strcat(productName,massName);
    int index = findSobremesaIndex(massName);

    if (index != -1)
    {
        // O nome já existe na lista, apenas aumente a quantidade
        listaSobremesas[index].quant += 1;
        listaSobremesas[index].price += value_casq;
    }
    else
    {

        // O nome não existe, adicione um novo objeto à lista
        strcpy(listaSobremesas[ordem].name, productName);
        listaSobremesas[ordem].quant = 1;
        listaSobremesas[ordem].price = value_casq;

        // Incrementa o índice para a próxima posição livre na lista
        ordem++;
    }

    // Atualize o total antes de exibir o novo produto
    if (before != listaSobremesas[ordem - 1].quant)
        calculateTotal();

   // Construa o texto da caixa de edição
    char displayText[500] = "";  // Ajuste o tamanho conforme necessário

    for (int i = 0; i < ordem; ++i)
    {
        char productText[100];
         sprintf(productText, "Name: %s, Quantity: %d, Price: %.2f \t\t\n", listaSobremesas[i].name, listaSobremesas[i].quant, listaSobremesas[i].price);
    strcat(displayText, productText);
   SetWindowText(hEditProductDetails, displayText);
    }


    // Defina o texto da caixa de edição
  //  SetWindowText(hEditProductDetails, displayText);
    //selectedId=0;
}


void AddSund(char massName[20])
{

    int before = listaSobremesas[ordem].quant;
    char productName[20] = "Sundae-";
    strcat(productName,massName);
    int index = findSobremesaIndex(massName);

    if (index != -1)
    {
        // O nome já existe na lista, apenas aumente a quantidade
        listaSobremesas[index].quant += 1;
        listaSobremesas[index].price += value_sund;
    }
    else
    {

        // O nome não existe, adicione um novo objeto à lista
        strcpy(listaSobremesas[ordem].name, productName);
        listaSobremesas[ordem].quant = 1;
        listaSobremesas[ordem].price = value_sund;

        // Incrementa o índice para a próxima posição livre na lista
        ordem++;
    }

    // Atualize o total antes de exibir o novo produto
    if (before != listaSobremesas[ordem - 1].quant)
        calculateTotal();

   // Construa o texto da caixa de edição
    char displayText[500] = "";  // Ajuste o tamanho conforme necessário

    for (int i = 0; i < ordem; ++i)
    {
        char productText[100];
         sprintf(productText, "Name: %s, Quantity: %d, Price: %.2f \t\t\n", listaSobremesas[i].name, listaSobremesas[i].quant, listaSobremesas[i].price);
    strcat(displayText, productText);
   SetWindowText(hEditProductDetails, displayText);
    }


    // Defina o texto da caixa de edição
  //  SetWindowText(hEditProductDetails, displayText);
    //selectedId=0;
}
