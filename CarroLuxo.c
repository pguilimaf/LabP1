#include "constantes.h"

CarroLuxo createCarroLuxo(HWND data, HWND dias){
	
	CarroLuxo aux;
	char string[30];
	
	GetWindowText(data, aux.data, 20);
	GetWindowText(dias, string, 30);
	
	aux.dias = atoi(string);
	
	return aux;
}
