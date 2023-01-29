#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include<sys/wait.h>

struct my_msg{
    char text [255];
    char a;
    char b;

};
int sockfd;
int opcje = 0;

void sigint_handler(int signo)
{
    printf("Odebrano sygnal SIGINT\n");
    close(sockfd);
    exit(EXIT_SUCCESS);
}

void sigusr_1(int signum)
{
    printf("Wlaczam opcje\n");
    opcje = 1;
}
void sigusr_2(int signum)
{
    printf("Wylaczam opcje\n");
    opcje = 0;
}

int ile_wystepuja(char a, char b, char napis[])
{
    int i = 0;
    int ile = 0;
    while(napis[i] != '\0')
    {
        if(napis[i] == a || napis[i] == b)
        {
            ile++;
        }
        i++;
    }
    return ile;
}
void aborto(int sig)
{
	int status;
	pid_t pid;

	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		printf("Child process with PID %d terminated.\n", pid);
	}
} 

int main(int argc, char *argv[])
{
    signal(SIGINT, sigint_handler);
    signal(SIGUSR1,sigusr_1 );
    signal(SIGUSR2,sigusr_2 );
    signal(SIGCHLD, abort);
    int port;
    struct sockaddr_in server_addr, client_addr;
    struct my_msg wiadomosc;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (atoi(argv[1]) < 1501 || atoi(argv[1]) > 2501) {
        fprintf(stderr, "Zly port\n");
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);
    port = port * 4;
    printf("[SERWER] Port: %d\n", port);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (sockfd == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    listen(sockfd ,5);

    unsigned int client_addr_len;
    while(1)
    {
        int cl_len = sizeof(client_addr);
        printf("[SERWER]: Czekam na polaczenie..\n ");
        int client_sockfd = accept(sockfd,  (struct sockaddr *)&client_addr, &cl_len);
        printf("Polaczona z %s : %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        int pid = fork();
        if (pid == 0)
        {
            close(sockfd);
            while(1)
            {
                int bytes = read(client_sockfd, &wiadomosc, sizeof(wiadomosc));
                if (bytes == -1) {
                    perror("recvfrom");
                    exit(EXIT_FAILURE);
                }
                if (strcmp(wiadomosc.text, "koniec") == 0)
                {
                    printf("[SERWER] Koniec polaczenia.\n");
                    break;
                }
                if (opcje == 1)
                {
                    printf("[SERWER] Odebrano %zu b od %s:%d - %s znaki: %c %c \n", sizeof(wiadomosc), inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), wiadomosc.text, wiadomosc.a, wiadomosc.b);
                }
                else
                {
                    printf("[SERWER] Odebrano %zu b - %s znaki: %c %c \n", bytes, wiadomosc.text, wiadomosc.a, wiadomosc.b);
                }
                
                int ile = ile_wystepuja(wiadomosc.a, wiadomosc.b, wiadomosc.text);
                printf("[SERWER] Ilosc wystapien: %d\n", ile);
                //wyslanie do klienta
                int bytes2 = write(client_sockfd, &ile, sizeof(ile));
                if (bytes2>0)
                {
                    printf("Przeslano do klienta...\n");
                }
            }
            close(client_sockfd);
            exit(0);
        }
        else{
            close(client_sockfd);
        }

        
    } 


    return 0;


}