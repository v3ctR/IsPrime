#include <iostream>
#include <cstring>
#include "BigNum.h"
using namespace std;

int main()
{
    BigNum kek("48602850238572");
    BigNum lel("1846602860286");
    BigNum one("");
    BigNum two("9999999");


    cout << kek*lel<< endl << one*two;
    return 0;
}

