/*
** EPITECH PROJECT, 2021
** Projets_tek2
** File description:
** malloc
*/

#include "malloc.h"

s_block_t *request_space(size_t size)
{
    s_block_t *block = NULL;
    void *tmp_brk = sbrk(0);

    void *request = sbrk(size + STRUCT_SIZE);
    if (request == (void *) -1) {
        return NULL;
    }
    block = sbrk(0);
    block->adress = tmp_brk + STRUCT_SIZE;
    block->size = size;
    block->next = NULL;
    return block;
}

void *find_free_block(size_t size)
{
    s_block_t *pointeur = _glob_struct;

    for (; pointeur; pointeur = pointeur->next){
        if (size <= pointeur->size && pointeur->free == 1){
            pointeur->free = 0;
            return (pointeur->adress);
        }
    }

    for (pointeur = _glob_struct; pointeur->next; pointeur = pointeur->next);
    pointeur->next = request_space(size);
    return (pointeur->next->adress);
}

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
    if (_glob_struct == NULL) {
        return sbrk(getpage * np2);
    } else {
        p = find_free_block(size);
        if (p == NULL)
            return NULL;
        return p;
    }
    return p;
}

void free(void *ptr)
{
    if (ptr == NULL)
        return;

    s_block_t *p = _glob_struct;

    for (; p; p = p -> next){
        if (p->adress == ptr){
            memset(p->adress, 0, p->size);
            p->free = 1;
            return;
        }
    }
}

void *realloc(void *ptr, size_t size)
{
    s_block_t *p = _glob_struct;

    for (; p; p = p->next) {
        if (p->adress == ptr) {
            void *memr = malloc(p->size + size);
            if (memr == NULL) {
                return (NULL);
            }
            memcpy(memr, p->adress, p->size);
            free(p->adress);
            return (memr);
        }
    }
    return (malloc(size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}