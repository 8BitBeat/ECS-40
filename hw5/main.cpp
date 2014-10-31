//Christopher Chan
#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "VectorList.h"

using namespace std;

// display program instructions to user
void instructions()
{
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n"
      << "  2 to insert at end of list\n"
      << "  3 to delete from beginning of list\n"
      << "  4 to delete from end of list\n"
      << "  5 to reverse list\n"
      << "  6 to sort list processing\n"
      << "  7 to remove duplicates\n"
      << "  8 to add values to l2\n"
      << "  9 to check if vList and l2 share any nodes\n"
      << "  10 to obtain max sum of consecutive subsets\n"
      << "  11 to multiply every node by 2 (map)\n"
      << "  12 to filter out all negative numbers (filter)\n"
      << "  13 to end list processing\n";
}

template< typename NODETYPE >
bool predicate(const NODETYPE &y)//checks for negative values
{
  if(y>=0)
  return true;

  else
  return false;
}

template< typename NODETYPE >
NODETYPE func(const NODETYPE &x)
{
  return x*2;
}


// function to test a LinkedList
template< typename T >
void testLinkedList( LinkedList< T > &listObject, const string &typeName )
{
   cout << "Testing a LinkedList of " << typeName << " values\n";
   instructions();       // display instructions
   LinkedList< T > l2;
   int choice;           // store user choice
   T value;              // store input value


   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice )
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;

         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;

            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
        case 5:
            listObject.reverse();
            listObject.print();
            break;
        case 6:
            listObject.sort();
            listObject.print();
            break;
        case 7:
            listObject.removeDup();
            listObject.print();
            break;
        case 8:
            cout << "Enter " << typeName << ": ";
            cin >> value;
            l2.insertAtBack(value);
            l2.print();
            break;
        case 9:
            if(listObject.shared(l2)==true)
            cout<<"LinkedList and l2 share nodes\n\n";
            else
            cout<<"LinkedList and l2 DOES NOT share nodes\n\n";
            break;
        case 10:
            if(listObject.isEmpty())
            cout<<"The are no nodes in the list\n"<<endl;
            else
            cout<<"The max sub sum of the list is "
            <<listObject.maxSubSum()<<"\n\n";
            break;
        case 11:
            listObject.map(func);
            listObject.print();
            break;
        case 12:
            listObject.filter(predicate);
            listObject.print();
            break;
      }
   } while ( choice < 13 );

   cout << "End list test\n\n";
}


// function to test a VectorList
template< typename T >
void testVectorList( VectorList< T > &listObject, const string &typeName )
{
   cout << "Testing a VectorList of " << typeName << " values\n";
   instructions();       // display instructions
   int choice;           // store user choice
   T value;              // store input value
   VectorList< T > l2;

   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice )
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
            cout << value << " removed from list\n";
            listObject.print();
            break;
          case 5:         //reverse
            listObject.reverse();
            listObject.print();
            break;
          case 6:
            listObject.sortvec();
            listObject.print();
            break;
          case 7:
            listObject.removeDup();
            listObject.print();
            break;
          case 8:
            cout << "Enter " << typeName << ": ";
            cin >> value;
            l2.insertAtBack(value);
            l2.print();
            break;

          case 9:
            if(listObject.shared(l2)==true)
            cout<<"vList and l2 share nodes\n\n";
            else
            cout<<"vList and l2 DOES NOT share nodes\n\n";
            break;
          case 10:
            if(listObject.isEmpty())
            cout<<"The are no nodes in the vector\n"<<endl;
            else
            cout<<"The max sub sum of the vector is "
            <<listObject.maxSubSum()<<"\n\n";
            break;
          case 11:
            listObject.map(func);
            listObject.print();
            break;
          case 12:
            listObject.filter(predicate);
            listObject.print();
            break;
      }
   } while ( choice < 13 );

   cout << "End list test\n\n";
}


int main()
{
   // test LinkedList of int values
   LinkedList< int > integerLinkedList;
   testLinkedList( integerLinkedList, "integer" );

   // test VectorList of int values
   VectorList< int > integerVectorList;
   testVectorList( integerVectorList, "integer" );

   // test LinkedList of double values
   LinkedList< double > doubleLinkedList;
   testLinkedList( doubleLinkedList, "double" );

   // test VectorList of double values
   VectorList< double > doubleVectorList;
   testVectorList( doubleVectorList, "double" );

   return 0;
}

