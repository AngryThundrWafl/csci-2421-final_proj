//
// Created by Brian on 5/12/2016.
//
#include <sstream>
#include "functions.h"

void readFile(AVLClass &book, std::vector<Affiliates> & affil) {
    string line, line2;
    int id;
    string tempID,tempString;

    string firstname,middlename,lastname,companyname,homePhone,mobilePhone,email,officePhone,address,city,state,zipCode,country;
    ifstream input;
    input.open("input.txt");
    if (input.fail()) {
        cout << "Could not open file" << endl;
        return;
    }
    cout << "File Opened Succedfully" << endl;
    while(getline(input,line, '|')) {
        if (line[0] == '\n')
            line.erase(0, 1);
        std::stringstream ss(line);     //puts everything in a ss stream the we wil sperate each part
        getline(ss, tempID);
        id = std::stoi(tempID);
        getline(ss, firstname);
        getline(ss, middlename);
        getline(ss, lastname);
        getline(ss, companyname);
        getline(ss, homePhone);
        getline(ss, mobilePhone);
        getline(ss, email);
        getline(ss, officePhone);
        getline(ss, address);
        getline(ss, city);
        getline(ss, state);
        getline(ss, zipCode);
        getline(ss, country);
        Contact *tempBook = new Contact(id, firstname, middlename, lastname, companyname, homePhone, mobilePhone, email,
                                        officePhone, address, city, state, zipCode, country);
        while (getline(ss, line2)) {
            stringstream ss2(line2);
            if (line2 != "") {
                Affiliates tempAffil;
                tempAffil.keyId = id;
                getline(ss2, tempAffil.FName, ' ');
                getline(ss2, tempAffil.LName, ',');
                getline(ss2, tempAffil.Phone, ',');
                getline(ss2, tempAffil.Email, ',');
                tempBook->setAfill(tempAffil);
                affil.push_back(tempAffil);
            }
        }
        book.Insert(*tempBook);
    }
    input.close();
}

void pause() {
    cout << "Press enter to continue" << endl;
    cin.get();
}

