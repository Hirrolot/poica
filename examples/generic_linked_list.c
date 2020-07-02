#include <poica.h>

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define DeclLinkedList(type)                                                   \
    typedef struct LinkedList(type) {                                          \
        type *data;                                                            \
        struct LinkedList(type) * next;                                        \
    }                                                                          \
    LinkedList(type);                                                          \
                                                                               \
    static LinkedList(type) * listNew(type)(type item);                        \
    static void listFree(type)(LinkedList(type) * list);                       \
                                                                               \
    POICA_FORCE_SEMICOLON

#define DefLinkedList(type)                                                    \
    static LinkedList(type) * listNew(type)(type item) {                       \
        LinkedList(type) *list = malloc(sizeof(type));                         \
        assert(list);                                                          \
                                                                               \
        list->data = malloc(sizeof(type));                                     \
        assert(list->data);                                                    \
        memcpy(list->data, &item, sizeof(type));                               \
        list->next = NULL;                                                     \
                                                                               \
        return list;                                                           \
    }                                                                          \
                                                                               \
    static void listFree(type)(LinkedList(type) * list) {                      \
        LinkedList(type) *node = list;                                         \
                                                                               \
        do {                                                                   \
            free(node->data);                                                  \
            LinkedList(type) *next_node = node->next;                          \
            free(node);                                                        \
            node = next_node;                                                  \
        } while (node);                                                        \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#define LinkedList(type) POICA_MONOMORPHISE(LinkedList, type)
#define listNew(type)    POICA_MONOMORPHISE(listNew, type)
#define listFree(type)   POICA_MONOMORPHISE(listFree, type)

DeclLinkedList(int);
DefLinkedList(int);

int main(void) {
    LinkedList(int) *list = listNew(int)(123);
    list->next = listNew(int)(456);
    list->next->next = listNew(int)(789);

    listFree(int)(list);
}
