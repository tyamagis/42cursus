#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	result(int signum)
{
	o

int main(int ac, char **av)
{
	struct sigaction sa_old;
	struct sigaction sa_new;

	sa_new.sa_handler = result;
	sigemptyset(&sa_new.sa_mask);
	// sa_new.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa_new, &sa_old);

	sigaction(SIGUSR1, &sa_old, 0);

	return (0);
}
