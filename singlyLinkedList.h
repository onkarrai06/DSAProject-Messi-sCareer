#pragma once
#include <iostream>
#include <string>
using namespace std;


class FootballMatch
{
public:
  string season;
  string competition;
  string matchday;
  string date;
  string venue;
  string club;
  string opponent;
  string result;
  string playing_position;
  string minute;
  string at_score;
  string type;
  string goal_assist;
  FootballMatch* next;
  FootballMatch* minutenext = NULL;

  FootballMatch()
  {
      next = NULL;
  }
};

class SinglyLinkedList 
{
    public:

    FootballMatch *head = NULL;
    FootballMatch *tail = NULL;
    FootballMatch *loc = NULL;
    FootballMatch *pred = NULL;
    int count = 0;

    void printList() 
    {
        FootballMatch *temp = head;
        while (temp != NULL) 
        {
            cout << temp->season << ", " << temp->competition << ", " << temp->matchday << ", " << temp->date << ", " << temp->venue << ", " << temp->club << ", " << temp->opponent << ", " << temp->result << ", " << temp->playing_position << ", " << temp->minute << ", " << temp->at_score << ", " << temp->type << ", " << temp->goal_assist << endl
                 << endl;
            count++;
            temp = temp->next;
        }
    }


};
