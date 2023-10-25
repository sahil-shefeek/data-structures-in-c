#include <stdio.h>
#define SIZE 20

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

void simplfy_terms(Polynomial *poly)
{
    // Todo
}

Term multiply(Term term1, Term term2)
{
    Term res;
    res.coeff = term1.coeff * term2.coeff;
    res.exp = term1.exp + term2.exp;
    return res;
}

int main()
{
    Polynomial poly_1, poly_2, res;
    printf("Enter the degree of first polynomial: ");
    scanf("%d", &poly_1.num_of_terms);
    poly_1.num_of_terms++;
    get_polynomial(&poly_1);
    printf("You have entered: \n");
    print_polynomial(&poly_1);

    printf("Enter the degree of second polynomial: ");
    scanf("%d", &poly_2.num_of_terms);
    poly_2.num_of_terms++;
    get_polynomial(&poly_2);
    printf("You have entered: \n");
    print_polynomial(&poly_2);

    int i = 0, k = 0;
    while (i < poly_1.num_of_terms)
    {
        int j = 0;
        while (j < poly_2.num_of_terms)
            res.terms[k++] = multiply(poly_1.terms[i], poly_2.terms[j++]);
        i++;
    }
    res.num_of_terms = k++;

    printf("The product is :\n");
    print_polynomial(&res);
    return 0;
}
