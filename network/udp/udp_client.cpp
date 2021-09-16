#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>


#define PORT	 8080

int main() {
	int sockfd, n;
	char buffer[1024];
	socklen_t len;
	char ping[]="ping from client";
	struct sockaddr_in servaddr;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	memset(&servaddr, 0 , sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);


		sendto(sockfd, (const char *)ping, strlen(ping), 
			MSG_CONFIRM, (const struct sockaddr *) &servaddr, len);
		recvfrom(sockfd, (char *)buffer, sizeof(buffer), 
			MSG_WAITALL, ( struct sockaddr *) &servaddr, &len);
			std::cout<<"receive from server"<<buffer<<std::endl;
	
}	

