#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>

int main(){
  int welcomeSocket, newSocket,len;
  double cpu_time_used ,end,start;
  
  char buffer[1024];
  char mssg[100];  
  int k[][3] = { {17,17,5},
               {21,18,21},
               {2,2,19}
             };  
          
  int ki[][3] = { {4,9,15},
                {15,17,6},
                {24,0,17}
             };  

  int c[3];
  int p[3];             
  
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

 
void get_mssg()
{
   printf("\n Enter the Plaintext (in caps): "); 
   gets(mssg); 
}

void multiply()
{
	int i,j;
  for(i=0;i<3;i++)
  {
   p[i] = 0;      
   for(j=0;j<3;j++)
     p[i] += c[j]*k[i][j];
   p[i] %= 26;             
  }       
}

void multiply2()
{
	int i,j;
  for(i=0;i<3;i++)
  {
   c[i] = 0;      
   for( j=0;j<3;j++)
     c[i] += p[j]*ki[i][j];
   c[i] %= 26;             
  }       
}

void en_mssg()
{
  int i = 0;
  while(i < strlen(mssg))
  {   
    c[0] = mssg[i]-65;
    if(mssg[i+1] == '\0')
      c[1] = c[2] = 0;
    else
    {
      c[1] = mssg[i+1]-65;  
      if(mssg[i+2] == '\0')
       c[2] = 0;
      else
       c[2] = mssg[i+2]-65;
    }
   
   multiply();



   int l =0;
   while(i<strlen(mssg) && l<3)
    mssg[i++] = p[l++]+65;          
    
  }   
  printf("\n The Ciphertext is : ");
 
}
  send(newSocket,msg,1024,0);
  end=clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f",cpu_time_used);

  return 0;
}
