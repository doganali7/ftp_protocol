#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include<unistd.h>

#define DEFAULT_BUFFER_SIZE 512
#define PORT 8080


bool passwordFound(char *password_file_name, char *password)
{
    long fl_size;
    char *buffer;
    size_t res;
    FILE *password_file = fopen(password_file_name, "r");
    if (password_file == NULL)
    {
        fprintf(stderr, "Password File error\n");
        exit(1);
    }
    fseek(password_file, 0, SEEK_END);
    fl_size = ftell(password_file);
    rewind(password_file);

    buffer = (char *)malloc(sizeof(char) * fl_size);

    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        exit(2);
    }

    res = fread(buffer, 1, fl_size, password_file);
    if (res != fl_size)
    {
        fputs("Reading error", stderr);
        exit(3);
    }

    char *strtok_res;
    strtok_res = strtok(buffer, ":");
    while (strtok_res != NULL)
    {
        printf("%s\n", strtok_res);
        if (strcmp(password, strtok_res) == 0)
        {
            return true;
        }
        strtok_res = strtok(NULL, ":");
    }
    /*
     * DONE!
     */

    fclose(password_file);
    free(buffer);

    return false;
}

int main(int argc, char *argv[])
{
    char *directory, *port_string, *password;
    int port;
    if (argc != 7)
    {
        perror("Enter the correct arguments");
        exit(1);
    }
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0)
        {
            directory = argv[i + 1];
        }
        if (strcmp(argv[i], "-p") == 0)
        {
            port_string = argv[i + 1];
            port = atoi(port_string);
        }
        if (strcmp(argv[i], "-u") == 0)
        {
            password = argv[i + 1];
        }
    }

    if (passwordFound("password.txt", password) == false)
    {
        perror("Password incorrect");
        return 1;
    }

    char *default_ip_addr = "127.0.0.1";
    int bind_result, socket_holder, new_socket;
    int bind_result, socket_holder, new_socket, n;

    struct sockaddr_in new_address, server_address;
    socklen_t address_size;
    char buffer[DEFAULT_BUFFER_SIZE];

    socket_holder = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_holder < 0){
    if (socket_holder < 0)
    {
        perror("[-]Error");
        exit(1);
        return 1;
    }
    printf("[+]Server created\n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = PORT;
    server_address.sin_port = port;
    server_address.sin_addr.s_addr = inet_addr(default_ip_addr);

    bind_result = bind(socket_holder, (struct sockaddr*)&server_address, sizeof(server_address));
    if(bind_result < 0){
        bind_result = bind(socket_holder, (struct sockaddr *)&server_address, sizeof(server_address));
        if (bind_result < 0)
        {
            perror("[ - ]Error binding\n");
            exit(1);
            return 1;
        }

        printf("[+]Binding done\n");

        bind_result = listen(socket_holder, 10);
        if (bind_result == 0)
        {
            printf("[+]File server listening on localhost port %i\n", port);
        }
        else
        {
            perror("[-]Error");
            return 1;
        }

        address_size = sizeof(new_address);
        new_socket = accept(socket_holder, (struct sockaddr *)&new_address, &address_size);

        if (new_socket < 0)
        {
            perror("Can't accept");
            return 1;
        }
        write(new_socket, "Welcome to the server", 22);
        while ((n = recv(new_socket, buffer, 2000, 0)) > 0)
        {
            buffer[n] = '\0';
            printf("SERVER GOT MESSAGE: %s\n", buffer);
        }
    } 
    }