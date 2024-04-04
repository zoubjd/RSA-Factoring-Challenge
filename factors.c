#include <stdio.h>
#include <stdlib.h>

int *factorise(long long int num);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: factors <file>");
        exit(EXIT_FAILURE);
    }
    
    FILE *factors = fopen(argv[1], "r");
    if (factors == NULL) {
        printf("File not found");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    long long int num, denominater, i;
    int *result;
    
    while ((read = getline(&line, &len, factors)) != 1)
    {
        num = atol(line);
        result = factorise(num);
        denominater = result[0];
        i = result[1];
        printf("%lld=%lld*%lld\n", num, denominater, i);
        free(result);
    }

    fclose(factors);
    if (line != NULL)
        free(line);

    exit(EXIT_SUCCESS);
}

int *factorise(long long int num)
{
    int *result = malloc(sizeof(int) * 2);
    if (result == NULL)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (long long int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            result[0] = num / i;
            result[1] = i;
            break;
        }
    }
    return result;
}

