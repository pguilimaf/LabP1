#include "constantes.h"

void breakJanelas(){
	DestroyWindow(printar);
	DestroyWindow(botao1);
	DestroyWindow(botao2);
	DestroyWindow(botao3);
	DestroyWindow(botao4);
	DestroyWindow(botao5);
	DestroyWindow(static1);
	DestroyWindow(static2);
	DestroyWindow(static3);
	DestroyWindow(static4);
	DestroyWindow(static5);
	DestroyWindow(static6);
	DestroyWindow(edit1);
	DestroyWindow(edit2);
	DestroyWindow(edit3);
	DestroyWindow(edit4);	
	DestroyWindow(comboBox1);
	DestroyWindow(comboBox2);
	DestroyWindow(comboBox3);
}


void criarLogin(HWND tela){
	static1 = CreateWindowW(L"static", L"Login: ", WS_VISIBLE | WS_CHILD , 240, 200, 350, 17, tela, 0, 0, 0);
	static2 = CreateWindowW(L"static", L"Password: ", WS_VISIBLE | WS_CHILD | ES_PASSWORD, 240, 240, 100, 20, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 360, 200 , 150, 25, tela, 0, 0, 0);
	edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 360, 240, 150, 25, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Logar", WS_VISIBLE  | WS_CHILD, 390, 300, 100, 25, tela, (HMENU) JANELABOTOES, 0, 0);
}


void criarMenu(HWND tela){
	botao1 = CreateWindowW(L"Button", L"Hospedes", WS_VISIBLE  | WS_CHILD, 200, 130, 200, 75, tela, (HMENU) HOSPEDES, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Contratos", WS_VISIBLE  | WS_CHILD, 400, 130, 200, 75, tela, (HMENU) CONTRATOS, 0, 0);
	botao3 = CreateWindowW(L"Button", L"Vagas", WS_VISIBLE  | WS_CHILD, 300, 240, 200, 75, tela, (HMENU) VAGAS, 0, 0);
}


void criarMenuHospedes(HWND tela){
	botao1 = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 200, 130, 200, 75, tela, (HMENU) CADASTRAR_HOSPEDES, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Pesquisar", WS_VISIBLE  | WS_CHILD, 400, 130, 200, 75, tela, (HMENU) PESQUISAR_HOSPEDES, 0, 0);
	botao3 = CreateWindowW(L"Button", L"Editar", WS_VISIBLE  | WS_CHILD, 300, 240, 200, 75, tela, (HMENU) EDITAR_HOSPEDES, 0, 0);
	botao4 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_GERAL, 0, 0);
}


void criarMenuCadastroHospedes(HWND tela){
	
	
	static1 = CreateWindowW(L"static", L"Nome: ", WS_VISIBLE | WS_CHILD , 20, 40, 350, 17, tela,0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 250, 40 , 300, 25, tela, 0, 0, 0);
	
	static2 = CreateWindowW(L"static", L"Cpf (Somente Numeros): ", WS_VISIBLE | WS_CHILD , 20, 80, 350, 17, tela,0, 0, 0);
	edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 250, 80, 300, 25, tela, 0, 0, 0);
	
	static3 = CreateWindowW(L"static", L"Nascimento (Separados por / ): ", WS_VISIBLE | WS_CHILD , 20, 120, 350, 17, tela, 0, 0, 0);
	edit3 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 250, 120, 300, 25, tela, 0, 0, 0);
	
	botao1 = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 300, 200, 200, 50, tela, (HMENU) CADASTRAR, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_HOSPEDES, 0, 0);
		
}

void criarMenuPesquisarHospedes(HWND tela){
	static1 = CreateWindowW(L"static", L"Cpf (Somente Numeros): ", WS_VISIBLE | WS_CHILD , 20, 80, 350, 17, tela,0, 0, 0);
	
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 200, 80, 300, 25, tela, 0, 0, 0);
	
	botao1 = CreateWindowW(L"Button", L"Pesquisar", WS_VISIBLE  | WS_CHILD, 250, 150, 200, 50, tela, (HMENU) PESQUISAR, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_HOSPEDES, 0, 0);
		
}

void printaHospedes(HWND tela){
	printar = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY , 165,240,400,100, tela,NULL,NULL, NULL);			
	
	valor = verificarPesquisa(edit1, tela);			
	
	if(valor != -1){
		
		strcat(saida, "* Nome: ");
		strcat(saida, hospedes_cadastrados[valor].nome);
		strcat(saida, "\r\n* Data de Nascimento: ");
		strcat(saida, hospedes_cadastrados[valor].dataNascimento);
		sprintf(cpf1, "%llu", hospedes_cadastrados[valor].cpf);
		strcat(saida, "\r\n* Cpf: ");
		strcat(saida, cpf1);
		SetWindowText(printar, saida);
	}
	
	strcpy(saida, "");
		
}




