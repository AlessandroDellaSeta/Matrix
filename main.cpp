#include <iostream>
using namespace std;
class Matrix {
private:
    double *m;
    int rows, cols;
public:
    Matrix(const Matrix &orig) : rows(orig.rows), cols(orig.cols), m(new double[rows][cols]) {
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++) {
                m[i] = orig.m[i];
            }
        }
    }
/*
    0 1 2 3
4 5 6 7
    8 9 10 11
 */
    double& 	operator ()(int i, int j)  {
        return m[i*cols + j];
    }
    double 	operator ()(int i, int j)const {
        return m[i*cols + j];
    }
    friend ostream& operator <<(ostream& s, const Matrix& mat){
        for (int i = 0; i < mat.rows; i++){
            for (int j = 0; j < mat.cols; j++) {
               s << mat.m[i];
            }
};


int main() {

    /**
         0.0  0.0  0.0  0.0
         0.0  0.0  0.0  0.0
         0.0  0.0  0.0  0.0
     */
    Matrix a(3,4);  // single block of memory 3 * 4 set all to 0.0

    a(1,1) = 1.5;
    a(2,1) = 3.2;
    /**
     0.0  0.0  0.0  0.0
     0.0  1.5  0.0  0.0
     3.2  0.0  0.0  0.0
 */

    cout << a(1,2) << '\n';

    cout << a;

    Matrix b(3,4,1.5); // set all values to 1.5
    Matrix c = a + b;
    Matrix d(4,3,2.5);
    Matrix e = b * d; // matrix  mult.
}
