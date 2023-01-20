#include "Convert.hpp"

int ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c == '.'))
		return (1);
	else
		return (0);
}

int parsing(std::string str)
{
	int i = 0;
	while (str[i] && str.length() != 1)
	{
		if (!ft_isdigit(str[i]) && str[str.length() - 1] != 'f')
			return (0);
		i++;
	}
	i = 0;
	int flag = 0;
	while (str[i])
	{
		if (str[i] == '.')
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	return (1);
}
int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	std::string str(av[1]);
	if (!parsing(str))
		return (std::cout << "error!!\n", 0);
	std::cout << str << std::endl;
	return (0);
}