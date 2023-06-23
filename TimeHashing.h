#pragma once
#include <iostream>
#include "parser.h"
#include "singlyLinkedList.h"
#include "teamLinkedList.h"
#include "TeamBST.h"
#include "Source.h"
#include <cstring>
#include "Assists.h"
#include <string>



using namespace std;

class hashtable_minute
{
public:
	FootballMatch** hasharray  = new FootballMatch* [10] {NULL};


	void insert(FootballMatch* newRecord)
	{
		int location = hashfunction(newRecord->minute);

		if (hasharray[location] == NULL)
		{
			hasharray[location] = newRecord;
		}
		else
		{
			FootballMatch* loc = hasharray[location];
			FootballMatch* ploc = NULL;

			while (loc != NULL)
			{
				ploc = loc;
				loc = loc->minutenext;
			}
			ploc->minutenext = newRecord;
		}
	}
	
	FootballMatch* search(string minute)
	{
		int location = hashfunction(minute);
		cout << location << endl;

		FootballMatch* loc = hasharray[location];
		FootballMatch* ploc = NULL;

		while (loc != NULL && loc->minute != minute)
		{
			ploc = loc;
			loc = loc->next;;
		}

		return loc;
	}
	
	void printHashChain(int hash) {
		FootballMatch* loc = hasharray[hash];
		while (loc != NULL)
		{
			cout << loc->season << ", " << loc->competition << ", " << loc->matchday << ", " << loc->date << ", " << loc->venue << ", " << loc->club << ", " << loc->opponent << ", " << loc->result << ", " << loc->playing_position << ", " << loc->minute << ", " << loc->at_score << ", " << loc->type << ", " << loc->goal_assist << endl
				<< endl;
			loc = loc->minutenext;
		}
	}

	int hashfunction(string minute)
	{
		
		if (minute.length() > 1) {
			//cout << stoi(minute.substr(0, 1))<< endl;
			return stoi(minute.substr(0,1));
			
		}
		else
		{
			return 0;
		}

	}

};

