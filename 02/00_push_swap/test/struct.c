typedef struct s_struct
{
	int				i;
	struct s_stack	*next;
} t_struct;

int main(void)
{
	t_struct *list;

	list = (t_struct *)malloc(sizeof(t_struct));
