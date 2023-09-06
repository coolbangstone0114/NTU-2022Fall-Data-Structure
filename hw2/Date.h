/**
 * It is a header file of the class that can display date.
 *
 * @author 			»¯·s¤¸
 * @ID 				B10505057
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * Date.cpp
 * version 1.0
 */

#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Date
{
private:
  int month;
  int day;
  int year;
  int days;
  int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int mdl[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
  /**
   *  Constructs a Date with the given month, day and year.   If the date is
   *  not valid, the entire program will halt with an error message.
   */
  Date(int month, int day, int year);

  /**
   *  Constructs a Date object corresponding to the given string which
   *  should be a string of the form "month/day/year".
   *  If the string does not match the requirements or is not
   *  a valid date, the program halts with an error message.
   */
  Date(const string &s);

  /**
   *  Checks whether the given year is a leap year.
   */
  bool isLeapYear(int year);

  /**
   *  Returns the number of days in a given month.
   */
  int daysInMonth(int month, int year);

  /**
   *  Checks whether the given date is valid.
   */
  bool isValidDate(int month, int day, int year);

  /**
   *  Returns a string representation of this Date in the form month/day/year.
   */
  string toString() const;

  /**
   *  Determines whether this Date is before the Date d.
   */
  bool isBefore(const Date &d);

  /**
   *  Determines whether this Date is after the Date d.
   */
  bool isAfter(const Date &d);

  /**
   *  Determines whether this Date is equal to the Date d.
   */
  bool isEqual(const Date &d);

  /**
   *  Returns the number of this Date in the year.
   */
  int dayInYear();

  /**
   *  Determines the difference in days between d and this Date.
   */
  int difference(const Date &d);
};

#endif
