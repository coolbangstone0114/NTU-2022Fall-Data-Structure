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

  /**
   *  Get the value of the int variable.
   *  @return the stored value.
   */
  int getvalue() const {
    return i;
  }

  int compareTo(const Integer& integer) const {
    if (i > integer.getvalue()) {
      return 1;
    } else if(i < integer.getvalue()) {
      return -1;
    } else {
      return 0;
    }
  }
};

#endif
