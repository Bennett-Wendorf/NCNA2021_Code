/*  2021/2022 Regional
    International Collegiate Programming Contest

    Problem ?
    Ultimate Binary Watch
    M. K. Furon.                    2021-11-10.                       */




#include   <stdio.h>
#include   <stdlib.h>
#include   <ctype.h>




int bit, c, count, i, testbit, timechar;
int timedigit[4];
char lineimage[84];




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int main (int argc, char *argv[], char *envp[])
{
   /*  Read the input digits.                                         */
   if ((fgets (lineimage, 82, stdin)) == NULL)
      abend ("Missing time in input.");
   for (i = 0; i < 4; i++)
      {
      if (isdigit (lineimage[i]))
         timedigit[i] = lineimage[i] - '0';
      else
         abend ("Non-digit in input.");
      }
   //(void) fputs (lineimage, stdout);
   
   /*  Print the time vertically in binary, with single spaces
       separating the BCD digits and three spaces between the hours
       and minutes.                                                   */
   for (bit = 3; bit >= 0; bit--)
      {
      testbit = 1 << bit;
      for (i = 0; i < 4; i++)
         {
         /*  Print an asterisk if the corresponding bit in the digit
	     is set, a period if it is not.                           */
	 timechar = (timedigit[i] & testbit) ? '*' : '.';
	 (void) putchar (timechar);
         /*  Print spacing between digits.                            */
         (void) putchar ((i < 3) ? ' ' : '\n');
	 if (i == 1)                /*  If in hour ones position      */
	    (void) fputs ("  ", stdout);
         }
      }
      
return (0);
}
