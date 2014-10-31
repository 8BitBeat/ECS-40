//Christopher Chan
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template< typename NODETYPE >
class LinkedList
{
 public:
  LinkedList(); // constructor
  ~LinkedList(); // destructor

  void insertAtFront( const NODETYPE & );
  void insertAtBack( const NODETYPE & );
  bool removeFromFront( NODETYPE & );
  bool removeFromBack( NODETYPE & );
  bool isEmpty() const;
  void print() const;

  /////////////////////////////////////////////////////////
  // new member functions for HW 5

  // overload array access operator
  NODETYPE &operator[](int index) const;//DONE

  // Find the MAXIMAL SUM of values among all consecutive sub-lists
  // of the linked list, assuming +, <, == are overloaded for NODETYPE
  NODETYPE maxSubSum() const;//DONE

  // Sort the linked list in ascending order,
  // assuming NODETYPE supports <, ==, etc.
  void sort();//DONE

  // In-place reversal of the linked list, i.e., don't create a new list
  // to perform the reversal, and use the list itself
  void reverse();//DONE

  // Check whether the current list and the input l2 share any nodes or not
  bool shared(const LinkedList< NODETYPE > &l2);//DONE

  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &));

  // Keep only those nodes n where predicate(n) = true
  void filter(bool predicate(const NODETYPE &));

  // Remove all duplicates from the list
  void removeDup();//DONE

  //
  /////////////////////////////////////////////////////////

 private:
  ListNode< NODETYPE > *firstPtr;   // pointer to first node
  ListNode< NODETYPE > *lastPtr;    // pointer to last node

  // utility function to allocate new node
  ListNode< NODETYPE > *getNewNode( const NODETYPE & );
};
/////////////////////////////////////////////////////////////////////////////
template< typename NODETYPE >
NODETYPE& LinkedList< NODETYPE >::operator[](int index) const
{
  ListNode< NODETYPE > *temp;
  temp=firstPtr;

  for (int i=0; i<index-1; i++)
  {
    temp = temp->nextPtr;
  }

  return temp->data;
}

template< typename NODETYPE >
void LinkedList< NODETYPE >::reverse()
{
  if(firstPtr == NULL) return;
  NODETYPE temp;

  ListNode< NODETYPE > *itPtr=firstPtr;

  int listsize=1;

  while(itPtr!=NULL)
  {
    itPtr= itPtr->nextPtr;
    listsize++;
  }


  int reverserange = (listsize/2) +1;

  for(int i=1; i!= reverserange; i++)
  {
    temp= (*this)[i];
    (*this)[i]=(*this)[listsize-i];
    (*this)[listsize-i]= temp;
  }
}


template< typename NODETYPE >
void LinkedList< NODETYPE >::sort()
{

  if(isEmpty())
  return;

  int numnodes =1;
  ListNode< NODETYPE > *currentPtr;

  for(currentPtr=firstPtr; currentPtr!=lastPtr; currentPtr= currentPtr->nextPtr)
  {
    numnodes++;
  }

  for(int i=2;i<numnodes+1;i++)
  {
    for(int j= i-1; j>=0 && (*this)[j+1]<(*this)[j];j--)
    {
      NODETYPE temp = (*this)[j+1];
      (*this)[j+1] = (*this)[j];
      (*this)[j]= temp;
    }
  }

}

template< typename NODETYPE >
void LinkedList< NODETYPE >::removeDup()
{
  if(isEmpty())
  return;

  ListNode< NODETYPE > *indexPtr;
  ListNode< NODETYPE > *itPtr;
  ListNode< NODETYPE > *prevPtr = firstPtr;
  NODETYPE dummy;

  for(indexPtr =  firstPtr; indexPtr!=NULL; indexPtr = indexPtr->nextPtr)
  {
    for(itPtr = indexPtr->nextPtr; itPtr!=NULL; itPtr=itPtr->nextPtr)
    {
      if(itPtr->data == indexPtr->data)
      {
        while(prevPtr->nextPtr!=itPtr)
        prevPtr=prevPtr->nextPtr;

        if(itPtr->nextPtr ==NULL)
        {
          removeFromBack(dummy);
          itPtr= prevPtr;
        }

        else
        {
          prevPtr->nextPtr = itPtr->nextPtr;
          delete itPtr;
          itPtr=prevPtr;
        }
      }
    }
  }
}



template< typename NODETYPE >
bool LinkedList< NODETYPE >::shared(const LinkedList< NODETYPE > &l2)
{
  ListNode< NODETYPE > *indexPtr;
  ListNode< NODETYPE > *l2Ptr ;
  for(l2Ptr= l2.firstPtr; l2Ptr!=NULL; l2Ptr= l2Ptr->nextPtr)
  {
    for(indexPtr = firstPtr; indexPtr!=NULL; indexPtr=indexPtr->nextPtr)
    {
      if(l2Ptr->data==indexPtr->data)
      return true;
    }
  }
  return false;
}

