#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip> // for formatting
#include <conio.h> // Optional, for getch()

using namespace std;

// Define a structure for the components of the unit
struct Component {
    string name;      // Component name (e.g., "Mouse", "Keyboard", etc.)
    int quantity;     // Quantity of the component (always 1 in this case)
    string status;    // Status (e.g., "Good" or "Bad")
};

class Unit {
public:
    // Properties of the unit, each unit contains 5 components
    Component components[5]; // Array of 5 components per unit
    
    // Constructor to initialize the unit's components with random status
    Unit() {
        // Initializing each component for the unit with name, quantity 1, and random status
        components[0] = {"Mouse", 1, randomStatus()};
        components[1] = {"Keyboard", 1, randomStatus()};
        components[2] = {"AVR", 1, randomStatus()};
        components[3] = {"HDMI", 1, randomStatus()};
        components[4] = {"System Unit", 1, randomStatus()};
    }

    // Method to generate a random status (Good or Bad)
    string randomStatus() {
        return (rand() % 15 == 0) ? "Bad!" : "Good"; // 80% chance for "Good", 20% chance for "Bad"
    }

    // Method to display the details of the components in the unit
    void displayUnitDetails() {
        cout << "Unit components:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Component Name: " << components[i].name << endl;
            cout << "Quantity: " << components[i].quantity << endl;
            cout << "Status: " << components[i].status << endl;
            cout << "-----------------------------\n";
        }
    }

    // Method to search for and display the components of this unit
    void searchAndDisplay(int unitNumber) {
        cout << "                 ________________________________________________________\n";
    	cout << "                |  ____________________________________________________  |\n";
    	cout << "                |:|                      UNIT NO. " << unitNumber << "                    |:|\n";  // Ensure proper unit number formatting
    	cout << "                |:|                   COMPUTER LAB 01                  |:|\n";
    	cout << "                |:|----------------------------------------------------|:|\n";
    	cout << "                |:|   COMPONENTS NAME  |    QUANTITY    |    STATUS    |:|\n";
    	cout << "                |:|----------------------------------------------------|:|\n";

    	// Loop through and display the components of the selected unit
    	for (int i = 0; i < 5; ++i) {
        	cout << "                |:|   " << left << setw(15) << components[i].name 
           	  	 << "  |       " << right << setw(2) << components[i].quantity  // Correct quantity formatting
            	 << "       |     " << components[i].status << "     |:|\n";
    	}

   	 	cout << "                |:|____________________________________________________|:|\n";
    	cout << "                |________________________________________________________|\n";

        // Show the options menu for editing, deleting, or going back
        showComponentOptions(unitNumber);
    }

    // Edit component details
    void editComponent(int componentIndex, const string& newName, int newQuantity, const string& newStatus) {
        components[componentIndex].name = newName;
        components[componentIndex].quantity = newQuantity;
        components[componentIndex].status = newStatus;
        cout << "Component " << components[componentIndex].name << " has been updated.\n";
    }

    // Delete a component (just clear the data in this example)
    void deleteComponent(int componentIndex) {
        components[componentIndex].name = "Deleted";
        components[componentIndex].quantity = 0;
        components[componentIndex].status = "Deleted";
        cout << "Component " << componentIndex + 1 << " has been deleted.\n";
    }

    // Function to return the status of the unit (if any component is "Bad", the unit status is "Bad")
    string getUnitStatus() {
        for (int i = 0; i < 5; ++i) {
            if (components[i].status == "Bad!") {
                return "Bad!";
            }
        }
        return "Good";
    }

