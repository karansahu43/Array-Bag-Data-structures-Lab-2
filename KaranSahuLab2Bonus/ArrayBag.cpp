//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>
#include <algorithm> 
using namespace std;

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector


template<class ItemType>
void ArrayBag<ItemType>::Sort()
{
	sort(items, items + itemCount);
}  // end clear

template<class ItemType>
void ArrayBag<ItemType>::removedup()

{
	    ArrayBag<ItemType> temp; 
		int counter = itemCount; 
 
    // Start traversing elements
    int j = 0;
    for (int i=0; i<itemCount-1; i++)
 
        // If current element is not equal
        // to next element then store that
        // current element
        if (items[i] != items[i+1])
            temp.items[j++] = items[i];
 
    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously
    temp.items[j++] = items[itemCount-1];
 
    // Modify original array
    for (int i=0; i<j; i++)
        items[i] = temp.items[i];
    

    for (int i = counter; i > j - 1; i--)
    {
    	remove(items[i]);

    
	}

}
  // end clear
  

template<class ItemType>
void ArrayBag<ItemType>::display()
{
    cout << "The bag contains " << getCurrentSize()
        << " items:" << endl;
    
    for (int i = 0; i < getCurrentSize(); i++)
    {
    	cout << items[i]<< " ";
	}
	cout << endl << endl;
}

// Bag Union non extra credit 
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>:: bagUnion(const ArrayBag<ItemType>& aBag) const
{
	ArrayBag<ItemType> result;    // creat an empty bag
	int numItems;
	//add the contents of the bag that was called to the result
	numItems =getCurrentSize ();
	for(int i = 0; i < numItems ; i++)
	{
		result.add(items[i]);
	}
	
	//add the contents of the second bag that was called to the result
	numItems = aBag.getCurrentSize ();
	for(int i = 0; i < numItems ; i++)
	{
		result.add(aBag.items[i]);
	}
	

	result.Sort();
	result.removedup();
	return result;
	
}

// Bag Intersection Not complete

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>:: bagIntersection(const ArrayBag<ItemType>& aBag) const
{
	ArrayBag<ItemType> result;    // creat an empty bag
	int numItems, numItems2;
	
	
	numItems =getCurrentSize ();
	numItems2 = aBag.getCurrentSize ();
	
	for(int i = 0; i < numItems ; i++)
	{
		for(int j = 0; j < numItems2 ; j++)
		{
			if(items[i] == aBag.items[j])
			{
				result.add(aBag.items[j]);
			}
				
		}
	}
	
	result.Sort();
	result.removedup();

		
	return result;
	
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>:: bagDifference(const ArrayBag<ItemType>& aBag) const
{
	ArrayBag<ItemType> result;    // creat an empty bag
	int numItems, numItems2;
	
	
	numItems =getCurrentSize ();
	numItems2 = aBag.getCurrentSize ();
	
	for(int i = 0; i < numItems ; i++)
	{
		result.add(items[i]);
	}
	for(int i = 0; i < numItems ; i++)
	{
		for(int j = 0; j < numItems2 ; j++)
		{
			if(result.items[i] == aBag.items[j])
			{
				result.remove(items[i]);
			}
				
		}
	}

	result.Sort();


		
	return result;
	
}






// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
