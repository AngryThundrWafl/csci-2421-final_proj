//
// Created by Brian on 5/12/2016.
//

#ifndef ADDRESSBOOKCLEANERVERSION_CONTACT_H
#define ADDRESSBOOKCLEANERVERSION_CONTACT_H

#include <iostream>
#include <vector>
#include "contact.h"
using std::cout;
using std::endl;

//###############################################################################################################//
//a structure called affiliates that will hold the afffiliates of the addressbook there are multiple to a contact//
struct Affiliates{
    int keyId;
    std::string FName,LName,Phone,Email;                        //members of the affiliate structure
};
//###############################################################################################################//
// CLASS DECLARATION CALLED CONTACT ADREESSBOOK WILL HAVE MULTIPLE ENTRIES IN THE TREE                           //
class Contact{
private:
    int __Id, __vecIndexDelete;                                                   //holds the Id of the contact main way the tree balances by
    std::string __FNAme,__MName,__LName,__CName,__HomePhone,__MobilePhone,__Email,__OfficePhone,__address,__city,__state,__Zip,__country;
    std::vector<Affiliates> __affil;
public:
    //############################################################################################################//
    //DEFAULT CONSTRUCTOR, CONSTRUCTOR, DESTRUCTOR                                                                //
    Contact();                                                  //default constructor
    Contact(int,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string); //constructor
    ~Contact() {}                                               //desctructor for Contact class
    //############################################################################################################//
    // SETTERS FOR THE CONTACT CLASS                                                                              //
    void setId(int);
    void setFName(std::string);                                 //sets First name
    void setLNAme(std::string);                                 //sets the lastname
    void setMName(std::string);                                 //sets the middle name
    void setCName(std::string);                                 //sets the company name
    void setHome(std::string);                                  //sets the __homePhone
    void setMob(std::string);                                   //sets the __mobPhone
    void setEmail(std::string);                                 //sets the email
    void setOffice(std::string);                                //sets the __officePhone
    void setAd(std::string);                                    //sets the address
    void setCity(std::string);                                  //sets the city
    void setState(std::string);                                 //sets state
    void setZip(std::string);                                   //sets the __zip
    void setCountry(std::string);                               //sets the country
    void setAfill(Affiliates&);
    void setvecIndexDelete(int);
    //############################################################################################################//
    // GETTERS FOR THE CONTACT CLASS RETURNS THE RESPECTIVE VARIABLE                                              //
    int getId()const{return __Id;}                              //gets Id
    std::string getHome()const{return __HomePhone;}             //get home phone number
    std::string getOffice()const{return __OfficePhone;}         //gets Office Number
    std::string getMob()const{return __MobilePhone;}            //gets Mobile number
    std::string getZip()const{return __Zip;}                    //gets Zip code
    std::string getFName()const{return __FNAme;}                //gets first name
    std::string getLName()const{return __LName;}                //gets last name
    std::string getMName()const{return __MName;}                //gets Middle name
    std::string getCName()const{return __CName;}                //gets company name
    std::string getEmail()const{return __Email;}                //gets email
    std::string getAd()const{return __address;}                 //gets Address
    std::string getCity()const{return __city;}                  //gets City
    std::string getState()const{ return  __state;}              //gets state
    std::string getCountry()const{return __country;}            //gets country
    //############################################################################################################//
    //OPERATOR OVERLOADS SO THAT THE BSTREE.CPP AND AVLTREE CAN ACCEPT MY CONTACT CLASS IN ITEMTYPE
    friend  bool operator<(const Contact&,const Contact&);      //will check if the id is less than the other
    friend  bool operator>(const Contact&, const Contact&);     //checks if the id is greater than the other
    friend bool operator==(const Contact&, const Contact&);     //checks if the ID is the same
    Contact operator = (const Contact&);
    //############################################################################################################//
    void printContact();
    void printSorted(int);
    //############################################################################################################//
    void printAffil();
    void delAffil();
    bool searchAffil(std::string);
    void getAffil(std::vector<Affiliates>&);
    void writeBook(std::ofstream&,int[],std::vector<Affiliates>&);
};
//###############################################################################################################//
#endif //ADDRESSBOOKCLEANERVERSION_CONTACT_H
