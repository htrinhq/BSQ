/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** getnbr
*/

long condit(char const *str, int i, long nb)
{
	while (str[i] <= '9' && str[i] >= '0') {
		nb = nb	+ (str[i] - 48);
		nb = nb * 10;
		i = i +	1;
	}
	return (nb);
}

int my_getnbr(char const *str)
{
	int minus_count = 0;
	int i = 0;
	long nb = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			minus_count = minus_count + 1;
		i = i + 1;
	}
	nb = condit(str, i, nb);
	if (nb != 0 && (minus_count % 2) != 0)
		nb = (nb) * (-1);
	nb = nb / 10;
	return (nb);
}
