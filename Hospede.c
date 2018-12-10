#include "constantes.h"

int contHospedes = 0;


Hospede retornaHospede(HWND cpf, HWND nome, HWND dataNasc){
	Hospede aux;
	
	char string[30];
	
	GetWindowText(nome, aux.nome, 30);
	GetWindowText(dataNasc, aux.dataNascimento, 30);
	GetWindowText(cpf, string, 30);
	
	aux.cpf = atoll(string);
	
	return aux;
}


void cadastrarHospede(Hospede hospede){
	hospedes_cadastrados[contHospedes] = hospede;
	contHospedes++;
}


int procurarHospede(long long int cpf){
	int i;
	
	for(i = 0; i < contHospedes; i++){
		if (hospedes_cadastrados[i].cpf == cpf){
			return i;
		}
	}
	
	return -1;
}


Hospede objetoHospede(HWND cpf){
	int i;
	char string[30];
	
	GetWindowText(cpf, string, 30);

	
	for(i = 0; i < contHospedes; i++){
		if (hospedes_cadastrados[i].cpf == atoll(string)){
			return hospedes_cadastrados[i];
		}
	}
}


void atualizarInformacoesHospede(HWND antigoCpf, HWND cpf, HWND nome, HWND dataNasc){
	char string[30];
	int contrato = retornaIndexContrato(antigoCpf);
	int contrato2 = retornaIndexContratoFechado(antigoCpf);
	
	GetWindowText(antigoCpf, string, 30);

	int posHospede = procurarHospede(atoll(string));	
	
	GetWindowText(nome, hospedes_cadastrados[posHospede].nome, 30);
	GetWindowText(dataNasc, hospedes_cadastrados[posHospede].dataNascimento, 30);
	GetWindowText(cpf, string, 30);
	
	hospedes_cadastrados[posHospede].cpf = atoll(string);

	
	if(contrato != -1){
		contratos_abertos[contrato].hospede = hospedes_cadastrados[posHospede];
	}
	
	if(contrato2 != -1){
		contrato_fechados[contrato2].hospede =  hospedes_cadastrados[posHospede];
	}	
	
	salvarHospedes(hospedes_cadastrados);
}
	
	
	
	

