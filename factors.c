#include <stdio.h>
#include <stdlib.h>

/**
 * find_prime_factors -searches for the factors
 * @num: the num to be devided
 * @factors: factors
 * @num_factors: num_factors
 */

void find_prime_factors(long long int num, long long int *factors, long long int *num_factors) {
    *num_factors = 0;
    int i;
    if (num % 2 == 0) {
        factors[0] = num / 2;
        factors[1] = 2;
        *num_factors = 2;
        return;
    }
    for (i = 3; i < num; i += 2) {
        if (num % i == 0) {
            factors[0] = num / i;
            factors[1] = i;
            *num_factors = 2;
            break;
        }
    }
}

/**
 * main - gives the excess of the div the top two elements of the stack.
 * @argc: the num of cla
 * @argv: the command line argument
 * Return: 0 in case of success or 1
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("factors <file>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }
    long long int num;
    while (fscanf(file, "%lld", &num) == 1) {
        printf("%lld=", num);
        long long int factors[2];
        long long int num_factors;
        find_prime_factors(num, factors, &num_factors);
        if (num_factors == 2) {
            printf("%lld*%lld\n", factors[0], factors[1]);
        }
    }
    fclose(file);
    return 0;
}

