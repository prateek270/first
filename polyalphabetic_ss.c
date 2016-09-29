#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include<time.h>


int main()
{

  	int welcomeSocket, newSocket,len;

  	double cpu_time_used ,end,start;
 
  	int i,j=0;

        int tmp1,tmp2;

        int dtln,kln,sum;

        char key[100],cipher[100];

        char buffer[1024];

      
 
       printf("Enter Key : ");

        gets(key);

 
        dtln=strlen(buffer);
 
        kln=strlen(key);
 
 
  	struct sockaddr_in serverAddr;

 	struct sockaddr_storage serverStorage;
 
	socklen_t addr_size;

  	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

  	start=clock();


  	serverAddr.sin_family = AF_INET;

 
 	serverAddr.sin_port = htons(7891);


  	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

 
 	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
  


 	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));


  	if(listen(welcomeSocket,5)==0)
		
    printf("Listening\n");
 
	else
   
		 printf("Error\n");



  	addr_size = sizeof serverStorage;

  	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);


  	strcpy(buffer,"Since Everyone Can Read, Encoding Text In Neutral Sentences Is Doubtfully Effective\n");
 
   	 for(i=kln;i<dtln;i++)
         
   	{
                      
  		if(buffer[i]==32)
    
       		{
  
               		i++;
 
        	}
               
       		key[i]=key[j];
           
                j++;
        
    	}

	       
     	for(i=0;i<dtln;i++)
     
       	{
                  
 		if(buffer[i]==32)
   
                {
         
               	       cipher[i]=' ';
 
                       i++;
    
                }
          
         	else if(buffer[i]<=90 && buffer[i]>=65)
 
                {
                          
          		tmp1=buffer[i]-65;
             
      		}
              
     		else if(buffer[i]<=123 && buffer[i]>=97)
  
                {
                            
        		tmp1=buffer[i]-97;
                
   		}

                 
  		tmp2=key[i]-64;
       
            	sum=tmp1+tmp2;

     
              	if(sum>26)
          
         	{
                          
          		sum=sum-26;
                  
                  	cipher[i]=sum+64;
     
                }
            
       		else
              
     		{
                    
                	cipher[i]=sum+64;
     
              	}	
        
    	}
           
 	cipher[i++]='\0';
    
        
send(newSocket,cipher,1024,0);
  end=clock();

 
 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 
 	printf("%f",cpu_time_used);

 
 	return 0;

}
