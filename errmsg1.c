/* http://www.di.uevora.pt/~lmr/syscalls.html
 *
 * Print errno codes and cooresponding message
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i;
   extern int errno;
   extern const int sys_nerr;

   for (i = 0; i < sys_nerr; ++i)
   {
      fprintf(stderr, "%3d",i);
      errno = i;
      perror(" ");
   }
}
