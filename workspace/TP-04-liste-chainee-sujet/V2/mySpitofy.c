// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./linkedListOfString

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// Definitions of external functions
// ============

void afficheElement(Element e)
{
    Musique *mus = (Musique *)e;
    printf("%s,", mus->name);
    printf("%s,", mus->artist);
    printf("%s,", mus->album);
    printf("%s,", mus->genre);
    printf("%s,", mus->discNumber);
    printf("%s,", mus->trackNumber);
    printf("%s", mus->year);
    printf("\n");
}

void detruireElement(Element e)
{
    Musique *mus = (Musique *)e;
    free(mus->name);
    mus->name = NULL;
    free(mus->genre);
    mus->genre = NULL;
    free(mus->album);
    mus->album = NULL;
    free(mus->artist);
    mus->artist = NULL;
    free(mus->discNumber);
    mus->discNumber = NULL;
    free(mus->trackNumber);
    mus->trackNumber = NULL;
    free(mus->year);
    mus->year = NULL;
    free(mus);
    e = NULL;
}

// compare deux elements
// 0 --> false
// 1 --> true
bool equalsElement(Element e1, Element e2)
{
    Musique *mus1 = (Musique *)e1;
    Musique *mus2 = (Musique *)e2;

    if (strcmp(mus1->name, mus2->name) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->genre, mus2->genre) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->album, mus2->album) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->artist, mus2->artist) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->discNumber, mus2->discNumber) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->trackNumber, mus2->trackNumber) != 0)
    {
        return 0;
    }
    if (strcmp(mus1->year, mus2->year) != 0)
    {
        return 0;
    }
    return 1;
}

// Fonction pour lire le fichier csv en entrée
Liste readFile(FILE *csv)
{
    Liste l;
    l = NULL;
    Musique *musicTemp;
    char *line, *copy, *value, *tracer;
    line = calloc(256, sizeof(char));
    while (fgets(line, 256, csv) != NULL)
    {
        musicTemp = (Musique *)malloc(sizeof(Musique));
        copy = strdup(line);
        tracer = copy;

        value = strsep(&copy, ",\n");
        musicTemp->name = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->name, value);

        value = strsep(&copy, ",\n");
        musicTemp->artist = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->artist, value);

        value = strsep(&copy, ",\n");
        musicTemp->album = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->album, value);

        value = strsep(&copy, ",\n");
        musicTemp->genre = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->genre, value);

        value = strsep(&copy, ",\n");
        musicTemp->discNumber = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->discNumber, value);

        value = strsep(&copy, ",\n");
        musicTemp->trackNumber = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->trackNumber, value);

        value = strsep(&copy, ",\n");
        musicTemp->year = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->year, value);

        l = ajoutFin_i(musicTemp, l);
        free(tracer);
    }
    free(line);
    return l;
}

// ============
// main
// ============

int main(void)
{
    FILE *fichierCsv;
    fichierCsv = fopen("music.csv", "r");
    Liste playlist;
    playlist = readFile(fichierCsv);
    afficheListe_i(playlist);
    detruire_i(playlist);
    fclose(fichierCsv);
    return EXIT_SUCCESS;
}