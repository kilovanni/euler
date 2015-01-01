#include<iostream>

using namespace std;

/*
 * Computes the smallest integer that is divisible by all numbers in the range
 * 1..20.
 */
int main(void)
{
    bool notFound = true;
    int n = 2520;

    while (notFound) {
        
        for (int i = 1; i < 21; i++) {
            if (n % i != 0) {
                break; 
            }
            else if (i == 20 && n % i == 0) {
                notFound = false;
                cout << "Smallest integer is " << n << endl;
            }
        }

        n += 2;
    }

    return 0;
}
