#include <iostream>
#include <string>
#include <conio.h>
#include <CoreWindow.h>
#include <ctime>
#include "Voter.h"
#include "Contester.h"
#include "List.h"

using namespace std;

void main() {

    system("cls");

    //login page
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "\t\t\t\t\t\t    W E L C O M E\n\n\t\t\t\t\t\t         T O\n\n\t\t\t\t      D I G I T A L  V O T I N G   S Y S T E M !!" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    //date and time 
    time_t now = time(0);

    struct tm local_time;
    localtime_s(&local_time, &now);

    char buffer[80];
    strftime(buffer, 80, "\t\t\t\t\t\t      %d/%m/%Y\n\n\t\t\t\t\t\t        %H:%M", &local_time);
    cout << buffer;


    cout << endl << endl << endl << endl;

    char key;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
    cout << "Press any key to continue....";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    key = _getch();



    List<Voter> voters;
    List<Contester> contesters;
    int voterID = 6;



    //Add pre-defined voters to the list 
    //Voter(int Id,string FirstName,string LastName,string DateOfBirth,string Address, int Pin)
    voters.add(Voter(1, "Bilbo", "Baggins", "01/02/1998", "address 01", 1111));
    voters.add(Voter(2, "Chris", "Barnes", "01/09/1993", "address 02", 1111));
    voters.add(Voter(3, "Holand", "Barnes", "02/02/1992", "address 03", 1111));
    voters.add(Voter(4, "Thorin", "Evans", "03/08/1992", "address 04", 1111));
    voters.add(Voter(5, "Durin", "Dwarwen", "05/02/1958", "address 05", 1111));

    // Add pre-defined contesters to the list
    contesters.add(Contester(1, "Contester 1"));
    contesters.add(Contester(2, "Contester 2"));
    contesters.add(Contester(3, "Contester 3"));

    bool running = true;
    while (running) {
        // Display Main Menu
        system("cls");

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "\t\t\t\t\t\t\---MAIN MENU---\t\t\t\t\t\t" << endl << endl << endl << endl << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << "\t\t\t\t\t\t1. Add Voter\t\t\t\t" << endl << endl;
        cout << "\t\t\t\t\t\t2. Display All Contesters\t\t\t\t" << endl << endl;
        cout << "\t\t\t\t\t\t3. Give Vote\t\t\t\t" << endl << endl;
        cout << "\t\t\t\t\t\t4. Admin Panel\t\t\t\t" << endl << endl;
        cout << "\t\t\t\t\t\t5. Quit\t\t\t\t" << endl << endl;

        int choice;
        cout << endl << endl << "Enter your choice: ";
        try {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();   // clear the fail bit
                cin.ignore();  // discard the invalid input
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                throw runtime_error("Invalid input. Please enter an integer value.");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            // code to execute when input is valid
        }
        catch (const exception& e) {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cerr << "Error: " << e.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            system("pause");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("cls");
            // code to handle the exception
        }

        switch (choice) {
        case 1: {
            // Add Voter
            system("cls");
            string firstName, lastName, address;
            int pin;
            string dateOfBirth;

            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << "\t\t\t\t\t\t---ADD VOTER---\t\t\t\t\t\t" << endl << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            cout << "Enter First Name: ";
            cin >> firstName;

            cout << "Enter Last Name: ";
            cin >> lastName;

            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin >> dateOfBirth;

            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, address);

            cout << "Enter 4-digit Pin: ";
            try {
                cin >> pin;
                if (cin.fail()) {
                    cin.clear();   // clear the fail bit
                    cin.ignore();  // discard the invalid input
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    throw runtime_error("Invalid input. Please enter an integer value.");
                    cout << endl << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
                // code to execute when input is valid
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                system("pause");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                system("cls");
                // code to handle the exception
            }
            Voter voter(voterID, firstName, lastName, dateOfBirth, address, pin);
            voters.add(voter);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout << endl << "Voter added Successfully.." << endl << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            voterID++;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            system("pause");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("cls");
            break; }
        case 2:
            // Display All Contesters
        {
            system("cls");

            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << "\t\t\t\t\t\t---CONTESTERS---\t\t\t\t\t" << endl << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            contesters.contesterDisplay();

            cout << endl << endl;;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            system("pause");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        case 3:
            // Give Vote
        {
            int voterID;

            system("cls");

            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << "\t\t\t\t\t\t---VOTING PANEL---\t\t\t\t\t\t" << endl << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            cout << "Enter Voter ID: ";
            try {
                cin >> voterID;
                if (cin.fail()) {
                    cin.clear();   // clear the fail bit
                    cin.ignore();  // discard the invalid input
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    throw runtime_error("Invalid input. Please enter an integer value.");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                // code to execute when input is valid
            }
            catch (const exception& e) {
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cerr << "Error: " << e.what() << endl;
                cout << endl << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                system("pause");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                system("cls");
                // code to handle the exception
            }
            int pin = 0;
            char c;
            cout << "Enter Pin: ";
            try {
                while ((c = _getch()) != '\r') {  // loop until the Enter key is pressed
                    if (isdigit(c) && pin < 10000) {  // handle digits and limit input to 4 digits
                        pin = pin * 10 + (c - '0');
                        cout << "*";
                    }
                    else if (c == '\b') {  // handle backspace characters
                        if (pin > 0) {
                            pin /= 10;
                            cout << "\b \b";
                        }
                    }
                    else {
                        cout << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                        throw runtime_error("Invalid input. Please enter a numeric value.");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                if (pin < 1000 || pin > 9999) {
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    throw runtime_error("Invalid input. Please enter a 4-digit pin.");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                cout << endl;
                // code to execute after pin is entered
            }
            catch (const exception& ex) {
                cout << endl << ex.what() << endl;
                // code to execute if exception is caught
            }

            Voter* voter = voters.findByID(voterID);
            if (voter->getPin() == pin) {

                Voter* votertemp = voters.findByID(voterID);

                if (!votertemp->getIsVoted()) {
                    contesters.contesterDisplay();
                    cout << endl << endl << "Enter Contester ID to give vote: ";
                    int contesterID;
                    try {
                        cin >> contesterID;
                        if (cin.fail()) {
                            cin.clear();   // clear the fail bit
                            cin.ignore();  // discard the invalid input
                            cout << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                            throw runtime_error("Invalid input. Please enter an integer value.");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                        // code to execute when input is valid
                    }
                    catch (const exception& e) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                        cerr << "Error: " << e.what() << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                        system("pause");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        system("cls");
                        // code to handle the exception
                    }

                    Contester* contestertemp = contesters.findByID(contesterID);
                    contestertemp->vote();
                    votertemp->vote();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                    cout << endl << "Vote given successfully!" << endl << endl << endl;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    cout << endl << "You have already given vote." << endl << endl << endl;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            else {
                cout << endl << "Incorrect Pin!" << endl << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                system("pause");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            break;
        }
        case 4:
            // Admin Panel
        {
            system("cls");

            string password;
            char c;
            cout << "Enter Admin Password: ";
            while ((c = _getch()) != '\r') {  // loop until the Enter key is pressed
                if (c == '\b') {  // handle backspace characters
                    if (password.size() > 0) {
                        password.pop_back();
                        cout << "\b \b";
                    }
                }
                else {
                    password += c;
                    cout << "*";
                }
            }
            cout << endl;

            if (password == "admin") {
                system("cls");

                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << "\t\t\t\t\t\t---ADMIN PANEL---\t\t\t\t\t" << endl << endl << endl << endl << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                cout << "\t\t\t\t\t\t1. Display All Voters" << endl << endl;
                cout << "\t\t\t\t\t\t2. Final Result" << endl << endl << endl;
                cout << "Enter choice: ";

                int choice;
                try {
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();   // clear the fail bit
                        cin.ignore();  // discard the invalid input      numeric_limits<streamsize>::max(), '\n'
                        cout << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                        throw runtime_error("Invalid input. Please enter an integer value.");

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                        system("pause");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    }
                    // code to execute when input is valid
                }
                catch (const exception& e) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    cerr << "Error: " << e.what() << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    system("cls");
                    // code to handle the exception
                }
                switch (choice) {
                case 1:
                {
                    system("cls");
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "\t\t\t\t\t\t---VOTERS---\t\t\t\t\t" << endl << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    voters.voterDisplay();
                    cout << endl << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
                case 2:
                    // finalResult();
                    system("cls");
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "\t\t\t\t\t\t---RESULTS---\t\t\t\t\t" << endl << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    contesters.finalResults();
                    cout << endl << endl << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                default:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    cout << endl << "Invalid choice" << endl << endl << endl;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                    system("pause");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << endl << "Incorrect Password!" << endl << endl << endl;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                system("pause");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            break;
        }
        case 5:
            // Quit
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t    T H A N K S  F O R  V O T I N G ! !" << "\n\n\n\n\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            system("pause");
            running = false;
            break;
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << "Invalid choice\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            system("pause");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }
    cout << "Program Ended Successfully" << endl;
}