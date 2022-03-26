#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>   /* For mode constants */
#include <fcntl.h>   /* For O_* constants */
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define BLOCKSIZE 4096


size_t read_all_bytes(int fd,char* buffer,size_t max_bytes);
