
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>

int main(){
  int clientSocket,i,len,k;
  char buffer[1024],mssg[1024];
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
  
end=clock();
cpu_time_used=((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f",cpu_time_used);
  
  return 0;
}

  int i = 0;
  while(i < strlen(mssg))
  {   
    p[0] = mssg[i]-65;
    if(mssg[i+1] == '\0')
      p[1] = p[2] = 0;
    else
    {
      p[1] = mssg[i+1]-65;  
      if(mssg[i+2] == '\0')
       p[2] = 0;
      else
       p[2] = mssg[i+2]-65;
    }
   
   multiply2();
   int l =0;
   while(i<strlen(mssg) && l<3)
    mssg[i++] = c[l++]+65;          
  

printf("%s\n",mssg);
 
}