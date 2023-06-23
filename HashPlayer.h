#pragma once
#include <iostream>
#include "parser.h"
#include "singlyLinkedList.h"
#include "teamLinkedList.h"
#include "TeamBST.h"
#include "Source.h"
#include <cstring>
#include "Assists.h"


// Hashtable to implement the players and their assists

using namespace std;

class hashtable_player
{
public:
	Assist** hasharray = new Assist* [1000]{NULL};
	

	void insert(Assist* newassist)
	{
		int location = hashfunction(newassist->player_name);
		
		if (hasharray[location] == NULL)
		{
			hasharray[location] = newassist;
		}
		else
		{
			Assist* loc = hasharray[location];
			Assist* ploc = NULL;
			
			while (loc != NULL)
			{
				ploc = loc;
				loc = loc->next;
			}
			ploc->next = newassist;
		}
	}
	Assist* search(string player_name)
	{
		int location = hashfunction(player_name);
		
		Assist* loc = hasharray[location];
		Assist* ploc = NULL;
		
		while (loc != NULL && loc->player_name != player_name)
		{
			ploc = loc;
			loc = loc->next;;
		}
		
		return loc;
	}

	
	int hashfunction(string player_name)
	{
		long long int hash = 0;
		hash = 3;
		for (int i = 0; i < player_name.length(); i++)
		{
			hash = hash + 7 * (int)player_name[i];
		}
		return hash % 1000;
		
	}
	
	
};

