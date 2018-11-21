#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


char myhostname[1024];
struct sockaddr_in soc;
FILE *flog;

int main() 
{
  int sdServerSocket, sdConnection, retval;
  socklen_t sin_size;
  struct sockaddr_in incoming;
  struct hostent *heLocalHost;

  sin_size = sizeof(struct sockaddr_in);

  sdServerSocket = socket(PF_INET, SOCK_STREAM, 0);
  gethostname(myhostname, 1023);
  heLocalHost = gethostbyname(myhostname);

  struct stat st = {0};

  soc.sin_family = AF_INET;
  soc.sin_port = htons(5007);
  soc.sin_addr = *(struct in_addr*) 
  heLocalHost->h_addr;
  memset(&(soc.sin_zero),0,8);
  char nazwa [20];

  char signal;


//tworzenie plików
  if (stat("./serv", &st) == -1) 
  {
    mkdir("./serv", 0777);
  }
  if (stat("./serv/pom", &st) == -1) 
  {
    mkdir("./serv/pom", 0777);
  }
//tworzednie plików

  printf("slucham na %s : %d\n",
  inet_ntoa(soc.sin_addr),
  ntohs(soc.sin_port));

  retval = bind(sdServerSocket, (struct sockaddr*) &soc, sizeof(struct sockaddr));
  if (retval < 0) 
  {
    printf("bind nie powiodl sie\n");
    return 1;
  }
  listen(sdServerSocket, 10);

  while ((sdConnection = accept(sdServerSocket, (struct sockaddr*) &incoming, &sin_size)) > 0) 
  {
    printf("Polaczenie z %s:%d\n",
    inet_ntoa(incoming.sin_addr),
    ntohs(incoming.sin_port));

if (recv(sdConnection, &signal, sizeof(signal),0) != sizeof(signal))
{
    printf("pierwszy recv nie powiodl sie. \n");
    close(sdConnection);
    continue;
}
printf("Odebrano %c \n", signal);
}
char potw[5] = "gdsad";
if (send(sdConnection, &potw, sizeof(potw), 0) != sizeof(potw))
{
printf("send sie nie powiodl \n");
}
    close(sdConnection);

return 0;
}
