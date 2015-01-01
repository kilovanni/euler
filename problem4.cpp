#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*
 * The program finds, and prints, the largest palindrome number that is the 
 * product of two smaller 3-digit integers.
 */
int main(void)
{
    vector<int> numbers;
    int largest;
    string numb;
    string revnumb;

    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
           numbers.push_back(i*j); 
        }
    }

    largest = numbers[0];

    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        numb = to_string(*it);
        revnumb = to_string(*it);
        reverse(revnumb.begin(), revnumb.end());
        if (numb.compare(revnumb) == 0) {
            largest = largest < *it ? *it : largest;
        }
    }
    
    cout << "The largest number is " << largest << endl;

    return 0;
}
