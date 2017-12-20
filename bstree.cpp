/* Filename:  BSTree.cpp

Programmer:  Br. David Carlson

Date:  October 10, 1997

Modified:  August 8, 1998.

Modified:  June 9, 1999 so that ClearTree only tries to do any work
if the root pointer is non-null.

This file implements the functions for the BSTClass as set up in
the header file bstree.h.
*/

#include <iostream>
#include "bstree.h"
#include "functions.h"


/* Given:  Nothing,
Task:   This is the constructor to initialize a binary search tree as empty.
Return: Nothing directly, but it creates the implicit BSTClass object.
*/
BSTClass::BSTClass(void)
{
	Root = NULL;
	Count = 0;
}


/* Given:  Nothing (other than the implicit BSTClass object).
Task:   This is the destructor.  It's job is to wipe out all data
storage used by this binary search tree.
Return: Nothing directly, but the implicit BSTClass object is destroyed.
*/
BSTClass::~BSTClass(void)
{
	ClearTree();
}


/* Given:  Nothing (other than the implicit BSTClass object).
Task:   To clear out all nodes of the implicit binary search tree.
Return: Nothing directly, but the implicit BSTClass object is modified
to be an empty binary search tree.
*/
void BSTClass::ClearTree(void)
{
	if (Root != NULL)
	{
		ClearSubtree(Root);
		Root = NULL;
		Count = 0;
	}
}


/* Given:  Current   A pointer to a node in the implicit BSTClass object.
Task:   To wipe out all nodes of this subtree.
Return: Nothing directly, but the implicit BSTClass object is modified.
*/
void BSTClass::ClearSubtree(BSTNodePtr Current)
{
	//  Use a postorder traversal:
	if (Current != NULL)
	{
		ClearSubtree(Current->Left);
		ClearSubtree(Current->Right);
		FreeNode(Current);
	}
}


/* Given:  Item      A data item to place into a new node.
LeftPtr   The pointer to place in the left field of the node.
RightPtr  The pointer to place in the right field of the node.
Task:   To create a new node containing the above 3 items.
Return: A pointer to the new node.
*/
BSTNodePtr BSTClass::GetNode(const ItemType & Item,
	BSTNodePtr LeftPtr, BSTNodePtr RightPtr)
{
	BSTNodePtr NodePtr;

	NodePtr = new BSTNodeClass(Item, LeftPtr, RightPtr);
	if (NodePtr == NULL)
	{
		cerr << "Memory allocation error!" << endl;
		exit(1);
	}
	return NodePtr;
}


/* Given:  NodePtr   A pointer to a node of the implicit binary search tree.
Task:   To reclaim the space used by this node.
Return: Nothing directly, but the implicit object is modified.
*/
void BSTClass::FreeNode(BSTNodePtr NodePtr)
{
	delete NodePtr;
}


/* Given:  Nothing (other than the implicit BSTClass object).
Task:   To look up the number of items in this object.
Return: This number of items in the function name.
*/
int BSTClass::NumItems(void) const
{
	return Count;
}


/* Given:  Nothing (other than the implicit BSTClass object).
Task:   To check if this object (binary search tree) is empty.
Return: true if empty; false otherwise.
*/
bool BSTClass::Empty(void) const
{
	if (Count > 0)
		return false;
	else
		return true;
}


/* Given:  Item   A data item to be inserted.
Task:   To insert a new node containing Item into the implicit binary
search tree so that it remains a binary search tree.
Return: Nothing directly, but the implicit binary search tree is modified.
*/
void BSTClass::Insert(const ItemType & Item)
{
	BSTNodePtr Current, Parent, NewNodePtr;

	Current = Root;
	Parent = NULL;
	while (Current != NULL)
	{
		Parent = Current;
		if (Item < Current->Info)
			Current = Current->Left;
		else
			Current = Current->Right;
	}

	NewNodePtr = GetNode(Item, NULL, NULL);
	if (Parent == NULL)
		Root = NewNodePtr;
	else if (Item < Parent->Info)
		Parent->Left = NewNodePtr;
	else
		Parent->Right = NewNodePtr;

	Count++;
}


