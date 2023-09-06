/**
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 **/

#include "Double.h"
#include <cmath>
#include <typeinfo>
#include <cstring>
/**
 *  Construct a new Double with the given variable.
 *  @param d the double variable by which the Double stores.
 */
Double::Double(const double &d)
{
    this->d = d;
}

/**
 *  Get the value of the double variable.
 *  @return the stored value.
 */
double Double::getvalue() const
{
    return this->d;
}

/**
 *  Returns true if "this" Double and "db" have identical values.
 *  @param db is the second Double.
 *  @return true if the double values are equal, false otherwise.
 */
bool Double::equals(const Double &db)
{
    return (this->d == db.d);
}

/**
 *  Returns a hash code for this Double.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int Double::hashCode() const
{
    unsigned int hash;
    memcpy(&hash, &d, sizeof(float));
    return hash & 0xfffff000;
}
