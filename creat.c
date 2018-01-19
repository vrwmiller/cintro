/* http://www.di.uevora.pt/~lmr/syscalls.html */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>        /* defines types used by sys/stat.h */
#include <sys/stat.h>         /* defines S_IREAD & S_IWRITE       */

int main()
{
   int fd;
   fd = creat("datafile.dat", S_IREAD | S_IWRITE);
   if (fd == -1)
      printf("Error in opening datafile.dat\n");
   else
   {
      printf("datafile.dat opened for read/write access\n");
      printf("datafile.dat is currently empty\n");
   }
   close(fd);
}
