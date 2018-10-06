#ifndef SHIFTER_H
#define SHIFTER_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Shifter
{
    public:
        Shifter();
        virtual ~Shifter();
        void selector(bool A[8], bool (&ccr)[4]);
    protected:

    private:
        void PrintWithLabel(bool in[],char label[],int length);
        void ShiftLeft(bool A[8], bool (&ccr)[4], bool LeftShift);
        void ShiftRight(bool A[8], bool (&ccr)[4], bool RightShift);
        void Nothing();
        void Clear(bool A[8], bool (&ccr)[4]);
        bool carry;
        void  FlagUpdate(bool A[8], bool (&ccr)[4]);
};

#endif // SHIFTER_H
