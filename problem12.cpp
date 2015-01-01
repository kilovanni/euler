#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

/*
 * Finds the first triangle number to have over 500 divisors.
 * Triangle numbers: 1; 1,3; 1,3,6; 1,3,6,10; ...
 */
int main(void)
{
    vector<int> trianlgeNumbers{1};

    int foundDivs = 1;
    int firstTriNum = 0;
    int largestSoFar = 0;

    // Generate some triangle numbers
    for(int i = 2; i <= 120000; i++) {
        trianlgeNumbers.push_back(*(trianlgeNumbers.end()-1) + i);
    }

    // Test divisors
    for (int e : trianlgeNumbers) {
        for (int i = 1; i <= sqrt(e)+1; i++) {
            if(e % i == 0) {foundDivs += 2;} 
        }

        if (foundDivs > 500) {
            firstTriNum = e;
            break;
        }

        largestSoFar = largestSoFar < foundDivs ? foundDivs : largestSoFar;

        foundDivs = 1;
    }

    if (foundDivs == 1) {
        cout << "You're out of luck!" << endl;
        cout << "Most divisors found: " << largestSoFar << endl;
    } else {
        cout << "Found it! " << firstTriNum << endl;
    }

    return 0;
}
