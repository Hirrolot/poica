#include <poica.h>

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define DeclLinkedList(type)                                                                       \
    typedef struct P(LinkedList, type) {                                                           \
        type *data;                                                                                \
        struct P(LinkedList, type) * next;                                                         \
    } P(LinkedList, type);                                                                         \
                                                                                                   \
    static P(LinkedList, type) * P(listNew, type)(type item);                                      \
    static void P(listFree, type)(P(LinkedList, type) * list);                                     \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#define DefLinkedList(type)                                                                        \
    static P(LinkedList, type) * P(listNew, type)(type item) {                                     \
        P(LinkedList, type) *list = malloc(sizeof(*list));                                         \
        assert(list);                                                                              \
                                                                                                   \
        list->data = malloc(sizeof(type));                                                         \
        assert(list->data);                                                                        \
        memcpy(list->data, &item, sizeof(type));                                                   \
        list->next = NULL;                                                                         \
                                                                                                   \
        return list;                                                                               \
    }                                                                                              \
                                                                                                   \
    static void P(listFree, type)(P(LinkedList, type) * list) {                                    \
        P(LinkedList, type) *node = list;                                                          \
                                                                                                   \
        do {                                                                                       \
            free(node->data);                                                                      \
            P(LinkedList, type) *next_node = node->next;                                           \
            free(node);                                                                            \
            node = next_node;                                                                      \
        } while (node);                                                                            \
    }                                                                                              \
                                                                                                   \
    POICA_FORCE_SEMICOLON

DeclLinkedList(int);
DefLinkedList(int);

int main(void) {
    P(LinkedList, int) *list = P(listNew, int)(123);
    list->next = P(listNew, int)(456);
    list->next->next = P(listNew, int)(789);

    P(listFree, int)(list);
}
