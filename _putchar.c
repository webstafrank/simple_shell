#include "main.h"
/* _putchar prints to thr stdout
 * prototype - void print_char(char c)
 * returns 1 0n success and 0 on fail 
 */
char print_char(char c)
{
	return(write (1, &c, 1));
}
