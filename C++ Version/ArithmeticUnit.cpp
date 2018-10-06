#include "ArithmeticUnit.h"

ArithmeticUnit::ArithmeticUnit()
{
    //ctor
}

ArithmeticUnit::~ArithmeticUnit()
{
    //dtor
}
bool* ArithmeticUnit::Add(bool A[8], bool B[8],bool (&ccr)[4])
{
    ClearCarry();
    for(int i=7;i>=0;i--)
        {
            adder(A[i],B[i],i);
        }
    FlagUpdate(ccr);
    return temp;
}
bool* ArithmeticUnit::AddWithCarry(bool A[8], bool B[8],bool (&ccr)[4])
{
    ClearCarry();
    carry[8]=1;
    for(int i=7;i>=0;i--)
        {
            adder(A[i],B[i],i);
        }
    FlagUpdate(ccr);
    return temp;
}
bool* ArithmeticUnit::Sub(bool A[8], bool B[8],bool (&ccr)[4])
{
    ClearCarry();
    carry[8]=1;
    for(int i=7;i>=0;i--) adder(A[i],!B[i],i);
    FlagUpdate(ccr);
    return temp;
}
bool* ArithmeticUnit::Increment(bool A[8],bool (&ccr)[4])
{
    ClearCarry();
    carry[8]=1;
    for(int i=7;i>=0;i--) adder(A[i],0,i);
    FlagUpdate(ccr);
    return temp;
}
void ArithmeticUnit::FlagUpdate(bool (&ccr)[4])
{
    ccr[0] = temp[0];

    for(int i=0;i<8;i++)
    {
        ccr[1] += temp[i];
    }
    ccr[1] = !ccr[1];

    if(carry[0]==carry[1])ccr[2]=0;
    else ccr[2]=1;

    ccr[3] = carry[0];
}
void ArithmeticUnit::adder(bool A, bool B, int i)
{
    if((carry[i+1] && A) || (carry[i+1] && B) || (A && B))
    {
        carry[i] = 1;
    }
    int XOR=0;
    if (carry[i+1] != A)
    {
        XOR = 1;
    }
    if (B == XOR)
    {
        XOR = 0;
    }
    else
    {
        XOR=1;
    }
    temp[i]=XOR;
}
void ArithmeticUnit::ClearCarry()
{
    for(int i=0;i<9;i++)
        {
            carry[i]=0;
        }
}
