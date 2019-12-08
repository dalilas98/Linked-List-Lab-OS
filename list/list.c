// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
    list_t *l = (list_t*) malloc(sizeof(list_t));
    l -> head = NULL;
    return l;
    
}
void list_free(list_t *l) {
    node_t *curr = l->head;
    if (curr == NULL) {
        free(l-> head);
        free(l);
        return;
    }
    node_t *tempNode;
    while(curr != NULL){
        tempNode = curr;
        curr = curr -> next;
        free(tempNode);
    }
    free(l);
}

void list_print(list_t *l) {
    node_t * curr;
    
    if (l->head == NULL) {
        printf("List is Empty");
        return;
    }
    curr = l->head;
    while (curr != NULL) {
        printf("%d", curr -> value);
        curr = curr -> next;
    }
}
int list_length(list_t *l) {
    node_t * curr = l -> head;
    if (curr == NULL) {
        return 0;
    }
    int count = 0;
    while (curr != NULL) {
        count++;
        curr = curr -> next;
    }
    return count; 
}

void list_add_to_back(list_t *l, elem value) {
    node_t *curr = l -> head;
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    newNode -> value = value;
    newNode -> next = NULL;
    
    if(curr != NULL) {
        while (curr -> next != NULL) curr = curr -> next;
        curr -> next = newNode;
    }
    
    else {
        l -> head = newNode;
    }

}
void list_add_to_front(list_t *l, elem value) {
    node_t *curr = l -> head;
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    newNode -> value = value;
    
    if (curr != NULL) {
        newNode -> next = l -> head;
        l -> head = newNode;
    }
    else {
        newNode -> next = NULL;
        l -> head = newNode;
    }
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t *prev = l->head;
    
    int count = 0;
    if ((index > list_length(l)) || (index < 0 )) {
        return;
    }
    
    if (prev == NULL) {
        l->head = (node_t*) malloc(sizeof(node_t));
        l->head->value = value;
        l->head-> next = NULL;
        return;
    }
    
    else {
        while ((count < index -1) && (prev->next != NULL)) {
            prev = prev -> next;
            count++;
        }
        node_t *newNode = (node_t*) malloc(sizeof(node_t));
        newNode->next = prev-> next;
        newNode->value = value;
        prev->next = newNode;
    }
}

elem list_remove_from_back(list_t *l) {
    node_t *curr = l->head;
    
    if (curr == NULL) {
        return -1;
    }
    else {
        if (list_length(l) < 2) {
            l->head = NULL;
            free(curr);
        }
        else {
            while (curr -> next->next != NULL) curr = curr -> next;
            node_t *temp = curr->next;
            curr->next = NULL;
            free(temp);
        }
    }
    return false;
}
elem list_remove_from_front(list_t *l) {
    node_t * curr = l->head;
    if (curr == NULL) {
         return -1;
    }
    int val = curr->value;
    l->head = (list_length(l) < 2) ? NULL : curr->next;
    free(curr);
    return val;
}
elem list_remove_at_index(list_t *l, int index) {
    node_t *curr = l->head;
    node_t *temp;
    int value = index;
    int count = index;
    
    if ((index > list_length(l) + 1) || (index < 1)) {
        printf("incorrect index");
        return -1;
    }
    else {
        while (count > 1) {
            curr = curr -> next;
            count--;
        }
        
        temp = curr->next;
        curr->next = NULL;
        value = temp->value;
        free(temp);
        printf("%d", index);
    }
    return value;
}

bool list_is_in(list_t *l, elem value) {
    node_t *curr = l->head;
    
    while (curr != NULL) {
        if (curr -> value == value)
            return true;
        curr = curr -> next;
    }
    return false;
}
elem list_get_elem_at(list_t *l, int index) {
    node_t *curr = l->head;
    if ((index > list_length(l) -1 ) || (index < 0)) {
        return -1;
    }
    while (curr -> next != NULL && index >= 0) {
        curr = curr -> next;
        index--;
    }
    return curr-> value;
}
int list_get_index_of(list_t *l, elem value) {
    node_t *curr = l->head;
    int index = 0;
    
    while (curr != NULL) {
        if (curr->value == value) return index;
        curr = curr->next;
        index++;
    }
    return -1; 
}
