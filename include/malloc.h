#ifndef MALLOC_H
#define MALLOC_H


#include "stdio.h"
#include "stdlib.h"
#include "sys/mman.h"


typedef struct	s_memory_trace
{
	void*	beginning_of_memory;
	void*	end_of_memory;

}		t_memory_trace;


void       ft_free(void *ptr);
void       *ft_malloc(size_t size);
void       *ft_realloc(void *ptr, size_t size);


#endif