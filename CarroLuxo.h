struct carroLuxo{
	char tipo[30];
	int dias;
	char data[20];
	
	
};


typedef struct carroLuxo CarroLuxo;


CarroLuxo createCarroLuxo(HWND data, HWND dias);

int contCarroLuxo;
