#include "Shifter.h"

Shifter::Shifter()
{
    //ctor
}

Shifter::~Shifter()
{
    //dtor
}
void Shifter::selector(bool A[8], bool (&ccr)[4])
{
    int choice;
    bool shift;
    top:
        system("cls");
        cout << "Shift Operations";
        cout << "\n1:NO SHIFTS";
        cout << "\n2:Shift Left";
        cout << "\n3:Shift Right";
        cout << "\n4:Zero Input";
        cout << "\nSelect An Option:";
        cin >> choice;
        switch(choice)
        {
            case 1: break;
            case 2: cout << "Input Left Shift Value (0-1): ";
                    cin >> shift;
                    if(shift != 0 && shift != 1)
                    {
                        cout << "\nInvalid Input";
                        goto top;
                    }
                    ShiftLeft(A,ccr,shift);
                    cout << "\nShiftLeft";
                    break;
            case 3: cout << "Input Right Shift Value (0-1): ";
                    cin >> shift;
                    if(shift != 0 && shift != 1)
                    {
                        cout << "\nInvalid Input";
                        goto top;
                    }
                    ShiftRight(A,ccr,shift);
                    cout << "\nShiftRight";
                    break;
            case 4: Clear(A,ccr);
                    cout << "\nCleared Input";
                    break;
            default:cout << "INVALID RESPONSE!\n";
                    system("pause");
                    system("cls");
                    goto top;
        }
        PrintWithLabel(A,"Output",8);
        PrintWithLabel(ccr,"ccr",4);
        cout << endl;
        return;
}
void Shifter::PrintWithLabel(bool in[],char label[],int length)
{
    cout << endl << label << ": ";
    for(int i=0;i<length;i++)
    {
        cout << in[i];
    }
    return;
}
void Shifter::ShiftLeft(bool A[8], bool (&ccr)[4], bool LeftShift)
{
    carry = A[0];
    for(int i=0;i<6;i++)
    {
        A[i]=A[i+1];
    }
    A[7]=LeftShift;

    if(carry==A[0])ccr[2]=0; ///Shift Left OverFlow Flag
    else ccr[2]=1;           ///
    FlagUpdate(A,ccr);
}
void Shifter::ShiftRight(bool A[8], bool (&ccr)[4], bool RightShift)
{
    carry = A[7];

    for(int i=6;i>=0;i--)
    {
        A[i+1]=A[i];
    }
    A[0]=RightShift;

    if(A[0]==A[1])ccr[2]=0;///Shift Right OverFlow Flag
    else ccr[2]=1;         ///
    FlagUpdate(A,ccr);
}
void Shifter::Nothing()
{
}
void Shifter::Clear(bool A[8], bool (&ccr)[4])
{
    carry=0;
    for(int i=0;i<8;i++)
    {
        A[i]=0;
    }

    ccr[2]=0;              ///Clear OverFlow Flag Because Cleared everything
    FlagUpdate(A,ccr);
}
void Shifter::FlagUpdate(bool A[8], bool (&ccr)[4])
{
    ccr[0] = A[0];

    for(int i=0;i<8;i++)
    {
        ccr[1] += A[i];
    }
    ccr[1] = !ccr[1];

    ccr[3] = carry;
}
