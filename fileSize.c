/*
Purpose : . To write a program that uses lseek  function to get the size of an open file,
but appears not to have changed the value of the read-write file position pointer.

Author: Osama A (codingXllama)

Date: 16/10/19
*/


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    // creating file discriptor
    int fd1;
    // creating filesize var
    long int fileSize = 0;

    // opening the file
    fd1 = open(argv[1], O_RDONLY);

    //getting the size of the file via lseek
    fileSize = lseek(fd1, 0L, SEEK_END);

    // printing the result
    printf("The file Size is: %ld\n", fileSize);

    // resetting the read-write file position pointer
    lseek(fd1, fileSize, SEEK_CUR);

    // closing the file stream
    close(fd1);

    return 0;
}
