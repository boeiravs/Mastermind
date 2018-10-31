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
 * #                             **  Arquivo Princial do Jogo **                                 #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * # Desenvolvido: 01/08/2018         Conclusão: 03/10/2018                   *** versão: 06 *** #
 * #                                                                                             #
 * ###############################################################################################
 * */

/* Chamada das Bibliotecas */
#include <stdio.h>			// Biblioteca com as funções de I/O input/output
#include <stdlib.h>			// Biblioteca com as funções de emulador de prompt de sistema operacional
#include <string.h>	        // Biblioteca que tratam as variaveis e funções de 'string'
#include "mastermind_funcoes.h"		// 'Biblioteca' que inclui as funções no arquivo principal 


/* Programa Principal / Menu Principal Mastermind */
void main(void){
	/* Variaveis locais do algoritimo */
	int opcao=0;
    char usuario[20];

	/* Bloco de código do algoritimo */
    system("clear");
    printf("************************************\n");
    printf("*** BEM-VINDO AO JOGO MASTERMIND ***\n");

	do {
        printf("************************************\n");
        printf("******* MENU MASTERMIND ************\n");
        printf("************************************\n");
        printf("*   1) Cadastrar Jogador           *\n");
        printf("*   2) Consultar Jogador           *\n");
        printf("*   3) Jogar                       *\n");
        printf("*   4) Estatísticas dos Jogadores  *\n");
        printf("*   5) Sair                        *\n");
        printf("************************************\n");
        printf("**  Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("************************************\n");

		switch(opcao){
            case 1:
                system("clear");
                printf("    1) Cadastrar Jogador\n");
                cadastro();
            break;
            case 2:
                system("clear");
                printf("    2) Consultar Jogador\n");
                printf("Digite o nome do usuário a ser pesquisado: ");
                scanf("%s", &usuario);
                consulta(usuario);
            break;
            case 3:
                system("clear");
                printf("    3) Jogar\n");
                jogar();
            break;
            case 4:
                system("clear");
                printf("    4) Estatísticas dos Jogadores\n");
                estatistica();
            break;
            case 5:
                printf("    5) Saindo do Mastermind...\n    Até breve! ;)\n");
                exit;
            break;
            default:
                printf("    Erro. Opção Inválida!\n");
            break;
		}
        printf("\n");

	} while(opcao > 0 && opcao < 5);

}
