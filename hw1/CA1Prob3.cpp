/**
 * check if n is a multiple of m
 *
 * @author 趙新元 CHAO,SIN-YUAN
 * @ID B10505057
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include <iostream>
bool isMultiple(long n, long m)
{
	if (n % m == 0) // if n is a multiple of m
		return true;
	return false; // if not
}