#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <cstdio>
#include <sys/time.h> 

#define PORT     8080 
#define MAXLINE 1024 

// Driver code 
int main() { 
    int sockfd; 
    double t1,t2;
    struct timeval start,end;
    char buffer[MAXLINE]; 
    char ping[] = "ping from client"; 
    struct sockaddr_in   servaddr; 

    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        //perror("socket creation failed");
        std::cout<<"SASD"<<std::endl; 
        exit(EXIT_FAILURE); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 

    int n; 
    socklen_t len;
	for(int i = 0;i<10;i++){
		
	
		sendto(sockfd, (const char *)ping, strlen(ping), 
		    MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
		        sizeof(servaddr));
		//printf("Hello message sent.\n");
		if(gettimeofday(&start,NULL)){
			std::cout<<"start fail"<<std::endl;
			exit(1);
		} 
		std::cout<<"send ping to server"<<std::endl;
		sleep(0.5);
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
		if(n < 0){
			std::cout<<"package loss"<<std::endl;
			continue;
		}
		else{
			buffer[n] = '\0';
			std::cout<<buffer<<std::endl;
			std::cout<<"receive package"<<std::endl;
		}
		if(gettimeofday(&end,NULL)){
			std::cout<<"end fail"<<std::endl;
			exit(1);
		}   
		//printf("Server : %s\n", buffer);
		t1+=start.tv_sec+(start.tv_usec/100000.0);
		t2+=end.tv_sec+(end.tv_usec/100000.0);
		float rtt = t2-t1;
		std::cout<<rtt<<std::endl;
		
		}
		
		std::cout<<"transmission end"<<std::endl;
		close(sockfd); 
    return 0; 
} 
