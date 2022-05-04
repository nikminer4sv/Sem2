#pragma once

#include <vector>
#include "4.1_Header.h"
#include <algorithm>
#include "Vector.h"

Object *CreateObject()
{
    Rock *rock = new Rock();
    Chest *chest = new Chest();
    Trader *trader = new Trader();
    Civilian *civilian = new Civilian();
    Player *player = new Player();

    std::cout << "Choose the type of the object: \n"
              << "1 - Rock\n"
              << "2 - Chest\n"
              << "3 - Trader\n"
              << "4 - Civilian\n"
              << "5 - Player\n";

    int choice;

    std::cin >> choice;

    switch (choice)
    {
    case 1:
        rock->Add();
        return rock;
    case 2:
        chest->Add();
        return chest;
    case 3:
        trader->Add();
        return trader;
    case 4:
        civilian->Add();
        return civilian;
    case 5:
        player->Add();
        return player;
    }

    delete rock;
    delete chest;
    delete trader;
    delete civilian;
    delete player;
}

class Collection
{
private:
    Vector<Object *> _collection;

    inline void IndexValidation(size_t index) const
    {
        if (index >= _collection.getSize())
            throw std::invalid_argument("Invalid index!");
    }

public:
    Collection() = default;

    Collection(const Collection &collection) { _collection = collection._collection; }

    Collection(Collection &&other)
    {
        _collection = std::move(other._collection);
    }

    void Append(Object *object) { _collection.push_back(object); }

    void Clear()
    {
        _collection.Clear();
    }

    void Remove(size_t index) {
        IndexValidation(index);
        _collection.erase(index);
    }

    friend std::ostream &operator<<(std::ostream &str, const Collection &c)
    {

        for(int i = 0; i < c._collection.getSize(); i++)
        {
            c._collection[i]->Print(std::cout);
            std::cout << std::endl;
        }

        return str;
    }

    Object *&operator[](size_t index)
    {
        IndexValidation(index);
        return _collection[index];
    }

    Collection &operator=(const Collection &collection)
    {
        _collection = collection._collection;
        return *this;
    }

    Collection &operator=(Collection &&collection)
    {
        if (this != &collection)
            _collection = std::move(collection._collection);

        return *this;
    }
};

void Task(Collection &collection)
{
    bool IsWorking = true;
    int i = 0;
    while (IsWorking)
    {
        std::cout
                << "1. Add\n"
                << "2. Print\n"
                << "3. Exit\n";

        int Choice = 0;
        std::cin >> Choice;

        switch (Choice)
        {
            case 1:
            {
                collection.Append(CreateObject());
                break;
            }

            case 2:
            {
                std::cout << std::endl << collection;
                break;
            }

            case 3:
                IsWorking = false;
                break;

            default:
                std::cout << "Invalid Enter!\n";
                break;
        }
    }
}