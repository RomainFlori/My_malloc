/*
** EPITECH PROJECT, 2021
** Projets_tek2
** File description:
** calloc
*/

#include <unistd.h>

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;

    size_t *new_tab = malloc(nmemb * size);
    size_t x = nmemb * size;

    for (size_t i = 0; i < x; i++) {
        new_tab[i] = 0;
    }

    return new_tab;
}
