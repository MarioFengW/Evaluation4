#include <iostream>
#include <string>
#define RESET "\033[0m"          // Reset to default color
#define LIGHT_GRAY "\033[37m"    // Light gray for less important text
#define WHITE "\033[97m"         // White for main text
#define BOLD "\033[1m"           // Bold text
#define DIM "\033[2m"            // Dimmed text for subtle options
#define BLUE "\033[94m"   
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Create friendship" << endl;
    cout << "2. Add content" << endl;
    cout << "3. Add interest to a user" << endl;
    cout << "4. Adult content?" << endl;
    cout << "5. Age" << endl;
    cout << "6. View recommendations" << endl;
    cout << "7. Add user" << endl;
    cout << "8. Exit" << endl;
    cout << "Select an option: ";
}


void handleMenu() {
    int option;
    string inputString;

    do {
        showMenu();
        cin >> option;
        cin.ignore(); 

        switch (option) {
            case 1:
                cout << "Option selected: Create friendship" << endl;
                cout << "Enter the name of the friend: ";
                getline(cin, inputString); 
                cout << "Friendship created with: " << inputString << endl;
                break;
            case 2:
                cout << "Option selected: Add content" << endl;
                cout << "Enter the content: ";
                getline(cin, inputString); 
                cout << "Content added: " << inputString << endl;
                break;
            case 3:
                cout << "Option selected: Add interest to a user" << endl;
                cout << "Enter the interest: ";
                getline(cin, inputString); 
                cout << "Interest added: " << inputString << endl;
                break;
            case 4:
                cout << "Option selected: Adult content?" << endl;
                cout << "Enter 'yes' or 'no': ";
                getline(cin, inputString); 
                cout << "Your input: " << inputString << endl;
                break;
            case 5:
                cout << "Option selected: Age" << endl;
                cout << "Enter your age: ";
                getline(cin, inputString); 
                cout << "Your age is: " << inputString << endl;
                break;
            case 6:
                cout << "Option selected: View recommendations" << endl;
                
                break;
            case 7:
                cout << "Option selected: Add user" << endl;
                cout << "Enter the name of the new user: ";
                getline(cin, inputString); 
                cout << "User added: " << inputString << endl;
                break;
            case 8:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl; 
    } while (option != 8);
}
