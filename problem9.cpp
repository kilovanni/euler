#include<iostream>
#include<cmath>
#include<ctime>

using std::cout;
using std::endl;
using std::pow;

int main(void)
{
    std::clock_t start;
    double duration;

    start = std::clock();

    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < i; j++) {
            if ((1000-i-j) + i + j == 1000 && 
                    pow(1000-i-j,2) == pow(i,2)+ pow(j,2)) {

                cout << i << endl;
                cout << j << endl;
                cout << 1000 - i -j << endl;
            }
        }
    }

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "Time elapsed: " << duration << "s" << endl;

    return 0;
}
