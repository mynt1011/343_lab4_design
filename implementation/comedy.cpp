#include "comedy.h"
#include <iostream>

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Comedy::Comedy(){
//TODO: find out if productdata objects should even be created.
    COMEDY_DATA_TYPES.push_back("director");
    COMEDY_DATA_TYPES.push_back("title");
    COMEDY_DATA_TYPES.push_back("date");

    COMEDY_SORTED_BY.push_back("title");
    COMEDY_SORTED_BY.push_back("date");
}

// cleans up any productdata objects it created
Comedy::~Comedy(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.  //TODO: rewrite description
bool Comedy::setData(Event* e){
    std::string eventToken;
    std::string eventDetails = e->getEventDetails();
    int dataTypeCounter = 0;
    //deliminating eventDetails string by comma
    for(int i = 1; i < eventDetails.size(); ++i){
        if(dataTypeCounter > COMEDY_DATA_TYPES.size()){            
            break;            
        }
        else if(eventDetails.at(i) == ','){
             //load into product's ht
            productData[COMEDY_DATA_TYPES.at(dataTypeCounter)] = eventToken;
            dataTypeCounter++;
            eventToken = "";
        }
        else{
            eventToken.push_back(eventDetails.at(i));        
        }
    }
    // Need to get the last token after the comma
    productData[COMEDY_DATA_TYPES.at(dataTypeCounter)] = eventToken; 

    delete e;
    return true; //TODO
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Comedy::create(){
    return new Comedy();
}

// TODO: Not sure if this method is necessary
// The type method returns the type of the genre product object. For this one,
// it will return the string "comedy". This is used as a key for the hashtable.
std::string Comedy::type() const{
    return "Comedy";
}

// The display method displays the private data members using cout.
void Comedy::display(){
    for(int i = 0; i < COMEDY_SORTED_BY.size(); ++i){
        std::cout << COMEDY_SORTED_BY[i] << ": " << productData[COMEDY_SORTED_BY[i]] << std::endl;
    }
}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
// const std::string* Comedy::dataTypeNames() const{
//     return Comedy::COMEDY_DATA_TYPES;
// }

// const std::string* Comedy::sortedByNames() const{
//     return Comedy::COMEDY_SORTED_BY;
// }

// returns unique identifier
std::string Comedy::getKey(){
    return "Comedy";
}


//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
// bool Comedy::operator==(const NodeData &) const{

// }

// bool Comedy::operator!=(const NodeData &) const{

// }

// bool Comedy::operator<(const NodeData &) const{

// }

// bool Comedy::operator>(const NodeData &) const{

// }

// bool Comedy::operator<=(const NodeData &) const{

// }

// bool Comedy::operator>=(const NodeData &) const{

// }