void menuEditarHospedes(HWND tela){
	
	static4 = CreateWindowW(L"static", L"Digite Cpf para atualizar: ", WS_VISIBLE | WS_CHILD , 20, 40, 350, 17, tela,0, 0, 0);
	edit4 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 280, 40 , 300, 25, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 320, 80, 200, 50, tela, (HMENU) PESQUISAR_EDIT, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_HOSPEDES, 0, 0);
		
	}
			


void menuEditarHospesdes2(HWND tela){
	static1 = CreateWindowW(L"static", L"Novo Nome: ", WS_VISIBLE | WS_CHILD , 20, 140, 350, 17, tela,0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 280, 140, 300, 25, tela, 0, 0, 0);

	static2 = CreateWindowW(L"static", L"Novo Cpf (Somente Numeros): ", WS_VISIBLE | WS_CHILD , 20, 180, 350, 17, tela,0, 0, 0);
	edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 280, 180, 300, 25, tela, 0, 0, 0);

	static3 = CreateWindowW(L"static", L"Novo Nascimento (Separados por / ): ", WS_VISIBLE | WS_CHILD , 20, 220, 350, 17, tela, 0, 0, 0);
	edit3 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 280, 220, 300, 25, tela, 0, 0, 0);

	botao3 = CreateWindowW(L"Button", L"Editar", WS_VISIBLE  | WS_CHILD, 320, 280, 200, 50, tela, (HMENU) BOTAO_EDITAR_HOSPEDES, 0, 0);
		
}


void editarHospede(HWND tela){
	verificarEdicao(edit2, edit3, edit1, tela);
}


void printarTodasVagas(HWND tela){
		printar = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY , 120,50,500,400, tela,NULL,NULL, NULL);
		botao1 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_GERAL, 0, 0);
		
		strcat(saida, "* Vagas Presidencial: ");
		sprintf(vagas, "%d", vetor_hotel[0].presidencial);
		strcat(saida, vagas);
		
		strcat(saida, "\r\n");
		
		
		strcat(saida, "\r\n* Vagas Luxo Triplo: ");
		sprintf(vagas, "%d", vetor_hotel[0].luxoTriplo);
		strcat(saida, vagas);
		strcat(saida, "\r\n* Vagas Luxo Duplo: ");
		sprintf(vagas, "%d", vetor_hotel[0].luxoDuplo);
		strcat(saida, vagas);
		strcat(saida, "\r\n* Vagas Luxo Simples: ");
		sprintf(vagas, "%d", vetor_hotel[0].luxoSimples);
		strcat(saida, vagas);		
		
		strcat(saida, "\r\n");
		
		strcat(saida, "\r\n* Vagas Executivo Triplo: ");
		sprintf(vagas, "%d", vetor_hotel[0].luxoTriplo);
		strcat(saida, vagas);
		strcat(saida, "\r\n* Vagas Executivo Duplo: ");
		sprintf(vagas, "%d", vetor_hotel[0].executivoDuplo);
		strcat(saida, vagas);
		strcat(saida, "\r\n* Vagas Executivo Simples: ");
		sprintf(vagas, "%d", vetor_hotel[0].executivoSimples);
		strcat(saida, vagas);
			
			
	
		SetWindowText(printar, saida);
		strcpy(saida, "");
}


void menuContratos(HWND tela){
	botao1 = CreateWindowW(L"Button", L"Check In", WS_VISIBLE  | WS_CHILD, 200, 130, 200, 75, tela, (HMENU) CHECKIN, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Check Out", WS_VISIBLE  | WS_CHILD, 400, 130, 200, 75, tela, (HMENU) CHECKOUT, 0, 0);
	botao3 = CreateWindowW(L"Button", L"Servicos", WS_VISIBLE  | WS_CHILD, 200, 240, 200, 75, tela, (HMENU) SERVICOS, 0, 0);
	botao4 = CreateWindowW(L"Button", L"Pesquisar", WS_VISIBLE  | WS_CHILD, 400, 240, 200, 75, tela, (HMENU) PESQUISAR_CONTRATOS, 0, 0);
	
	
	botao5 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENU_GERAL, 0, 0);
}


void createComboBoxTipoQuarto(HWND tela){

	
	comboBox1 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 50,180, 400, 500, tela, NULL, 0, 0) ; 
                               
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Presidencial R$: 1.200/dia");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Luxo triplo R$: 620/dia");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Luxo duplo  R$: 570/dia");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Luxo simples R$: 520/dia");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Executivo triplo R$: 440/dia");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Executivo duplo R$: 385/dia");
    SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Executivo simples R$: 360/dia");
    
    
    SendMessage(comboBox1, CB_SETCURSEL, 0, 0);
}


void createComboBoxAltaTemporada(HWND tela){
	comboBox2 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 50, 300, 150, 500, tela, NULL, 0, 0) ; 
	
	SendMessage (comboBox2, CB_ADDSTRING, 0, (LPARAM) "Sim");
	SendMessage (comboBox2, CB_ADDSTRING, 0, (LPARAM) "Nao");
	
	
	SendMessage(comboBox2, CB_SETCURSEL, 1, 0);
}




