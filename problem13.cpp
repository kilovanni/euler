#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

/*
 * Computes the first ten digits of a very large sum of giver
 * large integers. (In an external file given as an argument)
 */
int main(int argc, char* argv[]) 
{
    ifstream s(argv[1]);
    string line;

    vector<unsigned long int> numbers;
    unsigned long int sum = 0;

    while(getline(s, line)) {
       numbers.push_back((stoul(string(line.begin(), line.begin()+12))));
    }

    for (auto e : numbers) {
        sum += e;
    }

    string s_sum = string(to_string(sum).substr(0,10));

    cout << "The first ten digits are: " << s_sum << endl;
    
    return 0;
}
