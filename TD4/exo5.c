#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node* next;
	char element[256];
};
typedef struct node Node;

Node* create(char* string){
	Node* new = malloc(sizeof(Node));
	new->next = NULL;
	strncpy(new->element, string, 256);

	return new;
}

void display(Node* node){
	printf("%s\n", node->element);
	if(node->next!=NULL) {
		display(node->next);
	}
}

Node* insert(Node* list, char* str){
	Node* new_node = create(str);
	Node* current_node = list;
	if(!current_node) {
		return new_node;
	}

	Node* next_node = list->next;

	if(strcmp(current_node->element, new_node->element) > 0) {
		new_node->next = current_node;
		return new_node;
	}

	while(next_node && strcmp(next_node->element, str) < 0) {
		current_node = next_node;
		next_node = next_node->next;
	}
	/* we need to insert new_node between cur_node and next_node */

	new_node->next = next_node;
	current_node->next = new_node;

	return list;
}

struct node* destroy(struct node* list, char* str) {
	struct node* cur_node = list;
	struct node* next_node = NULL;

	if(cur_node) {
		next_node = cur_node->next;
		if(strcmp(cur_node->element, str) == 0) {
			free(cur_node);
			return next_node;
		}
	}

	while(next_node && strcmp(next_node->element, str) != 0) {
		cur_node = next_node;
		next_node = next_node->next;
	}

	if(next_node) {
		cur_node->next = next_node->next;
		free(next_node);
	}
	return list;
}

int main(int argc, char** argv){
	struct node* list = NULL;

	list = insert(list, "que");
	list = insert(list, "la");
	list = insert(list, "force");
	list = insert(list, "soit");
	list = insert(list, "avec");
	list = insert(list, "toi");
	list = destroy(list, "force");
	display(list);
	return(0);
}
