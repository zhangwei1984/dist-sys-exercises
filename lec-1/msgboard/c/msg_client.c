// CS 6421 - Simple Message Board Client in C
// Authors: Chenghu He and Wei Zhang
// Compile with: gcc msg_client -o msg_client
// Run with:     ./msg_client

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>

#define MAX_LINE 128

int main(int argc, char ** argv)
{

    int opt;
    char* server_port = "5555";
    char* server_ip;
	
	// your code here!
	char* name;
	char* msg;
	char buf[MAX_LINE];
	struct addrinfo hints, *server;
	int sockfd;
	int ret;

	//parse command line
    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname name msg\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    name = argv[2];
    msg = argv[3];


    memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	//get an addrinfo struct for the host you want to connect to	
	if (ret = getaddrinfo(server_ip, server_port, &hints, &server) != 0) {
		perror(gai_strerror(ret));
		exit(-1);
	}

	//create the socket
	sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
	if (sockfd == -1) {
		perror("ERROR open socket");
		exit(-1);
	}

	//connect to the server
	ret = connect(sockfd, server->ai_addr, server->ai_addrlen);
	if (ret == -1) {
		perror("ERROR on connect");
		close(sockfd);
		exit(-1);
	}

	printf("name:%s\n", name);
	printf("msg:%s\n", msg);

	//construct the message according to the client-server protocol
	snprintf(buf, sizeof(buf) - 1, "%s\n%s\n", name, msg);	
	//send the message to the server
	send(sockfd, buf, strlen(buf), 0);

    close(sockfd);

    printf("Done.\n");
    return 0;
}