void menuCheckIn(HWND tela){
	
	static1 = CreateWindowW(L"static", L"Digite cpf do hospede cadastrado para efetuar checkin: ", WS_VISIBLE | WS_CHILD , 50, 50, 400, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 430, 50, 300, 20, tela, 0, 0, 0);
	
	botao1 = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 300, 100, 150, 50, tela, (HMENU) PROCURAR_CHECK_IN, 0, 0);
	
	botao5 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENUS_CONTRATO, 0, 0);
	
}

void cpfCheckinEncontrado(HWND tela){
	char string[30];
	
	GetWindowText(edit1, string, 30);
	
	if(procurarHospede(atoll(string)) == -1){
    	MessageBoxW(tela, L"Hospede nao encontrado", L"Erro", MB_OK | MB_ICONINFORMATION);
    	breakJanelas();
    	menuCheckIn(tela);
	}
	
	else if(retornaIndexContrato(edit1) != -1){
		MessageBoxW(tela, L"Esse Hospede esta com Check In Aberto", L"Erro", MB_OK | MB_ICONINFORMATION);
    	breakJanelas();
    	menuCheckIn(tela);
	}
	
	else{
		static2 = CreateWindowW(L"static", L"Selecione qual tipo de quarto: ", WS_VISIBLE | WS_CHILD , 50, 160, 400, 17, tela, 0, 0, 0);
		createComboBoxTipoQuarto(tela);
		
		static3 = CreateWindowW(L"static", L"Digite a data inicial da alocacao: ", WS_VISIBLE | WS_CHILD , 50, 220, 400, 17, tela, 0, 0, 0);
		edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 270, 220, 300, 20, tela, 0, 0, 0);
		
		static4 = CreateWindowW(L"static", L"Digite quantos dias de estadia: ", WS_VISIBLE | WS_CHILD , 50, 250, 400, 17, tela, 0, 0, 0);
		edit3 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 270, 250, 50, 20, tela, 0, 0, 0);
		
		static5 = CreateWindowW(L"static", L"Alta temporada ?", WS_VISIBLE | WS_CHILD , 50, 280, 400, 17, tela, 0, 0, 0);
		createComboBoxAltaTemporada(tela);
		
		static6 = CreateWindowW(L"static", L"Numero Cartao de Credito: ", WS_VISIBLE | WS_CHILD , 50, 330, 400, 17, tela, 0, 0, 0);
		edit4 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 230, 330, 200, 20, tela, 0, 0, 0);
		
		botao2 = CreateWindowW(L"Button", L"Abrir Contrato", WS_VISIBLE  | WS_CHILD, 300, 380, 150, 50, tela, (HMENU) ABRIR_CONTRATO, 0, 0);
		
	}
	
}


void abrindoContrato(HWND tela){
	int flagCreateBox2;
	char string[30];
	
	if(verificaAbrirContrato(edit2, edit3, edit4) == -1){
		MessageBoxW(tela, L"Campo(s) nao preenchido(s)", L"Erro", MB_OK | MB_ICONINFORMATION);
		breakJanelas();
		menuCheckIn(tela);
	}

	else{
		if(SendMessage(comboBox2, CB_GETCURSEL, 0, 0) == 0){
			flagCreateBox2 = 0;
	}
	
		else{
			
			flagCreateBox2 = 1;
		}
		
		if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 0){
			strcpy(string, "Presidencial");
			valorQuarto = 1200.0;
			vetor_hotel[0].presidencial--;
		}
		
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 1){
			strcpy(string, "Luxo Triplo");
			valorQuarto = 620.0;
			vetor_hotel[0].luxoTriplo--;
		}
		
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 2){
			strcpy(string, "Luxo Duplo");
			valorQuarto = 570.0;
			vetor_hotel[0].luxoDuplo--;
		}
		
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 3){
			strcpy(string, "Luxo Simples");
			valorQuarto = 520.0;
			vetor_hotel[0].luxoSimples--;
		}
	
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 4){
			strcpy(string, "Executivo Triplo");
			valorQuarto = 440.0;
			vetor_hotel[0].executivoTriplo--;
		}
		
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 5){
			strcpy(string, "Executivo Duplo");
			valorQuarto = 385.0;
			vetor_hotel[0].executivoDuplo--;
		}
		
		else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 6){
			strcpy(string, "Executivo Simples");
			valorQuarto = 360.0;
			vetor_hotel[0].executivoSimples--;
		}
		
		if(flagCreateBox2 == 0){
			valorQuarto += ((valorQuarto *25) / 100);
		}
		salvarContratoCheckIn(criarContrato(flagCreateBox2, edit4, edit3, edit2, string, objetoHospede(edit1), valorQuarto));
		
		MessageBoxW(tela, L"Contrato Aberto !", L"Ok", MB_OK | MB_ICONINFORMATION);
		breakJanelas();
		menuCheckIn(tela);
	}
}


