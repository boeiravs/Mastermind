/*
 * ###############################################################################################
 * #                                                                                             #
 * # Matricula:    201110924                                 Universitário: V. Boeira            #
 * # Matricula:    200510633                                 Universitário: J. Júnior            #
 * # Professor(a): Mauricio Beraldin Barreto                                                     #
 * # Disciplina:   Desenvolvimento de Redes de Computadores  Sala:          306-1 (quarta-feira) #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * #                             CÓDIGO EM "C" Projeto Mastermind                                #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * #                              **  Arquivo das Funções **                                     #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * # Desenvolvido: 01/08/2018         Conclusão: 03/10/2018                   *** versão: 06 *** #
 * #                                                                                             #
 * ###############################################################################################
 * */

/* Chamada das Bibliotecas */
#include "mastermind_funcoes.h"	// 'Biblioteca' que inclui as funções no arquivo principal

// Função adastro de jogadores
void cadastro(void){
    char usuario[20], nome[20], idade[3];
	int i, teste1, teste2;

    FILE *arq;
    arq = fopen("jogadores.txt", "a");

    if(arq == NULL){	// verificando se arquivo existe
		printf("*************************************************\n");
        printf("*	Arquivo não pode ser aberto ou não existe!	*\n");
		printf("*************************************************\n");
        exit(0);
    }

	do{	
		printf("*	Usuário: ");
		scanf("%s", &usuario);

		teste1 = validaLet(usuario);	// chama função para validar somente letras
		teste2 = consulta(usuario);		// chama função para validar se usuário/nome já existe
	}while(teste1 == 0 || teste2 ==1);	// teste1(validação letras) e teste2(validação se existe)


	do{
    	printf("*	Nome: ");
		scanf("%s", &nome);

		teste1 = validaLet(nome);		// chama função para validar somente letras
		teste2 = consulta(nome);		// chama função para validar se usuário/nome já existe
	}while(teste1 == 0 || teste2 ==1);	// teste1(validação letras) e teste2(validação se existe)

	do{
		printf("*	Idade: ");
		scanf("%s", &idade);

		teste1 = validaNum(idade);		// chama função para validar somente nº
	} while(teste1 == 0);
    
	for (i = 0; i < strlen(usuario); i++){	   		// Converte cada caracter do usuário para minuscula
		usuario[i] = tolower(usuario[i]);	
	}

	for (i = 0; i < strlen(nome); i++){	   		// Converte cada caracter do nome
		if (i == 0){
			nome[i] = toupper (nome[i]);		// 1º letra  maiuscula
		}else{
			nome[i] = tolower (nome[i]); 		// restante para minusculas
		}
	}
    fprintf(arq, "%s	:	%s	:	%s	\n", usuario, nome, idade);
	printf("*************************************\n");
	printf("* Cadastro efetuado com sucesso!    *\n");
	printf("*************************************\n");

	fclose(arq);
}

// Função consulta de jogadores
int consulta(char usuarioPesq[20]){
    char pesq[50];

    FILE *arq;
    arq = fopen("jogadores.txt", "r");

    if(arq == NULL){	// verificando se arquivo existe
		printf("*************************************************\n");
        printf("*	Arquivo não pode ser aberto ou não existe!	*\n");
		printf("*************************************************\n");
        exit;
    }

    while (fgets(pesq, sizeof(pesq), arq) != NULL){		// verificando se usuário digitado existe em alguma linha do arquivo
    	if (strstr(pesq, usuarioPesq) != NULL){			// se usuário localizado exibir msg de confirmação
			printf("**********************************************\n");
            printf("*	Usuário Encontrado:\n");
			printf("	USUÁRIO		NOME		IDADE\n%s\n", pesq);
			printf("**********************************************\n");
            fclose(arq); 
            return 1;   // return 1 para voltar ao menu
        }
    }
	
	printf("***************************************\n");
    printf("*	Usuário não localizado!	      *\n");
	printf("***************************************\n");
	return 0;
    fclose(arq);
}

// Função para verificar estátisticas dos jogadores
int estatistica(void){
	char pesq[50], usuario[20];//verArq;
	int usuarioEncontrado = 0;

    FILE *arq;
    arq = fopen("pontuacao.txt", "r");
	//char verArq = "pontuacao.txt";

    if(arq == NULL){	// verificando se arquivo existe
        printf("Arquivo não pode ser aberto ou não existe\n");
        exit;
    }
	
	printf("Digite o nome do usuário para verificar sua pontuação: ");
    scanf("%s", &usuario);
	printf("**************************************************\n");
	while (fgets(pesq, sizeof(pesq), arq) != NULL){		// verificando se usuário digitado existe em alguma linha do arquivo
    	if (strstr(pesq, usuario) != NULL){
			usuarioEncontrado = 1;			// se usuário localizado exibir msg de confirmação
			printf("*  NOME	    PONTOS	   DATA		HORA\n");
			printf("%s", pesq);
			printf("**************************************************\n");
            //fclose(arq); 
            // return 1;   // return 1 para voltar ao menu
        }
    }

	if (usuarioEncontrado == 0) {
		printf("***************************************\n");
		printf("*	Usuário não localizado!	      *\n");
		printf("***************************************\n");
	}
	
    fclose(arq);
}

