#ifndef ARITHMETICUNIT_H
#define ARITHMETICUNIT_H


class ArithmeticUnit
{
    public:
        ArithmeticUnit();
        virtual ~ArithmeticUnit();
        bool* Add(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* AddWithCarry(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Sub(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Increment(bool A[8],bool (&ccr)[4]);

    protected:

    private:
        bool carry[9];
        bool temp[8];
        void ClearCarry();
        void  FlagUpdate(bool (&ccr)[4]);
        void adder(bool A, bool B, int i);

};

#endif // ARITHMETICUNIT_H
