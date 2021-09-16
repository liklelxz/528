#include <iostream> 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>


#define PORT     17777
#define MAXLINE 1024 
int main() { 
    int sockfd,read_fd1;
    char Alice[] = "Client X: Alice";
    char buffer2[MAXLINE]; 
    char pong[] = "pong from server";
    struct sockaddr_in servaddr; 
	int len = sizeof(servaddr);
		
    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr)); 
    //memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 

    connect(sockfd,(struct sockaddr *)&servaddr, len);
    
    send(sockfd, Alice,strlen(Alice),0);
    
    read_fd1 = read(sockfd,buffer2,1024);
    std::cout<<"Message: "<<Alice<<" has been sent to server!"<<std::endl;
    std::cout<<"Reply from server: "<<buffer2<<std::endl;
    
    
    
}
