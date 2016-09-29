#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>

int main(){
  int welcomeSocket, newSocket,len;
  double cpu_time_used ,end,start;
  char c[26],k[30]; 
 int i,index,max=26;  
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

	  for(i=97;i<=122;i++)  
          {  
               c[i-97]=i;  
          }


   printf("Enter plain text: ");  
          gets(s);  
          printf("Your key is: ");  
          randomize();  
          for(i=0;i<strlen(s);i++)  
          {  
               index=random(max)%26;  
               k[i]=c[index];  
          }  
          k[i]='\0';  
  send(newSocket,k,1024,0);
  end=clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f",cpu_time_used);

  return 0;
}
