#pragma once
#include <iostream>
#include <string>
#include "teamLinkedList.h"

using namespace std;

class TeamTreeNode
{
public:
    string team_name;
    int goals_scored;
    TeamTreeNode *lchild;
    TeamTreeNode *rchild;

    TeamTreeNode(string name, int goals)
    {
        this->team_name = name;
        this->goals_scored = goals;
    }
};

class TeamTree
{
public:
    TeamTreeNode *root;
    TeamTreeNode *loc;
    TeamTreeNode *ploc;

    // void Foot() 
    // {
    //     cout << root->team_name;
    // }

    TeamTreeNode *sortedListtoBST(Team *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        else if (head->next == NULL)
        {
            return new TeamTreeNode(head->team, head->goals);
        }

        else
        {
            Team *previous = head;
            Team *quick = head;
            Team *slow = head;

            while (quick != NULL && quick->next != NULL)
            {
                previous = slow;
                slow = slow->next;
                quick = quick->next->next;
            }

            previous->next = NULL;

            TeamTreeNode *root = new TeamTreeNode(slow->team, slow->goals);
            root->lchild = sortedListtoBST(head);
            root->rchild = sortedListtoBST(slow->next);
            // cout << root->team_name;
            return root;
        }
    }

    void InOrderTrav(TeamTreeNode *temp)
    {
        if (temp !=NULL)
        {
            InOrderTrav(temp->lchild);
            cout << temp->team_name << ", " << temp->goals_scored << endl;
            InOrderTrav(temp->rchild);
        }
    }

    void SearchTeam(string name)
    {
        if (root == NULL)
        {
            cout << "The tree is empty, searching not possible" << endl;
        }

        else {
            loc = root;
            ploc = NULL;

            while (loc != NULL && loc->team_name != name)
            {
                if (name < loc->team_name)
                {
                    ploc = loc;
                    loc = loc->lchild;
                }

                else {
                    ploc = loc;
                    loc = loc->rchild;
                }
            }
        }
    }
};
