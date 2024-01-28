#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include <windows.h>
#include "control.h"

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3

#define EDIT_PRODUCT_DETAILS 1001

// Products Button
#define BUTTON_CASQUINHA 4
#define BUTTON_SUNDAE 5
#define BUTTON_TOPSUNDAE 6
#define BUTTON_COLOSSO 7
#define BUTTON_FLURRY 8
#define BUTTON_SHAKE 9


// Mass Button
#define BUTTON_CREME 10
#define BUTTON_MISTA 11
#define BUTTON_CHOCOLATE 12


#define BUTTON_CALD_CREME 13
#define BUTTON_CALD_MISTA 14
#define BUTTON_CALD_CHOCOLATE 15


float value_casq = 3.50,
value_colos = 4.00,
value_sund = 6.90,
value_topSund = 8.90,
value_flurry = 12.00,
value_shake = 16.00;

int ordem=0;
int selectedId = 0;
char  totalText;
struct sobremesa
{
    char name[30];
    int quant;
    float price;
};
struct sobremesa listaSobremesas[20];


HWND hEditProductDetails;
HWND hEditProductTotal;

HWND hButtonCasquinha;
HWND hButtonSundae;
HWND hButtonTopSundae;
HWND hButtonColosso;
HWND hButtonFlurry;
HWND hButtonShake;

HWND hButtonCreme;
HWND hButtonMista;
HWND hButtonChocolate;

HWND hButtonCaldaCh;
HWND hButtonCaldaMo;
HWND hButtonCaldaCa;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenu(HWND);
void AddControls(HWND);
void calculateTotal();
void showType(HWND hWnd, int selected, float price);

#endif // MAIN_HEADER_H
