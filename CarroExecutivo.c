#include "constantes.h"

CarroExecutivo createCarroExecutivo(HWND data, HWND dias){
	
	CarroExecutivo aux;
	char string[30];
	
	GetWindowText(data, aux.data, 20);
	GetWindowText(dias, string, 30);
	
	aux.dias = atoi(string);
	
	return aux;
}
