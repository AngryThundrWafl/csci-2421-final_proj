/* Filename:  bstree.h

Programmer:  Br. David Carlson

Date:  October 10, 1997

Modified:  August 8, 1998.

Modified:  June 9, 1999 to make AVLClass a friend of BSTClass.

This is the header file to accompany bstree.cpp.  It provides the
BSTClass as shown below.
*/

#ifndef BSTREE_H
#define BSTREE_H

#include "bstnode.h"


class BSTClass
{
private:
	BSTNodePtr GetNode(const ItemType & Item,
		BSTNodePtr LeftPtr = NULL, BSTNodePtr RightPtr = NULL);
	void FreeNode(BSTNodePtr NodePtr);
	void ClearTree(void);
	void ClearSubtree(BSTNodePtr Current);
	BSTNodePtr SubtreeFind(BSTNodePtr Current,
		const ItemType & Item) const;
	////////////////////////
	std::vector<Contact> __results;		//The search results will be held in a vector
	BSTNodePtr SubtreeSearch(BSTNodePtr Current,
						   const ItemType & Item, int) const;
	BSTNodePtr SubtreeModify(BSTNodePtr Current,
							 const ItemType & Item) const;
	BSTNodePtr SubtreeLeftDel(BSTNodePtr Current,
							 string) const;
	void writeSubtree(BSTNodePtr NodePtr, int Level, std::ofstream&, int[], std::vector<Affiliates>&) const;        //this fucntion derives off print and is used to write out the tree to a output file

	void PrintAffilSubtree(BSTNodePtr NodePtr, int Level,std::vector<Affiliates>&) const;
	/////////////////////////
	void PrintSubtree(BSTNodePtr NodePtr, int Level) const;
	// The following data fields could be made protected instead of
	// private.  This would make them accessible to the derived AVLClass
	// without making AVLClass a friend of BSTClass.
	BSTNodePtr Root;
	int Count;
public:
	BSTClass(void);
	~BSTClass(void);
	int NumItems(void) const;
	bool Empty(void) const;
	void Insert(const ItemType & Item);
	//  Some sort of Remove method could also be added, but
	//  it would require effort to remake the binary search tree
	//  after the deletion of a node.
	BSTNodePtr Find(const ItemType & Item) const;
	void Print(void) const;
	friend class AVLClass;
	///////////////////////////////////////////////////////////////////////
	void setSearchResults(Contact&)const;
	void PrintAffil(std::vector<Affiliates>&) const;
	void Sort(const ItemType & Item,int);
	void PrintSorted(int) const;
	void PrintSortedSubtree(BSTNodePtr NodePtr, int Level, int) const;
	BSTNodePtr Search(const ItemType & Item, int) const;
	BSTNodePtr Modify(const ItemType & Item) const;
	BSTNodePtr LeftDel(string) const;
	void Write(std::vector<Affiliates>&) const;         //derives of the print function but insrtead writes to the file
};

#endif