#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int socket_desc, new_socket, c;
        struct sockaddr_in server, client;
        char *message;

        //create socket
        socket_desc = socket(AF_INET, SOCK_STREAM,0);
        if(socket_desc == -1)
        {
                printf("Could not create socket");
        }

        //prepare the sockaddr_in structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr=INADDR_ANY;
        server.sin_port=htons(8080);

        //bind
        if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0)
        {
                puts("bind failed");
                return 1;
        }

        puts("bind done");

        //listen
        listen(socket_desc, 3);

        //accept and incoming connection
        puts("Waiting for incoming connections...");
        c=sizeof(struct sockaddr_in);
        while(1)
        {
            new_socket=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
            if (new_socket<0)
            {
                    perror("accept failed");
                    return 1;
            }
            puts("Connection accepted");
            srand(time(0));
            int random_number = rand() % 900 + 100;
            printf("Random number generated: %d\n", random_number);
            write(new_socket, &random_number, sizeof(random_number));
            close(new_socket);
            sleep(1);
        }

    return 0;
}

