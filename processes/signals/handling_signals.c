#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

void	ft_handle_sigtstp(int sig)
{
	printf("\nStop is not allowed by the program\nGive me the number\n");
}

void	ft_handle_sigint(int sig)
{
	printf("\nSIGINT is prohibited now\n");
}

void	ft_handle_sigcont(int sig)
{
	printf("Insert a number: \n");
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	sa.sa_handler = &ft_handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);
	//another signal handling function:
	signal(SIGINT, &ft_handle_sigint);
	int	x;
	printf("Insert a number: \n");
	scanf("%d", &x);
	printf("res: %d * 5 = %d\n", x, x * 5);
	return (0);
}
