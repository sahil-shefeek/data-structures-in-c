#include <stdio.h>
#define SIZE 10

typedef struct Term
{
    int exp;
    int coeff;
} Term;

typedef struct Polynomial
{
    int num_of_terms;
    Term terms[SIZE];
} Polynomial;

void get_polynomial(Polynomial *poly)
{
    for (int i = 0; i < poly->num_of_terms; i++)
    {
        printf("Enter the coefficient of term %d:  ", i + 1);
        scanf("%d", &poly->terms[i].coeff);
        printf("Enter the exponent of term %d:  ", i + 1);
        scanf("%d", &poly->terms[i].exp);
        printf("\n");
    }
}

void print_polynomial(Polynomial poly)
{
    for (int i = 0; i < poly.num_of_terms; i++)
    {
        int exp = poly.terms[i].exp;
        if (exp == 0)
            printf("%d\n", poly.terms[i].coeff);
        else if (exp == 1)
            printf("%dx + ", poly.terms[i].coeff);
        else
            printf("%dx^%d + ", poly.terms[i].coeff, poly.terms[i].exp);
    }
}

// Term get_term(int num)
// {
//     Term term;
//     for (int i = 0; i < num; i++)
//     {
//         printf("Enter the exponent of term:  ");
//         scanf("%d", &term.exp);
//         printf("Enter the coefficient of term:  ");
//         scanf("%d", &term.coeff);
//         printf("\n");
//     }
//     return term;
// }

int main()
{
    Polynomial poly_1, poly_2;
    printf("Enter details of first polynomial: \n");
    printf("Enter the number of terms: ");
    scanf("%d", &poly_1.num_of_terms);
    get_polynomial(&poly_1);
    printf("You have entered: \n");
    print_polynomial(poly_1);
    printf("Enter details of second polynomial: \n");
    printf("Enter the number of terms: ");
    scanf("%d", &poly_2.num_of_terms);
    get_polynomial(&poly_2);
    printf("You have entered: \n");
    print_polynomial(poly_2);

    // for (int i = 0; i < num; i++)
    // {
    //     printf("Enter the exponent of term %d:  ", i + 1);
    //     scanf("%d", &terms[i].exp);
    //     printf("Enter the coefficient of term %d:  ", i + 1);
    //     scanf("%d", &terms[i].coeff);
    //     printf("\n");
    // }

    // for (int i = 0; i < num; i++)
    // {
    //     int exp = terms[i].exp;
    //     if (exp == 0)
    //         printf("%d\n", terms[i].coeff);
    //     else if (exp == 1)
    //         printf("%dx + ", terms[i].coeff);
    //     else
    //         printf("%dx^%d + ", terms[i].coeff, exp);
    // }
}