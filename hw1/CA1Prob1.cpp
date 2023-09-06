/**
* calculate the dot product
*
* @author 趙新元 CHAO,SIN-YUAN
* @ID B10505057
* @Department Engineering Science and Ocean Engineering
* @Affiliation National Taiwan University
*/

#include<iostream>
#include<exception>
using namespace std;
int dotProduct(int a[], int b[], int n) 
{
	if (n <= 0)throw "wrong inputs";//print "wrong inputs" when the number n ins't reasonable
	int c = 0 ;
	for (int k = 0; k < n; k++)//caculate the dot product
		c += a[k] * b[k];
	return c;
}