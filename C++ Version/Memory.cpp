#include "Memory.h"

using namespace std;

Memory::Memory()
{
    Clear();
    srand(time(0));
}

Memory::~Memory()
{
    //dtor
}

void Memory::Options(bool MBR[8],int &cMBR)
{
    int choice,address;
    while(1)
    {
        system("cls");
        cout << "Memory Option Menu";
        cout << "\n1:Set A Memory Address Value";
        cout << "\n2:Print Out Memory Table";
        cout << "\n3:Clear Memory";
        cout << "\n4:Initialize Memory In Order";
        cout << "\n5:Randomize Memory";
        cout << "\n6:Return";
        cout << "\nSelect An Option:";
        cin >> choice;
        switch(choice)
        {
            getaddress:
            case 1: cout << "\nSelect The Memory Address from 0-" << MaxMemory-1 << ": ";
                    cMBR=1;
                    cin >> address;
                    if (address>0-1 && address<MaxMemory-1)
                    {

                    value:
                        cout << "\nEnter the value to be loaded into Memory from 0-255: ";
                        cin >> choice;
                        if (choice>=0 && choice<256)
                        {
                            for(int i=7;i>=0;i--)
                            {
                                MBR[i] += choice%2;
                                choice -= MBR[i];
                                choice /= 2;
                            }
                            Store(address,MBR);
                        }
                        else{
                            cout << "\n INVALID INPUT!";
                            goto value;
                        }
                    }
                    else{
                        cout << "\n INVALID INPUT!";
                        goto getaddress;
                    }
                    cout << "\nValue Loaded\n";
                    system("pause");
                    cMBR=0;
                    break;

            case 2: Print();
                    cout << endl;
                    system("pause");
                    break;
            case 3: Clear();
                    cout << "\nMemory Cleared\n";
                    system("pause");
                    break;
            case 4: Initialize();
                    cout << "\nMemory Initialized\n";
                    system("pause");
                    break;
            case 5: Randomize();
                    cout << "\nMemory Randomized\n";
                    system("pause");
                    break;
            case 6: return;
            default:cout << "INVALID RESPONSE!\n";
                    system("pause");
                    system("cls");
                    break;
        }
    }
}
int Memory::getmax()
{
    return MaxMemory;
}

void Memory::Load(int index, bool MBR[8])
{
    for(int i=0;i<8;i++)
    {
        MBR[i] = MainMemory[index][i];
    }
}
void Memory::Store(int index, bool MBR[8])
{
    for(int i=0;i<8;i++)
    {
        MainMemory[index][i] = MBR[i];
    }
}
void Memory::Print()
{
    char hex;
    std::cout << "Memory Table";
    for(int i=0;i<MaxMemory;i++)
    {
        if(i%16 == 0)
        {
            std::cout << std::endl;
            if(i<10) std::cout << 0;
            if(i<100) std::cout << 0;
            std::cout << i << ": ";
        }
        hex=0;
        for(int j=0;j<4;j++)
        {
            hex += pow(2,3-j)*MainMemory[i][j];
        }
        if(hex<10) hex += 48;
        else hex += 55;
        std::cout << hex;

        hex=0;
        for(int j=4;j<8;j++)
        {
            hex += pow(2,7-j)*MainMemory[i][j];
        }
        if(hex<10) hex += 48;
        else hex += 55;
        std::cout << hex << " ";
    }
}
void Memory::Clear()
{
    for(int i=0;i<MaxMemory;i++)
    {
        for(int j=0;j<8;j++)
        {
            MainMemory[i][j]=0;
        }
    }
}
void Memory::Randomize()
{
    for(int i=0;i<MaxMemory;i++)
    {
        for(int j=0;j<8;j++)
        {
            MainMemory[i][j]=rand()%2;
        }
    }
}
void Memory::Initialize()
{
    for(int i=0;i<MaxMemory;i++)
    {
        int value=i%256;
        for(int i=7;i>=0;i--)
        {
            temp[i]=value%2;
            value -= temp[i];
            value /= 2;
        }
        Store(i,temp);
    }
}
