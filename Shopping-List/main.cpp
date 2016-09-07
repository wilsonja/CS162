#include <iostream>
#include <string>
#include "list.hpp"

int main()
{
    int choice;
    List itemList;
    char cont;
    
    do{
        displayMenu();
        choice = getChoice();
        
        if(choice == 1)
        {
            do{
                std::string name;
                std::string unit;
                int quant;
                double unitPrice;
                
                std::cin.ignore();
                
                std::cout << "Please enter item name." << std::endl;
                getline(std::cin, name);
            
                std::cout << "Please enter the unit type (can, box, lbs, oz, etc)." << std::endl;
                getline(std::cin, unit);
    
                std::cout << "Please enter the quantity you would like to purchase." << std::endl;
                std::cin >> quant;
    
                std::cout << "Please enter the price per unit." << std::endl;
                std::cin >> unitPrice;
    
                Items newItem(name, unit, quant, unitPrice);
    
                itemList.addItem(newItem);
    
                std::cout << "Would you like to add an additional item? (y/n)" << std::endl;
                std::cin >> cont;
        
            }while(cont == 'Y' || cont == 'y');
        }
        
        if(choice == 2)
        {
            std::string delName;
            
            std::cin.ignore();
            std::cout << "Enter the name of the item to delete." << std::endl;
            getline(std::cin, delName);
            
            itemList.delItem(delName);
        }
        
        if(choice == 3)
        {
            std::cout << std::endl;
            itemList.displayList();
            std::cout << std::endl;
        }
    }while(choice != 4);

    return 0;
}
