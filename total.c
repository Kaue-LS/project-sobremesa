#include "main_header.h"

void convertCharToWide(const char* source, wchar_t* dest, int destSize) {
    MultiByteToWideChar(CP_UTF8, 0, source, -1, dest, destSize);
}
float sumAllValue()
{
      float somaDosPrecos = 0.0;
    int numSobremesas = sizeof(listaSobremesas) / sizeof(listaSobremesas[0]);


    for (int i = 0; i < numSobremesas; ++i) {
        somaDosPrecos += listaSobremesas[i].price;
    }

    return somaDosPrecos;
}


void calculateTotal()
{
    float allValue = sumAllValue();
    // Exemplo de vari�vel char[]
    char charText[20];

    sprintf(charText, "Total:\t\tR$%.2f", allValue);

    // Tamanho da string wide necess�rio (incluindo o caractere nulo)
    int wideSize = MultiByteToWideChar(CP_UTF8, 0, charText, -1, NULL, 0);

    // Alocar mem�ria para a string wide
    wchar_t* wideText = (wchar_t*)malloc(wideSize * sizeof(wchar_t));

    // Converter a string char[] para wide
    convertCharToWide(charText, wideText, wideSize);


    // Liberar a mem�ria alocada
    free(wideText);

    SetWindowTextW(hEditProductTotal, wideText);
}
