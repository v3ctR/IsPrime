#ifndef BIGNUM_H_
#define BIGNUM_H_
#include <vector>

class BigNum
{
public:

    BigNum() = default;
    BigNum(int k) {for(int i=0;i<k;i++) number.push_back(0);}
    BigNum(const char*);
    virtual ~BigNum() = default;
    BigNum(const BigNum& x) = default;
    BigNum(BigNum&& x) = default;
    BigNum& operator= (const BigNum& x) = default;
    BigNum& operator= (BigNum&& x) = default;

    BigNum& operator+= (const BigNum x);
    BigNum& operator-= (const BigNum x);
    BigNum& operator/= (const BigNum x);
    BigNum& operator*= (const BigNum x);
    BigNum& operator%= (const BigNum x);

    const BigNum operator+ (const BigNum x) const;
    const BigNum operator- (const BigNum x) const;
    const BigNum operator* (const BigNum x) const;
    const BigNum operator/ (const BigNum x) const;

    bool operator< (const BigNum& x) const;
    bool operator> (const BigNum& x) const;
    bool operator<= (const BigNum& x) const;
    bool operator!= (const BigNum& x) const;
    bool operator== (const BigNum& x) const;
    bool operator>= (const BigNum& x) const;

    BigNum operator++();
    BigNum operator++(int);

    BigNum operator--();
    BigNum operator--(int);

    BigNum operator+() const;
    BigNum operator-() const;

    friend std::ostream& operator<< (std::ostream& stream, const BigNum& x);

private:
    std::vector<int8_t> number;
    bool positive = true;
};

#endif // BIGNUM_H_INCLUDED
