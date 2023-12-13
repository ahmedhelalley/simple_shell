#include "shell.h"

/**
<<<<<<< HEAD
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @errstr: string containing specified error type
=======
 * _erratoi - converts a string to an integer
 * @s: pointer to the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: A pointer to the parameter & return info struct
 * @estr: A pointer to the string containing specified error type
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *errstr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(errstr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @inp: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int inp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
		if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
		{
			buff[j] = '\0';
			break;
		}
}

/**
 * convert_number - converter function, a clone of itoa
<<<<<<< HEAD
 * @no: number
 * @base: base
 * @flags: argument flags
=======
 * @num: number var
 * @base: base var
 * @flags:the argument flags
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 *
 * Return: string
 */
char *convert_number(long int no, int base, int flags)
{
	static char *array;
	static char buff[50];
	char sign = 0;
	char *pt;
	unsigned long n = no;

	if (!(flags & CONVERT_UNSIGNED) && no < 0)
	{
		n = -no;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buff[49];
	*pt = '\0';

	do	{
		*--pt = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pt = sign;
	return (pt);
}

/**
<<<<<<< HEAD
 * _erratoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
=======
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: 0
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 */
int _erratoi(char *str)
{
	int j = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (j = 0;  str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			res *= 10;
			res += (str[j] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}