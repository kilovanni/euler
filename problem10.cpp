#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using std::cout; 
using std::endl; 
using std::vector;
using std::floor;
using std::round;
using std::sqrt;

bool isPrime(unsigned long int);

/*
 * Computes the sum of all primes below one million.
 */
int main(void)
{
    std::clock_t start;
    double duration;
    start = std::clock();

    vector<unsigned long int> primes{2,3,5,7};
    unsigned long int sum = 0;

    for (unsigned long int i = 10; i < 2000000; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (unsigned long int e : primes) {
        sum += e;
    }

    cout << "The sum of all primes below two million is: " << sum << endl;

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Time elapsed: " << duration << "s." << endl;

    return 0;
}

bool isPrime(register unsigned long int n) 
{
    //if(n == 2) {return true;}
    //if(n == 3) {return true;}
    if(n % 2 == 0) {return false;}
    if(n % 3 == 0) {return false;}

    unsigned long int r =  floor(sqrt(n));
    unsigned long int f = 5;
    
    while(f <= r) {
        if (n % f == 0) {return false;}
        if (n % (f + 2) == 0) {return false;}
        f += 6;
    }

    return true;
}
