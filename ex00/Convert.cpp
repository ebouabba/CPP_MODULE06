#include "Convert.hpp"

Convert::Convert()
{
	this->str = "no type";
}

Convert::Convert(std::string type)
{
	this->str = type;
}

Convert::Convert(const Convert &c)
{
	*this = c;
}

Convert &Convert::operator=(const Convert &c)
{
	if (this == &c)
		return (*this);
	this->str = c.str;
	return (*this);
}
Convert::~Convert()
{
}

int isItReallyDouble(std::string str)
{
	int i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			;
		else if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int isItReallyInt(std::string str)
{
	int i = -1;
	while (str[++i])
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int whatType(std::string str)
{
	if (isprint(str[0]) && !isdigit(str[0]) && str.length() == 1)
		return (IS_CHAR);
	if (isItReallyInt(str))
		return (IS_INT);
	if (isItReallyDouble(str))
		return (IS_DOUBLE);
	else
		return (IS_FLOAT);
}

int Convert::parsing()
{
	int i = -1;
	int flag = 0;
	int flag_f = 0;
	if (str[str.length() - 1] == '.' && str.length() > 1)
		return (0);
	while (str[++i] && str.length() != 1)
	{
		if (str[i] == 'f')
			flag_f++;
		if (str[i] == '.')
			flag++;
		else if ((!isdigit(str[i]) && str[str.length() - 1] != 'f'))
			return (0);
	}
	if (flag == 0 && str[str.length() - 1] == 'f')
		return (0);
	if (flag > 1 || flag_f > 1 || (str.length() > 1 && str[0] == '.'))
		return (0);
	return (whatType(str));
}

int Convert::execute(int type)
{
	if (type == IS_CHAR)
	{
		char c = str[0];
		std::cout << std::fixed
				  << "char: " << c << std::endl
				  << "int: " << static_cast<int>(c) << std::endl
				  << "float: " << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl
				  << "double: " << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}
	else if (type == IS_INT)
	{
		int n = std::atoi(str.c_str());
		if (isprint(n))
			std::cout << "char: " << static_cast<char>(n) << std::endl;
		else
			std::cout << "char: "
					  << "not displayable" << std::endl;
		std::cout << std::fixed
				  << "int: " << static_cast<int>(n) << std::endl
				  << "float: " << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl
				  << "double: " << std::setprecision(1) << static_cast<double>(n) << std::endl;
	}
	else if (type == IS_DOUBLE || type == IS_FLOAT)
	{
		// int size = -1;
		// int flg = 0;
		// for (int i = 0; str[i]; i++)
		// {
		// 	if (str[i] == '.')
		// 		flg = 1;
		// 	if (flg == 1 && str[i] != '\f')
		// 		size++;
		// }
		double d = std::atof(str.c_str());
		std::cout << "char: "
				  << "not displayable" << std::endl
				  << "int: " << static_cast<int>(d) << std::endl
				  << "float: " << static_cast<float>(d) << "f" << std::endl
				  << "double: " << static_cast<double>(d) << std::endl;
	}
	return (0);
}