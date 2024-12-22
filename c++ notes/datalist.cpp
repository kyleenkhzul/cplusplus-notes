#include "datalist.h"

#include <iostream>
#include <cstdlib> 

using namespace std;

// Initializes the object to an empty list with specified size.
GenericList::GenericList(long max_size) : 
 list(new double[max_size]), physical_size(max_size), logical_size(0) {}

// Destructor to deallocate dynamic memory.
GenericList::~GenericList()
{
    delete[] list;
}

// Copy constructor.
GenericList::GenericList(const GenericList &other) 
 : list(new double[other.physical_size]), physical_size(other.physical_size),
   logical_size(other.logical_size)
{
    for (long i = 0; i < logical_size; ++i)
    {
        list[i] = other.list[i];
    }
}

// Assignment operator.
GenericList &GenericList::operator=(const GenericList &other)
{
    if (this != &other)
    {
        delete[] list;
        physical_size = other.physical_size;
        logical_size = other.logical_size;
        list = new double[physical_size];
        for (long i = 0; i < logical_size; ++i)
        {
            list[i] = other.list[i];
        }
    }
    return *this;
}

// Overload the [] operator for element access
    double& GenericList::operator[](long index) {
    if (index < 0 || index >= logical_size) {
        cerr << "Error: Index out of range" << endl;
        exit(1);
    }
    return list[index];
}

// Define the operator+= member function inside the class
GenericList& GenericList::operator+=(double value) {
    add_value(value);
    return *this;
}

// Define the << operator as a friend function
ostream& operator<<(ostream& os, const GenericList& list) {
    for (long i = 0; i < list.logical_size; ++i) {
        os << list.list[i] << " ";
    }
    return os;
    }

// Precondition:  The list is not full.
// Postcondition:  The value has been added to the END of the list,
//                 if there was room. If the list is full, it will be resized.
void GenericList::add_value(double value)
{
    if (full())
    {
        // Resize the list
        long new_physical_size = (physical_size == 0) ? 1 : physical_size * 2;
        double *new_list = new double[new_physical_size];
        for (long i = 0; i < logical_size; ++i)
        {
            new_list[i] = list[i];
        }
        delete[] list;
        list = new_list;
        physical_size = new_physical_size;
    }
    list[logical_size++] = value;
}

// Returns true if the list is full, false otherwise.
bool GenericList::full() const
{
    return (logical_size == physical_size);
}

// Returns the number of values in the list.
long GenericList::get_size() const
{
    return logical_size;
}

// Precondition:  0 <= position < get_size()
// Returns the value at specified position.
double GenericList::get_value(long position) const
{
    return ((position >= logical_size) || (position < 0)) ? (0.0) : 
		(list[position]);
}

// Returns a copy of the last value in the list.
double GenericList::get_last() const
{
    if (logical_size == 0)
        return 0.0; // or NaN, depending on your preference
    return list[logical_size - 1];
}

// Deletes the last value from the list.
// If the logical size becomes significantly smaller than the physical size,
// the list is resized to release the wasted elements.
void GenericList::delete_last()
{
  if (logical_size > 0)
    {
     --logical_size;
        
// Check if the logical size is significantly smaller than the physical size
     if (logical_size < physical_size / 2)
     {
 // Resize the list
  long new_physical_size = (physical_size == 0) ? 0 : physical_size / 2;
      if (new_physical_size == 0) {
       delete[] list;
        list = nullptr;
    } else {
      double *new_list = new double[new_physical_size];
       for (long i = 0; i < logical_size; ++i)
       {
        new_list[i] = list[i];
       }
      delete[] list;
      list = new_list;
     }
     physical_size = new_physical_size;
    }
  }
}

// Precondition:  If outs is a file output stream, then outs has
//                already been connected to a file.
// Postcondition:  Values are output one per line on the stream.
void GenericList::output(ostream &outs) const
{
    for (long i = 0; i < logical_size; ++i)
    {
        outs << list[i] << '\n';
    }
}

int main() {
  const long MAX_SIZE = 5; // Maximum size of the list
    
  // Create a list with maximum size MAX_SIZE
  GenericList list(MAX_SIZE);
  
  cout << "Creating a list with a maximum size of: " << MAX_SIZE << endl;
    
  // Add some values to the list
  list += 10.5;  // Using +=
  list += 20.3;
  list.add_value(15.7); // Using add_value
  list.add_value(30.2);
  list.add_value(25.9);
    
  // Output the values in the list using <<
  cout << "Values in the list: " << list << endl;
    
  // Test element access using []
  cout << "Value at index 2: " << list[2] << endl;
    
  // Test deleting the last value
  list.delete_last();
  cout << "After deleting the last value: " << list << endl;
    
  // Test full
  cout << "Is the list full? " << (list.full() ? "Yes" : "No") << endl;

    return 0;
}