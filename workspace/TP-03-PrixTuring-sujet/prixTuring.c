/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char *scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize + 1, sizeof(char));

	scanf("%250[^\n]", line);

	if ((c = getchar()) != '\n')
	{
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars until the end of line
		while (((c = getchar()) != '\n') && c != EOF)
			;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt()
{
	int buf;
	scanf("%i\n", &buf);
	return buf;
}

struct gagnantTuring
{
	int annee;
	char *noms;
	char *raison;
};
typedef struct gagnantTuring GagnantTuring;

void readWinners(GagnantTuring **g, int nb)
{
	*g = (GagnantTuring *)malloc(sizeof(GagnantTuring) * nb);
	for (int i = 0; i < nb; i++)
	{
		(*g)[i].annee = scanLineAsInt();
		(*g)[i].noms = scanLine();
		(*g)[i].raison = scanLine();
	}
}

void printWinners(GagnantTuring *g, int nb){
	printf("%i\n",nb);
	for (int t = 0; t < nb; t++){
		printf("%i\n%s\n%s\n", g[t].annee, g[t].noms, g[t].raison);
	}
}

void infosAnnee(GagnantTuring *g, int nb,int an){
	for (int i=0;i<nb;i++){
		if(g[i].annee == an){
			printf("L'année %i, le gagnant a été %s \nNature des travaux:%s",g[i].annee,g[i].noms,g[i].raison);
		
		}
	}
}

int main(void)
{

	GagnantTuring *G;
	int nbGagnants = scanLineAsInt();
	readWinners(&G, nbGagnants);
	printWinners(G, nbGagnants);
	infosAnnee(G, nbGagnants, 1969);
	free(G);

	return EXIT_SUCCESS;
}
