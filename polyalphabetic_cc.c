#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include<time.h>


int main()
{

  	int clientSocket,i,len,k;

  	char buffer[1024],message[1024];
 
   	int i,j=0;

        int tmp1,tmp2;
        int dtln,kln,sum;
        char data[100],key[100],decipher[100];

 
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

 
 	recv(clientSocket, buffer, 1024, 0);

 
 	start=clock();
printf("Receiver Side\n");
 
        for(i=0;decipher[i]!='\0';i++)
       
     	{
                  
 		tmp1=decipher[i]-64;
          
         	tmp2=key[i]-65;
           
        	sum=tmp1-tmp2;

        
           	if(sum<0)
         
         	{	
                  
                  	sum=sum+26;
         
                        decipher[i]=sum+64;
     
              	}	
       
            	else
    
               	{
         
         	        decipher[i]=sum+64;
 
                }
       
     	}
  
        decipher[i++]='\0';

        printf("decipher text:");
 
        printf("%s",decipher);

	end=clock();

	cpu_time_used=((double) (end - start)) / CLOCKS_PER_SEC;

  	printf("%f",cpu_time_used);
  

  return 0;

}

