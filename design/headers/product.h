#ifndef PRODUCT_H
#define PRODUCT_H
#include "hashtable.h"
#include <string>
#include "event.h"
#include "productformat.h"
#include "productformatcollection.h"
#include <map>
#include <iostream>

/*
Product class

A product object is a movie, a book, a music album, or some other form of 
product. At its most basic level, a Product has the ability to say which of 
these types it is and/or what genre it is, store and output its data (which 
might include title, publication date, composer, sculptor, set designer, etc), 
and compare itself to other Product objects of the same type and genre. 

Each product object stores its format (DVD, blu-ray, book on tape, grain of 
rice, etc) in a ProductFormat object, and all of its other data in a hashTable 
called productData. The object is stored and sorted by  some (but not all) of 
this data, as defined in the string arrays in each specific product type. 
(example: CLASSIC_MOVIE_SORTED BY.) The order of the corresponding string array 
determines the prority of each data type for sorting. (For instance, classic 
movies are sorted first by date, then by famous actor.)

The full arrays of data types (any string arrays ending in "_DATA_TYPES") 
represent all data for a type of Product object, regardless of sorting, in the
order the productfactory creating the Product reads these data members. (They 
are outputted in the same order.)

The productType() string is a pure virtual method which is overridden for each
direct subclass of Product. (Movie returns "movie", Music returns "music", etc.)
The genre() string works similarly, but is overridden only by instantiable
types like ComedyMovie (which would return "comedy"). dataType() concatenates
these two strings to create a unique idenifier for an instantiable product type,
aiding in sorting.

dataTypeNames() and sortedByNames() are helper methods which quickly retrieve 
the corresponding _DATA_TYPES and _SORTED_BY arrays. 

dataString() outputs the Product object's format, along with all of its data in 
order of its dataTypeNames(). The dataString() method is called as part of a 
product BinTree's display method. This is the only method called by the <<
operator.

create() is merely an instatiation method called by the ProductFactory that 
creates a product object.

The addData() method inserts data into the Product's hashtable, with the form
<dataType,data> (Example: <"title","Titanic">). This data is retrieved in a
similar way by dataString().

All of any Product object's comparison operators work under the same principles:
Product objects are compared, in order, by their sorting criteria, ignoring any 
data found in _DATA_TYPES but not in _SORTED_BY. (format is always ignored.)
By this defintion, no "equal" Product objects are stored as separate objects. 
Instead, the quantity of an existing Product object is increased if an equal 
object is inserted.

Each product inserted into a ProductCollection counts as 10 identical Product 
objects, in terms of both count and size variables. Whenever an identical 
Product is inserted, incrementQuantity() is called and increases each value by 
another 10. "count" refers to the number of available copies of the product, 
while size refers to the total number of copies that the store owns (i.e., all 
copies including those borrowed.) borrowedCopies() subtracts count from size to 
determine how many copies of a product.have been borrowed.
*/

//most generic Product type
class Product {
public:
	Product();
	virtual ~Product();
	bool setData(Event); // Returns false if input invalid.
    virtual Product* create() = 0; // Creates a new, empty Product 
    //returns the type (the class) of product. Used as a key.
    virtual std::string type() const = 0;	
	virtual void display(); // Displays contents via cout
	
	// Returns all data, inorder of input, deliminated by commas
	virtual const std::string* dataTypeNames() const = 0; 
	// Returns the sorting data, delineated by commas
	virtual const std::string* sortedByNames() const = 0; 
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const Product &) const;
    virtual bool operator!=(const Product &) const;
    virtual bool operator<(const Product &) const;
    virtual bool operator>(const Product &) const;
    virtual bool operator<=(const Product &) const;
    virtual bool operator>=(const Product &) const;
	
	//increments the quantity of a particular product format.
    void incrementQuantity(ProductFormat);		
    //number of copies borrowed by customers of a particular product format
    int getBorrowedItems(ProductFormat) const; 			
    //number of copies borrowed by customers of a particular product format
	int getRemainingItems(ProductFormat) const; 			
private:
	//Contains the quantities and different formats this product has.	
	ProductFormatCollection inventory; 
	//Contains the attributes of this product.
	std::map<std::string,std::string> productData;    
	//Contains valid formats of the product. The identifier code is the key. 
	std::map<std::string,ProductFormat> validFormats; 
	// Returns false if key doesn't exist  in productData;
    bool addData(std::string key,std::string value); 
    // All products must have possible format(s).        
	virtual void initValidFormats() = 0; 
	bool addFormat(ProductFormat); //Returns false if data invalid.
};

#endif