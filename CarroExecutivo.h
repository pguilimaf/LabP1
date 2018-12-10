struct carroExecutivo{
	char tipo[30];
	int dias;
	char data[20];
	
	
};

typedef struct carroExecutivo CarroExecutivo;


CarroExecutivo createCarroExecutivo(HWND data, HWND dias);

int contCarroExecutivo;
