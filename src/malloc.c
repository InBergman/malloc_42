#include "malloc.h"

// La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur la mémoire allouée.

void		*ft_malloc(size_t size)
{
	static t_memory_trace memory_data;

	// Tiny  = 16 bytes  -> size * 16
	// Small = 512 bytes -> size * 512
	// Large = 4 Kb 	 -> size * 4000

	int full_memory_page_size = (16 * 125) + (512 * 32) + (4000 * 25);

	//@TODO: a ajouter ?  | MAP_FIXED

	memory_data.beginning_of_memory = mmap(0, full_memory_page_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	memory_data.end_of_memory = memory_data.beginning_of_memory + size;
	printf("[0][MEMORY_ADDRESS]::[BEGIN] %p\n", memory_data.beginning_of_memory);
	printf("[1][MEMORY_ADDRESS]::[ END ] %p\n", memory_data.end_of_memory);

	return memory_data.beginning_of_memory;
}