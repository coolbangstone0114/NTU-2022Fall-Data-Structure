/**
 *  A class that stores a variable of type int.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef INTEGER_H
#define INTEGER_H

class Integer {
private:
  int i;

public:

  /**
   *  Construct a new Integer with the given variable.
   *  @param i the int variable by which the Integer stores.
   */
  Integer(const int& i) {
    this->i = i;
  }
Integer() {}

  /**
   *  Get the value of the int variable.
   *  @return the stored value.
   */
  int getvalue() const {
    return i;
  }
};

#endif
