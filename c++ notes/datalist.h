#ifndef DATALIST_H
#define DATALIST_H

#include <iostream>

class GenericList {
  double *list;       // dynamic array of double data
  long physical_size; // maximum size of the list
  long logical_size;  // number of array positions filled

public:
  // Constructor
  GenericList(long max_size);

  // Destructor
  ~GenericList();

  // Copy constructor
  GenericList(const GenericList &other);

  // Assignment operator
  GenericList &operator=(const GenericList &other);

  // Adds a value to the list
  void add_value(double value);
	
  // Checks if the list is full
  bool full() const;

  // Returns the number of values in the list
  long get_size() const;

  // Returns the value at the specified position
  double get_value(long position) const;

  // Returns a reference to the last value in the list
  double get_last() const;

  // Deletes the last value from the list
  void delete_last();

  // Outputs the values in the list
  void output(std::ostream &outs) const;

  // Overload the [] operator for element access
  double& operator[](long index);

  // Overload the += operator for adding values to the list
  GenericList& operator+=(double value);

  // Declare the << operator as a friend function
  friend std::ostream& operator<<(std::ostream& os, const GenericList& list);
};

#endif