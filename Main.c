#include "constantes.h"

LRESULT CALLBACK WndProc(HWND janela, UINT Message, WPARAM wParam, LPARAM lParam) {

	switch(Message) {
		case WM_CREATE:
			vetor_hotel[0] = criar_hotel();
			criarLogin(janela);
			break;
		
		case WM_COMMAND:
			switch (wParam){
				case JANELABOTOES:
					if(verificarLogin(edit1, edit2, janela) == 1){
						breakJanelas();
						criarMenu(janela);
					}
			
					break;
				
				case HOSPEDES:
					breakJanelas();
					criarMenuHospedes(janela);
					break;
				
				case CADASTRAR_HOSPEDES:
					breakJanelas();
					criarMenuCadastroHospedes(janela);
					break;
					
				case VOLTAR_MENU_GERAL:
					breakJanelas();
					criarMenu(janela);
					break;
					
				case CADASTRAR:
					verificarCadastro(edit2, edit3, edit1, janela);
					break;
					
					
				case PESQUISAR_HOSPEDES:
					breakJanelas();
					criarMenuPesquisarHospedes(janela);
					break;
					
				case PESQUISAR:
					DestroyWindow(printar);
					printaHospedes(janela);	
					break;
					
				case EDITAR_HOSPEDES:
					breakJanelas();
					menuEditarHospedes(janela);
					break;
					
				case PESQUISAR_EDIT:
					if(verificarPesquisa(edit4, janela) != -1){
						menuEditarHospesdes2(janela);
					}
					
					break;
				
				case BOTAO_EDITAR_HOSPEDES:
					editarHospede(janela);
					break;
				
				case VOLTAR_MENU_HOSPEDES:
					breakJanelas();
					criarMenuHospedes(janela);
					break;
					
					
				case VAGAS:
					breakJanelas();
					printarTodasVagas(janela);
					break;
				
				
				case CONTRATOS:
					breakJanelas();
					menuContratos(janela);
					break;
					
				case CHECKIN:
					breakJanelas();
					menuCheckIn(janela);
					break;
				
				case PROCURAR_CHECK_IN:
					cpfCheckinEncontrado(janela);
					break;
				
				case ABRIR_CONTRATO:
					abrindoContrato(janela);
					break;
				
				case VOLTAR_MENUS_CONTRATO:
					breakJanelas();
					menuContratos(janela);
					break;
					
				case PESQUISAR_CONTRATOS:
					breakJanelas();
					menuPesquisaContratos(janela);
					break;
					
				case MOSTRAR_CONTRATOS_ABERTOS:
					breakJanelas();
					mostrarTodosOsContratoAbertos(janela);
					break;
				
				case MOSTRAR_CONTRATOS_FECHADOS:
					breakJanelas();
					mostrarTodosOsContratosFechados(janela);
					break;
					
				case MENU_CONTRATO_ABERTO_FECHADO:
					breakJanelas();
					menuPesquisaContratos(janela);
					break;
				
				case SERVICOS:
					breakJanelas();
					menuServicos(janela);
					break;
				
				case ABRIR_SERVICOS:
					addServicos(janela);
					break;
				
				case CARRO:
					breakJanelas();
					servicoCarro(janela);
					break;
					
				case ADICIONAR_CARRO:
					adicionarCarro(janela);
					breakJanelas();
					menuServicos(janela);
					break;
				
				case BABA:
					breakJanelas();
					servicoBaba(janela);
					break;
					
				case ADICIONAR_BABA:
					adicionarBaba(janela);
					breakJanelas();
					menuServicos(janela);
					break;
				
				
			    case CHECKOUT:
			    	breakJanelas();
			    	menuCheckOut(janela);
			    	break;
			    	
			    case PROCURAR_NOTA:
			    	printarNota(janela);
			    	break;
				
				case PAGAR:
					breakJanelas();
					pagar(janela);
					break;
				
				case CONCLUIR_PAGAMENTO:
					concluirPagamento(janela);
					break;
				
				case RESTAURANTE:
					breakJanelas();
					createComboBoxComidas(janela);
					break;
				case ADICIONAR_RESTAURANTE:	
					addServicosRestaurante(janela);
					break;
										
			}
			
			
			break;
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
	
		default:
			return DefWindowProc(janela, Message, wParam, lParam);
	}
	return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd; 
	MSG msg; 

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Hotel Confort Premium",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		800, 
		600, 
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}
	return msg.wParam;
	
}
