//
// Created by Brian on 5/12/2016.
//
#include "contact.h"
#include <fstream>

//###############################################################################################################//
// CONTACT CLASS DEFAULT CONSTRUCTOR
Contact::Contact() {
    __Id = 0;                           //initilizes all values to a default type
    __vecIndexDelete = 0;
    __FNAme = "";
    __MName = "";
    __LName = "";
    __CName = "";
    __HomePhone = "";
    __MobilePhone = "";
    __Email = "";
    __OfficePhone = "";
    __address = "";
    __city = "";
    __state = "";
    __Zip = "";
    __country = "";
}
//###############################################################################################################//
//Contact Class Constructor
Contact::Contact(int id, std::string firtName, std::string middleName, std::string lastName, std::string companyName,
                 std::string homePhone, std::string mobilePhone, std::string email, std::string officePhone,
                 std::string address, std::string city, std::string state, std::string zipCode,
                 std::string country) {
    __Id = id;                          //initializes all the values that are put in
    __FNAme = firtName;
    __MName = middleName;
    __LName = lastName;
    __CName = companyName;
    __HomePhone = homePhone;
    __MobilePhone = mobilePhone;
    __Email = email;
    __OfficePhone = officePhone;
    __address = address;
    __city = city;
    __state = state;
    __Zip =  zipCode;
    __country = country;
}
//###############################################################################################################//
//SETTERS FOR THE CONTACT CLASS
void Contact::setId(int id) {
    __Id = id;
}

void Contact::setFName(std::string firstName) {
        __FNAme = firstName;
}

void Contact::setLNAme(std::string lastName) {
    __LName = lastName;

}

void Contact::setMName(std::string middleName) {
    __MName = middleName;
}

void Contact::setCName(std::string companyName) {
    __CName = companyName;
}

void Contact::setHome(std::string homePhone) {
    __HomePhone = homePhone;
}

void Contact::setMob(std::string mobile) {
    __MobilePhone = mobile;
}

void Contact::setEmail(std::string email) {
    __Email = email;
}

void Contact::setOffice(std::string office) {
    __OfficePhone = office;
}

void Contact::setAd(std::string ad) {
    __address = ad;
}

void Contact::setCity(std::string city) {
    __city = city;
}

void Contact::setState(std::string state) {
    __state = state;
}

void Contact::setZip(std::string zip) {
    __Zip = zip;
}

void Contact::setCountry(std::string country) {
    __country = country;
}
//###############################################################################################################//
// OVERLOADED OPERATORS FOR THE CONTACT CLASS SO THAT THE AVL TREE CAN BALANCE ITSELF
bool operator<(const Contact &contact1, const Contact &contact2) {
    if(contact1.getId() < contact2.getId()){            //compares the contact ID
        if(contact1.getId() == contact2.getId()){       //if the id are equal it will make a deeper comparison
            return(contact1.getFName() < contact2.getFName());
        }
        return true;
    }
    else
        return false;                                    // if it is not less than

}

bool operator>(const Contact &contact1, const Contact &contact2) {
    return (!(contact1 < contact2));                    //not the same as the other function opposite
}

bool operator==(const Contact &contact1, const Contact &contact2) {
    if(contact1.getId() == contact2.getId()){
        return(contact1.getFName() == contact2.getFName());
    }
}
//###############################################################################################################//
//FUNCTION WILL PRINT OUT A WHOLE CONTACT WILL BE CALLED MANLY IN PRINT TREE IN THE BSTREE
void Contact::printContact() {
    cout << endl;
    cout << "ID#: " << __Id << endl;
    cout << "First Name: " << __FNAme << endl;
    cout << "Middle Name: " <<  __MName << endl;
    cout << "Last Name: " <<  __LName << endl;
    cout << "Company Name: " << __CName << endl;
    cout << "Home Phone: " << __HomePhone << endl;
    cout << "Mobile Phone: " << __MobilePhone << endl;
    cout << "Email: " << __Email << endl;
    cout << "Office Phone: " << __OfficePhone << endl;
    cout << "Address: " <<__address << endl;
    cout << "City: " <<__city << endl;
    cout << "State: " << __state << endl;
    cout << "Zip Code: " <<__Zip << endl;
    cout << "Country: " << __country << endl;
    for(int i = 0; i < __affil.size();i++){
        cout << "Affiliate: " << i +1 << endl;
        cout << "First Name: " << __affil[i].FName << endl;
        cout << "Last Name: " << __affil[i].LName << endl;
        cout << "Phone Number: " << __affil[i].Phone << endl;
        cout << "Email: " << __affil[i].Email << endl;
    }
    cout << endl;
}
//###############################################################################################################//
void Contact::setAfill(Affiliates& affil) {
    __affil.push_back(affil);
}

