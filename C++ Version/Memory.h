#ifndef MEMORY_H
#define MEMORY_H
#include <iostream> //cout
#include <stdlib.h> //rand & system
#include <math.h>   //pow
#include <time.h>   //time

#define MaxMemory 256

class Memory
{
    public:
        Memory();
        virtual ~Memory();
        void Options(bool MBR[8],int &cMBR);
        void Load(int index, bool MBR[8]);
        void Store(int index, bool MBR[8]);
        int getmax();
    protected:

    private:
        void Print();
        void Clear();
        void Randomize();
        void Initialize();

        bool temp[8];
        bool MainMemory[MaxMemory][8];
};

#endif // MEMORY_H
