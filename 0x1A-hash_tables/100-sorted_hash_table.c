#include "hash_tables.h"
#include <string.h>
/**
 * shash_table_create - create a sorted hash table
 * @size: size of hash table
 *
 * Return: hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;

	if (size != 0)
		ht = malloc(sizeof(*ht));
	if (ht)
	{
		ht->size = size;
		ht->array = malloc(sizeof(*ht->array) * size);
		if (!ht->array)
		{
			free(ht);
			return (NULL);
		}
		while (size--)
			ht->array[size] = NULL;
		ht->shead = NULL;
		ht->stail = NULL;
	}
	return (ht);
}
/**
 * shash_set_helper - add node into sorted linked list
 * @ht: hash table
 * @newNode: newNode
 */
void shash_set_helper(shash_table_t *ht, shash_node_t *newNode)
{
	shash_node_t *ptr = NULL;

	newNode->sprev = NULL;
	newNode->snext = ht->shead;
	if (!ht->shead || strcmp(newNode->key, ht->shead->key) <= 0)
	{
		if (ht->shead)
			ht->shead->sprev = newNode;
		ht->shead = newNode;
		if (!ht->stail)
			ht->stail = newNode;
	}
	else
	{
		do {
			ptr = newNode->snext;
			newNode->snext = ptr->snext;
		} while (newNode->snext &&
			 strcmp(newNode->key, newNode->snext->key) > 0);
		newNode->sprev = ptr;
		if (ptr->snext)
			ptr->snext->sprev = newNode;
		else
			ht->stail = newNode;
		ptr->snext = newNode;
	}
}
/**
 * shash_table_set - add a node into hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *newNode = NULL, *ptr = NULL;

	if (!ht || !ht->array || !key || !*key || !value)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	ptr = ht->array[index];
	/* see if key already exists */
	while (ptr)
	{
		if (!strcmp(ptr->key, key))
		{
			free(ptr->value);
			ptr->value = strdup(value);
			return (1);
		}
		ptr = ptr->next;
	}
	/* add new key entry */
	newNode = malloc(sizeof(*newNode));
	if (!newNode)
		return (0);
	newNode->key = strdup(key);
	newNode->value = strdup(value);
	if (!newNode->key || !newNode->value)
	{
		free(newNode->key);
		free(newNode->value);
		free(newNode);
		return (0);
	}
	newNode->next = ht->array[index] ? ht->array[index] : NULL;
	ht->array[index] = newNode;

	/* add to sorted linked list */
	shash_set_helper(ht, newNode);
	return (1);
}
/**
 * shash_table_get - get a value from the hash table associated with key
 * @ht: hash table
 * @key: key
 *
 * Return: vlaue, NULL if key DNE
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *ptr = NULL;

	if (!ht || !ht->array || !key || *key == 0)
		return (NULL);
	index = key_index((const unsigned char *) key, ht->size);
	for (ptr = ht->array[index]; ptr; ptr = ptr->next)
		if (!strcmp(ptr->key, key))
			return (ptr->value);
	return (NULL);
}
/**
 * shash_table_print - print hash table in order
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *ptr = NULL;
	int isFirst = 1;

	if (!ht || !ht->array)
		return;
	printf("{");
	for (ptr = ht->shead; ptr; ptr = ptr->snext)
	{
		if (isFirst)
		{
			isFirst = 0;
			printf("\'%s\': ", ptr->key);
		}
		else
			printf(", \'%s\': ", ptr->key);
		printf("\'%s\'", ptr->value);
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - print sorted hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *ptr = NULL;
	int isFirst = 1;

	if (!ht || !ht->array)
		return;
	printf("{");
	for (ptr = ht->stail; ptr; ptr = ptr->sprev)
	{
		if (isFirst)
		{
			isFirst = 0;
			printf("\'%s\': ", ptr->key);
		}
		else
			printf(", \'%s\': ", ptr->key);
		printf("\'%s\'", ptr->value);
	}
	printf("}\n");
}
/**
 * shash_table_delete - delete a hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *ptr = NULL, *tmp = NULL;

	if (ht)
	{
		for (i = 0; i < ht->size; i++)
		{
			ptr = ht->array[i];
			while (ptr)
			{
				free(ptr->key);
				free(ptr->value);
				tmp = ptr;
				ptr = ptr->next;
				free(tmp);
			}
		}
		free(ht->array);
		ht->array = NULL;
		free(ht);
	}
}
