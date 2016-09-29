#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include<time.h>


int main()
{
 
	int clientSocket,i,len,k;
 
 	char buffer[1024],cipher[1024];
  
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

 
 	recv(clientSocket, cipher, 1024, 0);

 
 	start=clock();

 
   	for (int i=0; i < num; i++)
 
   	{
	       
 		if (cipher[i] >= 'A' && cipher[i] <= 'Z')

	        {
          
  			cipher[i] = (char)(((cipher[i] - shift - 'A' + 26) % 26) + 'A');

	        }
	      
  		else if (cipher[i] >= 'a' && cipher[i] <= 'z')
     
   		{
	          
  			cipher[i] = (char)(((cipher[i] - shift - 'a' + 26) % 26) + 'a');

	        }
	
    	}  
	        
   	printf("Your decrypted text is: %s\n",cipher);

	end=clock();
cpu_time_used=((double) (end - start)) / CLOCKS_PER_SEC;
 
 	printf("%f",cpu_time_used);
  

  return 0;

}
