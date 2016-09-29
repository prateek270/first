#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>

int main(){
  int welcomeSocket, newSocket,len,j,k;
  double cpu_time_used ,end,start;
  char alpha[26][2]={ {'a','z'},{'b','w'},{'c','x'},{'d','y'},{'e','o'} ,{'f','p'},{'g','r'},{'h','q'},{'i','a'},{'j','h'}, {'k','c'},{'l','b'},{'m','e'},{'n','s'},{'o','u'},{'p','t'},{'q','v'},{'r','f'},{'s','g'},{'t','j'}, {'u','l'},{'v','k'},{'w','m'},{'x','n'},{'y','d'}, {'z','i'} };
  char buffer[1024],message[1024];

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

    gets(buffer);       
     j=0;
	k=0;
	while(buffer[j]!='\0')
    {
         for(i=0;i<=25;i++)
            { 
                if(alpha[i][0]==buffer[j])
                {
                message[k++]=alpha[i][1];
                break;
               }
            }
            j++;
    }

  send(newSocket,message,1024,0);
  end=clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f",cpu_time_used);

  return 0;
}
