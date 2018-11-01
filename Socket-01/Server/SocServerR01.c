// fonte: https://www.vivaolinux.com.br/script/Exemplo-de-sockets-um-client-e-um-server-bem-simples
// Exemplo de código 
/* Server */

//headers que são utilizados pelo socket
#include <sys/socket.h> 
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>


//header padrão para o desenvolvimento de um código
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


main()
{
   //Declarações de variáveis
   int cont,create_socket,new_socket,addrlen; 
   // Declaração das variáveis para utilização no código
   // importante salientar que o socket retorna um valor inteiro permitindo o tratamento de erro

   int bufsize = 1024; 
   // Definição do tamanho do buffer

   char *buffer = malloc(bufsize); 
   //Alocação de espaço na memória de acordo com o tamanho do buffer e carregando o ponteiro
   //comando Malloc http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

   struct sockaddr_in address; 
   // Estrutura do socket resp. por fornecer informações sobre a família, endereço IP, porta 
   
   printf("\x1B[2J"); // Formatação da tela de comando... inferior a direita

   if ((create_socket = socket(AF_INET,SOCK_STREAM,0)) > 0)
     printf("The socket was created\n");
   // Criação do socket dados por socket(AF_INET,SOCK_STREAM,0)) > 0), onde socket(); é definida no sys/socket.h
   // create_socket recebe a criação do socket e o retorno é um valor inteiro, possibilitando teste condicional 
   // Caso seja maior que ZERO o socket foi criado com sucesso. Verificar o estatus de '0', '-1' conforme MAN
   //  socket(AF_INET,SOCK_STREAM,0)) > 0) é definido logo abaixo:
   //  int socket(int familia, int tipo, int protocolo);
   /* familia:
      representa a familia do socket - como havia dito, usaremos a famàlia internet: AF_INET
      AF_INET6 > IPv6
      AF_LOCAL > Comunicação local

      tipo:
      tipo de socket a ser utilizado: SOCK_STREAM (TCP) ou SOCK_DGRAM (UDP);

     protocolo:
     é um argumento opcional que define o protocolo que deverá ser usado com o socket especificado. 
     Se passado como ZERO, o protocolo padrão para o tipo do socket especificado será utilizado.

    A função retorna um valor inteiro (o descritor de socket) caso o socket seja criado com sucesso.
    Do contrírio, o valor retornado é -1.
   */



   // Estrutura sockaddr_in (addr) permitindo atuação do socket no modo servidor
   address.sin_family = AF_INET;
   // Família no qual o socket pertence

   address.sin_addr.s_addr = INADDR_ANY;
   // Endereço ZERO, pois a conexão do servidor pode vir de qualquer IP
   // INADDR_ANY significa endereço local padrão

   address.sin_port = htons(15000);
   // Definição da porta no qual o socket vai escutar... aqui mora o perigo :-)
   // importante a definição de htons e seus co-irmãos em função do modo como os computadores armazenam as informações
   // Big-Endian (o byte mais significativo primeiro) e Little-Endian (o byte menos significativos primeiro)
   // Exemplo: endereço HEX 4B5F, Big-Endian (4B > 5F) e Little-Endian ( 5F > 4B)
   // Big-Endian é também chamado de Network Byte Order, porque é a forma como os dados devemser transmitidos em rede
   // Porém o PC aramazema em Host Byte Order, ou seja Little-Endian), existe ainda:
   // htons() host to network short
   // htonl() host to network short
   // ntohs() network to host short
   // ntohl() network to host long
   // Ah... logo temos htons() host to network short e a definição da porta, que no caso é 15000
   // As vezes é necessário acrescentar :
   // memset(&addr.sin_zero,0,sizeof(addr.sin_zero)); /* Preenche o restante da estrutura com ZEROS */
   


   if (bind(create_socket,(struct sockaddr *)&address,sizeof(address)) == 0)
     printf("Binding Socket\n");
   // Como explicado em aula sempre é necessário fazer o teste com a criação das funções resposáveis pela
   // via socket, neste caso a função bind também deve ter um teste condicional se foi realizado com sucesso
   // Vale ressaltar que a função bind() é responsável por associar um endereço e porta locais ao socket.
   // Associando a porta do exemplo, 15000, e o endereço local ao socket
   // create_socket é o descritor do socket
   // (struct sockaddr *)&address  utilizado para conversão da estrutura de sockaddr_in para sockaddr
   //    &address é o endereço da memória da estutura e deve ser passado como valor para o ponteiro
   //    (struct sockaddr *)&address converte a estrutura para sockaddr e passa o endereço de memória 
   // sizeof(address) retorna em byte o tamanho da estrutura

   listen(create_socket,3);
   // A função listen declara que está pronto para receber conexões e até quantas devem ser enfileiradas
   // ret = int listen  (int create_socket, int backlog)
   // create_socket é o descritor 
   // backlog define o número máximo de conexões pendentes




   addrlen = sizeof(struct sockaddr_in);
   // A variável addrlen recebe o tamanho da estrutura

   new_socket = accept(create_socket,(struct sockaddr *)&address,&addrlen);
   // Responsável por aceitar a conexão com o cliente
   // Lembrar do handshake e verificação do status do socket via netstat -aut (todas as conexões) TCP e UDP

   if (new_socket > 0){
      printf("The Client %s is connected...\n",inet_ntoa(address.sin_addr));
      for(cont=1;cont<5000;cont++)
   printf("\x7");
   }
   // A função Accept será definida pela variável inteira NEW_Socket e em seguida é realizado a condicional
   // inet_ntoa conversão de um string de/para um endereço
   /*SYNOPSIS
       #include <sys/socket.h>

       #include <netinet/in.h>
       #include <arpa/inet.h>

        The inet_ntoa() function converts the Internet host address in, given in network byte order, to  a  string 
      in  IPv4 dotted-decimal notation.  The string is returned in a statically allocated buffer, which subsequent 
      calls will over‐write.

      */



   do{
      /*
      printf("Message to send: ");
      gets(buffer); // Lembrar do gets utilizado na leitura de arquivos


      send(new_socket,buffer,bufsize,0);
      // int send(int socket, const void * dados, int tamanho , int flags); 
      /* socket:
         descritor do socket;
         dados:
         dados a serem enviados. Pode-se passar uma string ou variável como valor;
         tamanho:
         número de bytes a serem enviados;
         flags:
         valores opcionais normalmente passados como ZERO.

         A função send(), como a maioria das funções relacionadas a sockets, também retorna -1 se algum erro
      ocorrer ao tentar enviar os dados. Se a função for bem sucedida, ela retornarí o número de bytes enviados.
      *//*

      recv(new_socket,buffer,bufsize,0);
      //Idem a função send()

      printf("Message recieved: %s\n",buffer);
      // Interação com o usuário - imprimindo na tela a mensagem recebida do cliente (remoto)
      */
      recv(new_socket,buffer,bufsize,0);
      //Idem a função send()

      printf("Message recieved: %s\n",buffer);
      // Interação com o usuário - imprimindo na tela a mensagem recebida do cliente (remoto)
      
      if (strcmp(buffer,"/q")){
        printf("Message to send: ");
        gets(buffer); // Lembrar do gets utilizado na leitura de arquivos
        send(new_socket,buffer,bufsize,0);
        // int send(int socket, const void * dados, int tamanho , int flags); 
        /* socket:
          descritor do socket;
          dados:
          dados a serem enviados. Pode-se passar uma string ou variável como valor;
          tamanho:
          número de bytes a serem enviados;
          flags:
          valores opcionais normalmente passados como ZERO.

          A função send(), como a maioria das funções relacionadas a sockets, também retorna -1 se algum erro
        ocorrer ao tentar enviar os dados. Se a função for bem sucedida, ela retornarí o número de bytes enviados.
        */
      }


   }while(strcmp(buffer,"/q")); //user ‘q’ to quit
   // laço de controle/repetição usando a comparação de strings "Qualquer valor digitado" com "\q" 
   /* Explicação/uso do comando strcmp
      Sintaxe: variável do tipo inteiro = strcmp(string1, string2);
      Compara o conteúdo de duas strings;
      Possíveis valores de retorno:
        0: conteúdo das strings são iguais
      < 0: conteúdo da string1 é menor do que string2
      > 0: conteúdo da string1 é maior do que string2
  */

   close(new_socket);
   // Encerramento da variável "new_socket" atribuida com o handshake do accept

   close(create_socket);
   // Encerramento do socket criado no início do programa


} // Chave final do main


