#include "./libft/libft.h"
#include "./get_next_line.h"

int	main(int ac, char **av)
{
	int	retour;
	int	fd;
	int	fd2;
	char **test;
	char *line;

	retour = 2;
	fd = -1;
	printf("i'm in main\n");
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		printf("open failed\n");
		return (0);
	}
	if ((fd2 = open(av[2], O_RDONLY)) < 0)
	{
		printf("open failed\n");
		return (0);
	}
	printf("file is open\n");
	line = (char *)malloc(sizeof(line) * (2048));
	test = &line;
	if (line == NULL)
		printf("malloc main fail\n");
	printf("test du main est malloc\n");
	retour = get_next_line(6, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd, retour, test, test[0]);
	retour = get_next_line(fd2, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd2, retour, test, test[0]);
	retour = get_next_line(fd, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd, retour, test, test[0]);
	retour = get_next_line(fd2, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd2, retour, test, test[0]);
	retour = get_next_line(fd2, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd2, retour, test, test[0]);
	retour = get_next_line(fd, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd, retour, test, test[0]);
	retour = get_next_line(fd, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd, retour, test, test[0]);
	retour = get_next_line(fd, test);
	printf("retour %d = %d et test = %p -(%s).\n", fd, retour, test, test[0]);
	printf("on est arrive au bout\n");
	close(fd);
	return (0);
}
