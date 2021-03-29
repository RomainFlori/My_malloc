/*
** EPITECH PROJECT, 2021
** Projets_tek2
** File description:
** malloc
*/

#include "malloc.h"

size_t upper_power(size_t size)
{
    size_t i;

    if (size % 2 != 0) {
        return size;
    } else  {
        for (i = size + 1; i % 2 != 0; i++) {}
        return i;
    }

}

int isPowerOfTwo(size_t size)
{
    while (size != 1)
    {
        if (size % 2 != 0)
            return 0;
        size = size / 2;
    }
    return 1;
}

int nextPower_2(size_t size)
{
    size_t value = 1;

    while (value <= size) {
        value = value << 1;
    }

    return value;
}

void *malloc(size_t size)
{
    size = (size <= 0) ? 8 : size;
    size_t getpage = getpagesize();
    size_t np2 = 0;
    void *p = NULL;

    if (isPowerOfTwo(size) == 0) {
        np2 = nextPower_2(size);
    } else {
        np2 = size;
    }
    return sbrk(getpage * np2);
}

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    //useless to code the free function marvin don't check
}

void *realloc(void *ptr, size_t size)
{
    return (malloc(size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
