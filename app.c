#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512

int main(){
    char *ip_address = "127.0.0.1";
    int port = 8080;
    int k;

    int socket_holder;
    struct sockaddr_in server_address;
    FILE *file_pointer;
    char *file_name;

}