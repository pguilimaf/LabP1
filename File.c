#include "constantes.h"

void salvarHotel(Hotel hotel[]){
	int i;
	FILE *arq;
	
	arq = fopen("informacoeshotel.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < 1; i++){
			fwrite(&hotel[i], sizeof(Hotel), 1, arq);
		}
		
		
		fclose(arq);
		
	}	
	
	else
		printf("Falhou :(\n");
		
	fclose(arq);
}


void abrirHotel(Hotel hotel[]){
	

	FILE * arq = fopen("informacoeshotel.txt", "rb");
	
	if (arq != NULL){
		while(1){
			
			Hotel p;
			
			size_t r = fread(&p, sizeof(Hotel), 1, arq);
			
			if (r < 1)
				break;
			
			else
				hotel[0] = p;
		}
		
		fclose(arq);
	}
}

void salvarHospedes(Hospede hospede[]){
	int i;
	
	FILE *arq;
	
	arq = fopen("hospedes.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < contHospedes; i++){
			fwrite(&hospede[i], sizeof(Hotel), 1, arq);
		}
		
		fclose(arq);
		
	}	
	
	else
		printf("Falhou :(\n");
		
	fclose(arq);
}


void abrirHospedes(){

	FILE * arq = fopen("hospedes.txt", "rb");
	
	if (arq != NULL){
		
		
		
		printf("%d", contHospedes);
		
		while(1){
			
			Hospede p;
			
			size_t r = fread(&p, sizeof(Hospede), 1, arq);
			
			printf("%d", r);
			
			if (r < 1){
				printf(":(");
				break;
			}
			
			else{
				cadastrarHospede(p);
				printf("Ok");
			}
		}
		
		fclose(arq);
	}
	
	else{
		printf("Arquivo nao Criado !");
	}
	
}


