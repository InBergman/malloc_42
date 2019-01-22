#include "malloc.h"

// La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur la mémoire allouée.

void		*ft_malloc(size_t size)
{
	static t_memory_trace memory_data;
	// int full_memory_page_size = 118384;
	// int full_memory_page_size = 120400;

	// Si premier malloc:
		// 1: Alors mmap une page.
		// 2: Classifier la taille du l'allocation memoire.
	// Sinon:
		// Classifier la taille du l'allocation memoire.
		// Si espace insufisant dans l'espace memoire reserver:
			// 1: Allouer nouvel espace sur une nouvelle page.
			// 2: retourner l'addresse de l'espace alloué.
	
	if (size <= TINY)
	{
		printf("TINY\n");
	}
	if (size > TINY && size <= SMALL)
	{
		printf("SMALL\n");
	}
	else
	{
		printf("LARGE\n");
	}
	//@TODO: a ajouter ?  | MAP_FIXED

	memory_data.beginning_of_memory = mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// memory_data.end_of_memory = memory_data.beginning_of_memory + size;
	// printf("[0][MEMORY_ADDRESS]::[BEGIN] %p\n", memory_data.beginning_of_memory);
	// printf("[1][MEMORY_ADDRESS]::[ END ] %p\n", memory_data.end_of_memory);

	return memory_data.beginning_of_memory;
}