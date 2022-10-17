#include "doublyList.h"
#include "Node.h"
#include "GameObject.h"

using namespace std;



doublyList::doublyList() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0; //size is basically the count of how many nodes there are present in the list
}

// not used for this code but implemented it for the sake of it 
void doublyList::insertAtHead(GameObject* gmObject) //take game  object now
{
	//new node now points to the first node of the list
	Node* insertNode = new Node(gmObject);

	if (head == nullptr)
	{
		head = insertNode;
		tail = insertNode;
	}
	else
	{
		head->previous = insertNode;
		insertNode->next = head;
		head = insertNode;
	}
	size++;
}

void doublyList::insertAtTail(GameObject* gmObject) //take game  object now
{

	Node* insertNode = new Node(gmObject);
	if (head == nullptr && tail == nullptr)
	{
		head = insertNode;
		tail = insertNode;
	}
	else
	{
		tail->next = insertNode;
		insertNode->previous = tail;
		tail = insertNode;
	}
	size++;
}

//this is wrong as it does not cater to when there is one node or empty list
//either way I have not used this
void doublyList::deleteNodeHead() {

	Node* temp = head;

	head->next->previous = nullptr;
	head = head->next;

	temp = nullptr;
	delete temp;
	size--;
}

//this is wrong as it does not cater to when there is one node or empty list
//either way I have not used this
void doublyList::deleteNodeTail() {

	Node* temp = tail;
	temp->previous->next = nullptr;
	tail = tail->previous;

	delete temp;
	size--;
}

void doublyList::deleteNode(int index)
{
	Node* temp = head;
	int count = 0;

	//start from the head and traverse the list 
	while (temp != nullptr)
	{
		if (index == count)
		{
			//if there is only one node in the list
			if (temp->previous == nullptr && temp->next == nullptr)
			{
				head = nullptr;
				tail = nullptr;
			}
			//node to be deleted is head node
			else if (temp->previous == nullptr)
			{
				head = temp->next;
				head->previous = nullptr;
			}
			//node to be deleted is tail node
			else if (temp->next == nullptr)
			{
				tail = temp->previous;
				tail->next = nullptr;
			}
			//node to be deleted is in the middle of list
			else
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
			}
			//temp = nullptr;
			delete temp->gmObject;
			delete temp;
			size--;
			return;
		}
		count++;
		temp = temp->next;
	}
}


//returns the data of the node it is supposed to find
GameObject* doublyList::returnAt(int index)
{
	Node* temp = head;
	int count = 0;
	while (temp != nullptr)
	{
		if (index == count) {
			return temp->gmObject;
		}
		count++;
		temp = temp->next;
	}
}

int doublyList::returnSize() { //self explanatory
	return size;
}

Node* doublyList::returnHead() { //self explanatory
	return head;
}

Node* doublyList::returnTail() { //self explanatory
	return tail;
}