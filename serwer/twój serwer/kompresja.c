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
#include "kompresja.h"
//przekaż z(zapakować) lub u(rozpakować) nazwe pliku i scierzkęm do

int kom() {
char nazwa[20] = "nowe.txt";
        char commandname [200];
char ster = 'u';
switch ster{
case 'z':
    sprintf(commandname, "tar -zcvf %s.tar.gz serv/%s", nazwa, nazwa);
    break;
case 'u':
    sprintf(commandname, "tar -zxvf %s.tar.gz ./serv", nazwa);
    break;
default: 
    return(1);
}
system(commandname);
    return(0);
}

void czyt() 
{ 
  struct stat st = {0};
	struct dirent *de;

int i;
char file[26];
char ip [16];
	DIR *dir = opendir("./serv/pom");
    FILE *f = fopen("./serv/pom/list", "w");

while ((de = readdir(dir)) != NULL) 
{
    char *name;
    name = de->d_name;
    size_t len = strlen(name);
        if((strcmp( name + len - 4,".txt") == 0))

        {
            sprintf(file, "./serv/pom/%s", name);
            FILE *g = fopen( file, "r");
            fgets( ip, 16, g);
            fclose(g);
            fprintf(f, "%s %s\n", name, ip);
            printf("%s %s\n", name, ip);

        }
}
    fclose(f);
	closedir(dir);	
} 

