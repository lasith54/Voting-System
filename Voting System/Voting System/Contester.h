#pragma once
#include <iostream>
#include <string>
using namespace std;
class Contester {
private:
    int ID;
    string name;
    int voteCount;

public:
    Contester()
    {
        ID = NULL;
        name = "";
        voteCount = 0;
    }

    Contester(int Id, string Name) {
        ID = Id;
        name = Name;
        voteCount = 0;
    }

    //destructor
    ~Contester() {

    }

    int getID() {
        return ID;
    }

    string getName() {
        return name;
    }

    int getVoteCount() {
        return voteCount;
    }

    void vote() {
        voteCount++;
    }
};