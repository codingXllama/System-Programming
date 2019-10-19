/*
Purpose: To Write a C program called writer.c. It uses system call I/O to create a file called list1.txt which has the following text-based content:
101   GM Buick 2010
102   Ford Lincoln 2005

Author: Osama A. (codingXllama)
Date: 17/10/19

*/

// importing the required libraries
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Creating file discriptor
    int fd1;

    // opening the file discriptor by passing in a "list1.txt" file to create it
    //for the premission you can also put 0644
    fd1 = open("list1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0755);

    // checking the file discriptor if it's int value is greater than 0, then we will write the content onto the "list1.txt"
    //else we will just print the error to stderr (perror)
    //Note we are using ternary operator to check the required conditions
    //We are using strlen() to write the same amount of chars we have in our string to fd1, note * you must insert the string.h header!!
    fd1 >0 ? write(fd1, "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n", strlen("101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n")): perror("File error!");

    // closing file stream
    close(fd1);

    return 0;
}
