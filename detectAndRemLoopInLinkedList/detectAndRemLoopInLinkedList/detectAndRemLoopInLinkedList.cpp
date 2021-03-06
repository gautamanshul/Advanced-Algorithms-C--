// detectAndRemLoopInLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// reverseLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

struct Node {
	int data;
	struct Node * next;

	Node(int data) : data(data), next(nullptr) {}
};

struct LinkedList {
	struct Node *head;
	LinkedList() : head(nullptr) {}

	void push(int data)
	{
		struct Node *tmp = new Node(data);

		tmp->next = head;

		head = tmp;
	}


	

	void reverseLinkedList() {
		struct Node * next = nullptr;
		struct Node * current = head;
		struct Node * prev = nullptr;

		while (current != nullptr) {

			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	/* Print the linked list */
	void print()
	{
		struct Node *temp = head;
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

};

void removeLoop(struct Node *loop_node, struct Node *head)
{
	struct Node * ptr1 = nullptr;
	struct Node * ptr2 = nullptr;

	ptr1 = head;

	while (1) {
		ptr2 = loop_node;
		while (ptr2->next != loop_node && ptr2->next != ptr1) {
			ptr2 = ptr2->next;
		}

		if (ptr2->next == ptr1)
			break;

		ptr1 = ptr1->next;
	}

	ptr2->next = nullptr;
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool detectAndRemoveLoop(struct Node *head)
{
	struct Node *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if (slow_p == fast_p) {
			removeLoop(slow_p, head);

			return true;
		}
	}

	return false;
}

int main()
{

	struct Node *head = new struct Node(50);
	head->next = new struct Node(20);
	head->next->next = new struct Node(15);
	head->next->next->next = new struct Node(4);
	head->next->next->next->next = new struct Node(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	print(head);

}



