/**
 * find the prime
 *
 * @author 趙新元 CHAO,SIN-YUAN
 * @ID B10505057
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#include <iostream>
using namespace std;
int *showPrime(int p)
{
    if (p < 2)
        exit(0);              // The smallest prime is 2, so any p that is smaller than 2 is illegal
    int *primes = new int[2]; // The array we will return in the end
    int flag = 0;
    // Check whether p is prime or not
    for (int i = 1; i <= p; i++)
    {
        if (p % i == 0)
            flag += 1;
    }
    if (flag == 2) // if p is a prime
    {
        primes[0] = p; // set first element to be p
        primes[1] = 0; // set second element to be 0
        return primes; // Just return directly
    }
    // If p is not a prime
    // Find ps
    for (int i = p - 1; i >= 2; i--) // Find backward
    {
        flag = 0;
        for (int j = 1; j <= i; j++) // Find factors
        {
            if (i % j == 0)
                flag++; // flag means the number of factors
        }
        if (flag == 2) // when the factors of i are just itself and 1
        {
            primes[0] = i; // find ps
            break;
        }
    }

    // Find pl
    for (int i = p + 1;; i++) // Find forward
    {
        flag = 0;
        for (int j = 1; j <= i; j++) // Find factors
        {
            if (i % j == 0)
                flag++; // flag means the number of factors
        }
        if (flag == 2) // when the factors of i are just itself and 1
        {
            primes[1] = i; // find pl
            break;
        }
    }
    return primes;
}

/*
int main(void)
{
    int p;
    cin >> p;
    int* primes;
    primes = showPrime(p);
    cout << "primes[0] =" << primes[0] << endl << "primes[1] =" << primes[1];
}
*/
