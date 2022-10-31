#include "main.h"

/**
 * File: 100-elf_header.c
 */

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to an array
 * Description: if the file is 
 */

void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prinrs the magic numbers
 * @e_ident: pointer
 * Description: magic no
 */

void print_magic(unsigned char *e_ident)
{
	int x;

	printf(" Magic:  ");

	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%02x", e_ident[x]);

		if (x == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of ELF header
 * @e_ident: a pointer to an array
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:

			switch