// Função para criar sequência randomica do Mastermind
char sortear(char * s_correto){
	int x = 0;
	srand((unsigned)time(NULL)); //Seed da rand para deixar os numeros mais aleatorios.

	while( x < 4 ) {			// gerando numeros aleatorios sem repetir
		if ( x == 0 ){
			s_correto [ x ] = ( 1 + ( rand() % 6 ) );	// função rand para gerar nº randomico
			x++;
		}

		if ( x == 1 ) {
			s_correto [ x ] = ( 1 + ( rand() % 6 ) );	// função rand para gerar nº randomico
			if ( s_correto [ x ] != s_correto[ x - 1 ] ){
			       	x++; //Caso diferente do vetor anterior permite que ele continue incrementando
			}
		}

		if ( x == 2 ) {
			s_correto [ x ] = ( 1 + ( rand() % 6 ) );	// função rand para gerar nº randomico

			if ( s_correto [ x ] != s_correto[ x - 2 ] && s_correto[ x ] != s_correto[ x - 1 ] ){
			       	x++;//Caso diferente dos vetores anteriores permite que ele continue incrementando
			}
		}

		if ( x == 3 ) {
			s_correto[ x ] = ( 1 + ( rand() % 6 ) );	// função rand para gerar nº randomico

			if ( s_correto[ x ] != s_correto[ x - 3 ] && s_correto[ x ] != s_correto[ x - 2 ] && s_correto[ x ] != s_correto[ x - 1 ] ){
			       x++;//Caso diferente dos vetores anteriores permite que ele continue incrementando
			}
		}
	}

	for( x = 0; x != 4; x++ ) {		//Laço para trocar o inteiro por um caracter
		if( s_correto[ x ] == 1 ) s_correto[ x ] = 'L';
		if( s_correto[ x ] == 2 ) s_correto[ x ] = 'C';
		if( s_correto[ x ] == 3 ) s_correto[ x ] = 'A';
		if( s_correto[ x ] == 4 ) s_correto[ x ] = 'V';
		if( s_correto[ x ] == 5 ) s_correto[ x ] = 'R';
		if( s_correto[ x ] == 6 ) s_correto[ x ] = 'M';
	}
}

// Função para validação do usuário, se ele poderá ou não jogar
void jogar(){
	char nomeUsuario[15];
	int pode_jogar = 0;

	system("clear");

	printf("***************************************\n");
	printf("*     INFORME O USUÁRIO PARA JOGAR    *\n");
	printf("***************************************\n");

	printf("\nNome de Usuário: ");
	scanf("%s", &nomeUsuario);

	pode_jogar = consulta(nomeUsuario);		// verificando se usuário existe para pode jogar
	
	if (pode_jogar != 1){		// se usuário não existe, não poderá jogar
		sair();					// chama função sair do jogo
	} 

	if (pode_jogar == 1){			// se usuário existe, poderá jogar
		iniciaJogo(nomeUsuario);	// chama função incia jogo
	}
}

// Função que chama arquivo para iniciar Mastermind
void iniciaJogo( char nomeUsuario[20] ){
	system( "clear" );

	printf("***************************************\n");
	printf("*          USUÁRIO CADASTRADO!        *\n");
	printf("***************************************\n");

	printf("\nPressione qualquer tecla para inciar o jogo!");
	getc(stdin);	// zerando buffer
	getc(stdin);

	mastermind_iniciaJogo(nomeUsuario);		// chamada do arquivo para INICIAR MASTERMIND
}

// Função para fazer tratativa de usuário não cadastrado, permite cadastrar ou não novo usuário
void sair(){
	int registrar = 2;		// variavel iniciada em 2 para não cadastrar usuário
	char novoUsuario[20];

	printf("***************************************\n");
	printf("*      USUÁRIO NÃO CADASTRADO!        *\n");
	printf("***************************************\n");

	printf("\nDeseja se cadastrar agora?\n[1] Sim\n[2] Não\n");
	printf("Resposta: ");
	scanf("%d", &registrar);

	if(registrar == 1){		// verifica resposta do usuário, se for 1
		cadastro();			// chama função para cadastrar novo usuário
	}

	exit;
}

int validaLet(char testeLet[20]){
	int i;

	for(i=0; i <= strlen(testeLet); i++){ // Validação para aceitar somente letra neste campo
		if((testeLet[i] >= 'a' && testeLet[i] <= 'z') || (testeLet[i] >= 'A' && testeLet[i] <= 'Z')){
			return 1;	// se identificado somente letras, sai do for e passa para próxima etapa do cadastro
			break;
		}else{
			return 0;	// se identificado != de letras fica no for
			break;
		}
	}
}

int validaNum(char testeNum[2]){
	int i;

	for(i=0; i <= strlen(testeNum); i++){ // Validação para aceitar somente nº neste campo
		if(testeNum[i] >= '0' && testeNum[i] <= '9'){
			return 1;	// se identificado somente nº, sai do for e passa para próxima etapa do cadastro
			break;
		}else{
			return 0;	// se identificado != de nº fica no for
			break;
		}
	}
}
