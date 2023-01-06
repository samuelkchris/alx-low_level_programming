#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size) {
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL) {
        return NULL;
    }
    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t*));
    if (ht->array == NULL) {
        free(ht);
        return NULL;
    }
    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value) {
    if (ht == NULL || key == NULL || value == NULL) {
        return 0;
    }
    unsigned long int index = hash(key) % ht->size;
    shash_node_t *cur = ht->array[index];
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            free(cur->value);
            cur->value = strdup(value);
            if (cur->value == NULL) {
                return 0;
            }
            return 1;
        }
        cur = cur->next;
    }

    shash_node_t *new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL) {
        return 0;
    }
    new_node->key = strdup(key);
    if (new_node->key == NULL) {
        free(new_node);
        return 0;
    }
    new_node->value = strdup(value);
    if (
new_node->value == NULL) {
free(new_node->key);
free(new_node);
return 0;
}
new_node->next = ht->array[index];
ht->array[index] = new_node;
	if (ht->shead == NULL) {
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->shead = new_node;
    ht->stail = new_node;
} else if (strcmp(ht->shead->key, key) > 0) {
    new_node->sprev = NULL;
    new_node->snext = ht->shead;
    ht->shead->sprev = new_node;
    ht->shead = new_node;
} else {
    shash_node_t *tmp = ht->shead;
    while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0) {
        tmp = tmp->snext;
    }
    new_node->sprev = tmp;
    new_node->snext = tmp->snext;
    if (tmp->snext != NULL) {
        tmp->snext->sprev = new_node;
    } else {
        ht->stail = new_node;
    }
    tmp->snext = new_node;
}

return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key) {
if (ht == NULL || key == NULL) {
return NULL;
}
unsigned long int index = hash(key) % ht->size;
shash_node_t *cur = ht->array[index];
while (cur != NULL) {
if (strcmp(cur->key, key) == 0) {
return strdup(cur->value);
}
cur = cur->next;
}
return NULL;
}

void shash_table_print(const shash_table_t *ht) {
shash_node_t *cur = ht->shead;
while (cur != NULL) {
printf("%s: %s\n", cur->key, cur->value);
cur = cur->snext;
}
}

void shash_table_print_rev(const shash_table_t *ht) {
shash_node_t *cur = ht->stail;
while (cur != NULL) {
printf("%s: %s\n", cur->key, cur->value);
cur = cur->sprev;
}
}

void free_shash_node(shash_node_t *node) {
free(node->key);
free(node->value);
free(node);
}

void shash_table_delete(shash_table_t *ht) {
if (ht == NULL) {
return;
}
for (unsigned long int i = 0; i < ht->size; i++) {
	shash_node_t *cur = ht->array[i];
while (cur != NULL) {
shash_node_t *temp = cur;
cur = cur->next;
free_shash_node(temp);
}
}
free(ht->array);
free(ht);
}
