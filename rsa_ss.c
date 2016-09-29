#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include<time.h>

long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
char msg[100];

int prime(long int pr)
{ 

	int i;
 
	j=sqrt(pr);
 
	for(i=2;i<=j;i++)
 
	{ 
   
 		if(pr%i==0) 
 
   	return 0;
 
	} 

	return 1;

}

void ce()

{ 

	int k;

	k=0;
	for(i=2;i<t;i++)

	{ 
   
 		if(t%i==0) 

    		continue; 
  
  		flag=prime(i); 
  
  		if(flag==1&&i!=p&&i!=q) 

    		{ 
       
 		e[k]=i; 
   
     		flag=cd(e[k]);
 
        	if(flag>0)
 
        	{ 
    
        		d[k]=flag; 
   
         		k++; 
    
   		} 
     
   		if(k==99) 
 
       			break; 
  
  		} 

	}
}
long int cd(long int x)

{
 	
long int k=1;
 	
while(1)
 
	{ 
    	k=k+t; 

    	if(k%x==0) 

    	return(k/x);
 
	}
}
 


int main()

{

  	int welcomeSocket, newSocket,len;

  	double cpu_time_used ,end,start;

  
  	char buffer[1024];
 
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

  	printf("Enter string");
 
 	gets(msg);


  	len=strlen(msg);
 
	while(i!=len)
 
	{
	 
    pt=m[i]; 
 
             pt=pt-96; 
 
      	     k=1; 

    	     for(j=0;j<key;j++) 

             { 
      
  		k=k*pt; 
   
     		k=k%n; 
  
             } 
   
 	     temp[i]=k;
 
    	     ct=k+96; 

    	     en[i]=ct; 

             i++;
 
	} 

	en[i]=-1; 


  	strcpy(buffer,en);
 
 	send(newSocket,buffer,1024,0);

  	end=clock();

 
 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  	printf("%f",cpu_time_used);

  
	return 0;

}
