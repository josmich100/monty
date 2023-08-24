#include "monty.h"
#include <limits.h>
/**
 * _atoi - check the code
 *
 * @s: input
 *
 * Return: output
 */
int _atoi(char *s)
{
	unsigned int result = 0;
	int sign = 1;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;
	}

	if (result > (unsigned long)INT_MAX && sign == 1)
		return (0);
	if (result > (unsigned long)INT_MAX + 1 && sign == -1)
		return (0);

	return ((int)result * sign);
}
