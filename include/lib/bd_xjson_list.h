#ifndef bd_xjson_list_h
#define bd_xjson_list_h

#include "lib/bd_xjson_base.h"
#include "lib/bd_xjson_iter.h"

typedef struct bd_xjson_node bd_xjson_node;
typedef struct bd_xjson_list bd_xjson_list;

struct bd_xjson_node
{
    bd_xjson value;
    bd_xjson_node *next;
    bd_xjson_node *prev;
};


struct bd_xjson_list
{
    bd_xjson_node* head, * tail;
    int size;
};
int list_create(bd_xjson_list** list);
int list_copy(bd_xjson_list* dest, const bd_xjson_list* src);
int list_insert_direct(bd_xjson_list* list, int pos, const bd_xjson* val);
int list_insert(bd_xjson_list* list, int pos, const bd_xjson* val);
int list_erase(bd_xjson_list* list, int pos);
int list_free(bd_xjson_list* list);
int list_find(const bd_xjson_list* list, int pos, bd_xjson* val);
int list_update(bd_xjson_list* list, int pos, const bd_xjson* val);
int list_set(bd_xjson_list* list, int pos, const bd_xjson* val);
void list_qsort(bd_xjson_list* list, int (*compare_fn)(const void*, const void*));
#define bd_xjson_list_foreach(__list, __node) \
    for(bd_xjson_node* __node = __list->head; __node; __node = __node->next)
#define bd_xjson_list_foreach_in_reverse(__list, __node) \
    for(bd_xjson_node* __node = __list->tail; __node; __node = __node->prev)

typedef bd_xjson_iter(bd_xjson_node*, index, bd_xjson_node, data)
    bd_xjson_list_iter;
bd_xjson_list_iter list_begin(const bd_xjson_list* list);
bd_xjson_list_iter list_end(const bd_xjson_list* list);
bd_xjson_list_iter list_iterate(const bd_xjson_list* list, bd_xjson_list_iter iter);
bd_xjson_list_iter list_rbegin(const bd_xjson_list* list);
bd_xjson_list_iter list_rend(const bd_xjson_list* list);
bd_xjson_list_iter list_riterate(const bd_xjson_list* list, bd_xjson_list_iter iter);
int list_iter_get(bd_xjson_list_iter iter, bd_xjson* val);

#endif