void menuPesquisaContratos(HWND tela){
	botao1 = CreateWindowW(L"Button", L"Contrato(s) Aberto(s)", WS_VISIBLE  | WS_CHILD, 200, 130, 200, 75, tela, (HMENU) MOSTRAR_CONTRATOS_ABERTOS, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Contrato(s) Fechado(s)", WS_VISIBLE  | WS_CHILD, 400, 130, 200, 75, tela, (HMENU) MOSTRAR_CONTRATOS_FECHADOS, 0, 0);
	botao3 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENUS_CONTRATO, 0, 0);
	
	
}

int mostrarTodosOsContratosFechados(HWND tela){
	int i, j;
	
	
	printar = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY | WS_HSCROLL, 120, 100, 500, 375, tela,NULL,NULL, NULL);
	
	botao3 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) PESQUISAR_CONTRATOS, 0, 0);
	
	
	if(cont_fechado > 0){
		for(j = 0; j < cont_fechado; j++){
			strcat(saida, "* Nome: ");
			strcat(saida, contrato_fechados[j].hospede.nome);
			
			strcat(saida, "\r\n");
			
			strcat(saida, "* Nascimento: ");
			strcat(saida, contrato_fechados[j].hospede.dataNascimento);
			
			strcat(saida, "\r\n* Cpf: ");
			sprintf(vagas, "%llu",  contrato_fechados[j].hospede.cpf);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n* Tipo de Quarto: ");
			strcat(saida,  contrato_fechados[j].tipoQuarto);
			
			strcat(saida, "\r\n* Numero de Noites: ");
			sprintf(vagas, "%d", contrato_fechados[j].numeroNoites);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n* Numero Cartao de Credito: ");
			sprintf(cpf1, "%llu", contrato_fechados[j].cartaoCredito);
			strcat(saida, cpf1);
			
			
			strcat(saida, "\r\n* Tarifa tipo: ");
			sprintf(vagas, "%d", contrato_fechados[j].tipoTarifa);
			strcat(saida, vagas);
			
			if(contrato_fechados[j].tipoTarifa == 0){
				strcat(saida, " (Alta Temporada)");
			}	
			
			else{
				strcat(saida, "(Tipo Normal)");
			}
			
			strcat(saida, "\r\n* Servicos Pedidos");
			
			for(i = 0; i < contrato_fechados[j].qtdCarroLuxo; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contrato_fechados[j].carroLuxo[i].tipo);
				strcat(saida, "\r\n* Data: ");
				strcat(saida, contrato_fechados[j].carroLuxo[i].data);
				strcat(saida, "\r\n* Quantidade dias: ");
				sprintf(vagas, "%d", contratos_abertos[j].carroLuxo[i].dias);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			
			for(i = 0; i < contrato_fechados[j].qtdCarroExecutivo; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contrato_fechados[j].carroExecutivo[i].tipo);
				strcat(saida, "\r\n* Data: ");
				strcat(saida, contrato_fechados[j].carroExecutivo[i].data);
				strcat(saida, "\r\n* Quantidade dias: ");
				sprintf(vagas, "%d", contrato_fechados[j].carroExecutivo[i].dias);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			for(i = 0; i < contratos_abertos[j].qtdServicosBabas; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contrato_fechados[j].baba[i].tipo);
				strcat(saida, "\r\n* Idade: ");
				sprintf(vagas, "%d",  contrato_fechados[j].baba[i].idade);
				strcat(saida, vagas);
				strcat(saida, "\r\n* Quantidade horas: ");
				sprintf(vagas, "%d", contrato_fechados[j].baba[i].horas);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			for(i = 0; i < contrato_fechados[j].contRest; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: Restaurante");		
				strcat(saida, "\r\n");
				strcat(saida, contrato_fechados[j].restaurantes[i]);
		}
			
		
			strcat(saida, "\r\n* Valor a ser pago ate o momento: R$: ");
			
			
			sprintf(vagas, "%.2f", contrato_fechados[j].valorFinal);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n");
			strcat(saida, "_________________________________________________");
			strcat(saida, "\r\n");
			
			SetWindowText(printar, saida);

			
		}
		
		strcpy(saida, "");
	}
	
	strcpy(saida, "");
	
	
}

