#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void echangeContenu(int *a, int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

int estConvexe(int tab[], int length)
{
    int nbChange = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (tab[i] != tab[i + 1])
        {
            nbChange++;
        }
    }
    if (nbChange == 0 || nbChange == 1)
    {
        return 1;
    }
    if (nbChange == 2)
    {
        if (tab[0] == tab[length - 1])
        {
            return 1;
        }
    }
    return 0;
}

void mult_matrice(int64_t matResultat[5][5], int64_t matA[5][5], int64_t matB[5][5])
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            for (int i = 0; i < 5; i++)
            {
                matResultat[x][y] = matResultat[x][y] + ((matA[i][y]) * (matB[x][i]));
            }
        }
    }
}

void affiche_matrice(int64_t matrice[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%ld ", matrice[i][j]);
        }
        printf("\n");
    }
}
enum mois
{
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};
typedef enum mois Mois;

struct date
{
    int jour;
    Mois mois;
    int annee;
};
typedef struct date Date;

void initialiseDate(Date *d)
{
    printf("Entrez le jour :");
    int j;
    scanf("%i", &j);
    printf("Entrez le mois :");
    int m;
    scanf("%i", &m);
    printf("Entrez le annee :");
    int a;
    scanf("%i", &a);

    d->annee = a;
    d->mois = m;
    d->jour = j;
}

void afficheDate(Date *d)
{
    printf("Nous somme le %i %i %i \n", d->jour, d->mois, d->annee);
}

Date creerDateParCopie()
{
    Date d;
    printf("Entrez le jour :");
    scanf("%i", &d.jour);
    printf("Entrez le mois :");
    scanf("%i", (int *)&d.mois);
    printf("Entrez le annee :");
    scanf("%i", &d.annee);
    return d;
}

Date *newDate()
{
    Date *d;
    d = malloc(sizeof(*d));
    printf("Entrez le jour :");
    int j;
    scanf("%i", &j);
    printf("Entrez le mois :");
    int m;
    scanf("%i", &m);
    printf("Entrez le annee :");
    int a;
    scanf("%i", &a);

    d->annee = a;
    d->mois = m;
    d->jour = j;
    return d;
}

int main(void)
{
    //int a=1,b=2;
    //echangeContenu (&a,&b);
    //printf("%d, %d",a,b);

    // int t1[]={0,1,1,0,0};
    // int t2[]={1,1,0,0,1};
    // int t3[]={1,1,0,1,0};
    // int test1=estConvexe(t1,5);
    // int test2=estConvexe(t2,5);
    // int test3=estConvexe(t3,5);
    // printf("%d, %d, %d", test1,test2,test3);

    // int64_t matrice1[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    // int64_t matrice2[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    // int64_t matriceZero[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    // mult_matrice(matriceZero, matrice1, matrice2);
    // affiche_matrice(matriceZero);

    Date d;
    initialiseDate(&d); //On ajoute un & pour pouvoir modifier d dans la fonction
    afficheDate(&d);
    Date d2 = creerDateParCopie();
    afficheDate(&d2);
    Date *d3;
    d3 = newDate();
    afficheDate(d3);

    free(d3);

    return 0;
}
