/* Filename:  itemtype.h

Programmer:  Br. David Carlson

Date:  October 10, 1997

Modified:  June 26, 2000 to use modern headers.

This header file defines ItemType for use in bstnode.h.  It also
should be set up to define DEBUG if you want debugging output
statements to be compiled.
*/

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

using namespace std;

#include "contact.h"    //so that the it can read in my contact class from the header file

// Comment off the following line to omit debugging output statements:
//#define DEBUG

// Customize the following as needed:
typedef Contact ItemType;   //changed the item type to my contact class so that the tree can accept my class

#endif