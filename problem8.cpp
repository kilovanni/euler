#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;

/*
 * Calculates the largest product of thirteen adjecent integers in a series of
 * integers read from a file.
 */
int main(int argc, char *argv[]) 
{
    ifstream stream(argv[1]);
    string line;
    string input;

    long unsigned int largest_prod = 0;
    long unsigned int prod = 1;

    while (getline(stream, line)) {
        input.append(line);
    }

    string::iterator head = input.begin();
    string::iterator tail = head + 13;

    while (tail < input.end() + 1) {
        for(char e : string(head, tail)){
            prod *= e - '0';
        }

        largest_prod = largest_prod < prod ? prod : largest_prod;
        
        prod = 1;
        head++;
        tail++;
    }

    cout << "The largest product is: " << largest_prod << endl;

    return 0;
}
