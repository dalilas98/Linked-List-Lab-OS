#include <stdio.h>

#include "list.h"




int main() {
  printf("Tests for linked list implementation\n");
    
  list_t *testList = list_alloc();
    for(int i = 0; i < 5; i++)
    {
        list_add_to_back(testList, i+10);
    }
    
    printf("OG List:\n");
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nAdd 3 to the back:\n");
    list_add_to_back(testList, 3);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nAdd 4 to the front:\n");
    list_add_to_front(testList, 4);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nAdd 63 at index 5:\n");
    list_add_at_index(testList, 63, 5);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nRemoving element from the back:\n");
    list_remove_from_back(testList);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nRemoving element from the front:\n");
    list_remove_from_front(testList);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nRemoving element at index 3:\n");
    list_remove_at_index(testList, 3);
    list_print(testList);
    
    printf("\n\nLength of list is %d", list_length(testList));
    
    printf("\n\nChecking if 7 is in the list: %s\n", list_is_in(testList, 7) ? "true" : "false");
    
    printf("\n%d was found at index 3\n", list_get_elem_at(testList, 3));
    

   
  return 0;
}