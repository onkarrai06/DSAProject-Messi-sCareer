#pragma once
#include <iostream>
#include "singlyLinkedList.h"


using namespace std;

class Assist {
public:
	string player_name;
	int assists;
	
	Assist* next = NULL;
};