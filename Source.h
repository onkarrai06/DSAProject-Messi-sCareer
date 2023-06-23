#pragma once
#include <iostream>
//#include "Parser.h"
#include "singlyLinkedList.h"
#include "teamLinkedList.h"
#include "TeamBST.h"
#include <string>
#include "HashPlayer.h"
#include "TimeHashing.h"


using namespace std;


void Parser(SinglyLinkedList& list, hashtable_player* table, hashtable_minute* table_minute)
{
    ifstream file("data.csv");
    string line;
    getline(file, line);

    list.head = NULL;
    list.tail = NULL;

    while (getline(file, line))
    {

        int index = 0;
        string word = "";
        int count = 1;
        FootballMatch* newNode = new FootballMatch();

        
        for (int i = 0; i < line.length() + 1; i++)
        {
            if ((line[i] != ',') && (i != line.length()))
            {
                word += line[i];
            }
            else
            {
                if (count == 1)
                {
                    newNode->season = word;
                }
                else if (count == 2)
                {
                    newNode->competition = word;
                }
                else if (count == 3)
                {
                    newNode->matchday = word;
                }
                else if (count == 4)
                {
                    newNode->date = word;
                }
                else if (count == 5)
                {
                    newNode->venue = word;
                }
                else if (count == 6)
                {
                    newNode->club = word;
                }
                else if (count == 7)
                {
                    newNode->opponent = word;
                }
                else if (count == 8)
                {
                    newNode->result = word;
                }
                else if (count == 9)
                {
                    newNode->playing_position = word;
                }
                else if (count == 10)
                {
                    newNode->minute = word;
                }
                else if (count == 11)
                {
                    newNode->at_score = word;
                }
                else if (count == 12)
                {
                    newNode->type = word;
                }
                else if (count == 13)
                {
                    newNode->goal_assist = word;
                }
                count++;
                word = "";
            }
        }
        table_minute->insert(newNode);
        if (table->search(newNode->goal_assist) == NULL)
        {
            Assist* newAssist = new Assist;
            newAssist->assists = 1;
            newAssist->player_name = newNode->goal_assist;
            table->insert(newAssist);
           // cout << "Insertion in Player table done" << endl;
        }

        else
        {
            Assist* temp = table->search(newNode->goal_assist);
            temp->assists++;
        }

        //cout << "Insertion in Time Hash Done" << endl;
        if (list.head == NULL)
        {
            list.head = newNode;
            list.tail = newNode;
        }

        else
        {
            list.tail->next = newNode;
            list.tail = newNode;
        }

    }
    //cout << "Parsing Done" << endl;
}

class Solution {
public:
    hashtable_player* table_player = new hashtable_player;
    hashtable_minute* table_minute = new hashtable_minute;

    void MainMenu()
    {

        char choice = 'w';
        SinglyLinkedList list;
        
		Parser(list, table_player, table_minute);
        //list.printList();
        TeamList teams;
        teams.CreateList(list);
        //teams.PrintTeams();
        TeamTree teamTree;
        teamTree.root = teamTree.sortedListtoBST(teams.head);
        //teamTree.InOrderTrav(teamTree.root);

        while (choice != 'x') {
            cout << "\nPlease select an action: " << endl << endl;

            cout << "\t1. Read file data into a linked list and print the goal records" << endl;
            cout << "\t2. Search a team that Messi has scored against" << endl;
            cout << "\t3. Search a player to get his records on assisting Messi" << endl;
            cout << "\t4. Enter the minute range in which you want to see the records of the goals " << endl;
            cout << "Enter 'x' to terminate the loop!" << endl;

            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case ('1'):
            {
                list.printList();
            }; break;

            case ('2'):
            {
                         
                string s;
                cout << "Insert which team you want to search about:" << endl;
                getline(cin, s);
             

                teamTree.SearchTeam(s);

                if (teamTree.loc != NULL)
                {
                    cout << endl << endl;
                    cout << "Team: " << teamTree.loc->team_name << endl;
                    cout << "Goals scored against them: " << teamTree.loc->goals_scored << endl;
                }

                else
                {
                    cout << "Value not found!" << endl;
                }

            }; break;


            case ('3'):
            {  
				    string s;
				    cout << "Insert which player you want to search about:" << endl;
				    getline(cin, s);
				    Assist* get;
				    get = table_player->search(s);
				        if (get != NULL)
				        {
					        cout << endl << endl;
					        cout << "Player: " << get->player_name << endl;
					        cout << "Assists: " << get->assists << endl;
				        }

				        else
				        {
					        cout << "Value not found!" << endl;
				        }

			        }; break;

                    case ('4'):
                    {
                        int min1;
                        cout << "Enter the minute range that you want to see the records of the goals:" << endl;
                        cout << "\t0. 0 to 10 minutes" << endl;
                        cout << "\t1. 10 to 20 minutes" << endl;
                        cout << "\t2. 20 to 30 minutes" << endl;
                        cout << "\t3. 30 to 40 minutes" << endl;
                        cout << "\t4. 40 to 50 minutes" << endl;
                        cout << "\t5. 50 to 60 minutes" << endl;
                        cout << "\t6. 60 to 70 minutes" << endl;
                        cout << "\t7. 70 to 80 minutes" << endl;
                        cout << "\t8. 80 to 90 minutes" << endl;
                        cout << "\t9. 90 or more minutes" << endl;

                        cin >> min1;
                        table_minute->printHashChain(min1);

                    }; break;
             

            case ('x'):
            {
				cout << "Loop terminated, goodbye!" << endl;
                break;
            }; break;

            default:
                cout << "Invalid action selected, enter again!" << endl;

            }
        }
    }
};