#include "CyberGlove.h"


CyberGlove::CyberGlove(void)
{
	reset();
}


CyberGlove::~CyberGlove(void)
{
}
void CyberGlove::connect()
{
	open=OpenSerial();
}
void CyberGlove::update()
{
	char g='g';
	if(open==1)
	{
		tests.Write(&g,1);
		int DataRead=ReadSerial();
	}
}
void CyberGlove::reset()
{
	for(int i=0;i<18;i++)
	{
		data[i]=0;
		offset[i]=0;
		gain[i]=0;
	}
	open=0;
	offset[0]=181; gain[0]=23;
	offset[1]=179; gain[1]=43;
	offset[2]=162; gain[2]=46;
	offset[3]=105; gain[3]=105;
	offset[4]=149; gain[4]=66;
	offset[5]=146; gain[5]=61;
	offset[8]=151; gain[8]=62;
	offset[9]=159; gain[9]=45;
	offset[11]=95; gain[11]=68;
	offset[12]=162; gain[12]=60;
	offset[13]=152; gain[13]=34;
	offset[15]=104; gain[15]=69;
	offset[16]=153; gain[16]=56;
	offset[17]=145; gain[17]=51;

}
int CyberGlove::OpenSerial()
{
	int temp = 0;
	char port[6];
	strcpy_s(port, "COM3");
	if(tests.Open((LPCSTR)port, 115200))
	{
		cout << "Serial Ok\n";
		temp = 1;
	}
	else 
		cout << "Serial Error " << port;
	
	return temp;
}
int CyberGlove::ReadSerial()
{
	int temp = 0;
	char g;
	tests.Read(&g, 1);
	if(g=='g')
	{
		while(temp <18 )
		{ 
			char set[4];
			int value=0;
			for(int i=0;i<4;i++)
			{
				char c;
				tests.Read(&c, 1);
				set[i]=c;
				if(c!=' ')
				{
					switch(i)
					{
						case 0:;break;
						case 1:value+=((int)c-48)*100;break;
						case 2:value+=((int)c-48)*10;break;
						case 3:value+=((int)c-48);break;
					}
					
				}
			}

			//printf("%d:%c :%c :%c :%c =%d\n",temp,set[0],set[1],set[2],set[3],value);
			data[temp]=value;
			temp++;
		}
	}
	return temp;
}