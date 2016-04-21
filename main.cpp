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
/*
std::vector<Big> Fact::pollard_rho()
{
std::vector<Big> result;
auto G = [this](Big x) -> Big {return (x*x - 1)%this->num;};
auto GCD = [](Big a, Big b) -> Big
{
Big rem;
while (b!=0)
{
rem = a%b;
a=b;
b=rem;
}
return a;
};
//std::linear_congruential_engine lc_engine;
std::mt19937 mt_eng;
std::uniform_int_distribution<int> dist(0, 99);
auto gen_rand = std::bind(dist, mt_eng);
// std::vector<int> x_n {1,a};
// for (int i=0; i<30; i++)
// {
// x_n.push_back( G(x_n.back()) );
// }
Big tmpnum = num;
while (tmpnum%2==0)
{
tmpnum/=2;
result.emplace_back(2);
}
while (tmpnum > 1)
{
Big x = gen_rand();
Big factor = 1, x_fixed = x;
int cycle_size = 10;
while (factor == 1)
{
for (int count=1;count <= cycle_size && factor <= 1;count++) {
x = G(x);
factor = GCD(x - x_fixed, tmpnum);
}

cycle_size *= 2;
x_fixed = x;
}
result.push_back(factor);
tmpnum/=factor;
}
return result;
}*/
