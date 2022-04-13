/* test main */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stat		stat;
	t_record	record;

	if (ac == 1)
		return (0);
	psw_init_stat(&stat, ac, av);
	printf("init_stat();\n");
	//int i = psw_get_max_num(&stat, 'a');
	//printf("%d\n", i);
	psw_push(&stat, 'b', &record);
	psw_output_operation(record.history);
	return (0);
}