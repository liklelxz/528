// Server side implementation of UDP client-server model 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>


#define PORT     8080 
#define MAXLINE 1024 

// Driver code 
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char pong[] = "pong from server";
    struct sockaddr_in servaddr, cliaddr; 

    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 

    // Bind the socket with the server address 
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	
	srand(time(0));
    int n; 
    socklen_t len;
    
    while(1){
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL,(struct sockaddr *) &cliaddr, &len);
		
		buffer[n] = '\0'; 
		/*printf("Client : %s\n", buffer); */
		std::cout<<buffer<<std::endl;
		if(rand()%10<4){
			continue;
		}
		sendto(sockfd, (const char *)pong, strlen(pong), MSG_CONFIRM, (const struct sockaddr *) &cliaddr,len); 
		/*printf("Hello message sent.\n");*/ 
	}
    return 0; 
} 
