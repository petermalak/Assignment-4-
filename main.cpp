#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    matrix one ;
    bool test = true ;
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {2,2,2,2};
    int data5 [] = {1,0,0,1};

    matrix mat1 (4, 2, data1);
    matrix mat2 (2, 3, data2);
    matrix mat3 (4, 2, data3);
    matrix mat4 (2, 2, data4);
    matrix mat5 (2, 2, data5);

    return 0;
}
