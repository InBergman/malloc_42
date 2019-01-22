#ifndef MALLOC_H
#define MALLOC_H


#include "stdio.h"
#include "stdlib.h"
#include "sys/mman.h"
#include <unistd.h>


#define	TINY  16
#define	SMALL 512
#define	LARGE 4000
#define MEMORY_PAGE_SIZE 120400


typedef struct	s_memory_trace
{
	void*	beginning_of_memory;
	void*	end_of_memory;
	size_t	block_number;
	size_t	page_number;

	size_t buck_num;  //number of data segment
	size_t buck_size; //size of a data segment
	void *page;
	void *freeinfo;

}		t_memory_trace;


void       ft_free(void *ptr);
void       *ft_malloc(size_t size);
void       *ft_realloc(void *ptr, size_t size);


#endif