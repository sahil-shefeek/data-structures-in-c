#include <stdio.h>

typedef struct
{
    int coeff;
    int exp;
} Term;

Term poly1[10], poly2[10], res[20];
int res_terms = 0;

void copyTerm(int coef, int exp)
{
    res[res_terms].coeff = coef;
    res[res_terms].exp = exp;
    res_terms++;
}

int readPoly(Term poly[10])
{
    int num_terms;
    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    for (int i = 0; i < num_terms; i++)
    {
        printf("Enter term %d coeff: ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Enter term %d exp: ", i + 1);
        scanf("%d", &poly[i].exp);
    }

    return num_terms;
}

void display(Term poly[20], int num_terms)
{
    int i;
    for (i = 0; i < num_terms - 1; i++)
        printf("%dx^%d + ", poly[i].coeff, poly[i].exp);

    if (poly[i].exp == 0)
        printf("%d", poly[i].coeff);
    else
        printf("%dx^%d", poly[i].coeff, poly[i].exp);

    printf("\n\n");
}

void addPoly(int num_terms_poly1, int num_terms_poly2)
{
    int i = 0, j = 0;

    while (i < num_terms_poly1 && j < num_terms_poly2)
    {
        if (poly1[i].exp == poly2[j].exp)
        {
            copyTerm(poly1[i].coeff + poly2[j].coeff, poly1[i].exp);
            j++;
            i++;
        }
        else if (poly1[i].exp < poly2[j].exp)
        {
            copyTerm(poly2[j].coeff, poly2[j].exp);
            j++;
        }
        else if (poly1[i].exp > poly2[j].exp)
        {
            copyTerm(poly1[i].coeff, poly1[i].exp);
            i++;
        }
    }

    while (i < num_terms_poly1)
    {
        copyTerm(poly1[i].coeff, poly1[i].exp);
        i++;
    }

    while (j < num_terms_poly2)
    {
        copyTerm(poly2[j].coeff, poly2[j].exp);
        j++;
    }
}

int main()
{
    int num_terms_poly1, num_terms_poly2;
    printf("Polynomial 1\n");
    num_terms_poly1 = readPoly(poly1);
    printf("Entered polynomial: ");
    display(poly1, num_terms_poly1);

    printf("Polynomial 2\n");
    num_terms_poly2 = readPoly(poly2);
    printf("Entered polynomial: ");
    display(poly2, num_terms_poly2);

    addPoly(num_terms_poly1, num_terms_poly2);

    printf("Sum: ");
    display(res, res_terms);
}
