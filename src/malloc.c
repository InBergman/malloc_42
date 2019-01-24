#include "malloc.h"


// @TODO: Quand tous les blocks remplissent l'espace initialement alloue, indiquer que la page est full.
// @TODO: Checker si page est full avant de rechercher un block free.


// La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur la mémoire allouée.

static void
new_block_allocation(t_memory_blocks memory_block, t_memory_page memory_page, size_t size)
{
		memory_block.beginning_of_memory 	= memory_page.memory_addr;
		memory_block.is_free				= 1;
		memory_block.block_size				= size;
		
		if (size <= TINY)
			memory_block.type = 1;
		else if (size <= SMALL && size > TINY)
			memory_block.type = 2;
		else
			memory_block.type = 3;
}


void*
ft_malloc(size_t size)
{
	static t_memory_page *memory_page;
	t_memory_page *head_memory_page = NULL;
	void* memory_to_return = NULL;

	if (memory_page)
	{
		head_memory_page = memory_page;
		
		while(memory_page->page_is_full == 1)
			memory_page = memory_page->next;
		
		while(memory_page->blocks->next)
			memory_page->blocks = memory_page->next;

		memory_page->blocks->next = mmap(0, sizeof(t_memory_blocks*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		new_block_allocation(*(memory_page->blocks), *(memory_page), size);		
	}
	else
	{
		memory_page 								= mmap(0, sizeof(t_memory_page*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		head_memory_page 							= memory_page;
		memory_page->memory_addr 					= mmap(0, 120400, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		memory_page->blocks 						= mmap(0, sizeof(t_memory_blocks*), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		
		new_block_allocation(*(memory_page->blocks), *(memory_page), size);

		printf("[0][memory_addr] %p\n", memory_page->memory_addr);
		printf("[1][beginning_of_memory] %p\n", memory_page->blocks->beginning_of_memory);
		printf("[2][is_free] %zu\n", memory_page->blocks->is_free);
		printf("[3][block_size] %zu\n", memory_page->blocks->block_size);
	}


	memory_to_return = memory_page->blocks->beginning_of_memory;
	if(head_memory_page != NULL)
		memory_page = head_memory_page;

	return memory_to_return;
}