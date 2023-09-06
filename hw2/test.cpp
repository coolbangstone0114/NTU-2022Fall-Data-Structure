#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
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

Date::Date(int m, int d, int y)
{
  if (isValidDate(m, d, y))
  {
    month = m;
    day = d;
    year = y;
    days = dayInYear();
  }
  else
  {
    cout << "\nwrong inputs" << endl;
    exit(0);
  }
}

/**
 *  Constructs a Date object corresponding to the given string which
 *  should be a string of the form "month/day/year".
 *  If the string does not match the requirements or is not
 *  a valid date, the program halts with an error message.
 */
Date::Date(const string &s)
{
  //s.c_str();
  int a[3] = {0};
  char r[30] = {};
  int f = 0;
  int p = 1;
  int h = 0;

  for (int j = 0; s[j] != '\0'; ++j)
  {
    f = f + 1;
  }

  for (int j = 0; s[j] != '\0'; ++j)
  {
    r[j] = s[f - j - 1];
  }

  for (int j = 0; r[j] != '\0'; ++j)
  {
    if (r[j] == '/')
    {
      h = h + 1;
      p = 1;
      continue;
    }
    if ((int)r[j] < 48 || (int)r[j] > 57)
    {
      cout << "\nwrong inputs" << endl;
      exit(0);
    }

    a[h] = a[h] + ((int)r[j] - 48) * p;
    p = p * 10;
  }
  if (isValidDate(a[2], a[1], a[0]))
  {
    month = a[2];
    day = a[1];
    year = a[0];
    days = dayInYear();
    //printf("\nhello : %d %d %d No.%d\n",a[2],a[1],a[0],days);
  }
  else
  {
    cout << "\nwrong inputs" << endl;
    exit(0);
  }
}

/**
 *  Checks whether the given year is a leap year.
 */
bool Date::isLeapYear(int y) // OK
{
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    return true;
  else
    return false;
}

/**
 *  Returns the number of days in a given month.
 */
int Date::daysInMonth(int m, int y) // OK
{
  if (isLeapYear(y))
    return mdl[m];
  else
    return md[m];
}

/**
 *  Checks whether the given date is valid.
 */
bool Date::isValidDate(int m, int d, int y)
{
  if (y >= 1 && m <= 12 && m >= 1)
  {
    if (d > 0 && d <= daysInMonth(m, y))
      return true;
    else
      return false;
  }
  else
  {
    return false;
  }
}

/**
 *  Returns a string representation of this Date in the form month/day/year.
 */
string Date::toString() const 
{
  ostringstream output;
  output << month << '/' << day << '/' << year;
  return output.str();
}

/**
 *  Determines whether this Date is before the Date d.
 */
bool Date::isBefore(const Date &d)
{
  if (year < d.year)
    return true;
  else if (year == d.year && days < d.days)
    return true;
  else
    return false;
}

/**
 *  Determines whether this Date is after the Date d.
 */
bool Date::isAfter(const Date &d)
{
  if (year > d.year)
    return true;
  else if (year == d.year && days > d.days)
    return true;
  else
    return false;
}

/**
 *  Determines whether this Date is equal to the Date d.
 */
bool Date::isEqual(const Date &d)
{
  if (year == d.year && days == d.days)
    return true;
  else
    return false;
}

/**
 *  Returns the number of this Date in the year.
 */
int Date::dayInYear()
{
  int dd = 0;
  if (isLeapYear(year))
  {
    for (int m = 1; m < month; ++m)
    {
      dd = dd + mdl[m];
    }
    dd = dd + day;
  }
  else
  {
    for (int m = 1; m < month; ++m)
    {
      dd = dd + md[m];
    }
    dd = dd + day;
  }
  return dd;
}

/**
 *  Determines the difference in days between d and this Date.
 */
