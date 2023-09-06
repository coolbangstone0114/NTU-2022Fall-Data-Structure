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
  String(const string& str) {
    this->str = str;
  }

  /**
   *  Get the value of the string variable.
   *  @return the stored value.
   */
  string getvalue() const {
    return str;
  }

  int compareTo(const String& cString) const {
   if (str.compare(cString.getvalue()) > 0) {
     return 1;
   } else if(str.compare(cString.getvalue()) < 0) {
     return -1;
   } else {
     return 0;
   } 
  }

};

#endif
