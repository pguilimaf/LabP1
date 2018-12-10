struct contrato{
	
	char dataInicial[50];
	int numeroNoites;
	long long int cartaoCredito;
	int tanqueCheio;
	int carroAssegurado;
	char tipoQuarto[50];
	
	int tipoTarifa;

	Hospede hospede;
	Baba baba[100];
	char restaurantes[100][30];
	int contRest;
	int qtdServicosBabas;
	int qtdCarroLuxo;
	int qtdCarroExecutivo;
	CarroExecutivo carroExecutivo[100];
	CarroLuxo carroLuxo[100];
	
	float valorFinal;
};

typedef struct contrato Contrato;


int cont_aberto;
int cont_fechado;

int retornaIndexContratoFechado(HWND cpf);
Contrato contratos_abertos[200];
Contrato contrato_fechados[200];

Contrato criarContrato(int tipoTarifa, HWND cartaoCredito, HWND numeroNoites, HWND dataInicial, char tipoQuarto[], Hospede hos, float valor);
void salvarContratoCheckIn(Contrato contrato);
int retornaIndexContrato(HWND cpf);
