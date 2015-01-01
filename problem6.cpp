#include <iostream>
#include <cmath>

using namespace std;

/*
 * Computes the difference between the square of the sum 1+2+3+...+100, and the 
 * sum of the squares 1^2+2^2+3^2+...+100^2.
 */
int main(void)
{
    int sum_squares = 0;
    int square_sum = 0;
    int difference = 0;

    for (int i = 1; i < 101; i++) {
        sum_squares += pow(i, 2);
        square_sum += i;
    }
    
    square_sum *= square_sum;
    difference = square_sum - sum_squares;

    cout << "The difference is: " << difference << endl;

    return 0;
}
