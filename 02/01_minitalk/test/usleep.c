#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	struct timeval	tv[4];
	long			sec[4];
	long			us[4];
	int				sleeptime = 10;

	gettimeofday(&tv[0], NULL);
	gettimeofday(&tv[1], NULL);
	sec[0] = tv[0].tv_sec;
	sec[1] = tv[1].tv_sec;
	us[0] = tv[0].tv_usec;
	us[1] = tv[1].tv_usec;
	printf("1 : %lu %lu\n", sec[0], us[0]);
	printf("2 : %lu %lu\n", sec[1], us[1]);
	printf("1 - 0 gettimeofday() : %lu\n", (sec[1] * 1000000 + us[1]) - (sec[0] * 1000000 + us[0]));

	int i = 0;
	while (i++ < 10)
	{
		gettimeofday(&tv[2], NULL);
		usleep(sleeptime);
		gettimeofday(&tv[3], NULL);
		sec[2] = tv[2].tv_sec;
		sec[3] = tv[3].tv_sec;
		us[2] = tv[2].tv_usec;
		us[3] = tv[3].tv_usec;

		printf("3 - 2 usleep(%d) : %lu\n", sleeptime, (sec[3] * 1000000 + us[3]) - (sec[2] * 1000000 + us[2]));
	}
	return (0);
}
