#include <iostream>
#include <cstring>
#include "BigNum.h"
using namespace std;

int main()
{
    BigNum one("256743134645854");
    BigNum two("7");
    BigNum res("36677590663693");

    cout << (one/two==res);
    return 0;
}

