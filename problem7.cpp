#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
 * Computes the desired nth prime number using the Sieve of Sundaram.
 */
int main(void)
{
    int i = 1;
    int upperlimit = 101;
    int increment = 100;
    int desirednthprime = 10001;
    vector<int> primes{2};
    list<int> numbers;

    while(primes.size() < desirednthprime) {

        while (i < upperlimit) {
            numbers.push_back(i);
            i++;
        }

        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= j; k++) {
                if (j + k + 2*j*k > upperlimit) {
                    break;
                }
                numbers.remove(j + k + 2*j*k);
            }
        }

        for (auto e : numbers) {
            primes.push_back(e*2 +1);
        }

        upperlimit += increment;
        numbers.clear();
    }

    cout << "Total primes calculated: " <<primes.size() << endl;
    cout << desirednthprime << "st prime is: " 
            <<  primes[desirednthprime -1] << endl;

    return 0;
}
