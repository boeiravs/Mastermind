all: mastermind

mastermind: mastermind_principal.o mastermind_funcoes.o  mastermind_iniciaJogo.o 
	gcc mastermind_principal.o mastermind_funcoes.o  mastermind_iniciaJogo.o -o mastermind

mastermind_principal.o: mastermind_principal.c
	gcc -c mastermind_principal.c
mastermind_funcoes.o: mastermind_funcoes.c
	gcc -c mastermind_funcoes.c
mastermind_iniciaJogo.o: mastermind_iniciaJogo.c
	gcc -c mastermind_iniciaJogo.c

clean:
	rm *.o
