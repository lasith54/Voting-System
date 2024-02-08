#pragma once
#include <iostream>
#include <string>
using namespace std;
class Voter {
private:
    int ID;
    string firstName;
    string lastName;
    string dateOfBirth;
    string address;
    int pin;
    bool isVoted;


public:
    Voter() {
        ID = NULL;
        firstName = "";
        lastName = "";
        dateOfBirth = "";
        address = "";
        pin = NULL;
        isVoted = false;
    }

    Voter(int Id, string FirstName, string LastName, string DateOfBirth, string Address, int Pin) {
        ID = Id;
        firstName = FirstName;
        lastName = LastName;
        dateOfBirth = DateOfBirth;
        address = Address;
        pin = Pin;
        isVoted = false;
    }

    //destructor
    ~Voter() {

    }

    int getID() {
        return ID;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getDateOfBirth() {
        return dateOfBirth;
    }

    string getAddress() {
        return address;
    }

    int getPin() {
        return pin;
    }

    bool getIsVoted() {
        return isVoted;
    }

    void vote() {
        isVoted = true;
    }
};