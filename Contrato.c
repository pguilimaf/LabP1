#include "constantes.h"

int cont_aberto = 0;
int cont_fechado = 0;


Contrato criarContrato(int tipoTarifa, HWND cartaoCredito, HWND numeroNoites, HWND dataInicial, char tipoQuarto[], Hospede hos, float valor){
	Contrato aux;
	
	char string[30], string2[30], string3[30];
	
	GetWindowText(dataInicial, aux.dataInicial, 30);
	GetWindowText(numeroNoites, string3, 30);
	strcpy(aux.tipoQuarto, tipoQuarto);
	GetWindowText(cartaoCredito, string2, 30);
	
	aux.tipoTarifa = tipoTarifa;
	aux.cartaoCredito = atoll(string2);
	aux.numeroNoites = atoi(string3);
	
	aux.contRest = 0;
	aux.qtdServicosBabas = 0;
	aux.qtdCarroLuxo = 0;
	aux.qtdCarroExecutivo = 0;
	aux.hospede = hos;
	aux.valorFinal = valor * atoi(string3);
	
	return aux;
	
}


int retornaIndexContratoFechado(HWND cpf){
	char string[30];
	int i;
	
	GetWindowText(cpf, string, 30);
	
	for(i = 0; i < cont_fechado; i++){
		if(contrato_fechados[i].hospede.cpf == atoll(string)){
			return i;
		}
		
	}
	
	return -1;
}


void salvarContratoCheckIn(Contrato contrato){
	contratos_abertos[cont_aberto] = contrato;
	cont_aberto++;
}

void addContratoFechado(index){
	
	contrato_fechados[cont_fechado] = contratos_abertos[index];
	cont_fechado++;
}

int retornaIndexContrato(HWND cpf){
	char string[30];
	int i;
	
	GetWindowText(cpf, string, 30);
	
	for(i = 0; i < cont_aberto; i++){
		if(contratos_abertos[i].hospede.cpf == atoll(string)){
			return i;
		}
		
	}
	
	return -1;
}


void removerContratoAberto(HWND cpf){
	int x, i;
	
	x = retornaIndexContrato(cpf);
	
	if(x == cont_aberto - 1){
		cont_aberto--;
	}
	
	else{
		for(i = x+1; i < cont_aberto; i++){
			contratos_abertos[i-1] = contratos_abertos[i];
			
		}
		cont_aberto--;
	}
	
}

