/*  2021/2022 Regionals
    International Collegiate Programming Contest

    Problem ?
    Subprime
    M. K. Furon.                    2022-02-16.                       */




#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>




int answer, firstp, i, iocount, j, lastp, p, used;
char *pchar, *stringbuf;
char isprime[2097152], substring[8];

struct
{
int numeric;
char *pstring;
} primevalue[100001];




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int main (int argc, char *argv[], char *envp[])
{
/*  Run the Sieve of Eratosthenes to find the primes that fit in 21
    bits.                                                             */
isprime[0] = isprime[1] = (char) 0;
for (i = 2; i < 2097152; i++)
   isprime[i] = (char) 1;
for (i = 2; i < 1450; i++)
   if (isprime[i])
      for (j = i * i; j < 2097152; j += i)
	isprime[j] = (char) 0;
/*  Generate a table with the actual prime values and their base ten
    string representations.                                           */
stringbuf = malloc ((size_t) 1048576);
p = 1;
pchar = stringbuf;
for (i = 2; i < 2097152; i++)
   {
   if (isprime[i])
      {
      primevalue[p].numeric = i;
      primevalue[p++].pstring = pchar;
      used = snprintf (pchar, ((size_t) 8), "%d", i);
      pchar += (used + 1);
      if (p > 100000)
         break;
      }
   }
      
/*  Read each triple of (first prime, last prime, substring) and
    search the primes for the given substring.  Leading zeroes mean
    that the substring must be treated as exactly that.               */
   scanf ("%d %d %7s", &firstp, &lastp, substring);
   answer = 0;
   for (i = firstp; i <= lastp; i++)
      if (strstr (primevalue[i].pstring, substring) != NULL)
         answer++;
   (void) printf ("%d\n", answer);

return (0);
}
