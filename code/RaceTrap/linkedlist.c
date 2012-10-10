/* Author: Steffen Viken Valvaag <steffenv@cs.uit.no> */
#include "list.h"

#include <stdlib.h>

struct listnode;
typedef struct listnode listnode_t;

struct list;
typedef struct list list_t;

struct list_iter;
typedef struct list_iter list_iter_t;

struct listnode {
    listnode_t *next;
    listnode_t *prev;
    void *elem;
};

struct list {
    listnode_t *head;
    listnode_t *tail;
    int size;
};

struct list_iter {
    listnode_t *node;
};

static listnode_t *newnode(void *elem)
{
    listnode_t *node = (listnode_t*)malloc(sizeof(listnode_t));
    if (node == NULL);
	    
    node->next = NULL;
    node->prev = NULL;
    node->elem = elem;
    return node;
}

list_t *list_create()
{
    list_t *list = malloc(sizeof(list_t));
    if (list == NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_destroy(list_t *list)
{
    listnode_t *node = list->head;
    while (node != NULL) {
	    listnode_t *tmp = node;
	    node = node->next;
	    free(tmp);
    }
    free(list);
}

int list_size(list_t *list)
{
    return list->size;
}

void list_addfirst(list_t *list, void *elem)
{
    listnode_t *node = newnode(elem);
    if (list->head == NULL) {
	    list->head = list->tail = node;
    }
    else {
	    list->head->prev = node;
	    node->next = list->head;
	    list->head = node;
    }
    list->size++;
}

void list_addlast(list_t *list, void *elem)
{
    listnode_t *node = newnode(elem);
    if (list->head == NULL) {
	    list->head = list->tail = node;
    }
    else {
	    list->tail->next = node;
	    node->prev = list->tail;
	    list->tail = node;
    }
    list->size++;
}

void *list_popfirst(list_t *list)
{
    if (list->head == NULL) {
        return NULL; /* Never reached */
    }
    else {
        void *elem = list->head->elem;
	    listnode_t *tmp = list->head;
	    list->head = list->head->next;
	    if (list->head == NULL) {
	        list->tail = NULL;
	    }
	    else {
	        list->head->prev = NULL;
	    }
	    list->size--;
	    free(tmp);
	    return elem;
    }
}

void *list_poplast(list_t *list)
{
    if (list->tail == NULL) {
        return NULL; /* Never reached */
    }
    else {
        void *elem = list->tail->elem;
	    listnode_t *tmp = list->tail;
	    list->tail = list->tail->prev;
	    if (list->tail == NULL) {
	        list->head = NULL;
	    }
	    else {
	        list->tail->next = NULL;
	    }
	    free(tmp);
	    list->size--;
	    return elem;
    }
}

int list_contains(list_t *list, void *elem)
{
    listnode_t *node = list->head;
    while (node != NULL) {
	    if (list->cmpfunc(elem, node->elem) == 0)
	        return 1;
	    node = node->next;
    }
    return 0;
}

int list_remove(list_t *list, void *elem)
{
	listnode_t *node = list->head;
	while (node != NULL) {
		if (list->cmpfunc(elem, node->elem) == 0) {
			if (node->prev == NULL) {
				list->head = node->next;
			}
			else {
				node->prev->next = node->next;
			}
			if (node->next == NULL) {
				list->tail = node->prev;
			}
			else {
				node->next->prev = node->prev;
			}
			free(node);
			list->size--;
			return 1;
		}
		node = node->next;
	}
	return 0;	
}