int mostrarTodosOsContratoAbertos(HWND tela){
	int i, j;
	
	botao3 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) PESQUISAR_CONTRATOS, 0, 0);
	
	printar = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY | WS_HSCROLL, 120, 100, 500, 375, tela,NULL,NULL, NULL);
	
	if(cont_aberto > 0){
		for(j = 0; j < cont_aberto; j++){
			strcat(saida, "* Nome: ");
			strcat(saida, contratos_abertos[j].hospede.nome);
			
			strcat(saida, "\r\n");
			
			strcat(saida, "* Nascimento: ");
			strcat(saida, contratos_abertos[j].hospede.dataNascimento);
			
			strcat(saida, "\r\n* Cpf: ");
			sprintf(vagas, "%llu",  contratos_abertos[j].hospede.cpf);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n* Tipo de Quarto: ");
			strcat(saida,  contratos_abertos[j].tipoQuarto);
			
			strcat(saida, "\r\n* Numero de Noites: ");
			sprintf(vagas, "%d", contratos_abertos[j].numeroNoites);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n* Numero Cartao de Credito: ");
			sprintf(cpf1, "%llu", contratos_abertos[j].cartaoCredito);
			strcat(saida, cpf1);
			
			
			strcat(saida, "\r\n* Tarifa tipo: ");
			sprintf(vagas, "%d", contratos_abertos[j].tipoTarifa);
			strcat(saida, vagas);
			
			if(contratos_abertos[j].tipoTarifa == 0){
				strcat(saida, " (Alta Temporada)");
			}	
			
			else{
				strcat(saida, "(Tipo Normal)");
			}
			
			strcat(saida, "\r\n* Servicos Pedidos");
			
			for(i = 0; i < contratos_abertos[j].qtdCarroLuxo; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contratos_abertos[j].carroLuxo[i].tipo);
				strcat(saida, "\r\n* Data: ");
				strcat(saida, contratos_abertos[j].carroLuxo[i].data);
				strcat(saida, "\r\n* Quantidade dias: ");
				sprintf(vagas, "%d", contratos_abertos[j].carroLuxo[i].dias);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			
			for(i = 0; i < contratos_abertos[j].qtdCarroExecutivo; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contratos_abertos[j].carroExecutivo[i].tipo);
				strcat(saida, "\r\n* Data: ");
				strcat(saida, contratos_abertos[j].carroExecutivo[i].data);
				strcat(saida, "\r\n* Quantidade dias: ");
				sprintf(vagas, "%d", contratos_abertos[j].carroExecutivo[i].dias);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			for(i = 0; i < contratos_abertos[j].qtdServicosBabas; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: ");
				strcat(saida, contratos_abertos[j].baba[i].tipo);
				strcat(saida, "\r\n* Idade: ");
				sprintf(vagas, "%d",  contratos_abertos[j].baba[i].idade);
				strcat(saida, vagas);
				strcat(saida, "\r\n* Quantidade horas: ");
				sprintf(vagas, "%d", contratos_abertos[j].baba[i].horas);
				strcat(saida, vagas);
				strcat(saida, "\r\n");
			}
			
			
			for(i = 0; i < contratos_abertos[j].contRest; i++){
				strcat(saida, "\r\n");
				strcat(saida, "\r\n* Tipo Servico: Restaurante");		
				strcat(saida, "\r\n");
				strcat(saida, contratos_abertos[j].restaurantes[i]);
		}
			
			
		
			strcat(saida, "\r\n* Valor a ser pago ate o momento: R$: ");
			
			
			sprintf(vagas, "%.2f", contratos_abertos[j].valorFinal);
			strcat(saida, vagas);
			
			strcat(saida, "\r\n");
			strcat(saida, "_________________________________________________");
			strcat(saida, "\r\n");
			
			SetWindowText(printar, saida);

			
		}
		
		strcpy(saida, "");
	}
	
	strcpy(saida, "");
}



