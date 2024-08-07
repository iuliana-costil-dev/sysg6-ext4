#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
        int fd;
        char hello[]="Hello world";
	char bye[]="Bye world";
        fd = open("FichCreux.dat", O_WRONLY | O_CREAT, 0644);

        write(fd, hello, strlen(hello));

        lseek(fd, 100000, SEEK_SET);
 
        write(fd, bye, strlen(bye));

        close(fd);
        exit(0);
}

