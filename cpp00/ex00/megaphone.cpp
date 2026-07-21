#include <iostream>
#include <cctype>

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return EXIT_FAILURE;
	}
	int i = 1;
	while (i < ac)
	{
		int j = 0;
		while (av[i][j])
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
