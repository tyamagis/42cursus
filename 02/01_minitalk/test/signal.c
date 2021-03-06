/* ursig1.c */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static int count = 0;

void handler(int signo)
{
//	signal(SIGINT, handler);      /* Re-instate handler (only for non-BSD systems)*/
	++count;                      /* Increment count */
	write(1, "Got SIGINT\n", 11); /* Write message */
}

int main(int argc, char **argv)
{
	signal(SIGINT, handler); /* Register function */

	while (count < 2)
	{
		puts("Waiting for SIGINT..");
		sleep(4); /* Snooze */
	}
	puts("End.");
	return 0;
}
