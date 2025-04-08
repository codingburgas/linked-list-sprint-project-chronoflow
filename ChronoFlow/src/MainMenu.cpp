#include "../include/MainMenu.h"
#include "../include/Node.h"
#include <iostream>

int countEvents(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void displayMenu(Node* head) {
    std::cout << "\n==================== ChronoFlow ====================\n";
    std::cout << "||                                                ||\n";
    std::cout << "||                                                ||\n";
    std::cout << "||  1. Add Event                                  ||\n";
    std::cout << "||  2. Display All Events                         ||\n";
    std::cout << "||  3. Search Events                              ||\n";
    std::cout << "||  4. Delete Events                              ||\n";
    std::cout << "||  5. Sort Events                                ||\n";
    std::cout << "||  6. Exit                                       ||\n";
    std::cout << "||                                                ||\n";
    std::cout << "||  Current number of events: " << countEvents(head) << "                   ||\n";
    std::cout << "||                                                ||\n";
    std::cout << "==================== ChronoFlow ====================\n" << "\n";
    std::cout << "Choose an option: ";
}
