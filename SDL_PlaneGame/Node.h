#pragma once
#include <iostream>
#include <stdlib.h> 
#include "GameObject.h"

using namespace std;
//works the same way as before
class Node
{
public:
	Node* next;
	Node* previous;
	//Cloud* cloud;
	GameObject* gmObject; //updated


	Node(GameObject* gmObject)
	{
		next = nullptr;
		previous = nullptr;
		this->gmObject = gmObject;
	}
};