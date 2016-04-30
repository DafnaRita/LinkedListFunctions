#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct linked_list { 
    int value;
    struct linked_list* next; 
} linked_list;

linked_list* list_create(int number) {
    linked_list* link_at_first_struct = malloc(sizeof(linked_list));
    link_at_first_struct->value = number; 
    return link_at_first_struct;
}

linked_list* list_add_front(
    linked_list* link_at_previos_struct,
                           int number) {
    linked_list* link_at_struct = malloc(sizeof(linked_list));
    link_at_struct -> value = number;
    link_at_struct -> next = NULL;
    link_at_previos_struct -> next = link_at_struct; 
    return link_at_struct;
}

linked_list* list_node_at(linked_list* link_at_struct, int index) {
    int i;
    for (i = 0; i < index-1; i++)
    if(link_at_struct)link_at_struct= link_at_struct->next;
        else return NULL;
    return link_at_struct;
}

int list_get(linked_list* list, int index) {
    linked_list* struct_by_index = list_node_at(list,index);
    return struct_by_index -> value;
}

void list_show(
    linked_list* link_at_struct){
    while(link_at_struct != 0) {
        printf("%d ",link_at_struct -> value);
        link_at_struct= link_at_struct->next;
    }
}

int list_length(linked_list* link_at_struct) {
    size_t size_of_list = 0;
    while(link_at_struct != 0) {
        size_of_list++;
        link_at_struct= link_at_struct->next;
    }
    return size_of_list;
}

void list_free(linked_list* link_at_struct) {
    linked_list* current_link;
    while((link_at_struct)!=NULL) { 
        current_link=link_at_struct;
        link_at_struct=link_at_struct->next;
        free(current_link);
    }
}

int list_sum(linked_list* link_at_struct) {
    int i;
    int sum = 0;
    for(i=1; i<list_length(link_at_struct)+1; i++) {
    	sum= sum + list_get(link_at_struct, i);
    }
    return sum;
}

int* list_to_array(linked_list* link_first)
{
    int length = list_length(link_first);
    int* link_at_array = malloc(length*sizeof(int));
    int i;
    for(i=0; i<length; i++) {
        link_at_array[i]=link_first->value;
        link_first=link_first->next;
    }
    return link_at_array;
}

int main( int argc, char** argv ) 
{
    int input_number;
    int my_variant = 14;
    linked_list* link_at_struct=NULL;
    linked_list* link_first=NULL;
    printf("Input numbers:\n");
    while(scanf("%d", &input_number)!=EOF) { 
        if(link_at_struct==NULL) {/*first element*/
            link_at_struct=list_create(input_number);
            link_first = link_at_struct;
        } else {
            link_at_struct = list_add_front(link_at_struct,
                                input_number);
        }    
    }
    printf("Show all list:\n");
    list_show(link_first);
    printf("\n");
    if(list_node_at(link_first, my_variant)==NULL) {
        printf("Not enought elements");
    } else{
    printf("Show element[%d] = %d\n", my_variant ,list_get(link_first, my_variant)); 
    }
    
    printf("\n");
    printf("Sum of the list = %d\n", list_sum(link_first));
    printf("\n");

    list_to_array(link_first);
    printf("End of all program.\n");
    return 0;
}





