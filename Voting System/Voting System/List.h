#pragma once
#include <iostream>
using namespace std;

#define RED "\033[31m";

template <typename T>

class List {
public:
    class Node {
    public:
        T data;
        Node* next;

        //destructor
        ~Node() {

        }
    };
    Node* head;

    List() {
        head = NULL;
    }
    //destructor
    ~List() {

    }

    void add(T item) {
        Node* node = new Node;
        node->data = item;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node;
        }
    }

    T* findByID(int id) {
        Node* current = new Node;
        current = head;
        while (current != NULL) {
            if (current->data.getID() == id) {
                return &current->data;
            }
            current = current->next;
        }
        return NULL;
    }

    void contesterDisplay() {
        Node* newnode = new Node;
        newnode = head;
        cout << "\t\t\t\t\t________________________________\t" << endl;
        cout << "\t\t\t\t\t|   ID \t|\t" << "  NAME" << "\t\t|" << endl;
        cout << "\t\t\t\t\t________________________________\t" << endl;
        while (newnode != NULL)
        {
            cout << "\t\t\t\t\t|   " << newnode->data.getID() << "\t|\t" << newnode->data.getName() << "\t|" << endl;
            newnode = newnode->next;
        }
        cout << "\t\t\t\t\t________________________________\t" << endl;
    }

    void voterDisplay() {
        Node* newnode = head;
        cout << " _______________________________________________________________________________________________________________" << endl;
        cout << " | ID |" << "\tFIRSTNAME\t|" << "\tLASTNAME\t|" << "\tDOB\t\t|" << "\tADDRESS\t\t|" << "  Voted(0/1)  |" << endl;
        cout << " _______________________________________________________________________________________________________________" << endl;
        while (newnode != NULL)
        {
            cout << " | " << newnode->data.getID() << "  |\t" << newnode->data.getFirstName() <<
                "\t\t|\t" << newnode->data.getLastName() << "\t\t|\t" << newnode->data.getDateOfBirth() << "\t|\t" <<
                newnode->data.getAddress() << "\t|\t" << newnode->data.getIsVoted() << "      |" << endl;
            newnode = newnode->next;
        }
        cout << " _______________________________________________________________________________________________________________" << endl;
    }

    void contesterCountDisplay() {
        Node* newnode = new Node;
        newnode = head;
        cout << "\t\t\t________________________________________________________________" << endl;
        cout << "\t\t\t|\tID\t|" << "\tNAME\t\t" << "|\tVote Count\t|" << endl;
        cout << "\t\t\t________________________________________________________________" << endl;
        while (newnode != NULL)
        {
            if (newnode == head)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |FOREGROUND_BLUE);
            else
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "\t\t\t|\t" << newnode->data.getID() << "\t|\t" << newnode->data.getName() << "\t|\t  " << newnode->data.getVoteCount() << "    \t\t|" << endl;
            newnode = newnode->next;
        }
        cout << "\t\t\t________________________________________________________________" << endl;
    }


    void finalResults() {
        Node* newnode = new Node;
        newnode = head;
        while (newnode != NULL) {
            Node* temp = new Node;
            temp = newnode->next;
            while (temp != NULL) {
                if (newnode->data.getVoteCount() < temp->data.getVoteCount()) {
                    Node* N = new Node;
                    N->data = newnode->data;
                    newnode->data = temp->data;
                    temp->data = N->data;
                }
                temp = temp->next;
            }
            newnode = newnode->next;
        }
        contesterCountDisplay();
    }

};