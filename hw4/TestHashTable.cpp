/**
 * Briefly explain the function of this class->
 *
 * @author 			CHAO,SUN-YUAN
 * @ID 				B10505057
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * TestHashTable.cpp
 * version 1.0
 */
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.h"
#include "HashTableChained.cpp"
#include "CheckerBoard.h"
#include "CheckerBoard.cpp"
#include "Double.h"
#include "Double.cpp" 
#include "String.h"
#include "String.cpp"

template <typename K, typename V>
void initTable(HashTableChained<K, V> *table, int numBoards);
CheckerBoard *randomBoard();

int main()
{

    // initialize random seed:
    srand(time(NULL));

    int numBoards = 1000;

    cout << "===============================String Hash Table Test=====================================" << endl;
    HashTableChained<String *, Integer *> *stringTable = new HashTableChained<String *, Integer *>(numBoards);
    stringTable->insert(new String("abc"), new Integer(1));
    stringTable->insert(new String("def"), new Integer(2));
    cout << "Finding abc should be 1 : " << stringTable->find(new String("abc")) << endl;
    cout << "Finding def should be 1 : " << stringTable->find(new String("def")) << endl;
    stringTable->remove(new String("abc"));
    cout << "Finding abc should be 0 : " << stringTable->find(new String("abc")) << endl;
    cout << "Size should be 1 : " << stringTable->size() << endl;
    stringTable->makeEmpty();
    cout << "Size should be 0 : " << stringTable->size() << endl;

    cout << "===============================Double Hash Table Test=====================================" << endl;
    HashTableChained<Double *, Integer *> *doubleTable = new HashTableChained<Double *, Integer *>(numBoards);
    initTable(doubleTable, numBoards);
    doubleTable->insert(new Double(10), new Integer(1));
    doubleTable->insert(new Double(20), new Integer(2));
    cout << "Size should be 1002 : " << doubleTable->size() << endl;

    cout << "===============================CheckerBoard Hash Table Test===============================" << endl;
    HashTableChained<CheckerBoard *, Integer *> *table = new HashTableChained<CheckerBoard *, Integer *>(numBoards);
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++)
    {
        CheckerBoard *board = randomBoard();
        table->insert(board, new Integer(i));

        if (!board->equals(*board))
        {
            cout << "0";
            break;
        }
    }

    // To test your hash function, add a method to your HashTableChained class
    // that counts the number of collisions--or better yet, also prints
    // a histograph of the number of entries in each bucket.  Call this method
    // from here.
}

/**
 *  Generates a random 8 x 8 CheckerBoard.
 **/
CheckerBoard *randomBoard()
{
    CheckerBoard *board = new CheckerBoard;
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            board->setElementAt(x, y, rand());
        }
    }
    return board;
}

/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template <typename K, typename V>
void initTable(HashTableChained<K, V> *table, int numBoards)
{
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++)
    {
        table->insert(new Double(i), new Integer(i));
    }
}
