#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include<time.h>


long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100];

char msg[100];
 
int main()
{

  	int clientSocket,len;

  	char buffer[1024],message[1024];

  
	long int pt,ct,key=d[0],k,i; 

	i=0; 

    	double cpu_time_used ,end,start;

  	struct sockaddr_in serverAddr;

  	socklen_t addr_size;


 
 	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
 


  	serverAddr.sin_family = AF_INET;

 
 	serverAddr.sin_port = htons(7891);

 
 	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

 
 	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
  


  	addr_size = sizeof serverAddr;
 
 	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);


  	recv(clientSocket, en, 1024, 0);

 
 	start=clock();


	while(en[i]!=-1)
 	
{ 
  
  		ct=temp[i];
 
   		k=1; 
 
  		for(j=0;j<key;j++) 

    		{ 
       
 	 		k=k*ct; 
  
      			k=k%n; 

    		} 
  
 		pt=k+96; 

    		m[i]=pt;
 
    		i++;
 
	} 

	m[i]=-1;
 
	printf("\nTHE DECRYPTED MESSAGE IS\n");
 
	for(i=0;m[i]!=-1;i++)
	{
 		
printf("%c",m[i]);
 
	} 

	end=clock();

	cpu_time_used=((double) (end - start)) / CLOCKS_PER_SEC;

  	printf("%f",cpu_time_used);

  
  	return 0;

}