template< typename NODETYPE >
NODETYPE LinkedList< NODETYPE >:: maxSubSum() const
{
  NODETYPE sum = (*this)[1];
  NODETYPE temp = 0;
  ListNode< NODETYPE > *itPtr=firstPtr;
  int nodenum =1;

  while(itPtr!=NULL)
  {
    itPtr= itPtr->nextPtr;
    nodenum++;
  }



  for(int beginITrange=1; beginITrange!=nodenum; beginITrange++)
  {
    for(int endITrange=beginITrange; endITrange!=nodenum;endITrange++)
    {
      for(int it=beginITrange; it<= endITrange; it++)
      {
        temp+=(*this)[it];
      }
      if(temp> sum)
      sum = temp;
      temp = 0;
    }
  }
  return sum;
}

template< typename NODETYPE >
void LinkedList< NODETYPE >::map(NODETYPE func(const NODETYPE &))
{
  ListNode< NODETYPE > *itPtr;

  for(itPtr=firstPtr; itPtr!=NULL; itPtr=itPtr->nextPtr)
  {
    itPtr->data=func(itPtr->data);
  }
}

template< typename NODETYPE >
void LinkedList< NODETYPE >::filter(bool predicate(const NODETYPE &))
{
  NODETYPE dummy;
  ListNode< NODETYPE > *itPtr;
  ListNode< NODETYPE > *prevPtr=firstPtr;

  for(itPtr=firstPtr; itPtr!=NULL; itPtr=itPtr->nextPtr)
  {
    if(predicate(itPtr->data)==false)
    {
      while(prevPtr->nextPtr!=itPtr)
      prevPtr=prevPtr->nextPtr;

      if(itPtr->nextPtr ==NULL)
      {
        removeFromBack(dummy);
        itPtr= prevPtr;
      }
      else
      {
        prevPtr->nextPtr = itPtr->nextPtr;
        delete itPtr;
        itPtr=prevPtr;
      }

    }

  }



}

/////////////////////////////////////////////////////////////////////////////
template< typename NODETYPE >
LinkedList< NODETYPE >::LinkedList()
: firstPtr( 0 ), lastPtr( 0 )
{
  // empty body
}

template< typename NODETYPE >
LinkedList< NODETYPE >::~LinkedList()
{
  if ( !isEmpty() ) // LinkedList is not empty
    {
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
	{
	  tempPtr = currentPtr;
	  cout <<"deleted from LinkedList: "<< tempPtr->data << '\n';
	  currentPtr = currentPtr->nextPtr;
	  delete tempPtr;
	}
    }
}

// insert node at front of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtFront( const NODETYPE &value )
{
  ListNode< NODETYPE > *newPtr = getNewNode( value ); // new node

  if ( isEmpty() )                 // LinkedList is empty
    firstPtr = lastPtr = newPtr;   // new list has only one node
  else // LinkedList is not empty
    {
      newPtr->nextPtr = firstPtr;  // point new node to previous 1st node
      firstPtr = newPtr;           // aim firstPtr at new node
    }
}

// insert node at back of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  // new node
  ListNode< NODETYPE > *newPtr = getNewNode( value );

  if ( isEmpty() )                // LinkedList is empty
    firstPtr = lastPtr = newPtr;  // new list has only one node
  else                            // LinkedList is not empty
    {
      lastPtr->nextPtr = newPtr;  // update previous last node
      lastPtr = newPtr;           // new last node
    }

}

// delete node from front of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else
    {
      // hold tempPtr to delete
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else
	firstPtr = firstPtr->nextPtr; // point to previous 2nd node

      value = tempPtr->data;      // return data being removed
      delete tempPtr;             // reclaim previous front node
      return true;                // delete successful
    }
}

// delete node from back of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromBack( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else
    {
      ListNode< NODETYPE > *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr )  // LinkedList has one element
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else
	{
	  ListNode< NODETYPE > *currentPtr = firstPtr;

	  // locate second-to-last element
	  while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr; // move to next node

	  lastPtr = currentPtr;    // remove last node
	  currentPtr->nextPtr = 0; // this is now the last node
	}

      value = tempPtr->data;       // return value from old last node
      delete tempPtr;              // reclaim former last node
      return true;                 // delete successful
    }
}

// is LinkedList empty?
template< typename NODETYPE >
bool LinkedList< NODETYPE >::isEmpty() const
{
  return firstPtr == 0;
}

// return pointer to newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *LinkedList< NODETYPE >::getNewNode( const NODETYPE &value )
{
  return new ListNode< NODETYPE >( value );
}

// display contents of LinkedList
template< typename NODETYPE >
void LinkedList< NODETYPE >::print() const
{
  if ( isEmpty() )           // LinkedList is empty
    {
      cout << "The list is empty\n\n";
      return;
    }

  ListNode< NODETYPE > *currentPtr = firstPtr;

  cout << "The list is: ";

  while ( currentPtr != 0 ) // get element data
    {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
    }
  cout<<"\n\n";
}

#endif
