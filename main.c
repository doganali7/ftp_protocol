
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

    struct sockaddr_in new_address, server_addreadss;
    socklen_t address_size;
    char buffer[DEFAULT_BUFFER_SIZE];

    socket_holder = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_holder < 0){
        perror("[-]Error");
        exit(1);
    }
    printf("[+]Server created");
}