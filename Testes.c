#include "constantes.h"


int verificarLogin(HWND usuario, HWND senha, HWND tela){
	
	char string[30], string2[30];
	
	GetWindowText(usuario, string, 30);
	GetWindowText(senha, string2, 30);
	
	if(strlen(string) == 0 || strlen(string2) == 0){
		MessageBoxW(tela, L"Campo(s) nao preenchido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
		return 0;		
	}	
	
	else{
		if (strcmp(string, "admin") == 0 && strcmp(string2, "121314") == 0){
			return 1;
		}
		
		else{
			MessageBoxW(tela, L"Usuario ou Senha invalido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
			return 0;
		}
	}	
}


int verificarCadastro(HWND cpf, HWND nasc, HWND nome, HWND tela){
	
	char string[30], string1[30], string2[30];
	int index;
	
	
	GetWindowText(cpf, string, 30);
	GetWindowText(nasc, string1, 30);
	GetWindowText(nome, string2, 30);
	
	if(strlen(string) == 0 || strlen(string1) == 0 || strlen(string2) == 0){
		MessageBoxW(tela, L"Campo(s) nao preenchido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
		return 0;
	}
	
	else{
		index = procurarHospede(atoll(string));
	
		if(index == -1){
			cadastrarHospede(retornaHospede(cpf, nome, nasc));
			salvarHospedes(hospedes_cadastrados);
			MessageBoxW(tela, L"Hospede Cadastrado", L"OK", MB_OK | MB_ICONINFORMATION);
			return 1;
		}
		
		else{
			MessageBoxW(tela, L"Hospede ja Cadastrado", L"ERRO", MB_OK | MB_ICONINFORMATION);
			return 0;
		}
	
	}
}



int verificarEdicao(HWND cpf, HWND nasc, HWND nome, HWND tela){
	char string[30], string1[30], string2[30];
	int index;
	
	
	GetWindowText(cpf, string, 30);
	GetWindowText(nasc, string1, 30);
	GetWindowText(nome, string2, 30);
	
	if(strlen(string) == 0 || strlen(string1) == 0 || strlen(string2) == 0){
		MessageBoxW(tela, L"Campo(s) nao preenchido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
		return 0;
	}
	
	else{
		index = procurarHospede(atoll(string));
	
		if(index == -1){
			atualizarInformacoesHospede(edit4, edit2, edit1, edit3);
			MessageBoxW(tela, L"Hospede Editado", L"OK", MB_OK | MB_ICONINFORMATION);
			return 1;
		}
		
		else{
			MessageBoxW(tela, L"Hospede ja Cadastrado", L"ERRO", MB_OK | MB_ICONINFORMATION);
			return 0;
		}
	
	}
}


int verificarPesquisa(HWND cpf, HWND tela){
	char string[30], out[300];
	int index, cpf1;
	
	GetWindowText(cpf, string, 30);
	
	if(strlen(string) == 0){
		MessageBoxW(tela, L"Campo(s) nao preenchido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
		return -1;
	}
	
	else{
		index = procurarHospede(atoll(string));		
		if(index == -1){
			MessageBoxW(tela, L"Nao Cadastrado", L"Erro", MB_OK | MB_ICONINFORMATION);
			return -1;
		}
		
		else{
			return index;
		}
	}
}



int verificaAbrirContrato(HWND dataInicial, HWND diasEstadias, HWND cartaoCredito){
	char string[30], string2[30], string3[30];
	
	GetWindowText(dataInicial, string, 30);
	GetWindowText(diasEstadias, string2, 30);
	GetWindowText(cartaoCredito, string3, 30);	

	if(strlen(string) == 0 || strlen(string2) == 0 || strlen(string3) == 0){
		return -1;
	}
	
	else{
		return 0;
	}

}



int verificarExisteContratoAberto(HWND tela, HWND cpf){
	char string[30];
	
	
	GetWindowText(cpf, string, 30);
	

	if(strlen(string) == 0){
		MessageBoxW(tela, L"Campo nao preenchido", L"Erro", MB_OK | MB_ICONINFORMATION);
		return -1;
	}
	
	if(retornaIndexContrato(cpf) == -1){
		MessageBoxW(tela, L"Contrato nao Encontrado", L"Erro", MB_OK | MB_ICONINFORMATION);
		return -1;
	}	
	
	else{
		return 0;
	}
	
}



