#include "ofApp.h"

void ofApp::PrintWithLabel(bool in[],char label[],int length)
{
    cout << endl << label << ": ";
    for(int i=0;i<length;i++)
    {
        cout << in[i];
    }
    return;
}

//--------------------------------------------------------------
void ofApp::setup(){
Mem=0;
RA=0;
RB=0;
cALU=0;
cAU=0;
cLU=0;
cShifter=0;
cMBR=0;

startThread();
}

void ofApp::threadedFunction() {
    int i =0;
    while (isThreadRunning())
    {
        cout << "Welcome to My Two Port Scratch Pad Simulation.\n";
        system("pause");
        while(1)
        {
            Mem=0;
            RA=0;
            RB=0;
            cALU=0;
            cAU=0;
            cLU=0;
            cShifter=0;
            cMBR=0;
            system("cls");
            cout << "MainMenu\n\n";
            cout << "1:Load Register A\n";
            cout << "2:Load Register B\n";
            cout << "3:Load Register A&B\n";
            cout << "4:Print Values of Register A&B\n";
            cout << "5:ALU Operations\n";
            cout << "6:Manage Main Memory\n";
            cout << "7:Exit Simulator\n";
            cout << "Select An Option:";
            cin >> choice;
            switch(choice)
            {
                Aaddress:
                case 1: cout << "\nSelect The Memory Address Of The Value To Load Into A from 0-" << MainMemory.getmax()-1 << " :";
                        RA=1;
                        Mem=1;
                        cin >> choice;
                        if (choice>0-1 && choice<MainMemory.getmax())
                        {
                            MainMemory.Load(choice,A);
                        }
                        else{
                            cout << "\n INVALID INPUT!";
                            goto Aaddress;
                        }
                        PrintWithLabel(A,"A: ",8);
                        cout << endl;
                        system("pause");
                        RA=0;
                        Mem=0;
                        break;
                Baddress:
                case 2: cout << "\nSelect The Memory Address Of The Value To Load Into B from 0-" << MainMemory.getmax()-1 << " :";
                        RB=1;
                        Mem=1;
                        cin >> choice;
                        if (choice>0-1 && choice<MainMemory.getmax())
                        {
                            MainMemory.Load(choice,B);
                        }
                        else{
                            cout << "\n INVALID INPUT!";
                            goto Baddress;
                        }
                        PrintWithLabel(B,"B: ",8);
                        cout << endl;
                        system("pause");
                        RB=0;
                        Mem=0;
                        break;
                AAaddress:
                case 3: cout << "\nSelect The Memory Address Of The Value To Load Into A from 0-" << MainMemory.getmax()-1 << " :";
                        RA=1;
                        RB=1;
                        Mem=1;
                        cin >> choice;
                        if (choice<0 || choice>MainMemory.getmax())
                        {
                            cout << "\n INVALID INPUT!";
                            goto AAaddress;
                        }
                BBaddress:
                        cout << "\nSelect The Memory Address Of The Value To Load Into B from 0-" << MainMemory.getmax()-1 << " :";
                        int choice1;
                        cin >> choice1;
                        if (choice1>0-1 && choice1<MainMemory.getmax())
                        {
                            MainMemory.Load(choice,A);
                            MainMemory.Load(choice1,B);
                        }
                        else{
                            cout << "\n INVALID INPUT!";
                            goto BBaddress;
                        }
                        PrintWithLabel(A,"A: ",8);
                        PrintWithLabel(B,"B: ",8);
                        cout << endl;
                        system("pause");
                        RA=0;
                        RB=0;
                        Mem=0;
                        break;
                case 4: PrintWithLabel(A,"A: ",8);
                        PrintWithLabel(B,"B: ",8);
                        cout << endl;
                        RA=1;
                        RB=1;
                        system("pause");
                        RA=0;
                        RB=0;
                        break;
                case 5: cALU=1;
                        RA=1;
                        RB=1;
                        MBR = ALU.Operation(A,B,ccr,shift,cAU,cLU,RB);
                        if(shift)
                        {
                            system("pause");
                            RA=0;
                            RB=0;
                            cShifter=1;
                            SHIFTER.selector(MBR,ccr);
                            cMBR=1;
                            system("pause");
                        }
                        else
                        {
                            RA=0;
                            RB=0;
                            cALU=0;
                            break;
                        }
                prompt:
                        cALU=0;
                        cAU=0;
                        cLU=0;
                        cShifter=0;
                        cout << "\nWould You Like To Save The Result to Memory?(1=Yes, 0=No)\n";
                        cin >> choice;
                        switch(choice)
                        {
                            case 0: break;
                address:    case 1: Mem=1;
                                    cout << "\nChoice a Memory Address from 0-" << MainMemory.getmax()-1 << ": ";
                                    cin >> choice;
                                    if (choice>0-1 && choice<MainMemory.getmax()-1)
                                    {
                                        MainMemory.Store(choice,MBR);
                                    }
                                    else{
                                            cout << "\n INVALID INPUT!";
                                            goto address;
                                        }
                                    break;
                            default:cout << "\nINVALID INPUT!";
                                    goto prompt;
                        }
                        cMBR=0;
                        Mem=0;
                        break;
                case 6: Mem=1;
                        MainMemory.Options(MBR,cMBR);
                        Mem=0;
                        break;
                case 7: std::exit(0);
                        break;
                default:cout << "INVALID RESPONSE!\n";
                        system("pause");
                        system("cls");
                        break;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100,100 + ccr[0]*155,100);
    ofRect(60,30,20,20);

    ofSetColor(100,100+ ccr[1]*155,100);
    ofRect(85,30,20,20);

    ofSetColor(100,100+ ccr[2]*155,100);
    ofRect(110,30,20,20);

    ofSetColor(100,100+ ccr[3]*155,100);
    ofRect(135,30,20,20);

    ofSetColor(0,0,0);
    ofDrawBitmapString("Flags  N  Z  V  C",12,44);
    ///Main Memory
    ofSetColor(100,100+Mem*155,100);
    ofRect(300,50,200,100);
    ofSetColor(0,0,0);
    ofDrawBitmapString("Main Memory",350,100);

    /// Register A & B
    ofSetColor(100,100+RA*155,100);
    ofRect(300,175,95,25);

    ofSetColor(100,100+RB*155,100);
    ofRect(405,175,95,25);

    ofSetColor(0,0,0);
    ofDrawBitmapString("Register A",305,190);
    ofDrawBitmapString("Register B",410,190);

    /// ALU AU/LU

    ofSetColor(100,100+cALU*155,100);
    ofRect(300,250,200,200);

    ofSetColor(100+cAU*155,100,150);
    ofRect(312,312,75,75);

    ofSetColor(100+cLU*155,100,150);
    ofRect(412,312,75,75);

    ofSetColor(0,0,0);
    ofDrawBitmapString("ALU",390,275);
    ofDrawBitmapString("AU",340,350);
    ofDrawBitmapString("LU",440,350);

    ///Shifter

    ofSetColor(100,100+cShifter*155,100);
    ofRect(300,500,200,50);

    ofSetColor(0,0,0);
    ofDrawBitmapString("Shifter",370,530);

    ///Memory Buffer Register

    ofSetColor(100,100+cMBR*155,100);
    ofRect(350,600,100,25);

    ofSetColor(0,0,0);
    ofDrawBitmapString("MBR",383,615);

    ///LINES AND COLORING///
    ///==================///
    ///==================///

    ///memory to registers
    ofSetColor(255*RA*Mem,0,255-255*RA*Mem);
    ofLine(350,150,350,175);
    ofSetColor(255*RB*Mem,0,255-255*RB*Mem);
    ofLine(450,150,450,175);

    ///Registers to ALU
    ofSetColor(255*RA*cALU,0,255-255*RA*cALU);
    ofLine(350,200,350,250);
    ofSetColor(255*RB*cALU,0,255-255*RB*cALU);
    ofLine(450,200,450,250);

    ///Register A To Insides
    ofSetColor(255*RA*cAU,0,255-255*RA*cAU);
    ofLine(350,300,350,312);
    ofSetColor(255*RA*cLU,0,255-255*RA*cLU);
    ofLine(350,300,425,300);
    ofLine(425,312,425,300);
    ofSetColor(255*RA*(cLU||cAU),0,255-255*RA*(cLU||cAU));
    ofLine(350,250,350,300);

    ///Register B To Insides
    ofSetColor(255*RB*cLU,0,255-255*RB*cLU);
    ofLine(450,290,450,312);
    ofSetColor(255*RB*cAU,0,255-255*RB*cAU);
    ofLine(375,290,450,290);
    ofLine(375,290,375,312);
    ofSetColor(255*RB*(cLU||cAU),0,255-255*RB*(cLU||cAU));
    ofLine(450,250,450,290);

    ///ALU TO SHIFTER
    ofSetColor(255*cShifter*cAU,0,255-255*cShifter*cAU);
    ofLine(350,387,350,425);
    ofLine(350,425,399,425);
    ofSetColor(255*cShifter*cLU,0,255-255*cShifter*cLU);
    ofLine(450,387,450,425);
    ofLine(450,425,401,425);
    ofSetColor(255*cShifter*(cAU||cLU),0,255-255*cShifter*(cAU||cLU));
    ofLine(400,424,400,500);

    ///Shifter to MBR
    ofSetColor(255*cShifter*cMBR,0,255-255*cShifter*cMBR);
    ofLine(400,550,400,600);

    ///MBR to MAIN
    ofSetColor(255*Mem*cMBR,0,255-255*Mem*cMBR);
    ofLine(450,612,550,612);
    ofLine(550,100,550,612);
    ofLine(500,100,550,100);

    ///Register Values///
    ofSetColor(0,0,0);
    ofDrawBitmapString("A:",85,300);
    ofDrawBitmapString("B:",85,310);
    for(int i=0;i<8;i++) ofDrawBitmapString(ofToString(A[i]),100+7*i,300);
    for(int i=0;i<8;i++) ofDrawBitmapString(ofToString(B[i]),100+7*i,310);
}
