#include <string>
//#include <iostream>
#include <fstream>
//#include "lab4IoPrep.h"
#include "manager.h"

int main(){
	ifstream inputFile1("lab4TestData.txt");
	if (!inputFile1) {
    	cout << "File could not be opened." << endl;
        return 1;
   	}
   	//TODO: add other files to be read
   	Manager productManager;

    productManager.inputProduct(inputFile1);  
    productManager.displayAll();   //TODO: this will eventually be processed through commands instead.
   	
	return 1;
}