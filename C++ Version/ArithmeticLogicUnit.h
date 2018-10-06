#ifndef ArithmeticLogicUnit_H
#define ArithmeticLogicUnit_H
#include <ArithmeticUnit.h>
#include <LogicUnit.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class ArithmeticLogicUnit
{
    public:
        ArithmeticLogicUnit();
        virtual ~ArithmeticLogicUnit();
        bool* Operation(bool A[8], bool B[8],bool (&ccr)[4],bool &shift,int &cAU,int &cLU,int &RB);

    protected:

    private:
        void PrintWithLabel(bool in[],char label[],int length);
        bool* Add(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* AddWithCarry(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Sub(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Increment(bool A[8],bool (&ccr)[4]);
        bool* And(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Or(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Xor(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Compliment(bool A[8],bool (&ccr)[4]);
        bool* temp;
        LogicUnit LU;
        ArithmeticUnit AU;
};

#endif // ALU_H
