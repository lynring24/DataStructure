#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
   int data;
   int key;
	
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;

   if(head == NULL){
      return 0;
   }

   current = head->next;

   while(current != head){
      length++;
      current = current->next;   
   }
	
   return length;
}

void insertFirst(int key, int data){

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if (isEmpty()){
      head = link;
      head->next = head;
   } 
   else{
      link->next = head;
      head = link;
   }    
}

struct node * deleteFirst(){

   struct node *tempLink = head;
	
   if(head->next == head){  
      head = NULL;
      return tempLink;
   }     

   head = head->next;
	
   return tempLink;
}

void printList(){

   struct node *ptr = head;
   printf("\n[ ");

   if(head != NULL){
	
      while(ptr->next != ptr){     
         printf("(%d,%d) ",ptr->key,ptr->data);
         ptr = ptr->next;
      }
   }
	
   printf(" ]");
}