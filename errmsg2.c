/* http://www.di.uevora.pt/~lmr/syscalls.html
 *
 * Print errno codes and cooresponding messages
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i;
   extern const int sys_nerr;
   /* Compiler (clang) complains of a previous definition, commenting resolves.
    * Is there any benefit to redefining here?
    */
   /* extern char *sys_errlist[]; */

   fprintf(stderr,"Here are the current %d error messages:\n\n",sys_nerr);
   for (i = 0; i < sys_nerr; ++i)
      fprintf(stderr,"%3d: %s\n", i, sys_errlist[i]);
}
