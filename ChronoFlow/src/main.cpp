#include <iostream>
#include "../Include/MainMenu.h"
#include "../Include/Operations.h"
#include "../Include/Event.h"


int main() {

    Node* head = nullptr;

    bool running = true;

    while (running) {
        
        displayMenu(head);

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
            deleteEvent(head);
            break;
        case 5: {
            bool sortChoice;
            std::cout << std::endl << "Sort by date: " << std::endl;
            std::cout << std::endl << "0. Descending" << std::endl << "1. Ascending";
            std::cout << std::endl << std::endl << "Enter your choice: ";
            std::cin >> sortChoice;
            sortEvents(head, sortChoice == 1);
            break;
        }
        case 6:
            running = false;
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << std::endl << "Invalid choice. Try again.\n";
            break;
        }
    }
}
