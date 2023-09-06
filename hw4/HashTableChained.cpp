/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"
#include <iostream>
#include <cmath>
using namespace std;
/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate)
{
    if (sizeEstimate <= 0)
    {
        exit(0);
    }
    Size = 0;
    capacity = (sizeEstimate == 1 ? 1 : showPrime((unsigned)(sizeEstimate * 2)));
    t = new list<Entry<K, V> >[capacity];
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained()
{
    Size = 0;
    capacity = 101;
    t = new list<Entry<K, V> >[capacity];
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::compFunction(int code)
{
    return abs(code) % this->capacity;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::size()
{
    return this->Size;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::isEmpty()
{
    return (this->size() == 0);
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void HashTableChained<K, V>::insert(const K &key, const V &value)
{
    int s = this->compFunction(key->hashCode());
    list<Entry<K, V> > *a = &t[s];
    a->push_back(Entry<K, V>(key, value));
    ++Size;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::find(const K &key)
{
    list<Entry<K, V> > *a = &t[this->compFunction(key->hashCode())];
    typename list<Entry<K, V> >::iterator iter;
    for (iter = a->begin(); iter != a->end(); ++iter)
    {
        if (iter->getkey()->equals(*key))
        {
            return true;
        }
    }

    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void HashTableChained<K, V>::remove(const K &key)
{
    list<Entry<K, V> > *a = &t[this->compFunction(key->hashCode())];
    typename list<Entry<K, V> >::iterator iter;
    for (iter = a->begin(); iter != a->end(); ++iter)
    {
        if (iter->getkey()->equals(*key))
        {
            a->erase(iter);
            --Size;
            break;
        }
    }
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void HashTableChained<K, V>::makeEmpty()
{
    for (int i = 0; i < capacity; ++i)
    {
        t[i].clear();
    }
    Size = 0;
}

template <typename K, typename V>
int HashTableChained<K, V>::showPrime(int p)
{
    if (p < 2)
    {
        return 0;
    }
    int ps = 0;
    for (int s = 0;; ++s)
    {
        int f = 0;
        int d = p - s;
        for (int e = 2; (e ^ 2) < d; e++)
        {
            if (d % e == 0)
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            ps = d;
            goto t;
        }
    }
t:;
    return ps;
}
template <typename K, typename V>
void HashTableChained<K, V>::print()
{
    int nc;
    cout << "capacity: " << capacity << endl;
    cout << "size: " << Size << endl;
    nc = 0;
    for (int i = 0; i < capacity; ++i)
    {
        if (t[i].size() == 0)
        {
        }
        else
        {
            nc += (t[i].size() - 1);
        }
    }
    cout << "number of collisions: " << nc << endl;
}
