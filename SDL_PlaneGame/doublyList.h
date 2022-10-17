#pragma once
#include "Node.h"
#include "GameObject.h"

class doublyList
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	void insertAtHead(GameObject* gmObject); //now takes GameObject* pointer --> functionality is same as in Ass#1
	void insertAtTail(GameObject* gmObject); //now takes GameObject* pointer --> functionality is same as in Ass#1
	doublyList();
	void deleteNodeHead();
	void deleteNodeTail();
	void deleteNode(int index);
	GameObject* returnAt(int index);
	Node* returnHead();
	Node* returnTail();
	int returnSize();
};