void Contact::printSorted(int choice) {
    if(choice == 1)
        cout << __FNAme << endl;

    if(choice == 2)
        cout << __MName << endl;

    if(choice ==3)
        cout << __LName << endl;

    if(choice == 4)
        cout << __CName << endl;

    if(choice ==5)
        cout << __HomePhone << endl;

    if(choice == 5)
        cout << __MobilePhone << endl;

    if(choice == 6)
        cout << __Email << endl;

    if(choice == 7)
        cout << __OfficePhone << endl;

    if(choice == 8)
        cout << __address << endl;

    if(choice == 9)
        cout << __city << endl;

    if(choice == 10)
        cout << __state << endl;

    if(choice == 11)
        cout << __Zip << endl;

    if(choice == 12)
        cout << __country << endl;

}

void Contact::delAffil() {
    std::vector<Affiliates> tempVec;
    Affiliates tempAffil;
    for(int i =0; i <__affil.size();i++){
        if( i == __vecIndexDelete){
            i++;
        }
        tempAffil.FName = __affil[i].FName;
        tempAffil.LName = __affil[i].LName;
        tempAffil.Email = __affil[i].Email;
        tempAffil.Phone = __affil[i].Phone;
        tempVec.push_back(tempAffil);
    }
    __affil.clear();
    for(int i = 0; i < tempVec.size();i++){
        __affil[i].FName = tempAffil.FName;
        __affil[i].LName = tempAffil.LName;
        __affil[i].Email = tempAffil.Email;
        __affil[i].Phone = tempAffil.Phone;
    }


}

bool Contact::searchAffil(std::string field) {
    //for(int i = 0; i < __affil.size();i++){
    //    if(field.compare(__affil[i].FName) == 0 || field.compare(__affil[i].LName) == 0 || field.compare(__affil[i].Email) == 0 || field.compare(__affil[i])== 0){
    //        setvecIndexDelete(i);
    //        return true;
    //    }
    //}
    //return false;
}

void Contact::printAffil() {
    for(int i = 0; i < __affil.size(); i++){
        cout << "First Name: " << __affil[i].FName << endl;
        cout << "Last Name: " << __affil[i].LName<< endl;
        cout << "Phone: " << __affil[i].Phone<< endl;
        cout << "Email: " << __affil[i].Email << endl;
        cout << endl;
    }
}

void Contact::setvecIndexDelete(int index) {
    __vecIndexDelete = index;
}

Contact Contact::operator=(const Contact &contact) {
    __Id = contact.getId();
    __FNAme =  contact.getFName();
    __MName = contact.getMName();
    __LName = contact.getLName();
    __CName = contact.getCName();
    __HomePhone = contact.getHome();
    __MobilePhone = contact.getMob();
    __Email = contact.getEmail();
    __OfficePhone = contact.getOffice();
    __address = contact.getAd();
    __city = contact.getCity();
    __state = contact.getState();
    __Zip = contact.getZip();
    __country =  contact.getCountry();
    for(int i = 0; i < contact.__affil.size();i++){
        __affil.push_back(contact.__affil[i]);
    }
}

void Contact::getAffil(std::vector<Affiliates> &vector) {
    Affiliates temp;
    for(int i =0; i < __affil.size();i++) {
        temp.FName = __affil[i].FName;
        temp.LName = __affil[i].LName;
        temp.Phone = __affil[i].Phone;
        temp.Email = __affil[i].Email;
        vector.push_back(temp);
    }
}

void Contact::writeBook(std::ofstream & os, int *denomination, std::vector<Affiliates>& affil) {
    //IF THE DEBNOMINATIONS == 0 WE WILL PRINTOUT THE FIELDS IF NOT NOTHING IS DONE
    std::string string1;
    if(denomination[12] == 0) {

        os << __Id << endl;
    }

    if (denomination[0] == 0)
        os << __FNAme << endl;

    if (denomination[2] == 0)
        os << __MName << endl;

    if (denomination[1] == 0)
        os << __LName << endl;

    if (denomination[3] == 0)
        os << __CName << endl;

    if (denomination[9] == 0)
        os << __HomePhone << endl;

    if (denomination[10] == 0)
        os << __MobilePhone << endl;

    if (denomination[4] == 0)
        os << __Email << endl;


    if (denomination[11] == 0)
        os << __OfficePhone << endl;


    if(denomination[13] == 0)

        os << __address << endl;

    if (denomination[5] == 0)
        os << __city << endl;

    if (denomination[6] == 0)
        os << __state << endl;


    if (denomination[8] == 0)
        os << __Zip << endl;

    if (denomination[7] == 0)
        os << __country << endl;
    //###############################################################################################################//
//THIS WILL BE A LOOP TO GO THROUGH THE VECTOR THE KEYid IS USED TO COMPARE THE SBJET ID AND THE AFFILIATE ID AND THEN PRINTS THEM OUT IF THEY ARE THE SAME
    if(denomination[14] == 0){
        for(int i = 0; i < affil.size();i++){
            if(__Id == affil[i].keyId){
                os << affil[i].FName << "," << affil[i].LName << "," << affil[i].Phone << "," << affil[i].Email << endl;
            }
        }
    }
    os << "|" << endl;//IS USED TO SPLIT SEPERATE ENTRIES
}

