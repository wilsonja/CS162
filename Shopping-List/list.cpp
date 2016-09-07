#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "list.hpp"

/* DEFAULT CONSTRUCTOR */
List::List()
{
    arraySize = 100;
    itemsArray = new Items[arraySize];
    arrayEnd = 0;
}

/* COPY CONSTRUCTOR */
List::List(const List &obj)
{
    arrayEnd = obj.arrayEnd;
    
    itemsArray = new Items[arrayEnd];
    
    for(int i = 0; i < arrayEnd; i++)
    {
        itemsArray[i] = obj.itemsArray[i];
    }
    
    delete []itemsArray;
}

/* DESTRUCTOR */
List::~List()
{
    delete []itemsArray;
}

/* MEMBER FUNCTIONS */
void List::addItem(Items item)
{
    bool inArray = false;
    
    for(int i = 0; i < arrayEnd; i++)
    {
        if(item.get_name() == itemsArray[i].get_name())
        {
            int newQuant;
            char adjQuant;
            
            std::cout << item.get_name() << " is already in the list." << std::endl;
            std::cout << "Would you like to update the quantity? (y/n)" << std::endl;
            std::cin >> adjQuant;
        
            if(adjQuant == 'y' || adjQuant == 'Y')
            {
                std::cin.ignore();
                
                std::cout << "Please enter the new quantity for " << itemsArray[i].get_name() << std::endl;
                std::cin >> newQuant;
                
                itemsArray[i].set_quant(newQuant);
            }
            inArray = true;
        }
    }
    
    if(!inArray)
    {
        itemsArray[arrayEnd] = item;
        arrayEnd++;
    }
}

/*void List::resizeArray(Items array[])
{
    
}*/

void List::displayList()
{
    double total = 0;
    
    std::cout << std::left << std::setw(12) << "Item"
              << std::setw(8) << "Unit"
              << std::setw(10) << "Quantity"
              << std::setw(12) << "Unit Price"
              << std::setw(12) << "Item Price" << std::endl;
    std::cout << "-----------------------------------------------------\n";
    
    for(int i = 0; i < arrayEnd; i++)
    {
        std::cout << std::left;
        std::cout << std::setw(12) << itemsArray[i].get_name();
        std::cout << std::setw(10) << itemsArray[i].get_unit();
        std::cout << std::setw(10) << itemsArray[i].get_quant();
        
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(12) << itemsArray[i].get_unit_price();
        std::cout << std::setw(10) << itemsArray[i].item_subtotal();
        std::cout << std::endl;
    }
    
    std::cout << "-----------------------------------------------------\n";
    
    for(int i = 0; i < arrayEnd; i++)
    {
        total += itemsArray[i].item_subtotal();
    }
    
    std::cout << std::left << std::setw(42) << "Total Price:";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::right << "$" << total;
    std::cout << std::endl;
}

void List::delItem(std::string delItem)
{
    int itemPos = 0;
    
    for(int i = 0; i <= arrayEnd; i++)
    {
        if(delItem == itemsArray[i].get_name())
        {
            itemPos = i;
        }
    }
    
    for(int i = itemPos; i <= arrayEnd; i++)
    {
        itemsArray[i] = itemsArray[i + 1];
    }
    arrayEnd--;
    
    std::cout << delItem << " has been deleted." << std::endl;
    std::cout << std::endl;
}
