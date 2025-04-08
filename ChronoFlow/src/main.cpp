#include <iostream>
#include "../Include/MainMenu.h"
#include "../Include/Operations.h"
#include "../Include/Event.h"


int main() {

    Node* head = nullptr;

    bool running = true;

    while (running) {
        
        displayMenu();

        int choice;

        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addEvent(head);
            break;
        case 2:
            displayAllEvents(head);
            break;
        case 3:
            searchEvents(head);
            break;
        case 4:
            break;
        case 5: {
            int sortChoice;
            std::cout << "Sort by:\n1. Ascending\n2. Descending\n> ";
            std::cin >> sortChoice;
            break;
        }
        case 6:
            running = false;
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}