int mainMenu() {
    int choice;
    cout << "Please choose a following option " << endl;
    cout << "1:Sort the Address Book" << endl;
    cout << "2:Search the Address Book" << endl;
    cout << "3:Update the Adress Book" << endl;
    cout << "4;Print the Address Book" << endl;
    cout << "15:Exit" << endl;
    cin >> choice;
    /////will check if the a number is input as a choice
    while(cin.fail()){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    return choice;
}

void sort() {
    AVLClass book;
    int choice;
    do {
        cout << "Please choose what you wpuld like to sort by" << endl;
        cout << "1:First Name" << endl;
        cout << "2:Middle Name" << endl;
        cout << "3:Last Name" << endl;
        cout << "4:Company Name" << endl;
        cout << "5:Home Phone" << endl;
        cout << "6:Mobile Phone" << endl;
        cout << "7:Email" << endl;
        cout << "8:Office Phone" << endl;
        cout << "9:Address" << endl;
        cout << "10:City" << endl;
        cout << "11:State" << endl;
        cout << "12:Zipcode" << endl;
        cout << "13:Country" << endl;
        cin >> choice;
        while(cin.fail()){
            cout << "Error number was not inputted make sure input a number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Enter new value" << endl;
            cin >> choice;
        }
        cout << "You choose option # " << choice << endl;
        pause();
        //########################################################################################################################//
        //will read in data to create a new tree
        string line, line2;
        int id;
        string tempID, tempString;

        string firstname, middlename, lastname, companyname, homePhone, mobilePhone, email, officePhone, address, city, state, zipCode, country;
        ifstream input;
        input.open("input.txt");
        if (input.fail()) {
            cout << "Could not open file" << endl;
            return;
        }
        cout << "File Opened Succedfully" << endl;
        while (getline(input, line, '|')) {
            if (line[0] == '\n')
                line.erase(0, 1);
            std::stringstream ss(line);     //puts everything in a ss stream the we wil sperate each part
            getline(ss, tempID);
            id = std::stoi(tempID);
            getline(ss, firstname);
            getline(ss, middlename);
            getline(ss, lastname);
            getline(ss, companyname);
            getline(ss, homePhone);
            getline(ss, mobilePhone);
            getline(ss, email);
            getline(ss, officePhone);
            getline(ss, address);
            getline(ss, city);
            getline(ss, state);
            getline(ss, zipCode);
            getline(ss, country);
            Contact *tempBook = new Contact(id, firstname, middlename, lastname, companyname, homePhone, mobilePhone,
                                            email,
                                            officePhone, address, city, state, zipCode, country);
            while (getline(ss, line2)) {
                stringstream ss2(line2);
                if (line2 != "") {
                    Affiliates tempAffil;
                    getline(ss2, tempAffil.FName, ' ');
                    getline(ss2, tempAffil.LName, ',');
                    getline(ss2, tempAffil.Phone, ',');
                    getline(ss2, tempAffil.Email, ',');
                    tempBook->setAfill(tempAffil);
                }
            }
            book.Sort(*tempBook, choice);
        }
        book.PrintSorted(choice);
        input.close();
    }while(choice != 0);
        cout << "returning to main menu" << endl;
}

void updateBook(AVLClass &book,std::vector<Affiliates>& affil) {
    cout << "What would you like to do?" << endl;
    int choice;             //will hold the user input
    do{
        cout << "1:Update a entry" <<endl;
        cout << "2:Add entry" << endl;
        cout << "3:Delete entry" << endl;
        cout << "15:Exit" << endl;
        cin >> choice;
        while(cin.fail()){
            cout << "Error number was not inputted make sure input a number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Enter new value" << endl;
            cin >> choice;
        }
        if(choice == 1){            //will update a entry
            update(book);      //this function will update a entry in the adressbook

        }
        else if(choice == 2){       //will add entry
            add(book) ;       //this function will add a new entry to the addressbook
        }
        else if(choice == 3){       //delete entry
            deleteBook(book,affil);     //this fucntion will delete a affiliate entry in the addressbook
        }

    }while(choice != 15);           //exit
    cout << "Returning to main menu" << endl;
}

void update(AVLClass &book) {
    book.Print();
    Contact tempCon;
    int tempId;
    cout << "Please enter the ID of the Contact you're trying to modify" << endl;
    cin >> tempId;
    while(cin.fail()){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> tempId;
    }
    tempCon.setId(tempId);
    book.Modify(tempCon);

}

void deleteBook(AVLClass &book, std::vector<Affiliates>& affil) {
    std::vector<Affiliates> newAffil;
    Affiliates tempAffil;
    cout << "Please enter either firstname, lastname, phone or Email of the Affiliate youre trying to delete" << endl;
    int usrhoice;
    string choice;
    cin.ignore();
    getline(cin,choice);
    string string1,string2,string3,string4;
    for(int i =0;i < affil.size();i++){
        if(choice == affil[i].FName || choice == affil[i].LName || choice == affil[i].Email || choice == affil[i].Phone){
            int c = i + 2;
           if((c) == affil.size()) {
               cout << i << endl;
               printAffilVec(affil);
               return;
           }else
                 i++;

        }
        else if(choice != affil[i].FName || choice != affil[i].LName || choice != affil[i].Email || choice != affil[i].Phone){
            cout << "Adding affil" << endl;
            string1 = affil[i].FName;
            string2 = affil[i].LName;
            string3 = affil[i].Email;
            string4 = affil[i].Phone;
            tempAffil.FName = string1;
            tempAffil.LName = string2;
            tempAffil.Email = string3;
            tempAffil.Phone = string4;
            newAffil.push_back(tempAffil);
            //cout << "What would you like to change" << endl;
            //cout << "1:First NAme" << endl;
            //cout << "2:Last Name" << endl;
            //cout << "3:Phone" << endl;
            //cout << "4:Email" << endl;
            //cin >> usrhoice;
            //cin.ignore();
            //if(usrhoice == 1){
            //    cout << "Enter new field" << endl;
            //    getline(cin, choice);
            //    affil[i].FName = choice;
            //}
            //if(usrhoice ==2){
            //    cout << "Enter new field" << endl;
            //    getline(cin, choice);
            //    affil[i].LName = choice;
            //}
            //if(usrhoice == 3){
            //    cout << "Enter new field" << endl;
            //    getline(cin, choice);
            //    affil[i].Phone = choice;
            //}
            //if(usrhoice == 4){
            //    cout << "Enter new field" << endl;
            //    getline(cin, choice);
            //    affil[i].Email = choice;
            //}

        }
    }
    affil.clear();
    for(int i = 0; i < newAffil.size();i++){
        string1 = newAffil[i].FName;
        string2 = newAffil[i].LName;
        string3 = newAffil[i].Email;
        string4 = newAffil[i].Phone;
        tempAffil.FName = string1;
        tempAffil.LName = string2;
        tempAffil.Email = string3;
        tempAffil.Phone = string4;
        affil.push_back(tempAffil);
    }
    printAffilVec(affil);

}

void add(AVLClass &book) {
    Affiliates tempAffil;
    string firstname,middlename,lastname,companyname,homephone,mobilephone,email,oficephone,address,city,state,zip,country;
    string FirstN, LastN, Phone,Email;
    cout << "Please enter the following fields" << endl;
    srand(time(NULL));
    int randomNum = rand() % 1000000000 ;       //gnerates a randome number between 0 - 999999999
    cout << "1:First Name" << endl;
    getline(cin,firstname);
    cout << "2:Middle Name" << endl;
    getline(cin,middlename);
    cout << "3:Last Name" << endl;
    getline(cin,lastname);
    cout << "4:Company Name" << endl;
    getline(cin,companyname);
    cout << "5:Home Phone" << endl;
    getline(cin,homephone);
    cout << "6:Mobile Phone" << endl;
    getline(cin,mobilephone);
    cout << "7:Email" << endl;
    getline(cin,email);
    cout << "8:Office Phone" << endl;
    getline(cin,oficephone);
    cout << "9:Address" << endl;
    getline(cin,address);
    cout << "10:City" << endl;
    getline(cin,city);
    cout << "11:State" << endl;
    getline(cin,state);
    cout << "12:Zipcode" << endl;
    getline(cin,zip);
    cout << "13:Country" << endl;
    getline(cin,country);
    Contact tempCon(randomNum,firstname,middlename,lastname,companyname,homephone,mobilephone,email,oficephone,address,city,state,zip,country);
    cout << "How many affiliates woulf you like to add" << endl;
    int num;
    cin >> num;
    while(cin.fail()){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> num;
    }
    pause();
    for(int i = 0; i < num;i++){
        cout << "For Affiliate: " << i+1 << endl;
        cout << "First Name" << endl;
        getline(cin,FirstN);
        cout << "Last Name" << endl;
        getline(cin,LastN);
        cout << "Email" << endl;
        getline(cin,Email);
        cout << "Phone" << endl;
        getline(cin,Phone);
        tempAffil.FName = FirstN;
        tempAffil.LName = LastN;
        tempAffil.Phone = Phone;
        tempAffil.Email = Email;
        tempCon.setAfill(tempAffil);
    }
    book.Insert(tempCon);
}

void search(AVLClass &book) {
    Contact tempCon;
    int choice;
    string find;
    do {
        cout << "What field would you like to search by?" << endl;
        cout << "1:First Name" << endl;
        cout << "2:Middle Name" << endl;
        cout << "3:Last Name" << endl;
        cout << "4:Company Name" << endl;
        cout << "5:Home Phone" << endl;
        cout << "6:Mobile Phone" << endl;
        cout << "7:Email" << endl;
        cout << "8:Office Phone" << endl;
        cout << "9:Address" << endl;
        cout << "10:City" << endl;
        cout << "11:State" << endl;
        cout << "12:Zipcode" << endl;
        cout << "13:Country" << endl;
        cout << "15: Exit" << endl;
        cin >> choice;
        while (cin.fail()) {
            cout << "Error number was not inputted make sure input a number" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter new value" << endl;
            cin >> choice;
        }
        pause();
        cout << "Please enter what you would like to search for" << endl;
        getline(cin, find);
        switch (choice) {
            case 1:
                tempCon.setFName(find);
                break;
            case 2:
                tempCon.setMName(find);
                break;
            case 3:
                tempCon.setLNAme(find);
                break;
            case 4:
                tempCon.setCName(find);
                break;
            case 5:
                tempCon.setHome(find);
                break;
            case 6:
                tempCon.setMob(find);
                break;
            case 7:
                tempCon.setEmail(find);
                break;
            case 8:
                tempCon.setOffice(find);
                break;
            case 9:
                tempCon.setAd(find);
                break;
            case 10:
                tempCon.setCity(find);
                break;
            case 11:
                tempCon.setState(find);
                break;
            case 12:
                tempCon.setZip(find);
                break;
            case 13:
                tempCon.setCountry(find);
                break;
        }
        book.Search(tempCon, choice);
    }while(choice != 15);
    cout << "returning" << endl;
}

void printAffilVec(vector<Affiliates> &affil) {
    for(int i = 0; i < affil.size();i++){
        cout << "Affiliate" << i +1 << endl;
        cout << "First NAme: " << affil[i].FName << endl;
        cout << "LAst Name: " << affil[i].LName << endl;
        cout << "Phone" << affil[i].Phone << endl;
        cout << "Email: " << affil[i].Email << endl;
        cout << endl;
     }
}

void denomChange(int *pInt) {
    int choice;                      //will hold values for the user
    cout << "Pleae choose 0 = yes    and 1 = no " << endl;
    cout << "Youre going to select what fields you want to print out" << endl;
    pause();                        //this will pasue the program for the user
    cout << "First Name" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[0] = choice;
    cout << "Last Name" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[1] = choice;
    cout << "Middle Name" << endl;
    cin >>choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[2] = choice;
    cout << "Company Name" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[3] = choice;
    cout << "Email" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[4] = choice;
    cout << "City" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[5] = choice;
    cout << "State" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[6] = choice;
    cout << "Country" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[7] = choice;
    cout << "Zip Code" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[8] = choice;
    cout << "HomePhone" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[9] = choice;
    cout << "Mobile Phone" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[10] = choice;
    cout << "Office Phone" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[11] = choice;
    cout << "ID" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[12] = choice;
    cout << "Address" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[13] = choice;
    cout << "Affiliates" << endl;
    cin >> choice;
    while(cin.fail()||(choice != 0 && choice != 1)){
        cout << "Error number was not inputted make sure input a number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter new value" << endl;
        cin >> choice;
    }
    pInt[14] = choice;

}
