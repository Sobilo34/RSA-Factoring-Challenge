#include <stdio.h>
#include <stdlib.h>

void factorize(int num);

/**
 * main - Entry point of the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of strings representing command-line arguments.
 *
 * Reads natural numbers from a file specified in the command-line
 * argument and computes their factorizations using the 'factorize' function.
 * It prints factorizations on the standard output. File format is assumed
 * to contain one number per line.
 *
 * Return: 0 on successful execution.
 */

int main(int argc, char *argv[])
{
	char line[20];
	int num;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		num = atoi(line);
		factorize(num);
	}

	fclose(file);
	return (0);
}

/**
 * factorize - Computes a factorization of a given natural number.
 * @num: The natural number to be factorized.
 *
 * This function finds and prints a factorization of the input number in the
 * format "n=p*q" where p and q are smaller numbers.
 * It handles non-prime numbers & prints factorization on standard output.
 */

void factorize(int num)
{
	int i;
	int factor_found = 0;

	/* Handle negative numbers */
	if (num < 0)
	{
		printf("%d is a negative number and cannot be factorized.\n", num);
		return;
	}

	/* Special case for 1 */
	if (num == 1)
	{
		printf("1=1*1\n");
		return;
	}

	for (i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, i, num / i);
			factor_found = 1;
			break;
		}
	}

	/* If the number cannot be factorized, print it as the first factor */
	if (!factor_found)
	{
		printf("%d=%d*1\n", num, num);
	}
}
