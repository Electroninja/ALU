#pragma once

#include "ofMain.h"

#include <iostream>
#include <ArithmeticLogicUnit.h>
#include <Shifter.h>
#include <Memory.h>

class ofApp : public ofBaseApp, public ofThread{
	public:
		void setup();
		void draw();

        void PrintWithLabel(bool in[],char label[],int length);
        bool A[8] = {};                     //Register A
        bool B[8] = {};                     //Register B
        bool * MBR = (bool *) malloc(8);    //Memory Buffer Register
        bool ccr[4] = {0,0,0,0};            //Condition Code Register
        ArithmeticLogicUnit ALU;            //Arithmetic Logic Unit
        Shifter SHIFTER;                    //Shifter
        Memory MainMemory;                  //Scratch Memory
        int choice;
        bool shift;

        int Mem,RA,RB,cALU,cAU,cLU,cShifter,cMBR;
		void threadedFunction();
};
