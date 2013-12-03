#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "productfactory.h"
#include "historycmd.h"
#include "borrowcmd.h"
#include "returncmd.h"
#include "displayallproductcmd.h"
#include <string>

/*
A factory that produces Commands based on a key to a hashtable containing 
the different types of Command objects.

The CommandFactory constructor that takes a CustomerIndex and a
 ProductCollection
is used to pass along the two data structures to it's products.

The create method takes in a string and parses out the command portion of the
string. It then creates an instance of a child command object based on the 
command it parsed. Finally, it returns a pointer to that command.
*/


class CommandFactory {
public:
	//CommandFactory();
     // constructor, inits hash table
	CommandFactory(CustomerIndex*, ProductCollection*); 
	virtual ~CommandFactory();    // destructor
    // Creates and inits cmd obj based on key given, returns null if invalid key
    Command* create(std::string,ProductCollection*, CustomerIndex*);   
	
private:
    CustomerIndex* cIndex; // For commands that need access to the customers
    // For commands that need to access the products
    ProductCollection* pCollect; 
	ProductFactory* mFactory; // For commands that need to create products.
	
     // A pointer to an array of Commands implemented as a hash tabless
	Command* commandTemplates[HASH_TABLE_SIZE]; 
	int hash(std::string key);
};

#endif