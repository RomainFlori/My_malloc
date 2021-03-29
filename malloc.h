/*
** EPITECH PROJECT, 2021
** Projets tek2
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct s_block {
    size_t size;
    void* adress;
    int free;
    struct s_block *next;
} s_block_t;

s_block_t *_glob_struct;

s_block_t *request_space(size_t size);
void *find_free_block(size_t size);


#define STRUCT_SIZE	sizeof(struct s_block)

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void free(void *ptr);


#endif /* !MALLOC_H_ */