int mostrarContratoAberto(HWND tela){
	
	int i, index;
	char string[30];
	
	GetWindowText(edit1, string, 30);
	
	
	index = retornaIndexContrato(edit1);
	
	
	if(verificarExisteContratoAberto(tela, edit1) == 0){
		printar = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY | WS_HSCROLL, 140, 160, 500, 375, tela,NULL,NULL, NULL);
		
		strcat(saida, "* Nome: ");
		strcat(saida, contratos_abertos[index].hospede.nome);
		
		strcat(saida, "\r\n");
		
		strcat(saida, "* Nascimento: ");
		strcat(saida, contratos_abertos[index].hospede.dataNascimento);
		
		strcat(saida, "\r\n* Cpf: ");
		sprintf(vagas, "%llu",  contratos_abertos[index].hospede.cpf);
		strcat(saida, vagas);
		
		strcat(saida, "\r\n* Tipo de Quarto: ");
		strcat(saida,  contratos_abertos[index].tipoQuarto);
		
		strcat(saida, "\r\n* Numero de Noites: ");
		sprintf(vagas, "%d", contratos_abertos[index].numeroNoites);
		strcat(saida, vagas);
		
		strcat(saida, "\r\n* Numero Cartao de Credito: ");
		sprintf(cpf1, "%llu", contratos_abertos[index].cartaoCredito);
		strcat(saida, cpf1);
		
		
		strcat(saida, "\r\n* Tarifa tipo: ");
		sprintf(vagas, "%d", contratos_abertos[index].tipoTarifa);
		strcat(saida, vagas);
		
		if(contratos_abertos[index].tipoTarifa == 0){
			strcat(saida, " (Alta Temporada)");
		}	
		
		else{
			strcat(saida, "(Tipo Normal)");
		}
		
		strcat(saida, "\r\n* Servicos Pedidos");
		
		for(i = 0; i < contratos_abertos[index].qtdCarroLuxo; i++){
			strcat(saida, "\r\n");
			strcat(saida, "\r\n* Tipo Servico: ");
			strcat(saida, contratos_abertos[index].carroLuxo[i].tipo);
			strcat(saida, "\r\n* Data: ");
			strcat(saida, contratos_abertos[index].carroLuxo[i].data);
			strcat(saida, "\r\n* Quantidade dias: ");
			sprintf(vagas, "%d", contratos_abertos[index].carroLuxo[i].dias);
			strcat(saida, vagas);
			strcat(saida, "\r\n");
			}
			
			
		for(i = 0; i < contratos_abertos[index].qtdCarroExecutivo; i++){
			strcat(saida, "\r\n");
			strcat(saida, "\r\n* Tipo Servico: ");
			strcat(saida, contratos_abertos[index].carroExecutivo[i].tipo);
			strcat(saida, "\r\n* Data: ");
			strcat(saida, contratos_abertos[index].carroExecutivo[i].data);
			strcat(saida, "\r\n* Quantidade dias: ");
			sprintf(vagas, "%d", contratos_abertos[index].carroExecutivo[i].dias);
			strcat(saida, vagas);
			strcat(saida, "\r\n");
		}
		
		for(i = 0; i < contratos_abertos[index].qtdServicosBabas; i++){
			strcat(saida, "\r\n");
			strcat(saida, "\r\n* Tipo Servico: ");
			strcat(saida, contratos_abertos[index].baba[i].tipo);
			strcat(saida, "\r\n* Idade: ");
			sprintf(vagas, "%d",  contratos_abertos[index].baba[i].idade);
			strcat(saida, vagas);
			strcat(saida, "\r\n* Quantidade horas: ");
			sprintf(vagas, "%d", contratos_abertos[index].baba[i].horas);
			strcat(saida, vagas);
			strcat(saida, "\r\n");
		}
		
		
		for(i = 0; i < contratos_abertos[index].contRest; i++){
			strcat(saida, "\r\n");
			strcat(saida, "\r\n* Tipo Servico: Restaurante");		
			strcat(saida, "\r\n");
			strcat(saida, contratos_abertos[index].restaurantes[i]);
		}
	
	
		strcat(saida, "\r\n* Valor a ser pago ate o momento: R$: ");
		
		
		sprintf(vagas, "%.2f", contratos_abertos[index].valorFinal);
		strcat(saida, vagas);
		
		SetWindowText(printar, saida);
		
		strcpy(saida, "");
		return 1;
	}
	
	strcpy(saida, "");
}



void menuServicos(HWND tela){
	
	static1 = CreateWindowW(L"static", L"Digite cpf do hospede para adicionar servicos:", WS_VISIBLE | WS_CHILD , 50, 50, 400, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 450, 50, 300, 20, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 300, 100, 150, 50, tela, (HMENU) ABRIR_SERVICOS, 0, 0);
	botao2 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) VOLTAR_MENUS_CONTRATO, 0, 0);
	
	
}


void addServicos(HWND tela){
	
	
	if(verificarExisteContratoAberto(tela, edit1) == 0){
		botao3 = CreateWindowW(L"Button", L"Carro", WS_VISIBLE  | WS_CHILD, 200, 170, 200, 75, tela, (HMENU) CARRO, 0, 0);
		botao4 = CreateWindowW(L"Button", L"Baba", WS_VISIBLE  | WS_CHILD, 400, 170, 200, 75, tela, (HMENU) BABA, 0, 0);
		botao5 = CreateWindowW(L"Button", L"Restaurante", WS_VISIBLE  | WS_CHILD, 300, 270, 200, 75, tela, (HMENU) RESTAURANTE, 0, 0);
		
		valor = retornaIndexContrato(edit1);
	}
	

}


void createComboBoxTipoCarro(HWND tela){

	comboBox1 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 150 ,50, 200, 500, tela, NULL, 0, 0) ; 
                               
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Carro Luxo");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Carro Executivo");

    
    SendMessage(comboBox1, CB_SETCURSEL, 0, 0);
    
    comboBox2 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 150,100, 200, 500, tela, NULL, 0, 0);
	
	SendMessage (comboBox2, CB_ADDSTRING, 0, (LPARAM) "Sim");
	SendMessage (comboBox2, CB_ADDSTRING, 0, (LPARAM) "Nao");
	
	SendMessage(comboBox2, CB_SETCURSEL, 0, 0);
	
	comboBox3 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 150, 150, 200, 500, tela, NULL, 0, 0);
	
	SendMessage (comboBox3, CB_ADDSTRING, 0, (LPARAM) "Sim");
	SendMessage (comboBox3, CB_ADDSTRING, 0, (LPARAM) "Nao");
	
	SendMessage(comboBox3, CB_SETCURSEL, 0, 0);

}

