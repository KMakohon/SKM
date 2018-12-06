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

#include <dirent.h> 


//funkcje


void createfolder(){
struct stat st = {0};

  if (stat("./serv", &st) == -1) 
  {
    mkdir("./serv", 0777);
  }
  if (stat("./serv/pom", &st) == -1) 
  {
    mkdir("./serv/pom", 0777);
  }

}

int doA(int sdConnection, char ip[16]){


FILE *pic;
FILE *f;
FILE *g;
DIR *di;
struct dirent *de;
char name [15];
char nazwa [20];
char buffor[1024];
char nope = 'n';
char ok = 'k';
char ip2 [16];
char rozmiar[10];
memset(nazwa, 0 , sizeof(nazwa));
memset(name, 0, sizeof(name));
memset(buffor, 0, sizeof(buffor));

    if (recv(sdConnection, &name, sizeof(name), 0) <= 0)
    {
        printf("recv 2.1 sie nie powiodl %s \n", name);
        close(sdConnection);
        send(sdConnection, &nope, sizeof(char), 0);
        return 1;
    }
    else
    {
printf("%s \n", name);
//tworzenie pliku pomocniczego
        sprintf(nazwa, "./serv/pom/%s", name);
            pic = fopen(nazwa, "r");
        if (pic == NULL)
        {
            pic = fopen(nazwa, "a+");
        }
        else
        {
            int o = strcmp(fgets(ip2, 16, pic), ip);
            if (o !=0)
            {
                send(sdConnection, &nope, sizeof(char), 0);
                close(sdConnection);
                return 1;
            }
        }
        fprintf(pic, "%s", ip);
        fclose(pic);
//tworzenie po prostu pliku
        sprintf(nazwa, "./serv/%s", name);
            pic = fopen(nazwa, "w");
        if (pic == NULL)
        {
            pic = fopen(nazwa, "a+");
        }
//wysyłamy potwierdzenie
            send(sdConnection, &ok, sizeof(char), 0);
     }
//rozmiar
memset(rozmiar, 0, sizeof(rozmiar));
recv(sdConnection, &rozmiar, sizeof(rozmiar), 0);
send(sdConnection, &ok, sizeof(char), 0);
char *ptr;
long roz;
roz = strtol(rozmiar, &ptr, 10);
//wyślij plik
    while(roz > 0)
    {
    memset(buffor, 0, sizeof(buffor));
         if (recv(sdConnection, &buffor, sizeof(buffor), 0) == 0)
         {
            printf("recv 2.3 sie nie powiodl \n");
            send(sdConnection, &nope, sizeof(char), 0);
            return 1;

         }
         else
        {
            printf("%s", buffor);
            fprintf(pic, "%s", buffor);
            roz = roz - sizeof(buffor);
            send(sdConnection, &ok, sizeof(char), 0);
        }
    }
roz = 0;
//!= sizeof(buffor)
close(sdConnection);
fclose(pic);
//do listy
 di = opendir("./serv/pom");
 f = fopen("./serv/pom/list", "w");
char file [26];
while ((de = readdir(di)) != NULL) 
{
    char *name;
    name = de->d_name;
    size_t len = strlen(name);
        if((strcmp( name + len - 4,".txt") == 0))
        {          
            sprintf(file, "./serv/pom/%s", name);
            g = fopen( file, "r");
            fgets( ip, 16, g);
            fclose(g);
            fprintf(f, "%s %s\n", name, ip);

        }
}
    fclose(f);
	closedir(di);	
    close(sdConnection);
printf("Plik dotarł! \n");
// wylistowanie plików

return 0;
}


