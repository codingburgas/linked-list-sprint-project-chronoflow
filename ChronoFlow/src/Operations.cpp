#include "../Include/Operations.h"
#include "../Include/Event.h"
#include <iostream>

void addEvent(Node*& head) {
    std::string title, theme, location;
    int month, year;

    std::cout << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter theme: ";
    std::getline(std::cin, theme);

    std::cout << "Enter location: ";
    std::getline(std::cin, location);

    std::cout << "Enter month: ";
    while (!(std::cin >> month) || month < 1 || month > 12) {
        std::cout << std::endl << "Invalid input. Please enter a valid month number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    std::cout << "Enter year: ";
    while (!(std::cin >> year) || year < 0) {
        std::cout << std::endl <<"Invalid input. Please enter a valid positive year: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

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

    std::cout << std::endl << "Event added successfully.\n";
}

void displayAllEvents(Node* head) {
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void searchEvents(Node* head) {
	std::string searchTerm;
	std::cout << std::endl << "Enter title or theme to search: ";
	std::cin.ignore();
	std::getline(std::cin, searchTerm);

	Node* current = head;
	bool found = false;

    while (current != nullptr) {
        if (current->event.title.find(searchTerm) != std::string::npos || current->event.theme.find(searchTerm) != std::string::npos) {
			std::cout << std::endl << "Title: " << current->event.title << "\n";
			std::cout << "Theme: " << current->event.theme << "\n";
			std::cout << "Location: " << current->event.location << "\n";
			std::cout << "Date: " << current->event.month << "/" << current->event.year << "\n";
			std::cout << "---------------------------\n";
			found = true;
		}
		current = current->next;
	}

    if (!found) {
        std::cout << std::endl << "No events found matching the search term.\n";
	}
}
void deleteEvent(Node*& head) {
    std::cout << std::endl;
    if (head == nullptr) {
		std::cout << "No events to delete.\n";
		return;
	}
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string title;
    std::cout << "Enter the title of the event to delete: ";
    std::getline(std::cin, title);

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->event.title != title) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << std::endl << "Event not found.\n";
        return;
    }


    if (previous == nullptr) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current;
    std::cout << std::endl << "Event deleted successfully.\n";
}

void swapEvents(Event& a, Event& b) {
    Event temp = a;
    a = b;
    b = temp;
}

void sortEvents(Node* head, bool ascending) {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool swapped;
    Node* current;
    Node* last = nullptr;


    do {
        swapped = false;
        current = head;

        
        while (current->next != last) {
            if (ascending) {
                
                if ((current->event.year > current->next->event.year) ||
                    (current->event.year == current->next->event.year && current->event.month > current->next->event.month)) {
                    swapEvents(current->event, current->next->event); 
                    swapped = true;
                    std::cout << std::endl << "Successfully sorted by ascending " << std::endl;
                }
            }
            else {
                
                if ((current->event.year < current->next->event.year) ||
                    (current->event.year == current->next->event.year && current->event.month < current->next->event.month)) {
                    swapEvents(current->event, current->next->event); 
                    swapped = true;
                    std::cout << std::endl << "Successfully sorted by descending " << std::endl;

                }
            }
            current = current->next;  
        }
        last = current;  
    } while (swapped);  
}