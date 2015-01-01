#include<armadillo>
#include<iostream>
#include<ctime>

using std::cout;
using std::endl;
using std::stoi;
using std::time_t;
using std::clock;

using arma::Mat;

int Product(Mat<int>);
int DiagProduct(Mat<int>);
int AntiDiagProduct(Mat<int>);

int main(int argc, char *argv[])
{
    if(argc < 3) {
        cout << "Too few arguments, aborting." << endl;
        return 1;
    }
    else if ( argc > 3) {
        cout << "Too many arguments, aborting." <<endl;
        return 1;
    }

    Mat<int> A(20,20);
    Mat<int> V;

    
    if (!A.load(argv[1])) {
        return 2;
    }

    if (!A.is_square()) {
        cout << "Specified matrix is not square, aborting." << endl;
        cout << A << endl;
        return 3;
    }
    
    int prodLen = stoi(argv[2]);
    int msize = A.n_rows;
    
    if (prodLen > msize || prodLen <= 0) {
        cout << "Bad product length: " << prodLen <<endl;
        return 4;
    }

    prodLen--;

    int greatest_prod = 1;

    time_t start;
    double duration;
    start = clock();

    for (int r1 = 0, r2 = prodLen; r2 < msize; r1++, r2++) {
        for (int c1 = 0, c2 = prodLen; c2 < msize; c1++, c2++) {
            V = A.submat(r1, c1, r2, c2);

            greatest_prod = greatest_prod < DiagProduct(V) ? 
                DiagProduct(V) : greatest_prod;

            greatest_prod = greatest_prod < AntiDiagProduct(V) ? 
                AntiDiagProduct(V) : greatest_prod;

            V = A.submat(r1, c1, r1, c2);

            greatest_prod = greatest_prod < Product(V) ? 
                Product(V) : greatest_prod;

            V = A.submat(r1, c1, r2, c1);

            greatest_prod = greatest_prod < Product(V) ? 
                Product(V) : greatest_prod;
        }
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << "The greatest product is: " << greatest_prod << endl;
    cout << "Time elapsed: " << duration << "s." << endl;

    return 0;
}

int Product(Mat<int> M)
{
    int product = 1;
    
    for (int e : M){
        product *= e;   
    }

    return product;
}

int DiagProduct(Mat<int> M) 
{
    int product = 1;

    for (int i = 0; i < (int)M.n_rows; i++) {
        product *= M(i,i);       
    }

    return product;
}

int AntiDiagProduct(Mat<int> M) 
{
    int product = 1;

    for (int i = 0; i < (int)M.n_rows; i++) {
        product *= M((M.n_rows -1) - i,i);       
    }

    return product;
}
