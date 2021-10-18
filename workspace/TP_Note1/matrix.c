#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Matrix
{
    int valeur[5][5];
    int nbLigne;
    int nbColonne;
};
typedef struct Matrix Matrice;

struct MatrixArray
{
    Matrice matrices[9];
    int nbMatrice;
};
typedef struct MatrixArray MatriceTableau;

void readMatrix(Matrice **sousmatrice)
{
    int newvaleur;
    for (int i = 0; i < (*sousmatrice)->nbLigne; i++)
    {
        for (int j = 0; j < (*sousmatrice)->nbColonne; j++)
        {
            scanf("%i", &newvaleur);
            sousmatrice[i][j].valeur = newvaleur;
        }
    }
}

void readMatrixArray(MatriceTableau *resultat, Matrice **matrice)
{
    for (int i = 0; i < resultat->nbMatrice; i++)
    {
        resultat[i] = readMatrix((*resultat).matrices[i]);
    }
}

void printMatrix(Matrice *matrice)
{
    for (int i = 0; i < (*sousmatrice)->nbLigne; i++)
    {
        for (int j = 0; j < (*sousmatrice)->nbColonne; j++)
        {
            printf("%i ", matrice[i][j]);
        }
        printf("\n");
    }
}

void printMatrixArray(MatriceTableau matrices, Matrice *matrice)
{
    for (int i = 0; i < matricces.nbMatrice; i++)
    {
        printMatrix(matrices[i]);
        printf("\n");
    }
}

int main(void)
{
    int nbMat, ligne, colonne;
    scanf("%i", &nbMat);
    scanf("%i %i", &ligne, &colonne);
    MatriceTableau matricetab1;
    matricetab1.nbMatrice = nbMat;
    Matrice sousMatrice;
    sousMatrice.nbColonne = colonne;
    sousMatrice.nbLigne = ligne;
    readMatrixArray(matricetab1, sousMatrice);
    printMatrixArray(matricetab1, sousMatrice);
}