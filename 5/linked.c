#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    // just some form of data; could be a char* or whatever
    int num;

    // pointer to next node; have to include `struct` since this is a recursive definition
    struct node *next;
}
node;

// protoypes
node* insert_to_list(node *head, int value);
void print_list(node *head);
void free_list(node *head);

int main(void) {
    // initialize a new linked list
    node *head = malloc(sizeof(node));
    if (head == NULL) {
        return 1;
    }
    head->num = 1;

    // add values to the list
    head = insert_to_list(head, 2);
    head = insert_to_list(head, 4);
    head = insert_to_list(head, 5);
    head = insert_to_list(head, 2);
    head = insert_to_list(head, 3);

    // print the list
    print_list(head);

    // free the list
    free_list(head);
    // that's all folks!
    return 0;
}

node* insert_to_list(node* head, int value) {
    node *original_head = head;
    // iterate through the linked list
    while (head) {
        // check if the current place is the right place to insert the node
        if (head->num <= value && (head->next == NULL || head->next->num > value)) {
            // make a new node with given value
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL) {
                return original_head;
            }
            new_node->num = value;
            // insert the new node in to the list
            new_node->next = head->next;
            head->next = new_node;
            return original_head;
        }
        if (head->num > value) {
            // make a new node with given value
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL) {
                return original_head;
            }
            new_node->num = value;
            // insert the new node to the head of the list.
            new_node->next = head;
            return new_node;
        }
        head = head->next;
    }
    // code should never reach here
    return original_head;
}

void print_list(node *head) {
    int counter = 0;
    printf("Your list:\n");
    while(head) {
        printf("The value at position %d is %d\n", counter, head->num);
        counter++;
        head = head->next;
    }
}

void free_list(node *head) {
    node* current;
    while(head) {
        current = head;
        head = head->next;
        free(current);
    }
    return;
}
