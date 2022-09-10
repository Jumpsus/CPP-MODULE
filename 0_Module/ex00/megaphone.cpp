#include <iostream>

void	print_str(char *str)
{
	int	i = 0;

	while (str[i])
	{
		std::cout << (char) std::toupper(str[i++]);
	}
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBAACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		print_str(argv[i]);	
		i++;
	}
	std::cout << std::endl;
	return (0);
}