int doB(int sdConnection)
{
FILE *pic;
char buffor[1024];
pic = fopen("./serv/pom/list", "r");
                fseek(pic, 0L, SEEK_END);
                long int size = ftell(pic);
                fseek(pic, 0L, SEEK_SET);
 
        while(size > 0)
        {
            int przeczytano = fread(&buffor, 1, 1024, pic);
            int wyslano = send(sdConnection, &buffor, przeczytano, 0);
            size = size - przeczytano;
            if (przeczytano != wyslano)
            {
                printf("error break \n");
                break;
            }
            
        }
        printf("Wysłano plik. \n");
        close(sdConnection);
        fclose(pic);



return 0;
}


int doC(int sdConnection){
struct dirent *de;
DIR *dir;
char nazwa [20];
char buffor [1024];
FILE *pic;
    if (recv(sdConnection, &nazwa, sizeof(nazwa) , 0) <= sizeof(nazwa))
    {           
        dir = opendir("./serv");
        while ((de = readdir(dir)) != NULL) 
        {   
            char *name;
            name = de->d_name;
            int fool = strcmp(name,nazwa);
            if (fool == 0)
            {
                sprintf(nazwa, "./serv/%s", name);
                pic = fopen(nazwa, "r");
                fseek(pic, 0L, SEEK_END);
                long int size = ftell(pic);
                fseek(pic, 0L, SEEK_SET);
                while(size>0)
                {
                    int przeczytano = fread(buffor, 1, 1024, pic);
                    int wyslano = send(sdConnection, buffor, przeczytano, 0);
                    size = size - przeczytano;
                    if (przeczytano != wyslano)
                    {
                        printf("error break \n");
                        break;
                    }
                }
            fclose(pic);
            printf("Wysłano plik. \n");
            close(sdConnection);
            break;
            }
        }
    }
    close(sdConnection);


return 0;
}


char myhostname[1024];
struct sockaddr_in soc;


//program
int main(){

int sdServerSocket, sdConnection, retval;
struct sockaddr_in incoming;
socklen_t dladr = sizeof(struct sockaddr_in);
struct hostent *heLocalHost;

int sin_size = sizeof(struct sockaddr_in);

gethostname(myhostname, 1023);
heLocalHost = gethostbyname(myhostname);


soc.sin_family = AF_INET;
soc.sin_port = htons(5009);
soc.sin_addr = *(struct in_addr*) 
heLocalHost->h_addr;
memset(&(soc.sin_zero),0,8);

sdServerSocket = socket(PF_INET, SOCK_STREAM, 0);
char ip [16];
char signal;
createfolder();

  printf("slucham na %s : %d\n",
  inet_ntoa(soc.sin_addr),
  ntohs(soc.sin_port));

  retval = bind(sdServerSocket, (struct sockaddr*) &soc, dladr);
  if (retval < 0) 
  {
    printf("bind nie powiodl sie\n");
    return 1;
  }
 listen(sdServerSocket, 10);
while(1)
{
        dladr = sizeof(struct sockaddr_in);
        sdConnection = accept(sdServerSocket, (struct sockaddr*) &incoming, &dladr);

            printf("Polaczenie z %s:%d\n",
            inet_ntoa(incoming.sin_addr),
            ntohs(incoming.sin_port));
            if(fork()==0)
            {
                printf("Pomocnik na stanowisku! \n");
                char ip [16];
                sprintf(ip, "%s", inet_ntoa(incoming.sin_addr));
                if (recv(sdConnection, &signal, sizeof(char), 0) != sizeof(char))
                {
                    printf("pierwszy recv nie powiodl sie. \n");
                    close(sdConnection);
                    continue;
                }
                else
                    {
                        switch(signal)
                        {
                        //wysłanie pliku na serwer
                        case 'a':
                            
                            doA(sdConnection, ip);
                            break;
                        case 'b':
                            doB(sdConnection);
                            break;
                        case 'c':
                            doC(sdConnection);
                            break;
                        default:
                            close(sdConnection);
                            break;
                        }
                    }
            exit(0);  
            }
            else
            {
                printf("Główny na stanowisku! \n");
                continue;
            }

}
return 0;
}
