//Brian Pina
//Revision of data tructs final project where we manage a adressbook using a avl tree as the main structure
#include "avltree.h"
#include "contact.h"
#include "functions.h"


using namespace std;

int main() {
    cout << "Hello Welcome to this address book manager program" << endl;
    AVLClass addressBook;                    //creates a object the will be the avl tree or in our program the addressbook
    std::vector<Affiliates> affil;
    readFile(addressBook, affil);                  //this function will read in a file and fill the avl tree
    int choice;
    //WILL SHOW THE MENU UNLESS THE USER INPUTS THE EXIT INPUT WHICH IS 99 in thid program
    do{
        choice = mainMenu();                ///main menu will return a int value and choice will get that value
        ////////IF STATEMENTS FOR EACH CASE//////////
        if(choice == 1){
               sort();                       //will call function that will ask what field they want to sort by
        }
        else if(choice == 2){
               search(addressBook);                             //will call search book will ask by what field and then ask for the field they want to search by
        }
        else if(choice ==3){
             updateBook(addressBook,affil);                               //will call updatebook where it will search for a subject and then will ask for which field they want to update  or delete an affiliate
        }
        else if(choice == 4){
            addressBook.Print();
        }
        else if(choice != 1, choice != 2, choice != 3, choice != 4, choice != 15 )
            cout << "Please choose again" << endl;


    }while(choice != 15);                   //will do the while unless the user inputs 15
    addressBook.Write(affil);
    cout << "Exiting" << endl;              //tells the user that the program is closing
    return 0;
}