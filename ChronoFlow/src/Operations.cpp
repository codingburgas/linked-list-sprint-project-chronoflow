#include "../Include/Operations.h"
#include "../Include/Event.h"
#include <iostream>

void addEvent(Node*& head) {
    
    std::string title, theme, location;
    int month, year;

    std::cout << std::endl;

    std::cout << "Enter title: ";
    std::cin >> title;

    std::cout << "Enter theme: ";
    std::cin >> theme;

    std::cout << "Enter location: ";
    std::cin >> location;

    std::cout << "Enter month: ";
    std::cin >> month;

    std::cout << "Enter year: ";
    std::cin >> year;

    Event newEvent(title, theme, location, month, year);
    Node* newNode = new Node(newEvent);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }

    std::cout << "Event added successfully.\n";
}

void displayAllEvents(Node* head) {
   
    if (head == nullptr) {
        std::cout << "No events to display.\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {

        std::cout << std::endl;
        std::cout << "Title: " << current->event.title << "\n";
        std::cout << "Theme: " << current->event.theme << "\n";
        std::cout << "Location: " << current->event.location << "\n";
        std::cout << "Date: " << current->event.month << "/" << current->event.year << "\n";
        std::cout << "---------------------------\n";
        current = current->next;
    }
}