/* Given:  Item    A data item to look for.
Task:   To search for Item in the implicit binary search tree.
Return: A pointer to the node where Item was found or a NULL pointer
if it was not found.
*/
BSTNodePtr BSTClass::Find(const ItemType & Item) const
{
	return SubtreeFind(Root, Item);
}


/* Given:  Current  A pointer to a node in the implicit binary search tree.
Item     A data item to look for.
Task:   To search for Item in the subtree rooted at the node Current
points to.
Return: A pointer to the node where Item was found or a NULL pointer
if it was not found.
*/
BSTNodePtr BSTClass::SubtreeFind(BSTNodePtr Current,
	const ItemType & Item) const
{
	if (Current == NULL)
		return NULL;
	else if (Item == Current->Info)
		return Current;
	else if (Item < Current->Info)
		return SubtreeFind(Current->Left, Item);
	else
		return SubtreeFind(Current->Right, Item);
}


/* Given:  NodePtr   A pointer to the root of the subtree to be printed.
Level     Integer indentation level to be used.
Task:   To print (sideways) the subtree to which NodePtr points, using
an indentation proportional to Level.
Return: Nothing.
*/
void BSTClass::PrintSubtree(BSTNodePtr NodePtr, int Level) const
{
	int k;

	if (NodePtr != NULL)
	{
		PrintSubtree(NodePtr->Right, Level + 1);
		for (k = 0; k < 3 * Level; k++)
			cout << " ";
		//cout << NodePtr->Info << endl;
			 NodePtr->Info.printContact();				//changed this in the .cpp file so that it can prinout a whole contact
		PrintSubtree(NodePtr->Left, Level + 1);
	}
}


/* Given:  Nothing (other than the implicit object).
Task:   To print (sideways) the implicit binary search tree.
Return: Nothing.
*/
void BSTClass::Print(void) const
{
	PrintSubtree(Root, 0);
}

void BSTClass::Sort(const ItemType &Item, int choice) {
	BSTNodePtr Current, Parent, NewNodePtr;

	if(choice == 1){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getFName() > Current->Info.getFName())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getFName() > Parent->Info.getFName())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice ==2){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getMName() > Current->Info.getMName())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getMName() > Parent->Info.getMName())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 3){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getLName() > Current->Info.getLName())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getLName() > Parent->Info.getLName())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 4){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getCName() > Current->Info.getCName())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getCName() > Parent->Info.getCName())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice ==5){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getHome() > Current->Info.getHome())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getHome() > Parent->Info.getHome())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 6){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getMob() > Current->Info.getMob())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getMob() > Parent->Info.getMob())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 7){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getEmail() > Current->Info.getEmail())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getEmail() > Parent->Info.getEmail())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 8){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getOffice() > Current->Info.getOffice())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getOffice() > Parent->Info.getOffice())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 9){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getAd() > Current->Info.getAd())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getAd() > Parent->Info.getAd())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 10){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getCity() > Current->Info.getCity())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getCity() > Parent->Info.getCity())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 11){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getState() > Current->Info.getState())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getState() > Parent->Info.getState())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 12){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getZip() > Current->Info.getZip())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getZip() > Parent->Info.getZip())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}
	if(choice == 13){
		Current = Root;
		Parent = NULL;
		while (Current != NULL)
		{
			Parent = Current;
			if (Item.getCountry() > Current->Info.getCountry())
				Current = Current->Left;
			else
				Current = Current->Right;
		}

		NewNodePtr = GetNode(Item, NULL, NULL);
		if (Parent == NULL)
			Root = NewNodePtr;
		else if (Item.getCountry() > Parent->Info.getCountry())
			Parent->Left = NewNodePtr;
		else
			Parent->Right = NewNodePtr;

		Count++;
	}

}

void BSTClass::PrintSorted(int choice) const {
	PrintSortedSubtree(Root, 0, choice);
}

void BSTClass::PrintSortedSubtree(BSTNodePtr NodePtr, int Level, int choice) const {
	int k;

	if (NodePtr != NULL)
	{
		PrintSortedSubtree(NodePtr->Right, Level + 1,choice);
		for (k = 0; k < 3 * Level; k++)
			cout << " ";
		//cout << NodePtr->Info << endl;
		NodePtr->Info.printSorted(choice);				//changed this in the .cpp file so that it can prinout a whole contact
		PrintSortedSubtree(NodePtr->Left, Level + 1,choice);
	}
}

