#include <stdio.h>
#define SIZE 10

typedef struct Term
{
    int exp;
    int coeff;
} Term;

int main()
{
    Term terms[SIZE];
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter the exponent of term %d:  ", i + 1);
        scanf("%d", &terms[i].exp);
        printf("Enter the coefficient of term %d:  ", i + 1);
        scanf("%d", &terms[i].coeff);
        printf("\n");
    }

    printf("You have entered: \n");
    for (int i = 0; i < num; i++)
    {
        int exp = terms[i].exp;
        if (exp == 0)
            printf("%d\n", terms[i].coeff);
        else if (exp == 1)
            printf("%dx + ", terms[i].coeff);
        else
            printf("%dx^%d + ", terms[i].coeff, exp);
    }
}