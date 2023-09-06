/**
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef DOUBLE_H
#define DOUBLE_H


class Double {
private:
  double d;

public:

  /**
   *  Construct a new Double with the given variable.
   *  @param d the double variable by which the Double stores.
   */
  Double(const double& d);

  /**
   *  Get the value of the double variable.
   *  @return the stored value.
   */
  double getvalue() const;

  /**
   *  Returns true if "this" Double and "db" have identical values.
   *  @param db is the second Double.
   *  @return true if the double values are equal, false otherwise.
   */
  bool equals(const Double& db);

  /**
   *  Returns a hash code for this Double.
   *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
   */
  int hashCode()const;
};

#endif
