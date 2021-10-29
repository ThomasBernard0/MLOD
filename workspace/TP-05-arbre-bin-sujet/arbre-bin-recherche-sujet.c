#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
	return true;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
	ArbreBinaire a;
	a = malloc(sizeof(ArbreBinaire));
	a->val = e;
	initialiser(&a->filsGauche);
	initialiser(&a->filsDroit);
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e)
{
	ArbreBinaire temp;
	ArbreBinaire newNode = creer(e);
	temp = a;
	while (!estVide(temp))
	{
		if (e == temp->val)
		{
			return a;
		}
		if (e < temp->val)
		{
			if (estVide(temp->filsGauche))
			{
				temp->filsGauche = newNode;
				return a;
			}
			temp = temp->filsGauche;
		}
		else
		{
			if (estVide(temp->filsDroit))
			{
				temp->filsDroit = newNode;
				return a;
			}

			temp = temp->filsDroit;
		}
	}
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
	if (estVide(a))
	{
		return creer(e);
	}
	if (e < a->val)
	{
		a->filsGauche = insere_r(a->filsGauche, e);
	}
	if (e > a->val)
	{
		a->filsDroit = insere_r(a->filsDroit, e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	if (estVide(a))
	{
		return 0;
	}
	else
	{
		return 1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche);
	}
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	if (estVide(a))
	{
		return -1;
	}
	if (a->val == e)
	{
		return 0;
	}
	else
	{
		if (e < a->val)
		{
			return 1 + profondeur(a->filsGauche, e);
		}
		else
		{
			return 1 + profondeur(a->filsDroit, e);
		}
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	if (estVide(a))
	{
		return 0;
	}
	int hauteurGauche = hauteur(a->filsGauche);
	int hauteurDroite = hauteur(a->filsDroit);
	if (hauteurGauche >= hauteurDroite)
	{
		return hauteurGauche + 1;
	}
	else
	{
		return hauteurDroite + 1;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{

	return NULL;
}

void afficheRGD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("%i", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheRGD_r(a->filsGauche);
		printf("%i", a->val);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		printf("%i", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	while (!estVide(a->filsGauche))
	{
		a = a->filsGauche;
	}
	return a;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	while (!estVide(a->filsDroit))
	{
		a = a->filsDroit;
	}
	return a;
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{

	return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a)
{
}