private:
    void showComponentOptions(int unitNumber) {
        int choice, componentChoice;
        cout << "                     +------------+  +------------+  +------------+\n";
        cout << "                     | [1] EDIT   |  | [2] DELETE |  | [3] BACK   |\n";
        cout << "                     +------------+  +------------+  +------------+\n";
        
        // Wait for a single key press
        choice = _getch();  // This is used from conio.h (Windows-specific)

        // Check if the key pressed is a number ('1', '2', '3')
        if (choice == '1' || choice == '2' || choice == '3') {
            choice -= '0'; // Convert char to integer
        } else {
            cout << "\nInvalid selection. Please choose a valid option (1-3).\n";
            return;
        }

        switch (choice) {
            case 1:
                cout << "Enter component number (1 to 5) to edit: ";
                cin >> componentChoice;
                if (componentChoice >= 1 && componentChoice <= 5) {
                    string newName, newStatus;
                    int newQuantity;

                    cout << "Enter new name: ";
                    cin >> newName;
                    cout << "Enter new quantity: ";
                    cin >> newQuantity;
                    cout << "Enter new status (Good or Bad!): ";
                    cin >> newStatus;

                    editComponent(componentChoice - 1, newName, newQuantity, newStatus);  // -1 for 0-indexed array
                } else {
                    cout << "Invalid component number. Please enter a number between 1 and 5.\n";
                }
                break;

            case 2:
                cout << "Enter component number (1 to 5) to delete: ";
                cin >> componentChoice;
                if (componentChoice >= 1 && componentChoice <= 5) {
                    deleteComponent(componentChoice - 1);  // -1 for 0-indexed array
                } else {
                    cout << "Invalid component number. Please enter a number between 1 and 5.\n";
                }
                break;

            case 3:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
};

// Function to display the component grid
void displayComponentGrid() {
    cout << "                                _________________________ \n";
    cout << "                               |  _____________________  |\n";
    cout << "                               |:|  INVENTORY SYSTEM:  |:|\n";
    cout << "                               |:|_____________________|:|\n";
    cout << "                               |_________________________|\n";
    cout << "               _____________________________________________________________ \n";
    cout << "              |  _________________________________________________________  |\n";
    cout << "              |:|               COMPUTER LABORATOY 01 UNIT      [3] EXIT  |:|\n";
    cout << "              |:|---------------------------------------------------------|:|\n";
    cout << "              |:|   C01   |    C02    |    C03    |    C04    |    C05    |:|\n";
    cout << "              |:|---------------------------------------------------------|:|\n";
    cout << "              |:|   C06   |    C07    |    C08    |    C09    |    C10    |:|\n";
    cout << "              |:|---------------------------------------------------------|:|\n";
    cout << "              |:|   C11   |    C12    |    C13    |    C14    |    C15    |:|\n";
    cout << "              |:|---------------------------------------------------------|:|\n";
    cout << "              |:|   C16   |    C17    |    C18    |    C19    |    C20    |:|\n";
    cout << "              |:|_________|___________|___________|___________|___________|:|\n";
    cout << "              |_____________________________________________________________|\n";
}

// Function to display the menu options
void displayMenu() {
    cout << "                     +------------+       +--------------------------+ \n";
    cout << "                     | [1] Search |       | [2] Display all Units    | \n";
    cout << "                     +------------+       +--------------------------+ \n";
}

// Main function with menu interaction
int main() {
    int choice, unitChoice;

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Create an array of 20 units (C01 to C20)
    Unit units[20];

    while (true) {
        system("cls");
        // Display grid and menu
        displayComponentGrid();
        displayMenu();

        // Wait for a single key press
        choice = _getch();  // This is used from conio.h (Windows-specific)

        // Check if the key pressed is a number ('1', '2', '3')
        if (choice == '1' || choice == '2' || choice == '3') {
            choice -= '0'; // Convert char to integer
        } else {
            cout << "\nInvalid selection. Please choose a valid option (1-3).\n";
            continue;
        }

        // Handle user's choice
        switch (choice) {
            case 1:
                system("cls");
                cout << "                                _________________________ \n";
                cout << "                               |  _____________________  |\n";
                cout << "                               |:| SEARCH ____________ |:|\n";
                cout << "                               |:|_____________________|:|\n";
                cout << "                               |_________________________|\n\n";
                cout << "                          Enter the unit number (1 to 20): ";
                cin >> unitChoice;

                // Check if the input is within the valid range
                if (unitChoice >= 1 && unitChoice <= 20) {
                    // Call search function for the selected unit
                    cout << "                          Displaying details for Unit C" << setw(2) << setfill('0') << unitChoice << ":\n";
                    units[unitChoice - 1].searchAndDisplay(unitChoice); // -1 for 0-indexed array
                } else {
                    cout << "Invalid unit number. Please enter a number between 1 and 20.\n";
                }
                cout << "\nPress any key to return to the main page...";
                cin.ignore();  // To clear the buffer
                cin.get();  // Wait for the user to press any key
                break;

            case 2:
                system("cls");
                cout << "                                _________________________ \n";
                cout << "                               |  _____________________  |\n";
                cout << "                               |:|  DISPLAY ALL UNITS  |:|\n";
                cout << "                               |:|_____________________|:|\n";
                cout << "                               |_________________________|\n\n";

                // Show details for all 20 units
                cout << "                         _______________________________________\n";
                cout << "                        |  ___________________________________  |\n";
                cout << "                        |:|            ALL UNIT LIST          |:|\n";
                cout << "                        |:|           COMPUTER LAB 01         |:|\n";
                cout << "                        |:|-----------------------------------|:|\n";
                cout << "                        |:|   UNIT NO.   |       STATUS       |:|\n";
                cout << "                        |:|--------------+--------------------|:|\n";

                for (int i = 0; i < 20; ++i) {
                    cout << "                        |:|     C" << setw(2) << setfill('0') << (i + 1) << "      |        " << (units[i].getUnitStatus()) << "        |:|\n";
                }

                cout << "                        |:|___________________________________|:|\n";
                cout << "                        |_______________________________________|\n";
                cout << "\nPress any key to return to the main page...";
                cin.ignore();  // To clear the buffer
                cin.get();  // Wait for the user to press any key
                break;

            case 3:
                system("cls");
                cout << "                                _________________________ \n";
                cout << "                               |  _____________________  |\n";
                cout << "                               |:|         EXIT        |:|\n";
                cout << "                               |:|_____________________|:|\n";
                cout << "                               |_________________________|\n\n";
                cout << "                               Exiting the program.\n";
                return 0;

            default:
                cout << "\nInvalid selection. Please choose a valid option (1-3).\n";
                break;
        }
    }

    return 0;
}

