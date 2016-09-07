#ifndef LIST_HPP
#define LIST_HPP
#include "items.hpp"

class List
{
private:
    Items *itemsArray;
    int arraySize,
        arrayEnd;
    
public:
    List();
    List(const List&);
    ~List();
    void addItem(Items);
    //void resizeArray(Items []);
    void displayList();
    void delItem(std::string);
    
};

#endif
