#ifndef LOGICUNIT_H
#define LOGICUNIT_H


class LogicUnit
{
    public:
        LogicUnit();
        virtual ~LogicUnit();
        bool* And(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Or(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Xor(bool A[8], bool B[8],bool (&ccr)[4]);
        bool* Compliment(bool A[8],bool (&ccr)[4]);
    protected:

    private:
        void  FlagUpdate(bool (&ccr)[4]);
        bool temp[8];
};

#endif // LOGICUNIT_H
