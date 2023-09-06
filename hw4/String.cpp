/**
 *  A class that stores a string and generates a hash code for it.
 *
 **/

#include "String.h"
#include <cmath>
#include <typeinfo>
/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string &str)
{
	this->str = str;
}

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const
{
	return str;
}

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String &strg)
{
	return (this->str == strg.str);
}

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() const
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;
	const unsigned char* data = (const unsigned char*)str.c_str();
	while (*data)
	{
		hash = hash * seed + (*data++);
	}

	return (hash & 0x7FFFFFFF);
}
