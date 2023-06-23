#pragma once
#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

class Team
{
public:
    string team;
    int goals;
    Team *next;
};

class TeamList
{
public:
    Team *loc;
    Team *ploc;
    Team *head;
    Team *last;
    int length;

    TeamList()
    {
        loc = NULL;
        head = NULL;
        ploc = NULL;
        last = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void Search(string value)
    {
        if (isEmpty())
        {
            return;
        }

        loc = head;
        ploc = NULL;

        while (loc != NULL && loc->team < value)
        {
            ploc = loc;
            loc = loc->next;
        }

        if (loc!=NULL && loc->team!=value)
        {
            loc = NULL;
        }

    }

    void CreateList(SinglyLinkedList & list)
    {
        FootballMatch *temp = list.head;

        while (temp != NULL)
        {
            Search(temp->opponent);
            if (loc!=NULL)
            {
                loc->goals++;
                temp = temp->next;
                continue;
            }

            else {
                Team *newTeam = new Team();
                newTeam->team = temp->opponent;
                newTeam->goals = 1;
                newTeam->next = NULL;
                length++;

                if (last==NULL)
                {
                    head = newTeam;
                    last = newTeam;
                }

                else {
                    if (ploc == NULL)
                    {
                        newTeam->next = head;
                        head = newTeam;
                    }

                    else if (ploc == last) {
                        last->next = newTeam;
                        last = newTeam;
                    }

                    else {
                        newTeam->next = ploc->next;
                        ploc->next = newTeam;
                    }
                }

                temp = temp->next;

            }

        }
    }

    void PrintTeams()
    {
        Team *temp = head;

        while (temp!=NULL)
        {
            cout << temp->team << ", " << temp->goals << " " << endl;
            temp = temp->next;
        }
    }
};