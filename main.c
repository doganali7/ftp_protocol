
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define DEFAULT_BUFFER_SIZE 512
#define PORT 8080

int main()
{ 
    char *default_ip_addr = "127.0.0.1";
    int k, socket_holder, new_socket;
    int bind_result, socket_holder, new_socket;

    struct sockaddr_in new_address, server_addreadss;
    struct sockaddr_in new_address, server_address;
    socklen_t address_size;
    char buffer[DEFAULT_BUFFER_SIZE];
    if(socket_holder < 0){
        perror("[-]Error");
        exit(1);
    }
    printf("[+]Server created");
    printf("[+]Server created\n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = PORT;
    server_address.sin_addr.s_addr = inet_addr(default_ip_addr);

    bind_result = bind(socket_holder, (struct sockaddr*)&server_address, sizeof(server_address));
    if(bind_result < 0){
        perror("[ - ]Error binding\n");
        exit(1);
    }

    printf("[+]Binding done\n");

}