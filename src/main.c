#include "malloc.h"


// @TODO: Chaque zone doit pouvoir contenir au moins 100 allocations.
// @TODO: Les mallocs “TINY”, de 1 à n octets, seront stockés dans des zones de N octets
// @TODO: Les mallocs “SMALL”, de (n+1) à m octets, seront stockés dans des zones de M octets
// @TODO: Les mallocs “LARGE”, de (m+1) octets et plus, seront stockés hors zone, c’est à dire simplement avec un mmap(), ils seront en quelquesorte une zone à eux tout seul.
// @TODO: C’est à vous de définir la taille de n, m, N et M afin de trouver un bon compromis entre vitesse (économie d’appel système) et économie de mémoire.


// @TODO: Vous devez également écrire une fonction permettant d’afficher l’état des zones mé- moires allouées. Elle devra être prototypée comme suit :

// void      show_alloc_mem();

// @TODO: L’affichage sera formaté par adresse croissante comme dans l’exemple suivant :

// TINY : 0xA0000
// 0xA0020 - 0xA004A : 42 octets
// 0xA006A - 0xA00BE : 84 octets
// SMALL : 0xAD000
// 0xAD020 - 0xADEAD : 3725 octets
// LARGE : 0xB0000
// 0xB0020 - 0xBBEEF : 48847 octets
// Total : 52698 octets





// La fonction free() libère l’allocation de la mémoire pointée par “ptr”. Si “ptr” vaut NULL, free() ne fait rien.
// void       ft_free(void *ptr)
// {
	// munmap();
// }


// int 		main(int ac, char** av)
// {
// 	int size_to_alloc;
// 	char char_to_print;
// 	int iterator;
// 	char *test_string;

// 	ac = 0;
// 	size_to_alloc = sizeof(char) * atoi(av[2]);
// 	char_to_print = av[1][0];
// 	iterator = 0;
// 	test_string = (char*)ft_malloc(size_to_alloc);

// 	while(iterator < size_to_alloc)
// 	{
// 		test_string[iterator] = char_to_print;
// 		iterator++;
// 	}
// 	test_string[iterator] = '\0';
// 	printf("%s", test_string);

// 	return(0);
// }


int main()
{
	// int size = 1;
	void* gm1 = NULL;
	// void* gm2 = NULL;

	gm1 = ft_malloc(1);
	// printf("[3][MAIN] :: %lu\n", size * sizeof(int));

}