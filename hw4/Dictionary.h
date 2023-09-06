/**
 *  An abstract class for (unordered) dictionary ADTs.
 *
 *  DO NOT CHANGE THIS FILE.
 **/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Entry.h"

template<typename K, typename V>
class Dictionary {
public:

  /**
   *  Returns the number of entries stored in the dictionary.  Entries with
   *  the same key (or even the same key and value) each still count as
   *  a separate entry.
   *  @return number of entries in the dictionary.
   **/
  virtual int size() = 0;

  /**
   *  Tests if the dictionary is empty.
   *
   *  @return true if the dictionary has no entries; false otherwise.
   **/
  virtual bool isEmpty() = 0;

  /**
   *  Create a new Entry object referencing the input key and associated value,
   *  and insert the entry into the dictionary.
   *  Multiple entries with the same key (or even the same key and
   *  value) can coexist in the dictionary.
   *
   *  @param key the key by which the entry can be retrieved.
   *  @param value an arbitrary object.
   **/
  virtual void insert(const K& key, const V& value) = 0;

  /**
   *  Search for an entry with the specified key.  If such an entry is found,
   *  return true; otherwise return false.
   *
   *  @param key the search key.
   *  @return true if an entry containing the key is found, or false if
   *          no entry contains the specified key.
   **/
  virtual bool find(const K& key) = 0;

  /**
   *  Remove an entry with the specified key.  If such an entry is found,
   *  remove it from the table.
   *  If several entries have the specified key, choose one arbitrarily, then
   *  remove it.
   *
   *  @param key the search key.
   */
  virtual void remove(const K&  key) = 0;

  /**
   *  Remove all entries from the dictionary.
   */
  virtual void makeEmpty() = 0;
};

#endif
