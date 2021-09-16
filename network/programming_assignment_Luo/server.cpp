// Server side implementation of UDP client-server model 
#include <iostream> 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <cstring>


#define PORT     17777
#define MAXLINE 1024 

// Driver code 
int main() { 
    int sockfd, newfd_1, read_fd1,newfd_2,read_fd2; 
    char buffer1[MAXLINE];
    char buffer2[MAXLINE];
    char Alice[] = "X: Alice received before Y:Bob";
    char Bob[] = "Y: Bob received before X: Alice";
    char check[] = "Alice";
    struct sockaddr_in servaddr, cliaddr; 
	int addrlen = sizeof(servaddr);
		
    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 

    // Bind the socket with the server address 
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	
	
	if(listen(sockfd,2)<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	if((newfd_1 = accept(sockfd,(struct sockaddr *)&servaddr, (socklen_t*)&addrlen))<0){
		perror("accept");
		exit(EXIT_FAILURE);
	}

    read_fd1 = read(newfd_1, buffer1, 1024);
    char *output = NULL;
	output = strstr(buffer1,check);
    int n; 
	std::cout<<buffer1<<std::endl;
	if(listen(sockfd,2)<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if((newfd_2 = accept(sockfd,(struct sockaddr *)&servaddr, (socklen_t*)&addrlen))<0){
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	read_fd2 = read(newfd_2, buffer2, 1024);
	std::cout<<buffer2<<std::endl;
	
	
	if(output){
		send(newfd_1, Alice,strlen(Alice),0);
		send(newfd_2, Alice, strlen(Alice),0);
	}
	else{
		send(newfd_1, Bob,strlen(Bob),0);
		send(newfd_2, Bob, strlen(Bob),0);
	}
	std::cout<<"Sent acknowledgement to both X and Y"<<std::endl;
	
    return 0; 
}
















