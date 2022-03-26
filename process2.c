#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>

int read_all_nbytes(int fd,char* buffer,ssize_t nbytes)
{

    ssize_t nread=0;
    char ch;
    size_t i=0;
    
    while (1)
    {
        nread=read(fd,&ch,nbytes);
        if(nread==-1)
        {
            perror("error while reading\n");
            return nread;
        }
        else if(nread == 0)
        {
            return nread;
        }

        if(ch=='\0')
        {
            buffer[i]=ch;
            break;
        }
        if(ch == '\n')
        {
            break;
        }

        buffer[i]=ch;
        i++;
        
    }
    

    return  i;
    
}


int main()
{
    
    char str[100]={'\0'};

    int fd;
    int nwrite;
    
    

    size_t total_count=0;
    size_t len;
    size_t nread=0;
    fd=open("send_string",O_RDONLY);

    if(fd==-1)
    {
        perror("error opening namedpipe\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        nread=read_all_nbytes(fd,str,1);
        str[6]='\0';
        if(nread == 0)
        {
            break;
        }
        total_count++;
        printf("str is %s and len is %ld\n",str,nread);
        
    }
    printf("total count is %ld\n",total_count);
    close(fd);
    

    

}