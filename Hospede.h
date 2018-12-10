struct hospede{
	char nome[30], dataNascimento[30];
	long long int cpf;

		
};

typedef struct hospede Hospede;

int contHospedes;

Hospede hospedes_cadastrados[200];

void cadastrarHospede(Hospede hospede);

int procurarHospede(long long int cpf);

Hospede retornaHospede(HWND cpf, HWND nome, HWND dataNasc);

void atualizarInformacoesHospede(HWND antigoCpf, HWND cpf, HWND nome, HWND dataNasc);

Hospede objetoHospede(HWND cpf);
