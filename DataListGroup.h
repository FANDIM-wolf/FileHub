#ifndef DATALISTGROUP_H
#define DATALISTGROUP_H

#endif // DATALISTGROUP_H

#include "add_user_in_db.h";


class Node {
public:
    int key;
    QString data;
    Node* next;
};

void append(Node** head_ref, QString new_data , int key)
{
    /* 1. allocate node */
    Node* new_node = new Node();

    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;
    new_node->key = key;
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}


//function to delete node from linked list
void deleteNode(Node** head_ref, int key)
{

    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
    }
}

//function to find node in linked list
QString findNode(Node** head_ref, QString data)
{

    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == data)
    {

        //cout<< "Node was found:"<< temp->data<<endl;             // print head
        return temp->data;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return NULL;

    // Print found node
    return temp->data;

    }
}
