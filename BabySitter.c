#include "constantes.h"


Baba createBaba(HWND idade, HWND horas){
	
	Baba aux;
	char string1[30], string[30];
	
	GetWindowText(idade, string1, 30);
	GetWindowText(horas, string, 30);
	
	aux.idade = atoi(string1);
	aux.horas = atoi(string);
	
	return aux;
}
