#include<reg51.h>
#include<bujin.h>
/*
���ܣ�ʵ�ֶԲ�������Ŀ���
��������λ�ƣ������ٶ�
*/

code int positiveRe[8]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};

void run(double arc,bit direction,double speed)
{
	
	unsigned int count; 
	double time;
	unsigned int i;
	//�û��ȼ��������
	count=(arc/3.14*180)/STEP;
	//��ת�ټ�����ܵ���ʱ
	time=arc/speed;
	//����ÿһ����Լ��Ҫ����ʱ
	time=time/count;
	
	//ʵ�����彻��仯
	for(i=0;i<count;i++)
	{
		P2=0X00;
		if(direction)
		switch(i%8)
		{
			case 0:PORT=(PORT&0XF0)|positiveRe[0];break;
			case 1:PORT=(PORT&0XF0)|positiveRe[1];break;
			case 2:PORT=(PORT&0XF0)|positiveRe[2];break;
			case 3:PORT=(PORT&0XF0)|positiveRe[3];break;
			case 4:PORT=(PORT&0XF0)|positiveRe[4];break;
			case 5:PORT=(PORT&0XF0)|positiveRe[5];break;
			case 6:PORT=(PORT&0XF0)|positiveRe[6];break;
			case 7:PORT=(PORT&0XF0)|positiveRe[7];break;
		}
		else
			switch(i%8)
				{
			case 7:PORT=(PORT&0XF0)|positiveRe[0];break;
			case 6:PORT=(PORT&0XF0)|positiveRe[1];break;
			case 5:PORT=(PORT&0XF0)|positiveRe[2];break;
			case 4:PORT=(PORT&0XF0)|positiveRe[3];break;
			case 3:PORT=(PORT&0XF0)|positiveRe[4];break;
			case 2:PORT=(PORT&0XF0)|positiveRe[5];break;
			case 1:PORT=(PORT&0XF0)|positiveRe[6];break;
			case 0:PORT=(PORT&0XF0)|positiveRe[7];break;
				}
		bujinDelay(time*1000);  //�ӳ�һ��ʱ�����Ե����ٶ�
	}
}
	
	void bujinDelay_n_ms(unsigned int i)
	{
		//��ʱ���������������������ʱ��Ӧ����
	}
	
