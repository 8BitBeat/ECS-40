//Christopher Chan
#ifndef VECTORLIST_H
#define VECTORLIST_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template< typename NODETYPE >
class VectorList
{
 public:
  VectorList(); // constructor
  ~VectorList(); // destructor



  void insertAtFront( const NODETYPE & );
  void insertAtBack( const NODETYPE & );
  bool removeFromFront( NODETYPE & );
  bool removeFromBack( NODETYPE & );
  bool isEmpty() const;
  void print() const;


  /////////////////////////////////////////////////////////
  // new member functions for HW 5

  // overload array access operator
  NODETYPE &operator[](int index) const; //DONE(?)

  // Find the MAXIMAL SUM of values among all consecutive sub-lists
  // of the linked list, assuming +, <, == are overloaded for NODETYPE
  NODETYPE maxSubSum()const ;//DONE

  // Sort the linked list in ascending order,
  // assuming NODETYPE supports <, ==, etc->
  void sortvec();//DONE

  // In-place reversal of the linked list, i->e->, don't create a new list
  // to perform the reversal, and use the list itself
  void reverse();//DONE

  // Check whether the current list and the input l2 share any nodes or not
  bool shared(const VectorList< NODETYPE > &l2);//DONE

  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &));//DONE

  // Keep only those nodes n where predicate(n) = true
  void filter(bool predicate(const NODETYPE &));

  // Remove all duplicates from the list
  void removeDup(); //DONE

  //
  /////////////////////////////////////////////////////////

 private:
  vector< NODETYPE > *vList;  // list data as a vector
};

template< typename NODETYPE >
void VectorList< NODETYPE >::filter(bool predicate(const NODETYPE &))
{
  int vlistsize=vList->size();

  for(int i=0; i<vlistsize;i++)
  {
    if(predicate((*this)[i])==false)
    {
        vList->erase(vList->begin()+i);
        i--;
        vlistsize = vList->size();
    }

  }

}


template< typename NODETYPE >
void VectorList< NODETYPE >::map(NODETYPE func(const NODETYPE &))
{
  int vlistsize=vList->size();
  for(int i=0; i<vlistsize;i++)
  {
    (*this)[i]=func((*this)[i]);
  }
}

template< typename NODETYPE >
void VectorList< NODETYPE >::reverse()
{
  NODETYPE temp;
  int reverserange = vList->size()/2;
  int end = vList->size() -1;

  for(int i=0; i<reverserange; i++)
  {
    temp= (*this)[i];
    (*this)[i]=(*this)[end-i];
    (*this)[end-i]= temp;
  }
}

template< typename NODETYPE >
void VectorList< NODETYPE >::sortvec()
{
  sort(vList->begin(), vList->end());
}

template< typename NODETYPE >
NODETYPE& VectorList< NODETYPE >::operator[](int index) const
{
  return (*vList)[index];
}//array access operator overloading

template< typename NODETYPE >
bool VectorList< NODETYPE >::shared(const VectorList< NODETYPE > &l2)
{
  int l2size=l2.vList->size();
  int vlistsize = vList->size();

    for(int i=0; i< l2size; i++)
    {
      for(int j=0;j<vlistsize;j++)
      {
        if((*this)[j] == l2[i])
        {
          return true;
        }
      }
    }
  return false;
}


template< typename NODETYPE >
void VectorList< NODETYPE >::removeDup()
{
  int vListSize = vList->size();
  for(int i=0; i<vListSize; i++)
  {
    NODETYPE temp = (*this)[i];
    for(int index =i+1; index< vListSize; index++ )
    {
      if((*this)[index]==temp)
      {
        vList->erase(vList->begin()+index);
        index--;
        vListSize = vList->size();
      }
    }
  }
}

template< typename NODETYPE >
NODETYPE VectorList< NODETYPE >:: maxSubSum() const
{
  NODETYPE sum = (*this)[0];
  NODETYPE temp=0;

  int vlistsize = vList->size();

  for(int beginITrange=0; beginITrange<vlistsize; beginITrange++)
  {
    for(int endITrange=beginITrange; endITrange< vlistsize;endITrange++)
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

////////////////////////////////////////////////////////////////////////////////
template< typename NODETYPE >
VectorList< NODETYPE >::VectorList()
{
  vList = new vector <NODETYPE>;
}

template< typename NODETYPE >
VectorList< NODETYPE >::~VectorList()
{

  int vlistsize= vList->size();

  for (int i=0;i<vlistsize;i++)
  cout<<"deleted from VectorList: "<<(*this)[i]<<'\n';
  delete vList;

}

// insert node at front of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtFront( const NODETYPE &value )
{

  vList->insert(vList->begin(), value);

}

// insert node at back of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  vList->push_back(value);

}

// delete node from front of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if (isEmpty())
  {
    return false;
  }
  else
  {
    value = (*this)[0];
    vList->erase(vList->begin());
    return true;
  }
}

// delete node from back of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromBack( NODETYPE &value )
{
  if (isEmpty())
  {
    return false;
  }


  else
  {
    value =(*this)[(vList->size())-1];
    vList->pop_back();
    return true;
  }
}

// is VectorList empty?
template< typename NODETYPE >
bool VectorList< NODETYPE >::isEmpty() const
{
  if(vList->size()==0)
  return true;

  else
  return false;

}

// display contents of VectorList
template< typename NODETYPE >
void VectorList< NODETYPE >::print() const
{
  if (isEmpty())
  {
    cout << "The list is empty\n\n";
    return;
  }
  int vlistsize = vList->size();
  cout<<"The vector is: ";
  for(int i= 0; i< vlistsize; i++)
  {
    cout<< (*this)[i]<< " ";
  }

  cout<<"\n\n";
}

#endif
