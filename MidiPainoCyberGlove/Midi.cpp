#include "Midi.h"


CMidi::CMidi(void)
{
	message.data[0]=0x90;
	message.data[1]=60; 
	message.data[2]=100;
	message.data[3]=0;
}


CMidi::~CMidi(void)
{

}
void CMidi::Closed()
{
	midiOutReset(device);
	midiOutClose(device);
}
void CMidi::SendMidi()
{
	flag=midiOutShortMsg(device,message.word);
	if(flag!=MMSYSERR_NOERROR)
	{
		printf("Warning: MIDI Output is not open.\n");
	}
}
int CMidi::Connect(int argc,char** argv)
{
	if(argc<2)
	{
		midiport=0;
	}else
	{
		midiport=atoi(argv[1]);
	}
	printf("MIDI output port set to %d.\n",midiport);
	flag=midiOutOpen(&device,midiport,0,0,CALLBACK_NULL);
	if(flag!=MMSYSERR_NOERROR)
	{
		printf("Error opening MIDI Output.\n");
		return 1;
	}
}
int CMidi::Connect()
{

	midiport=0;

	printf("MIDI output port set to %d.\n",midiport);
	flag=midiOutOpen(&device,midiport,0,0,CALLBACK_NULL);
	if(flag!=MMSYSERR_NOERROR)
	{
		printf("Error opening MIDI Output.\n");
		return 1;
	}
}
void CMidi::PlaySound(int key,int octive)
{
	message.data[0]=0x90;
	message.data[1]=key; 
	message.data[2]=100;
	message.data[3]=0;

	CMidi::SendMidi();
}

void CMidi::ChangeInstrument(int  instrument)
{
	message.data[0]=0xC0;
	message.data[1]=instrument; 
	message.data[2]=100;
	message.data[3]=0;
	CMidi::SendMidi();
}