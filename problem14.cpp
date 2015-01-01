#include<iostream>
#include<vector>

using namespace std;

/*
 * Finds the largest starting number, under one million, that generates the
 * largest Collatz sequence.
 */
int main(void) 
{
    int longestSeq = 0;
    int startingNumb = 0;
    unsigned int n;
    vector<unsigned int> sequence;

    for(int i = 1; i < 1e6; i++) {
        n = i;

        while(n != 1) {
            if (n % 2 == 0) {
                sequence.push_back(n/2);
                n /= 2;
            } else {
                sequence.push_back(3*n + 1);
                n = 3*n + 1;
            }
        }

        if (sequence.size() > longestSeq) {
            startingNumb = i;
            longestSeq = sequence.size();
        }

        sequence.clear();
    }

    cout << "The longest sequence was generated with starting number: " 
        << startingNumb << ", and length: " << longestSeq + 2 << "." << endl;
    // The "+2" is due to the fact, that our above code does not include
    // the starting number itself, and 1, in the generated sequence.

    return 0;
}
