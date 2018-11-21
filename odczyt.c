#include <stdio.h> 
#include <dirent.h> 
#include <regex.h>
#include <string.h>

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


int main(void) 
{ 
  struct stat st = {0};
	struct dirent *de;

int i;
	DIR *dir = opendir("./serv");
    FILE *f = fopen("./serv/list", "a");;


while ((de = readdir(dir)) != NULL) 
{
    char *name;
    name = de->d_name;
    size_t len = strlen(name);
        if((strcmp( name + len - 4,".txt") == 0))

        {
            fprintf(f, "%s \n", name);
            printf("%s \n", name);
        }
}
    fclose(f);
	closedir(dir);	
	return 0; 
} 

//how to list subdirectories in linux c
