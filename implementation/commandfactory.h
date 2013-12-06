#pragma once
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "productfactory.h"
#include "command.h"
#include "historycmd.h"
#include "borrowcmd.h"
#include "displayallproductcmd.h"
#include "returncmd.h"
#include <string>
#include <map>

/*
A factory that produces Commands based on a key to a hashtable containing 
the different types of Command objects.
*/


class CommandFactory {
private:
    CustomerIndex* cIndex; // For commands that need access to the customers
    // For commands that need to access the products
    ProductCollection* pCollect; 
    ProductFactory* pFactory; // For commands that need to create products.
     // A pointer to an array of Commands implemented as a hash table
    // Command* hashTable;
    std::map<char, Command*> cmds;
    std::map<char, Command*>::iterator it;
    int hash(std::string key);

public:
    // constructor, inits hash table
	CommandFactory(CustomerIndex*, ProductCollection*); 
	virtual ~CommandFactory();    // destructor
    // Creates and inits cmd obj based on key given, returns null if invalid key
    Command* create(std::string key);   
    bool keyExists(char);
};

#endif