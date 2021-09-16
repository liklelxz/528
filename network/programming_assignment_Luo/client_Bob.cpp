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
    char Bob[] = "Client Y: Bob";
    char buffer1[MAXLINE]; 
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
    
    send(sockfd, Bob,strlen(Bob),0);
    
    
    read_fd1 = read(sockfd,buffer1,1024);
    std::cout<<"Message: "<<Bob<<" has been sent to the server!"<<std::endl;
    std::cout<<"Reply from server: "<<buffer1<<std::endl;
    
    
    
}
