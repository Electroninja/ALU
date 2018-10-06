#include "ArithmeticLogicUnit.h"

ArithmeticLogicUnit::ArithmeticLogicUnit()
{
    //ctor
}

ArithmeticLogicUnit::~ArithmeticLogicUnit()
{
    //dtor
}
bool * ArithmeticLogicUnit::Operation(bool A[8], bool B[8],bool (&ccr)[4],bool &shift,int &cAU,int &cLU,int &RB)
{
    int choice;
    top:
        system("cls");
        cout << "ALU Operations";
        cout << "\n1:ADD A & B";
        cout << "\n2:ADD A & B with Carry";
        cout << "\n3:Subtract B from A";
        cout << "\n4:Increment A";
        cout << "\n5:A AND B";
        cout << "\n6:A OR B";
        cout << "\n7:A XOR B";
        cout << "\n8:Compliment A";
        cout << "\n9:Return";
        cout << "\nSelect An Option:";
        cin >> choice;
        switch(choice)
        {
            case 1: cAU=1;
                    temp = Add(A,B,ccr);
                    cout << "\nADD";
                    break;
            case 2: cAU=1;
                    temp = AddWithCarry(A,B,ccr);
                    cout << "\nADD With Carry";
                    break;
            case 3: cAU=1;
                    temp = Sub(A,B,ccr);
                    cout << "\nSubtraction";
                    break;
            case 4: cAU=1;
                    RB=0;
                    temp = Increment(A,ccr);
                    cout << "\nIncrement";
                    break;
            case 5: cLU=1;
                    temp = And(A,B,ccr);
                    cout << "\nAND";
                    break;
            case 6: cLU=1;
                    temp = Or(A,B,ccr);
                    cout << "\nOR";
                    break;
            case 7: cLU=1;
                    temp = Xor(A,B,ccr);
                    cout << "\nXOR";
                    break;
            case 8: cLU=1;
                    RB=0;
                    temp = Compliment(A,ccr);
                    cout << "\nCompliment";
                    break;
            case 9: shift=0;
                    return temp;
            default:cout << "INVALID RESPONSE!\n";
                    system("pause");
                    system("cls");
                    goto top;
        }
        PrintWithLabel(A,"A",8);
        PrintWithLabel(B,"B",8);
        cout << "\n--------";
        PrintWithLabel(temp,"Output",8);
        PrintWithLabel(ccr,"ccr",4);
        cout << endl;
        shift=1;
        return temp;
}
void ArithmeticLogicUnit::PrintWithLabel(bool in[],char label[],int length)
{
    cout << endl << label << ": ";
    for(int i=0;i<length;i++)
    {
        cout << in[i];
    }
    return;
}
bool* ArithmeticLogicUnit::Add(bool A[8], bool B[8],bool (&ccr)[4])
{
    return AU.Add(A,B,ccr);
}
bool* ArithmeticLogicUnit::AddWithCarry(bool A[8], bool B[8],bool (&ccr)[4])
{
    return AU.AddWithCarry(A,B,ccr);
}
bool* ArithmeticLogicUnit::Sub(bool A[8], bool B[8],bool (&ccr)[4])
{
    return AU.Sub(A,B,ccr);
}
bool* ArithmeticLogicUnit::Increment(bool A[8],bool (&ccr)[4])
{
    return AU.Increment(A,ccr);
}
bool* ArithmeticLogicUnit::And(bool A[8], bool B[8],bool (&ccr)[4])
{
    return LU.And(A,B,ccr);
}
bool* ArithmeticLogicUnit::Or(bool A[8], bool B[8],bool (&ccr)[4])
{
    return LU.Or(A,B,ccr);
}
bool* ArithmeticLogicUnit::Xor(bool A[8], bool B[8],bool (&ccr)[4])
{
    return LU.Xor(A,B,ccr);
}
bool* ArithmeticLogicUnit::Compliment(bool A[8],bool (&ccr)[4])
{
    return LU.Compliment(A,ccr);
}
