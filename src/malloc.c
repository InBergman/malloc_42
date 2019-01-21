#include "malloc.h"


// La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur la mémoire allouée.

void		*ft_malloc(size_t size)
{
	static t_memory_trace memory_data;

	memory_data.beginning_of_memory = mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	memory_data.end_of_memory = memory_data.beginning_of_memory + size;
	printf("[0][MEMORY_ADDRESS]::[BEGIN] %p\n", memory_data.beginning_of_memory);
	printf("[1][MEMORY_ADDRESS]::[ END ] %p\n", memory_data.end_of_memory);

	return memory_data.beginning_of_memory;
}