void servicoCarro(HWND tela){
	static1 = CreateWindowW(L"static", L"Tipo do carro: ", WS_VISIBLE | WS_CHILD , 50, 50, 400, 17, tela, 0, 0, 0);
	static2 = CreateWindowW(L"static", L"Tanque Cheio: ", WS_VISIBLE | WS_CHILD , 50, 100, 400, 17, tela, 0, 0, 0);
	static3 = CreateWindowW(L"static", L"Seguro: ", WS_VISIBLE | WS_CHILD , 50, 150, 150, 17, tela, 0, 0, 0);
	static4 = CreateWindowW(L"static", L"Data: ", WS_VISIBLE | WS_CHILD , 50, 200, 150, 17, tela, 0, 0, 0);
	static5 = CreateWindowW(L"static", L"Dias: ", WS_VISIBLE | WS_CHILD , 50, 250, 150, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 150, 200, 300, 20, tela, 0, 0, 0);
	edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 150, 250, 300, 20, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Adicionar", WS_VISIBLE  | WS_CHILD, 240, 270, 200, 75, tela, (HMENU) ADICIONAR_CARRO, 0, 0);
	
	createComboBoxTipoCarro(tela);
	
	
}


void adicionarCarro(HWND tela){
	
	char string[30], string2[30];
	float preco;
	
	GetWindowText(edit2, string, 30);
	GetWindowText(edit1, string2, 30);
	
	if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 0){
	
		strcpy(contratos_abertos[valor].carroLuxo[contCarroLuxo].data, string2);
		contratos_abertos[valor].carroLuxo[contCarroLuxo].dias = atoi(string);
		
		strcpy(contratos_abertos[valor].carroLuxo[contCarroLuxo].tipo, "Carro Luxo");
		
	
		contratos_abertos[valor].valorFinal += (100.0 * atof(string));
	
		
		contratos_abertos[valor].qtdCarroLuxo++;
		
		if(SendMessage(comboBox2, CB_GETCURSEL, 0, 0) == 0){
			contratos_abertos[valor].valorFinal += 300.0;
		}
		
		if(SendMessage(comboBox3, CB_GETCURSEL, 0, 0) == 0){
			contratos_abertos[valor].valorFinal += 250.0;
		}
		
		MessageBoxW(tela, L"Servico carro luxo adicionado", L"Ok", MB_OK | MB_ICONINFORMATION);
	}
	
	else{
		strcpy(contratos_abertos[valor].carroExecutivo[contCarroLuxo].data, string2);
		contratos_abertos[valor].carroExecutivo[contCarroLuxo].dias = atoi(string);
		strcpy(contratos_abertos[valor].carroExecutivo[contCarroExecutivo].tipo, "Carro Executivo");
		
		contratos_abertos[valor].valorFinal += (atoi(string) * 60.0);
		contratos_abertos[valor].qtdCarroExecutivo++;
		
		if(SendMessage(comboBox2, CB_GETCURSEL, 0, 0) == 0){
			contratos_abertos[valor].valorFinal += 300;
		}
		
		if(SendMessage(comboBox3, CB_GETCURSEL, 0, 0) == 0){
			contratos_abertos[valor].valorFinal += 250;
		}
		
		MessageBoxW(tela, L"Servico carro executivo adicionado", L"Ok", MB_OK | MB_ICONINFORMATION);
		
		
	}
		
}

void servicoBaba(HWND tela){
	static1 = CreateWindowW(L"static", L"Idade: ", WS_VISIBLE | WS_CHILD , 50, 50, 400, 17, tela, 0, 0, 0);
	static2 = CreateWindowW(L"static", L"Horas:", WS_VISIBLE | WS_CHILD , 50, 100, 400, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 150, 50, 300, 20, tela, 0, 0, 0);
	edit2 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 150, 100, 300, 20, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Adicionar", WS_VISIBLE  | WS_CHILD, 240, 270, 200, 75, tela, (HMENU) ADICIONAR_BABA, 0, 0);
	
}


void adicionarBaba(HWND tela){
	
	char string[30], string2[30];
	
	GetWindowText(edit1, string, 30);
	GetWindowText(edit2, string2, 30);
	
	
	if (atoi(string) < 2 || atoi(string) > 9){
		MessageBoxW(tela, L"Idade nao adequada para baba", L"Erro", MB_OK | MB_ICONINFORMATION);
	}
	
	else{
		strcpy(contratos_abertos[valor].baba[contBaba].tipo, "Baba");
		contratos_abertos[valor].baba[contBaba].idade = atoi(string);
		contratos_abertos[valor].baba[contBaba].horas = atoi(string2);
		
		contratos_abertos[valor].valorFinal += (atoi(string2) * 45.0);
		contratos_abertos[valor].qtdServicosBabas++;
		MessageBoxW(tela, L"Servico baba adicionado", L"OK", MB_OK | MB_ICONINFORMATION);
	}
	
}



void menuCheckOut(HWND tela){
	static1 = CreateWindowW(L"static", L"Digite cpf do hospede para check out:", WS_VISIBLE | WS_CHILD , 50, 50, 400, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 300, 50, 300, 20, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 300, 80, 100, 50, tela, (HMENU) PROCURAR_NOTA, 0, 0);
	botao3 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 660, 500, 100, 50, tela, (HMENU) VOLTAR_MENUS_CONTRATO, 0, 0);
	controleEdit1 = edit1;
}

