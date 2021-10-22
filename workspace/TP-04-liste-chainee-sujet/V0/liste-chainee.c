#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
	Liste l;
	l = malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
	Liste ltete;
	ltete = creer(v);
	ltete->suiv = l;
	return ltete;
}

void afficheElement(Element e)
{
	printf("%i ", e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
	if (estVide(l))
	{
		printf("Liste vide");
	}
	else
	{
		while (!estVide(l))
		{
			afficheElement(l->val);
			l = l->suiv;
		}
		printf("\n");
	}
}

// version recursive
void afficheListe_r(Liste l)
{
	if (!estVide(l))
	{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else
	{
		printf("\n");
	}
}

void detruireElement(Element e)
{
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
	Liste temp;
	while (!estVide(l))
	{
		temp = l;
		l = l->suiv;
		detruireElement(temp->val);
		free(temp);
	}
}

// version récursive
void detruire_r(Liste l)
{
	if (!estVide(l))
	{
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{
	Liste lfin = creer(v);
	Liste temp = l;
	if (estVide(l))
	{
		return lfin;
	}
	while (!estVide(temp->suiv))
	{
		temp = temp->suiv;
	}
	temp->suiv = lfin;
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
	if (estVide(l))
	{
		return creer(v);
	}
	else
	{
		l->suiv = ajoutFin_r(v, l->suiv);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
	while (!estVide(l) && !equalsElement(l->val, v))
	{
		l = l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
	if (estVide(l))
	{
		return l;
	}
	if (equalsElement(l->val, v))
	{
		return l;
	}
	else
	{
		return cherche_r(v, l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
	Liste lien, temp;
	if (estVide(l))
	{
		return l;
	}
	if (equalsElement(l->val, v))
	{
		temp = l->suiv;
		l->suiv = NULL;
		detruire_i(l);
		return temp;
	}

	lien = l;
	temp = l->suiv;
	while (!estVide(temp) && !equalsElement(temp->val, v))
	{
		lien = temp;
		temp = temp->suiv;
	}
	if (!estVide(temp))
	{
		lien->suiv = temp->suiv;
		temp->suiv = NULL;
		detruire_i(temp);
	}
	return l;
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
	if (estVide(l))
	{
		return l;
	}
	if (equalsElement(l->val, v))
	{
		Liste temp = l->suiv;
		l->suiv = NULL;
		detruire_i(l);
		return temp;
	}
	l->suiv = retirePremier_r(v, l->suiv);
	return l;
}

void afficheEnvers_r(Liste l)
{
	if (!estVide(l))
	{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}
