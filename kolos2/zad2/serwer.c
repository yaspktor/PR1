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


struct my_msg{
    char text [255];
    char a;
    char b;

};
int sockfd;

void sigint_handler(int signo)
{
    printf("Odebrano sygnal SIGINT\n");
    close(sockfd);
    exit(EXIT_SUCCESS);
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


int main(int argc, char *argv[])
{
    signal(SIGINT, sigint_handler);
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
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (sockfd == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    unsigned int client_addr_len;
    while(1)
    {
        
        int bytes = recvfrom(sockfd, &wiadomosc, sizeof(wiadomosc), 0, (struct sockaddr *)&client_addr, &client_addr_len);
        if (bytes == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        printf("[SERWER] Odebrano %zu b od %s:%d - %s znaki: %c %c \n", sizeof(wiadomosc), inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), wiadomosc.text, wiadomosc.a, wiadomosc.b);
        int ile = ile_wystepuja(wiadomosc.a, wiadomosc.b, wiadomosc.text);
        printf("[SERWER] Ilosc wystapien: %d\n", ile);
        //wyslanie do klienta
        int bytes2 = sendto(sockfd, &ile, sizeof(ile), 0, ((struct sockaddr *)&client_addr), sizeof(server_addr));
        if (bytes2>0)
        {
            printf("Przeslano do klienta...\n");
        }
    }


    close(sockfd);


}