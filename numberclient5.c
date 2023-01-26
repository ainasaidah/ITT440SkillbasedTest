#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    int random_number;

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("192.168.145.129");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    read(sock, &random_number, sizeof(random_number));
    printf("Random number received: %d\n", random_number);

    close(sock);
    return 0;
}
