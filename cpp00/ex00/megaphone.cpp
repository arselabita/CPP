#include <iostream>

int main (int ac, char *av[])
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	int i = 1;
	while(i < ac)
	{
		int j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] = av[i][j] - 32;
			j++;
		}			
		std::cout << av[i];
		i++;
	}
	return (0);
}
