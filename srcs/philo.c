#include <philo.h>

int main(int argc, char **argv)
{
	t_deadly	philo;

	if (argc != 5 && argc != 6)
		return (1);
	//parsing_args(argc, argv);
	philo.philo_count = ft_atoi(argv[1]);
	philo.forks_count = philo.philo_count;
	if (argc == 5)
	{
		gluttonous_philos(&philo);
	}
	//else
	//{

	//}
	return (0);
}