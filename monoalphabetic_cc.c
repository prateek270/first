#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>

int main(){
  int clientSocket,i,len,k,j;
  char buffer[1024],message[1024];
  char alpha[26][2]={ {'a','z'},{'b','w'},{'c','x'},{'d','y'},{'e','o'} ,{'f','p'},{'g','r'},{'h','q'},{'i','a'},{'j','h'}, {'k','c'},{'l','b'},{'m','e'},{'n','s'},{'o','u'},{'p','t'},{'q','v'},{'r','f'},{'s','g'},{'t','j'}, {'u','l'},{'v','k'},{'w','m'},{'x','n'},{'y','d'}, {'z','i'} };
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
  j=0;
  k=0;
  while(buffer[j]!='\0')
    {
         for(i=0;i<=25;i++)
            { 
                if(alpha[i][1]==buffer[j])
                {
                message[k++]=alpha[i][0];
                break;
               }
            }
            j++;
    }
 

printf("%s\n",message);	  
end=clock();
cpu_time_used=((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f",cpu_time_used);
  
  return 0;
}
