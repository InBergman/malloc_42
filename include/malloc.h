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


typedef struct						s_memory_page
{
	size_t							memory_left;
	size_t 							page_is_full;  // 0:no 1:yes
	void*							memory_addr;
	t_memory_blocks*				blocks;
	struct s_memory_page*			next;

}									t_memory_page;


typedef struct						s_memory_blocks
{
	void*							beginning_of_memory;

	size_t							is_free; // 1:no 0:yes
	size_t 							block_size;
	struct s_memory_blocks* 		next;

}									t_memory_blocks;


void								ft_free(void *ptr);
void								*ft_malloc(size_t size);
void								*ft_realloc(void *ptr, size_t size);

#endif