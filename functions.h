//
// Created by Brian on 5/12/2016.
//

#ifndef ADDRESSBOOKCLEANERVERSION_FUNCTIONS_H
#define ADDRESSBOOKCLEANERVERSION_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include "avltree.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
using namespace std;

//function reads in a file and fills the tree
void readFile(AVLClass&,std::vector<Affiliates>&);
//just used to pause the program
void pause();
//main menu choice menu
int mainMenu();
//function will sort the tree alphabetically or in order from the chooosen field
void sort();
//function will call update book which has update entry,delete,add on there
void updateBook(AVLClass&,std::vector<Affiliates>&);
void update(AVLClass&);
void deleteBook(AVLClass&,std::vector<Affiliates>&);
void add(AVLClass&);
//function that will search for a entry in the tree
void search(AVLClass&);
//vector of affiliate printed
void printAffilVec(std::vector<Affiliates>&);
void denomChange(int []);                                                                           //this funciton will recieve a array created in the print function that will hold denominations




#endif //ADDRESSBOOKCLEANERVERSION_FUNCTIONS_H
