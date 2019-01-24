#include "malloc.h"

// La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur la mémoire allouée.
// @TODO: Checker si page est full avant de rechercher un block free.


void		*ft_malloc(size_t size)
{
	static t_memory_page *memory_page;
	t_memory_page *head_memory_page = NULL;
	void* tmp = NULL;

	if (memory_page)
	{
		head_memory_page = memory_page;
		if()
	}
	else
	{
		memory_page 									= mmap(0, sizeof(t_memory_page*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		memory_page->memory_addr 						= mmap(0, 120400, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		memory_page->blocks 							= mmap(0, sizeof(t_memory_blocks*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		memory_page->blocks->beginning_of_memory 		= memory_page->memory_addr;
		memory_page->blocks->is_free					= 1;
		memory_page->blocks->block_size					= size;
		head_memory_page 								= memory_page;
	}

	if(head_memory_page != NULL)
		memory_page = head_memory_page;

	return tmp;
}















	// memory_page->next = mmap(0, sizeof(t_memory_page*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// printf("[4][MEMORY_ADDRESS] %zu\n", ++(memory_page->page_is_full));
	// printf("[5][MEMORY_ADDRESS] %zu\n", ++(memory_page->memory_left));
