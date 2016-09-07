#include <iostream>
#include "menuFunctions.hpp"

void displayMenu()
{
    std::cout << "Would you like to;" << std::endl;
    std::cout << "\t" << "1. Add items" << std::endl;
    std::cout << "\t" << "2. Delete an item" << std::endl;
    std::cout << "\t" << "3. Display the shopping list" << std::endl;
    std::cout << "\t" << "4. Quit" << std::endl;
}

int getChoice()
{
    int choice;
    
    std::cin >> choice;
    
    while(choice < 1 || choice > 4)
    {
        std::cout << "Not a valid choice. Please enter 1, 2, 3, or 4" << std::endl;
        std::cin.ignore();
        std::cin >> choice;
    }
        
    return choice;
}
