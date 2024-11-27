#include "Menu.h"
#include "RecommendationSystem.h"
#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

RecommendationSystem recommendationSystem;

void showMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Add user" << endl;
    cout << "2. Create friendship" << endl;
    cout << "3. Add content" << endl;
    cout << "4. Add content to a user" << endl;
    cout << "5. View recommendations" << endl;
    cout << "6. Exit" << endl;
    cout << "Select an option: ";
}

void handleMenu() {
    int option;
    string inputString;

    do {
        showMenu();
        while (!(cin >> option)) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            showMenu();
        }
        cin.ignore(); 

        switch (option) {
            case 1: {
                cout << "Option selected: Add user" << endl;
                cout << "Enter the name of the new user: ";
                getline(cin, inputString);
                recommendationSystem.addUser(inputString, {});
                cout << "User added: " << inputString << endl;
                break;
            }
            case 2: {
                cout << "Option selected: Create friendship" << endl;
                cout << "Enter the name of the first friend: ";
                getline(cin, inputString);
                string friend1 = inputString;
                cout << "Enter the name of the second friend: ";
                getline(cin, inputString);
                string friend2 = inputString;
                recommendationSystem.addFriend(friend1, friend2);
                cout << "Friendship created between: " << friend1 << " and " << friend2 << endl;
                break;
            }
            case 3: {
                cout << "Option selected: Add content" << endl;
                cout << "Enter the category: ";
                getline(cin, inputString);
                string category = inputString;
                cout << "Enter the content: ";
                getline(cin, inputString);
                recommendationSystem.addContent(category, inputString);
                cout << "Content added to category " << category << ": " << inputString << endl;
                break;
            }
            case 4: {
                cout << "Option selected: Add content to a user" << endl;
                cout << "Enter the user name: ";
                getline(cin, inputString);
                string userName = inputString;
                cout << "Enter the category: ";
                getline(cin, inputString);
                string category = inputString;
                cout << "Enter the content: ";
                getline(cin, inputString);
                recommendationSystem.addContent(category, inputString);
                recommendationSystem.addInterestToUser(userName, category, 1);
                cout << "Content added to user " << userName << " in category " << category << ": " << inputString << endl;
                break;
            }
            case 5: {
                cout << "Option selected: View recommendations" << endl;
                cout << "Enter the user name: ";
                getline(cin, inputString);
                vector<string> recommendations = recommendationSystem.recommendContent(inputString);
                cout << "Recommendations for " << inputString << ":" << endl;
                for (const string& recommendation : recommendations) {
                    cout << recommendation << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl; 
    } while (option != 6);
}