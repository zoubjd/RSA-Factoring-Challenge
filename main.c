#include <stdio.h>
#include <stdlib.h>

/**
 * main - check code
 * description: the mai func
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
char line[100];
FILE *file = fopen(argv[1], "r");
if (argc != 2)
{
printf("Usage: %s filename\n", argv[0]);
return (1);
}
if (file == NULL)
{
perror("Error opening file");
return (1);
}
while (fgets(line, sizeof(line), file) != NULL)
{
long long num = atoll(line);
if (num < 1)
{
break;
}
printf("%lld=", num);
if (num % 2 == 0)
{
printf("%lld*2\n", num / 2);
continue;
}
for (long long i = 3; i < num; i += 2)
{
if (num % i == 0)
{
long long factor = num / i;
for (long long j = 3; j < factor; j += 2)
{
if (factor % j == 0 || i % j == 0)
{
break;
}
}
printf("%lld*%lld\n", factor, i);
break;
}
}
}
fclose(file);
return (0);
}
