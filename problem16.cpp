#include<iostream>
#include<cmath>

using  namespace std;

/* 
 * Calculates the power digit sum on 2^1000.
 */
int main(void)
{
    double big = pow(2,1000);   
    int sum = 0;

    string digs = to_string(big);
    auto pos = digs.find(".");
    
    for(int i = 0; i != (int)pos; i++ ){
        sum += digs[i] - '0';
    } 

    cout << "The power digit sum of 2^100 is: " << sum << endl;

    return 0;
}
