// Header file containing:
//		- Node Class
//		- Linked List Class

#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>

// Node Class
class Node
{
public:
	std::string data;
	Node *next;

	// constructors
	Node() {
		data = "";
		next = nullptr;
	}

	Node(std::string newValue, Node* nextNode) {
		data = newValue;
		next = nextNode;
	}
};

// Linked List Class
class LinkedList
{
public:
	Node* head;
	Node* tail;
	
	// constructor
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	
	// member functions
	bool isEmpty(Node*& head) const;
	void insertAtHead(Node*& head, Node*& tail ,std::string input = "");
	void insert(Node*& head, Node*& tail, std::string input = "");
	void deleteTail();
	void printList();
	void eraseList(Node *& head);
	std::string pop(Node*& head, Node*& tail);
	int getNodeCount(Node*& head);
};


#endif // !LINKED_LIST_H
