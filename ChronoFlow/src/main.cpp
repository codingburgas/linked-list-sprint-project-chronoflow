#include <iostream>
#include "../Include/MainMenu.h"

int main()
{
	
    int choice;

    bool running = true;

    displayMenu();

	std::cin >> choice;


    while (running)
    {
        switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            std::cout << "Exiting...\n";
            running = false;
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}