#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;
matrix::matrix()
{
    row = 0 ;
    col = 0 ;
    data = 0;
}
matrix::matrix (int r, int c, int num[])
{
    row = r;
    col = c;
    data = new int* [r];

    for (int i = 0; i < r; i++)
        data[i] = new int [c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            data[i][j] = num[i * c + j];
        }
    }


}

/*matrix matrix:: operator= (const matrix &mat)
{
    row = mat.row;
    col = mat.col;
    arr = new int*[mat.row];

    for (int i = 0; i < mat.row * mat.col; i++)
    {
        arr[i] = mat.data[i];
    }

}*/

int matrix :: get_row ()
{
    return  row;
}


int matrix :: get_col()
{
    return  col;
}


int matrix :: get_data()
{
    return  **data;
}


// STUDENT 1 WORK THE 6 OPERATORS

matrix matrix::operator+ ( matrix& mat)
{

    int*arr = new int [mat.row * mat.col] ;
    matrix temp(mat.row, mat.col, arr)  ;

    // Test for the two matrices to know if you can add them or not
    if ( mat.row == row && mat.col == col)
    {
        // loop to add the two crossponding elements
        for(int i=0; i < mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                temp.data[i][j] = mat.data[i][j] + data[i][j] ;
            }
        }

    }
    else
    {
        cout << "Enter two square matrices to make this operator" << endl;
    }



    return temp ;

}


matrix matrix::operator-  (matrix& mat)
{
    // Test for the two matrices to know if you can sub them or not

    int*arr = new int [mat.row * mat.col] ;
    matrix temp(mat.row, mat.col, arr)  ;

    if ( mat.row == row && mat.col == col )
    {
        // loop to sub the two crossponding elements
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                temp.data[i][j] = mat.data[i][j] - data[i][j] ;
            }
        }

    }
    else
    {
        cout << "Enter two square matrices to make this operator" << endl;
    }



    return temp;

}

matrix matrix::operator*  (matrix& mat)
{
    // Test to know if you can multibly the two matrices
    int*arr = new int [mat.row * mat.col] ;
    matrix temp(mat.row, mat.col, arr)  ;

    if(mat.row == col)
    {

        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                temp.data[i][j] = 0 ;
                temp.data[i][j] = mat.data[i][j] + ( mat.data[i][j] * data[j][i] );
            }



        }
    }

    else
    {
        cout << "Enter two another matrices to make this operator" << endl;
    }
    return temp;
}

matrix matrix::operator+  ( int scalar )
{
    // loop to add the scalar to every element in the matrix
    int*arr = new int [row * col] ;
    matrix temp(row, col, arr)  ;
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < col; j++)
        {
            temp.data[i][j] = data[i][j] + scalar   ;
        }
    }
    return temp  ;
}

matrix matrix::  operator-  ( int scalar )
{

    // loop to sub the scalar to every element in the matrix
    int*arr = new int [row * col] ;
    matrix temp(row, col, arr)  ;

    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            temp.data[i][j] = data[i][j] - scalar;
        }
    }
    return temp;
}

matrix matrix:: operator*  ( int scalar)
{
    // loop to multiply the scalar to every element in the matrix
    int*arr = new int [row * col] ;
    matrix temp(row, col, arr)  ;

    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            temp.data[i][j] = data[i][j] * scalar;
        }
    }
    return temp;
}


// STUDENT 2 WORK THE 6 OPERATORS

matrix matrix :: operator+= ( matrix& mat1 )
{

    // Test for the two matrices to know if you can add them or not
    if (mat1.row == row && mat1.col == col)
    {
        // loop to add the two crossponding elements
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                data[i][j] += mat1.data[i][j] ;
            }
        }

    }
    else
    {
        cout << "Enter two square matrices to make this operator" << endl;
    }
    return *this;
}

matrix matrix :: operator-= ( matrix& mat )
{

    // Test for the two matrices to know if you can sub them or not
    if ( mat.row == row && mat.col == col )
    {
        // loop to sub the two crossponding elements
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                data[i][j] = mat.data[i][j] - data[i][j] ;
            }
        }

    }
    else
    {
        cout << "Enter two square matrices to make this operator" << endl;
    }

    return *this;
}