void printarNota(HWND tela){
	if(mostrarContratoAberto(tela) == 1){
		botao2 = CreateWindowW(L"Button", L"Pagar", WS_VISIBLE  | WS_CHILD, 660, 400, 100, 50, tela, (HMENU) PAGAR, 0, 0);
		valor = retornaIndexContrato(edit1);
	}
	
}

void pagar(HWND tela){
	static1 = CreateWindowW(L"static", L"Digite o valor pra pagar:", WS_VISIBLE | WS_CHILD, 50, 50, 400, 17, tela, 0, 0, 0);
	edit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 300, 50, 300, 20, tela, 0, 0, 0);
	botao1 = CreateWindowW(L"Button", L"Concluir", WS_VISIBLE  | WS_CHILD, 300, 80, 100, 50, tela, (HMENU) CONCLUIR_PAGAMENTO, 0, 0);
	
	
}

void concluirPagamento(HWND tela){
	char string[30];
	
	GetWindowText(edit1, string, 30);
	
	if(contratos_abertos[valor].valorFinal <= atof(string)){
		if(strcmp(contratos_abertos[valor].tipoQuarto, "Presidencial") == 0){
			vetor_hotel[0].presidencial++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Luxo Triplo") == 0) {
			vetor_hotel[0].luxoTriplo++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Luxo Duplo") == 0){
			vetor_hotel[0].luxoDuplo++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Luxo Simples") == 0){
			vetor_hotel[0].luxoSimples++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Executivo Triplo") == 0){
			vetor_hotel[0].executivoTriplo++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Executivo Duplo") == 0){
			vetor_hotel[0].executivoDuplo++;
		}
		
		else if(strcmp(contratos_abertos[valor].tipoQuarto, "Executivo Simples") == 0){
			vetor_hotel[0].executivoSimples++;
		}
		
		
		MessageBoxW(tela, L"Pagamento Feito", L"OK", MB_OK | MB_ICONINFORMATION);
		addContratoFechado(valor);
		removerContratoAberto(controleEdit1);
		breakJanelas();
		menuCheckOut(tela);
	}
	
	
	else{
		MessageBoxW(tela, L"Valor pago nao e maior que o valor do contrato", L"Erro", MB_OK | MB_ICONINFORMATION);
		breakJanelas();
		menuCheckOut(tela);
		
	}
}


void createComboBoxComidas(HWND tela){

	static1 = CreateWindowW(L"static", L"Escolha qual servico voce quer:", WS_VISIBLE | WS_CHILD, 50, 50, 400, 17, tela, 0, 0, 0);
	
	comboBox1 = CreateWindow(TEXT ("combobox"), TEXT (""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 50,100, 400, 500, tela, NULL, 0, 0) ; 
                               
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Cafe da Manha R$: 40");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Almoco self-service R$: 80");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Jantar  R$: 80");
	SendMessage (comboBox1, CB_ADDSTRING, 0, (LPARAM) "Drink R$: 20");


    SendMessage(comboBox1, CB_SETCURSEL, 0, 0);
   	botao4 = CreateWindowW(L"Button", L"Voltar", WS_VISIBLE  | WS_CHILD, 650, 500, 100, 50, tela, (HMENU) SERVICOS, 0, 0);
    botao1 = CreateWindowW(L"Button", L"Adicionar", WS_VISIBLE  | WS_CHILD, 300, 150, 100, 50, tela, (HMENU) ADICIONAR_RESTAURANTE, 0, 0);
}


void addServicosRestaurante(HWND tela){
	
	if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 0){
		strcpy(contratos_abertos[valor].restaurantes[contratos_abertos[valor].contRest],"Cafe da manha");
		contratos_abertos[valor].contRest++;
		contratos_abertos[valor].valorFinal += 40;
		
	}
	
	else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 1){
		strcpy(contratos_abertos[valor].restaurantes[contratos_abertos[valor].contRest],"Almoco self-service");
		contratos_abertos[valor].contRest++;
		contratos_abertos[valor].valorFinal += 80;
	
	}

	else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 2){
		strcpy(contratos_abertos[valor].restaurantes[contratos_abertos[valor].contRest],"Jantar");
		contratos_abertos[valor].contRest++;
		contratos_abertos[valor].valorFinal += 80;
		
	}


	else if(SendMessage(comboBox1, CB_GETCURSEL, 0, 0) == 3){
		strcpy(contratos_abertos[valor].restaurantes[contratos_abertos[valor].contRest],"Drink");
		contratos_abertos[valor].contRest++;
		contratos_abertos[valor].valorFinal += 20;
	
	}
	
	
	MessageBoxW(tela, L"Servico restaurante Adicionado", L"OK", MB_OK | MB_ICONINFORMATION);
	breakJanelas();
	menuServicos(tela);
}




