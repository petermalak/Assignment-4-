#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

class matrix
{
public:
    matrix();
    matrix (int r, int c, int num[]);
    //matrix& operator= (matrix mat);
    int get_row();
    int get_col();
    int get_data();
    //matrix operator= (const matrix &mat);
    matrix operator+ (matrix& mat);                    // TOTALLY DONE
    matrix operator-  (matrix& mat);                   // TOTALLY DONE
    matrix operator*  (matrix& mat);
    matrix operator+  ( int scalar);                    //TOTALLY DONE
    matrix operator-  ( int scalar);                    //TOTALLY DONE
    matrix operator*  ( int scalar);                    //TATALLY DONE
    matrix operator+= ( matrix& mat1 );                 //TOTALLY DONE
    matrix operator-= (matrix& mat1);                   //TOTALLY DONE
    matrix operator+= (int scalar);                     //TOTALLY DONE
    matrix operator-= (int scalar);                     //TOTALLY DONE
    matrix operator++ (int scalar);                     //TOTALLY DONE
    matrix operator-- (int scalar);                     //TOTALLY DONE
    friend istream& operator>> (istream& in, matrix& mat); // TOTALLY DONE
    friend ostream& operator<< (ostream& out, matrix mat);   // TOTALLY DONE
    bool   operator== (matrix& mat1);                        // TOTALLY DONE
    bool   operator!= (matrix& mat1);                        // TOTALLY DONE
    bool   isSquare   (matrix& mat);                         // TOTALLY DONE
    bool   isSymetric (matrix &mat);                         // TOTALLY DONE
    bool   isIdentity (matrix &mat);                        // TOTALLY DONE
    matrix transpose  (matrix &mat);




    virtual ~matrix();

protected:

private:
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;

};

#endif // MATRIX_H