matrix matrix :: operator += ( int scalar)
{
    // loop to add the scalar to every element of the matrix
    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            data[i][j] += scalar;
        }
    }
    return *this;
}
matrix matrix :: operator-= ( int scalar)
{
    // loop to the scalar to every element of the matrix

    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            data[i][j] -= scalar;
        }
    }
    return *this;
}

matrix  matrix :: operator++ (int scalar)
{
    // loop to add one to every element in the matrix
    scalar = 1;
    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            data[i][j] += scalar ;
        }
    }
    return *this ;
}

matrix  matrix :: operator-- (int scalar)
{
    scalar = 1 ;
    // loop to sub one to every element in the matrix
    for(int i=0; i< row; i++)
    {
        for(int j=0; j< col; j++)
        {
            data[i][j] -= scalar;
        }
    }
    return *this;
}


std::istream& operator>> (istream& in, matrix& mat)
{
    // First input the number of rows then the number of col
    cout << " Please enter the number of rows and then press enter" << endl<<endl;
    in >> mat.row ;
    cout << " Please enter the number of coloumns and then press enter" << endl << endl;
    in >> mat.col;
    cout << " Please enter the elements of the matrix" << endl << endl;
    // loop to add the elements to a matrix
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++ )
        {
            in >> mat.data[i][j];
        }
    }
    return in;



}

std::ostream& operator<< (ostream& out, matrix mat )
{

    // loop to output the elements of the matrix to the screen
    for(int i=0; i < mat.row; i++)
    {
        for(int j=0; j < mat.  col; j++)
        {
            out << setw(6) << mat.data[i][j] ;
        }
        cout<<endl;
    }
    return out;
}

bool matrix::operator== (matrix & mat1)
{
    // Create a variable to check the operator is true or not
    // loop on every two crossponding elements in the two matrices
    // to know they are equal or not

    bool check = true;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if( data[i][j] != mat1.data[i][j] )
            {
                check = false;
                break;
            }

        }
    }
    return check;

}

bool matrix::operator!= (matrix& mat1)
{
    // Create a variable to check the operator is true or not
    // loop on every two crossponding elements in the two matrices
    // to know they are not equal or not
    bool check = true;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(data[i][j] != mat1.data[i][j])
            {

                continue;
            }
            else
            {
                check = false;
                break;
            }
        }
    }
    return check;
}

bool matrix::isSquare (matrix& mat)
{
    // Create a variable to check the operator is true or not
    // compare the row and of the matrix to know it is square or not
    bool check = true;
    if(mat.row != mat.col)
    {
        check = false;
    }
    return check;

}

bool matrix::isSymetric(matrix& mat)
{
    bool check = true;

    if(mat.row == mat.col)
    {
        for(int i = 0; i < mat.row; i++)
        {
            for(int j = 0; j < mat.col; j++)
            {
                if(i+1 == mat.row && j+1 == mat.col)
                {
                    break;
                }
                if(j+1 == mat.col)
                {
                    continue;
                }
                if(mat.data[i][j+1] != mat.data[j+1][i])
                {
                    check = false;
                    break;
                }
            }
        }
    }

    else
    {
        check = false;
    }
    return check;
}

bool matrix::isIdentity (matrix& mat)
{
    // Compare every element in the matrix to one

    bool check = true;

    if(row == col){
        for(int i = 0; i < row; i++){
            if(data[i][i] != 1){
                check == false;
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(j+1 == col){
                    continue;
                }
                if(data[i][j+1] != data[j+1][i] != 0){
                    check = false;
                    break;
                }
            }
        }
    }

    else{
        check = false;
    }
    return check;
}

matrix matrix::transpose(matrix& mat)
{

    // Creat anaother matrix to transpose the target matrix
    int*arr = new int [mat.row * mat.col];
    matrix transpose_mat(mat.col, mat.row, arr);



    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            transpose_mat.data[j][i] = mat.data[i][j];
        }
    }




    return transpose_mat;

}




matrix::~matrix()
{
    // delete[] data  ;
}
