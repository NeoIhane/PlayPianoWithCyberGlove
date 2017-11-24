#pragma once
#define CMIDI_H
#ifdef CMIDI_H
#include<conio.h>
#include<stdio.h>
#include<Windows.h>
#include<MMSystem.h>

class CMidi
{
public:


	HMIDIOUT device;
	union{unsigned long word;unsigned char data[4];}message;

	CMidi(void);
	~CMidi(void);

	int Connect(int argc,char** argv);
	int Connect();
	void PlaySound(int key,int octive);
	void ChangeInstrument (int  instrument);
	void Closed();
private:
	int 
		ckey,notestate,velocity,midiport,flag;
	void SendMidi();
};

#endif
