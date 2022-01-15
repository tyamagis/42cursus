#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/*
 * SIGACTION
 *
 * int	sigaction(int signum, const stcruct sigaction *act, struct sigaction *oldact);
 *
 * struct sigaction{
 * 		void		(*sa_handler)(int);
 * 		void		(*sa_sigaction)(int, siginfo_t *, void *);
 * 		sigset_t	sa_mask;
 * 		int			sa_flags;
 * 		void		(*sa_restorer)(void);
 * 		}
 *
 *
 * */
