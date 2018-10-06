#include "LogicUnit.h"

LogicUnit::LogicUnit()
{
    //ctor
}

LogicUnit::~LogicUnit()
{
    //dtor
}
bool* LogicUnit::And(bool A[8], bool B[8],bool (&ccr)[4])
{
    for(int i=0;i<8;i++)
    {
        if(A[i]==1 && B[i]==1) temp[i]=1;
        else temp[i]=0;
    }
    FlagUpdate(ccr);
    return temp;
}
bool* LogicUnit::Or(bool A[8], bool B[8],bool (&ccr)[4])
{
    for(int i=0;i<8;i++)
    {
        if(A[i]==1 || B[i]==1) temp[i]=1;
        else temp[i]=0;
    }
    FlagUpdate(ccr);
    return temp;
}
bool* LogicUnit::Xor(bool A[8], bool B[8],bool (&ccr)[4])
{
    for(int i=0;i<8;i++)
    {
        if(A[i]==B[i]) temp[i]=0;
        else temp[i]=1;
    }
    FlagUpdate(ccr);
    return temp;
}
bool* LogicUnit::Compliment(bool A[8],bool (&ccr)[4])
{
    for(int i=0;i<8;i++)
    {
        temp[i] = !A[i];
    }
    FlagUpdate(ccr);
    return temp;
}
void LogicUnit::FlagUpdate(bool (&ccr)[4])
{
    ccr[0]=temp[0];
    ccr[2]=0;
    ccr[3]=0;
    for(int i=0;i<8;i++)
    {
        ccr[1] += temp[i];
    }
    ccr[1] = !ccr[1];
}
