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

int main(int argc, char *argv[])
{
    int port;
    struct sockaddr_in server_addr;
    struct my_msg wiadomosc;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s ip\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("[Klient] Adres: %s\n", argv[1]);
    printf("Podaj port: ");
    scanf("%d", &port);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(argv[1], &server_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Podaj wiadomosc: ");
    while(getchar() != '\n'); 
    fgets(wiadomosc.text, 255, stdin);
    wiadomosc.text[strlen(wiadomosc.text)-1] ='\0';  

    printf("Podaj 2 znaki: ");
    
    scanf("%c %c", &wiadomosc.a, &wiadomosc.b);

    int bytes = write(sockfd, &wiadomosc, sizeof(wiadomosc));
    printf("[Klient]: Wyslano %i bajtow do serwera.\n", bytes);
    printf("Czekam na wiadomosc od servera...\n");

    int ile;
    int bytes2 = read(sockfd, &ile, sizeof(ile));
    printf("Liczba wystapien: %i\n", ile);




    close(sockfd);
    return 0;

}