int Date::difference(const Date &d)
{
  int di = 0;
  if (year == d.year)
  {
    di = days - d.days;
    return di;
  }
  if (year > d.year)
  {
    if (isLeapYear(d.year))
    {
      di = 366 - d.days;
    }
    else
    {
      di = 365 - d.days;
    }
    for (int c = d.year + 1; c < year; ++c)
    {
      if (isLeapYear(c))
      {
        di = di + 366;
      }
      else
      {
        di = di + 365;
      }
    }
    di = di + days;
    return di;
  }
  else
  {
    if (isLeapYear(year))
    {
      di = 366 - days;
    }
    else
    {
      di = 365 - days;
    }
    for (int c = year + 1; c < d.year; ++c)
    {
      if (isLeapYear(c))
      {
        di = di + 366;
      }
      else
      {
        di = di + 365;
      }
    }
    di = di + d.days;
    return -1 * di;
  }
}

int main()
{
  cout << "\nTesting constructors->";
  Date *d1 = new Date(1, 1, 1);
  cout << "\nDate should be 1/1/1: " << d1->toString();
  delete d1;
  d1 = new Date("2/29/2000");
  cout << "\nDate should be 2/29/2000: " << d1->toString();
  delete d1;
  d1 = new Date("2/29/1904");
  cout << "\nDate should be 2/29/1904: " << d1->toString();
  delete d1;
  d1 = new Date(12, 31, 1975);
  cout << "\nDate should be 12/31/1975: " << d1->toString();
  Date *d2 = new Date("1/1/1976");
  cout << "\nDate should be 1/1/1976: " << d2->toString();
  Date *d3 = new Date("1/2/1976");
  cout << "\nDate should be 1/2/1976: " << d3->toString();

  Date *d4 = new Date("2/27/1977");
  Date *d5 = new Date("8/31/2110");

  /* I recommend you write code to test the isLeapYear function! */

  cout << "\nTesting before, after and equal->";
  cout << "\n"
       << d2->toString() << " after " << d1->toString() << " should be true: " << d2->isAfter(*d1);
  cout << "\n"
       << d3->toString() << " after " << d2->toString() << " should be true: " << d3->isAfter(*d2);
  cout << "\n"
       << d1->toString() << " after " << d1->toString() << " should be false: " << d1->isAfter(*d1);
  cout << "\n"
       << d1->toString() << " after " << d2->toString() << " should be false: " << d1->isAfter(*d2);
  cout << "\n"
       << d2->toString() << " after " << d3->toString() << " should be false: " << d2->isAfter(*d3);

  cout << "\n"
       << d1->toString() << " before " << d2->toString() << " should be true: " << d1->isBefore(*d2);
  cout << "\n"
       << d2->toString() << " before " << d3->toString() << " should be true: " << d2->isBefore(*d3);
  cout << "\n"
       << d1->toString() << " before " << d1->toString() << " should be false: " << d1->isBefore(*d1);
  cout << "\n"
       << d2->toString() << " before " << d1->toString() << " should be false: " << d2->isBefore(*d1);
  cout << "\n"
       << d3->toString() << " before " << d2->toString() << " should be false: " << d3->isBefore(*d2);

  cout << "\n"
       << d2->toString() << " equal " << d3->toString() << " should be false: " << d2->isEqual(*d3);
  cout << "\n"
       << d5->toString() << " equal " << d5->toString() << " should be true: " << d5->isEqual(*d5);
  cout << "\n"
       << d1->toString() << " equal " << d4->toString() << " should be false: " << d1->isEqual(*d4);

  cout << "\nTesting difference->";
  cout << "\n"
       << d1->toString() << " - " << d1->toString() << " should be 0: " << d1->difference(*d1);
  cout << "\n"
       << d2->toString() << " - " << d1->toString() << " should be 1: " << d2->difference(*d1);
  cout << "\n"
       << d3->toString() << " - " << d1->toString() << " should be 2: " << d3->difference(*d1);
  cout << "\n"
       << d3->toString() << " - " << d4->toString() << " should be -422: " << d3->difference(*d4);
  cout << "\n"
       << d5->toString() << " - " << d4->toString() << " should be 48762: " << d5->difference(*d4);
  cout << "\n";
}