BSTNodePtr BSTClass::Search(const ItemType &Item, int choice) const {
	return SubtreeSearch(Root, Item, choice);
}

BSTNodePtr BSTClass::SubtreeSearch(BSTNodePtr Current,
								 const ItemType & Item, int choice) const{
	Contact tempCon;
	if(choice == 1) {
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getFName().compare(Current->Info.getFName()) > 0 || Item.getFName().compare(Current->Info.getFName()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getFName().compare(Current->Info.getFName())== 0) {

			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 2){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getMName().compare(Current->Info.getMName()) > 0 || Item.getMName().compare(Current->Info.getMName()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getMName().compare(Current->Info.getMName()) == 0)
		{

			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice ==3){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		if(Item.getLName().compare(Current->Info.getLName())> 0 || Item.getLName().compare(Current->Info.getLName()) < 0){
			tempCon = Current->Info;
			setSearchResults(tempCon);
		}
		if (Item.getLName().compare(Current->Info.getLName())==0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 4){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getCName().compare(Current->Info.getCName()) > 0 || Item.getCName().compare(Current->Info.getCName()) <0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getCName().compare(Current->Info.getCName()) == 0){

			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 5){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getHome().compare(Current->Info.getHome())> 0 || Item.getHome().compare(Current->Info.getHome())< 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getHome().compare(Current->Info.getHome())==0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 6){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getMob().compare(Current->Info.getMob()) > 0 || Item.getMob().compare(Current->Info.getMob()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getMob().compare(Current->Info.getMob()) == 0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice ==7){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getEmail().compare(Current->Info.getEmail()) > 0 || Item.getEmail().compare(Current->Info.getEmail()) <0 ){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getEmail().compare(Current->Info.getEmail()) == 0)
		{

			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice ==8){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getOffice().compare(Current->Info.getOffice()) > 0 || Item.getOffice().compare(Current->Info.getOffice()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getOffice().compare(Current->Info.getOffice()) == 0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice ==9){
		if (Current == NULL)
			cout << "Could not find in the book" << endl;
		//if(Item.getAd().compare(Current->Info.getAd()) > 0 || Item.getAd().compare(Current->Info.getAd()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getAd().compare(Current->Info.getAd()) == 0)
		{

			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 10){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getCity().compare(Current->Info.getCity()) > 0 || Item.getCity().compare(Current->Info.getCity()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getCity().compare(Current->Info.getCity()) == 0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 11){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getState().compare(Current->Info.getState()) > 0 || Item.getState().compare(Current->Info.getState()) < 0){
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getState().compare(Current->Info.getState()) == 0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}
	if(choice == 12){
		if (Current == NULL) {
			cout << "Could not find in the book" << endl;
			//if(!__results.empty()) {
			//	cout << "Here are similair Results" << endl;
			//	for(int i =0; i < __results.size();i++)
			//		__results[i].printContact();
			//}

		}
		//if(Item.getCountry().compare(Current->Info.getCountry()) > 0 || Item.getCountry().compare(Current->Info.getCountry()) < 0)
		//{
		//	tempCon = Current->Info;
		//	setSearchResults(tempCon);
		//}
		if (Item.getCountry().compare(Current->Info.getCountry()) == 0)
		{
			cout << "found the contact!" << endl;
			Current->Info.printContact();
		}
		if (Current->Left != NULL)
			return SubtreeSearch(Current->Left, Item, choice);
		if (Current->Right!= NULL)
			return SubtreeSearch(Current->Right, Item, choice);
	}

}

BSTNodePtr BSTClass::SubtreeModify(BSTNodePtr Current, const ItemType &Item) const {
	int choice;
	string field;
	if (Current == NULL)
		cout << "could not find the contact" << endl;
	if (Item.getId() == Current->Info.getId()){
		cout << "Contact found" << endl;

		do {
			Current->Info.printContact();
			cout << "What would you like to modify?" << endl;
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
			cout << "15:Exit" << endl;
			cin >> choice;
			if(choice == 15)
				return NULL;
				while(cin.fail()){
				cout << "Error number was not inputted make sure input a number" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Enter new value" << endl;
				cin >> choice;
			}
			cin.ignore();
			if(choice != 15)
				cout << "Enter the new field" << endl;
				getline(cin, field);

			if (choice == 1)
				Current->Info.setFName(field);
			if (choice == 2)
				Current->Info.setMName(field);
			if (choice == 3)
				Current->Info.setLNAme(field);
			if (choice == 4)
				Current->Info.setCName(field);
			if (choice == 5)
				Current->Info.setHome(field);
			if (choice == 6)
				Current->Info.setMob(field);
			if (choice == 7)
				Current->Info.setEmail(field);
			if (choice == 8)
				Current->Info.setOffice(field);
			if (choice == 9)
				Current->Info.setAd(field);
			if (choice == 10)
				Current->Info.setCity(field);
			if (choice == 11)
				Current->Info.setState(field);
			if (choice == 12)
				Current->Info.setZip(field);
			if (choice == 13)
				Current->Info.setCountry(field);
		}while(choice != 15);
			cout << "returning to previous menu" << endl;

	}
	if (Item < Current->Info)
		return SubtreeModify(Current->Left, Item);
	else
		return SubtreeModify(Current->Right, Item);
}


BSTNodePtr BSTClass::Modify(const ItemType &Item) const {
	return SubtreeModify(Root, Item);
}

BSTNodePtr BSTClass::LeftDel(std::string Item) const {
	return SubtreeLeftDel(Root,Item);
}

BSTNodePtr BSTClass::SubtreeLeftDel(BSTNodePtr Current, std::string Item) const {

	if (Current == NULL)
		return NULL;
	if (Current->Info.searchAffil(Item) == true)
			Current->Info.delAffil();
	if (Current!= NULL)
		return SubtreeLeftDel(Current->Left, Item);
	if ( Current != NULL)
		return SubtreeLeftDel(Current->Right, Item);
}

void BSTClass::PrintAffil(std::vector<Affiliates>&affil) const {
	PrintAffilSubtree(Root, 0,affil);
}

void BSTClass::PrintAffilSubtree(BSTNodePtr NodePtr, int Level, std::vector<Affiliates>& affil) const {
	int k;

	if (NodePtr != NULL)
	{
		PrintAffilSubtree(NodePtr->Right, Level + 1, affil);
		for (k = 0; k < 3 * Level; k++)
			cout << " ";
		//cout << NodePtr->Info << endl;
		NodePtr->Info.printAffil();				//changed this in the .cpp file so that it can prinout a whole contact
		NodePtr->Info.getAffil(affil);
		PrintAffilSubtree(NodePtr->Left, Level + 1,affil);
	}
}

void BSTClass::setSearchResults( Contact &contact1) const {
	//__results.push_back(contact1);
}

void BSTClass::Write(vector<Affiliates> &affil) const {
	cout << "Would you like to save your data to a new file or current file? 0 = current || 1 = new" << endl;
	int choice;
	cin >> choice;
	while (cin.fail()) {
		cout << "Error number was not inputted make sure input a number" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter new value" << endl;
		cin >> choice;
	}
	if (choice == 1) {
		ofstream file;
		file.open("output.txt");
		if (file.fail())
			cout << "Could not open file" << endl;
		int denomination[15];       //creates an array of 15 members for each field
		denomChange(denomination);  //pass the array through to the function

		writeSubtree(Root, 0, file, denomination, affil);
		file.close();
	}
	if (choice == 0) {
		ofstream file;
		file.open("input.txt");
		if (file.fail())
			cout << "Could not open file" << endl;
		int denomination[15];       //creates an array of 15 members for each field
		denomChange(denomination);  //pass the array through to the function

		writeSubtree(Root, 0, file, denomination, affil);
		file.close();
	}
}

void BSTClass::writeSubtree(BSTNodePtr NodePtr, int Level, ofstream &os, int *denomination,
								vector<Affiliates> &affil) const {

	int k;

	if (NodePtr != NULL)
	{
		writeSubtree(NodePtr->Right, Level + 1, os, denomination, affil);
		for (k = 0; k < 3 * Level; k++)
			cout << " ";
		NodePtr->Info.writeBook(os,denomination,affil);                      //modified bstree to print the tree
		writeSubtree(NodePtr->Left, Level + 1, os, denomination, affil);
	}

	}
