#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <deque>
#include "BigNum.h"

using namespace std;

BigNum::BigNum(const char * x)
{
    int charsize = 0;
    int k = 0; //determine push last el to vec or not (it may be '-')
    for(int i=0; i < 1000000; i++)
    {
        if(x[i]) charsize++;
        else break;
    }
    if (x[0] == '-')
    {
        positive = false;
        k=1;
    }
    for(int i = charsize-1;i>=k;i--) number.push_back(x[i] - '0');
}

std::ostream& operator<< (std::ostream& stream, const BigNum& x)
{
    if(!x.positive) stream << '-';
    for(int i=x.number.size()-1;i>=0;i--)
        stream << (int)x.number[i];
    return stream;
}

 bool BigNum::operator< (const BigNum& x) const
{
    if(this->positive!=x.positive)
        return this->positive < x.positive;
    if(this->number.size()!=x.number.size())
        return this->number.size() < x.number.size();
    else
        for(int i=x.number.size()-1;i>=0;i--)
        {
            if(this->number[i]!=x.number[i])
                return this->number[i] < x.number[i];
        }
}

 bool BigNum::operator<= (const BigNum& x) const
{
    if(*this==x)
        return true;
    else
        return *this<x;
 }

 bool BigNum::operator> (const BigNum& x) const
 {
    if(this->positive!=x.positive)
        return this->positive > x.positive;
    if(this->number.size()!=x.number.size())
        return this->number.size() > x.number.size();
    else
        for(int i=x.number.size()-1;i>=0;i--)
        {
            if(this->number[i]!=x.number[i])
                return this->number[i] > x.number[i];
        }

 }

 bool BigNum::operator>= (const BigNum& x) const
 {
    if(*this==x)
        return true;
    else
        return *this>x;
 }

 bool BigNum::operator!= (const BigNum& x) const
 {
    if(this->positive!=x.positive)
        return true;
    if(this->number.size()!=x.number.size())
        return true;
    else
        for(int i=x.number.size()-1;i>=0;i--)
        {
            if(this->number[i]!=x.number[i])
                return true;
        }
        return false;
 }

 bool BigNum::operator== (const BigNum& x) const
 {
    return !(*this!=x);
 }

 BigNum BigNum::operator+() const
 {
    BigNum output = *this;
    return output;
 }

 BigNum BigNum::operator-() const
 {
    BigNum output = *this;
    if(this->positive == false)
        output.positive = true;
    if(this->positive == true)
        output.positive = false;
    return output;
 }

BigNum BigNum::operator++()
{
    BigNum one("1");
    *this = *this + one;
    return *this;
}

BigNum BigNum::operator++(int)
{
    BigNum output = *this;
    BigNum one("1");
    *this = *this + one;
    return output;
}

BigNum BigNum::operator--()
{
    BigNum one("1");
    *this = *this - one;
    return *this;
}

BigNum BigNum::operator--(int)
{
    BigNum output = *this;
    BigNum one("1");
    *this = *this - one;
    return output;
}

 const BigNum BigNum::operator+ (const BigNum x) const
 {

	BigNum output;
	BigNum Short;
	if(this->positive == false && x.positive == false)
        output.positive = false;
    if(this->positive == false && x.positive == true)
    {
        output = *this;
        output.positive = true;
        return x - output;
    }
    if(this->positive == true && x.positive == false)
    {
        output = x;
        output.positive = true;
        return *this - output;
    }
	if( *this > x)
	{
		output = *this;
		Short = x;
		output.number.push_back(0);
	}
	else
	{
		output = x;
		Short = *this;
		output.number.push_back(0);
	}

	for(int i=0;i < Short.number.size();i++)
	{
		output.number[i] += Short.number[i];
	}

	for(int i=0;i < output.number.size()-1;i++)
	{
		if(output.number[i]/10 > 0)
		{
			output.number[i+1] += output.number[i] / 10;
			output.number[i] %= 10;
		}
	}

	while(!output.number.back())
		output.number.pop_back();

		return output;
 }

const BigNum BigNum::operator- (const BigNum x) const
{
BigNum output;
BigNum Short;
if(this->positive == true && x.positive == false)
{
    output = x;
    output.positive = true;
    return *this + output;
}
if(this->positive == false && x.positive == false)
{
    output = *this;
    output.positive = true;
    Short = x;
    Short.positive = true;
    return Short - output;
}
if(this->positive == false && x.positive == true)
{
    output = x;
    output.positive = false;
    return *this + output;
}
if(*this == x)
    {
        output.number.push_back(0);
        return output;
    }
if( *this > x)
	{
		output = *this;
		Short = x;
	}
	else
	{
		output = x;
		Short = *this;
		output.positive = false;
	}

	for(int i = 0; i < Short.number.size();i++)
	{
		output.number[i] -= Short.number[i];
	}

	for(int i = 0; i < output.number.size();i++)
	{
		if(output.number[i] < 0)
		{
			output.number[i] += 10;
			output.number[i+1]--;
		}
	}

	while(!output.number.back())
        output.number.pop_back();

	return output;
}

const BigNum BigNum::operator* (const BigNum x) const
{
	int NumSize = this->number.size() + x.number.size() + 1;
    BigNum output(NumSize);
    vector<long long> VECoutput(NumSize);
    BigNum xclone;
    if(this->positive == false && x.positive == false)
    {
        output = *this;
        output.positive = true;
        xclone = x;
        xclone.positive = true;
        return (output*xclone);
    }
    if(this->positive == true && x.positive == false)
    {
        xclone = x;
        xclone.positive = true;
        return -(*this*xclone);
    }
    if(this->positive == false && x.positive == true)
    {
            output = *this;
            output.positive = true;
            return -(output*x);
    }
	for(int i = 0; i < this->number.size(); i++)
		for(int j = 0; j < x.number.size(); j++)
			VECoutput[i+j] += this->number[i] * x.number[j];

	for(int i = 0; i < NumSize; i++)
	{
		VECoutput[i+1] += VECoutput[i]/10;
		VECoutput[i] %= 10;
	}

    for(int i = 0; i < NumSize;i++)
        output.number[i] = VECoutput[i];

    while(!output.number.back())
		output.number.pop_back();

	return output;
}

const BigNum BigNum::operator/ (const BigNum x) const
{
	BigNum output,a1;
	int diff;
	if(this->positive == false && x.positive == true)
    {
        a1 = *this;
        a1.positive = true;
        return -(a1/x);
    }
    if(this->positive == false && x.positive == false)
    {
            output = *this;
            a1 = x;
            output.positive = true;
            a1.positive = true;
            return output/a1;
    }
    if(this->positive == true && x.positive == false)
    {
        a1 = x;
        a1.positive = true;
        return -(*this/a1);
    }
	if(this->number.size() < x.number.size())
	{
		output.number.push_back(0);
		return output;
	}

	if(!x.number.back())
        return EXIT_FAILURE;

    if(*this == x)
        {
            output.number.push_back(1);
            return output;
        }

    if(this->number.size() > x.number.size())
	{


    }

    return output;


}

