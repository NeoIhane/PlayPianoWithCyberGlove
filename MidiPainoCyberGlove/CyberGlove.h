#pragma once
#ifndef __CyberGlove_h_
#define __CyberGlove_h_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "serial.h"
#include <math.h>
using namespace std;

class CyberGlove
{
public:
	CyberGlove(void);
	~CyberGlove(void);
	int data[18];
	int offset[18];
	int gain[18];
	void connect();
	void reset();
	void update();
	int OpenSerial();
	int ReadSerial();
	FILE *file;
	Serial tests;
	int open;
	float angle(int index)
	{
				//return (gain[index]-data[index])+offset[index];
				//return (gain[index]*data[index])+offset[index];
				//return (gain[index]-data[index]);
				//return -(data[index]+50);
		return (float)(gain[index]-data[index]);
	}
};

#endif