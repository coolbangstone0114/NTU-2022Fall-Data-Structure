/**
 *  A class that stores a string and generates a hash code for it.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef STRING_H
#define STRING_H

#include <string>
using namespace std;

class String {
private:
  string str;

public:

  /**
   *  Construct a new String with the given variable.
   *  @param str the string by which the String stores.
   */
  String(const string& str);
  String() {};

  /**
   *  Get the value of the string variable.
   *  @return the stored value.
   */
  string getvalue() const;

  /**
   *  Returns true if "this" String and "strg" have identical values.
   *  @param strg is the second String.
   *  @return true if the string values are equal, false otherwise.
   */
  bool equals(const String& strg);

  /**
   *  Returns a hash code for this String.
   *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
   */
  int hashCode() const;
};

#endif
