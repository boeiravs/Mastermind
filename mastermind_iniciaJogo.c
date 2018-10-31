/*
 * ###############################################################################################
 * #                                                                                             #
 * # Matricula:    201110924                                 Universit�rio: V. Boeira            #
 * # Matricula:    200510633                                 Universit�rio: J. J�nior            #
 * # Professor(a): Mauricio Beraldin Barreto                                                     #
 * # Disciplina:   Desenvolvimento de Redes de Computadores  Sala:          306-1 (quarta-feira) #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * #                             C�DIGO EM "C" Projeto Mastermind                                #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * #                           **  Arquivo da Fun��o Inicia Jogo **                              #
 * #                                                                                             #
 * ###############################################################################################
 * #                                                                                             #
 * # Desenvolvido: 01/08/2018         Conclusão: 03/10/2018                   *** versão: 06 *** #
 * #                                                                                             #
 * ###############################################################################################
 * */

/* 'Biblioteca' que inclui as fun��es no arquivo principal */
#include "mastermind_funcoes.h"

int mastermind_iniciaJogo(char nomeUsuario[20]){
    int coluna=0, linha=0, ganhar=0, jogada=0, linha2=0, coluna2=0, j_aux=0, dica=0;
    char respostas[4];      // vetor com as respostas corretas
    char opcao;
    char jogo[10][8];       // matriz principal do Mastermind

    FILE *db;
	char *pontuacao = "pontuacao.txt";

    sortear(&respostas[0]);     // chamada de função para criar sequência randomica

    for(linha2 = 0; linha2 != 10; linha2++){        // for para preencher os campos em branco
        for(coluna2 = 0; coluna2 != 8; coluna2 ++){

            if (coluna2 <= 3){
                jogo[linha2][coluna2] = ' ';
            }else{
                jogo[linha2][coluna2] = ' ';
            }

        }
    }

    for(jogada = 0; jogada < 10; jogada++){         // for para percorrer as linhas da matriz (até encerrar 10 jogadas)
        for(dica = 0; dica < 4; dica++){            // for para percorrer as colunas da matriz
            system("clear" );
            printf("\n******************************************************");
            printf("\n*                      MASTERMIND                    *");
            printf("\n******************************************************");
            printf("\n*       JOGADAS             *         DICAS          *");
            printf("\n******************************************************");
            printf("\n*                           *                        *");

            for(linha = 0; linha != 10; linha++) {          // for para imprimir linhas organizadas
                printf("\n");
                printf("* %i", linha + 1);

                for(coluna = 0; coluna != 8; coluna++) {    // for para imprimir colunas organizadas
                    if(linha == 9){                         // ifs abaixo para imprimir matriz organizada
                        if(coluna == 7)
                            printf(" [%c]  *", jogo[linha][coluna]);
                        if(coluna == 4)
                            printf("    *    [%c] ", jogo[linha][coluna]);
                        if(coluna != 4 && coluna != 7)
                            printf(" [%c] ", jogo[linha][coluna]);
                    }else{
                        if(coluna == 7)
                            printf("  [%c]  *", jogo[linha][coluna]);
                        if(coluna == 4)
                            printf("     *    [%c]", jogo[linha][coluna]);
                        if(coluna != 4 && coluna != 7)
                            printf("  [%c]", jogo[linha][coluna]);
                    }
                }
            }

            printf("\n******************************************************");
            printf("\n\nLEGENDA RESP DICAS:\n");
            printf("[P] = Cor Correta na Casa Correta\n");
            printf("[B] = Cor Correta na Casa Incorreta\n");
            printf("[ ] = Cor Incorreta\n");
            printf("\n\nEscolha 4 cores de acordo com as opções abaixo:" );
            printf("\n   L= Laranja\n   C= Cinza\n   A= Azul\n   V= Vermelho\n   R= Roxo\n   M= Marrom\n" );
            printf("******************************************************\n");

            // while para validar opção digitada pelo usuário
            // certificando que somente as letras corretas foram verificadas
            while(      
                    jogo[jogada ][ dica ] != 'L' &&
                    jogo[ jogada ][ dica ] != 'C' &&
                    jogo[ jogada ][ dica ] != 'A' &&
                    jogo[ jogada ][ dica ] != 'V' &&
                    jogo[ jogada ][ dica ] != 'R' &&
                    jogo[ jogada ][ dica ] != 'M'
            ){
                fflush(stdin);
                printf("******************************************************\n");
                printf("***     JOGADOR: %s     ***   Jogada: %i\n", nomeUsuario, jogada+1);
                printf("******************************************************\n");
                printf("Por favor, digite apenas cores disponiveis: ");
                scanf("%s", &opcao);

                fflush(stdin);

                opcao = toupper(opcao); // se usuário digitar letra minuscula essa função para converte em maiuscula

                if(
                    opcao == 'L' ||
                    opcao == 'C' ||
                    opcao == 'A' ||
                    opcao == 'V' ||
                    opcao == 'R' ||
                    opcao == 'M'
                )
                    jogo[jogada][dica] = opcao;

                opcao = ' ';
                fflush(stdin); //

            }

            for(coluna = 0; coluna != 4; coluna++) {    // for para preenchimento das dicas
                if(coluna == 0) {                       // atribuindo a 1º escolha em cada casa
                    if(jogo[jogada][coluna] == respostas[0]) jogo[jogada][coluna + 4] = 'P';
                    if(jogo[jogada][coluna] == respostas[1]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[2]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[3]) jogo[jogada][coluna + 4] = 'B';
                }

                if(coluna == 1) {                   // atribuindo a 2º escolha em cada casa
                    if(jogo[jogada][coluna] == respostas[0]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[1]) jogo[jogada][coluna + 4] = 'P';
                    if(jogo[jogada][coluna] == respostas[2]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[3]) jogo[jogada][coluna + 4] = 'B';
                }

                if(coluna == 2) {                   // atribuindo a 3º escolha em cada casa
                    if(jogo[jogada][coluna] == respostas[0]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[1]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[2]) jogo[jogada][coluna + 4] = 'P';
                    if(jogo[jogada][coluna] == respostas[3]) jogo[jogada][coluna + 4] = 'B';
                }

                if(coluna == 3) {                   // atribuindo a 4º escolha em cada casa
                    if(jogo[jogada][coluna] == respostas[0]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[1]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[2]) jogo[jogada][coluna + 4] = 'B';
                    if(jogo[jogada][coluna] == respostas[3]) jogo[jogada][coluna + 4] = 'P';
                }
            }
        }

        // if para verificar se usuário ganhou
        if(
            jogo[jogada][4] == 'P' &&
            jogo[jogada][5] == 'P' &&
            jogo[jogada][6] == 'P' &&
            jogo[jogada][7] == 'P'
        ){
            system("clear");

            if((db = fopen(pontuacao, "a+t" )) == NULL) {       // verificando se arquivo existe
		        printf("*************************************************\n");
                printf("*	Arquivo não pode ser aberto ou não existe!	*\n");
		        printf("*************************************************\n");
                exit(1);
            }

            fseek(db, 0L, SEEK_END);
            fprintf(db, "   %s  :   %d   :   "__DATE__"  :   "__TIME__"\n", nomeUsuario, jogada+1);   // insere resultado do usuário no pontuacao.txt
            fclose(db);
            system("clear");

            printf( "************************************\n");
            printf( "***    PARABÉNS! VOCÊ VENCEU!\n");
            printf( "***    Usuário: %s\n", nomeUsuario);
            printf( "***    Pontução: %i\n", jogada+1);
            printf( "************************************\n");

            ganhar = 1;
            return jogada;
            jogada = 10;
        }

    }

    if( ganhar == 0 ) {         // se o jogador não acertar nas 10 jogadas, irá exibir a mensagem de game over abaixo
        system("clear");

        printf( "************************************\n");
        printf( "***    QUE PENA! VOCÊ PERDEU!\n");
        printf( "***    Usuário: %s\n", nomeUsuario);
        printf( "************************************\n");

        system("sleep 2");
        system("clear");
        return 11;
    }
}
