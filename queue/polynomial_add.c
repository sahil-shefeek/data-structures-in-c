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

void print_polynomial(Polynomial *poly)
{
    if (poly->num_of_terms == 0)
    {
        printf("0\n");
        return;
    }

    for (int i = 0; i < poly->num_of_terms; i++)
    {
        if (i == 0)
        {
            if (poly->terms[i].exp == 0)
                printf("%d", poly->terms[i].coeff);
            else if (poly->terms[i].exp == 1)
                printf("%dx", poly->terms[i].coeff);
            else
                printf("%dx^%d", poly->terms[i].coeff, poly->terms[i].exp);
        }
        else
        {
            if (poly->terms[i].exp == 0)
                printf(" + %d", poly->terms[i].coeff);
            else if (poly->terms[i].coeff < 0)
                printf(" - %dx^%d", -poly->terms[i].coeff, poly->terms[i].exp);
            else
                printf(" + %dx^%d", poly->terms[i].coeff, poly->terms[i].exp);
        }
    }

    printf("\n");
}

void sort_terms(Polynomial *poly)
{
    int swapped;
    Term temp;
    do
    {
        swapped = 0;
        for (int i = 0; i < poly->num_of_terms - 1; i++)
        {
            if (poly->terms[i].exp < poly->terms[i + 1].exp)
            {
                temp = poly->terms[i];
                poly->terms[i] = poly->terms[i + 1];
                poly->terms[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main()
{
    Polynomial poly_1, poly_2, res;
    printf("Enter details of first polynomial: \n");
    printf("Enter the number of terms: ");
    scanf("%d", &poly_1.num_of_terms);
    get_polynomial(&poly_1);
    printf("You have entered: \n");
    sort_terms(&poly_1);
    print_polynomial(&poly_1);

    printf("Enter details of second polynomial: \n");
    printf("Enter the number of terms: ");
    scanf("%d", &poly_2.num_of_terms);
    get_polynomial(&poly_2);
    printf("You have entered: \n");
    sort_terms(&poly_2);
    print_polynomial(&poly_2);

    int i = 0, j = 0, k = 0;
    while (i < poly_1.num_of_terms && j < poly_2.num_of_terms)
    {
        if (poly_1.terms[i].exp == poly_2.terms[i].exp)
        {
            res.terms[k] = poly_1.terms[i++];
            res.terms[k++].coeff += poly_2.terms[j++].coeff;
        }
        else if (poly_1.terms[i].exp > poly_2.terms[j].exp)
            res.terms[k++] = poly_1.terms[i++];
        else
            res.terms[k++] = poly_2.terms[j++];
    }

    while (i < poly_1.num_of_terms)
        res.terms[k++] = poly_1.terms[i++];

    while (j < poly_2.num_of_terms)
        res.terms[k++] = poly_2.terms[j++];

    res.num_of_terms = k;

    printf("The sum is :\n");
    sort_terms(&res);
    print_polynomial(&res);
    return 0;
}