#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct sockaddr_in endpoint;
FILE *flog;
char myhostname[1024];
char pnazwa[20];

int main(int argc, char **argv) 
{
  int sdServerSocket, sdConnection, retval;
  socklen_t sin_size;
  struct sockaddr_in incoming;
  struct hostent *heLocalHost;
  char sign;
  int lnIn1;
  int sterujaca;
  char odp;
  char nazwa[20];

  sin_size = sizeof(struct sockaddr_in);

  sdServerSocket = socket(PF_INET, SOCK_STREAM, 0);
  gethostname(myhostname, 1023);
  heLocalHost = gethostbyname(myhostname);

  endpoint.sin_family = AF_INET;
  endpoint.sin_port = htons(5002);
  endpoint.sin_addr = *(struct in_addr*) 
  heLocalHost->h_addr;
  memset(&(endpoint.sin_zero),0,8);

  struct stat st = {0};

  if (stat("./serv", &st) == -1) 
  {
    mkdir("./serv", 0777);
  }
  if (stat("./serv/pom", &st) == -1) 
  {
    mkdir("./serv/pom", 0777);
  }

  printf("slucham na %s : %d\n",
  inet_ntoa(endpoint.sin_addr),
  ntohs(endpoint.sin_port));

  retval = bind(sdServerSocket, (struct sockaddr*) &endpoint, sizeof(struct sockaddr));
  if (retval < 0) 
  {
    printf("bind nie powiodl sie\n");
    return 1;
  }

  listen(sdServerSocket, 10);

  sin_size = sizeof(struct sockaddr_in);
  while ((sdConnection = accept(sdServerSocket, (struct sockaddr*) &incoming, &sin_size)) > 0) 
  {
    printf("Polaczenie z %s:%d\n",
    inet_ntoa(incoming.sin_addr),
    ntohs(incoming.sin_port));
  
  if (recv(sdConnection, &lnIn1, sizeof(int),0) != sizeof(int)) 
  {
    printf("pierwszy recv nie powiodl sie. \n");
    close(sdConnection);
    continue;
  }

  sterujaca = htonl(lnIn1);
  switch(sterujaca)
  {
    case 1: 
    printf("1\n");
    //przejrzyj pliki na dyku
    //wysyłamy ok
    odp = 'k';
    if (send(sdConnection, &odp, sizeof(odp), 0) != sizeof(odp)) 
    { 
      printf("pierwszy send się nie powiódł\n");
    }
    break;

    case 2: printf("2 \n");
    //wysyłamy ok
    odp = 'k';
    if (send(sdConnection, &odp, sizeof(odp), 0) != sizeof(odp)) 
    {
        printf("pierwszy send nie powiodl sie\n");
    }
    break;
    case 3: 
    //ściagnij plik
    printf("3 \n");
    //wysyłamy ok
    odp = 'k';
    if (send(sdConnection, &odp, sizeof(odp), 0) != sizeof(odp)) 
    {
        printf("pierwszy send nie powiodl sie\n"); break;
    }
    //wciągnięcie nazwy pliku
    if (recv(sdConnection, &nazwa, sizeof(nazwa),0) != sizeof(nazwa))
    {
        printf("brak nazwy \n");
    }
    break;

    case 4:
    printf("dost 4\n");
    close(sdConnection);
    break;

    default:  
    close(sdConnection);
    break;
  }
}
return 0;
}
