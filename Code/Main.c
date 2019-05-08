#include<reg51.h>
#include<bujin.h>
#include<remoteController.h>
#include<Lcd1602.h>
#include<keyBoard.h>
#include"serialPort.h"


/********************************************************************************************
���ܣ� �ó�����ͨ����д����λ��ʵ�ֲ�������Ŀ��ƣ����Կ��Ʋ��������ת��ת��λ�ƣ�ת���ٶȣ�����ͨ�������ȸи�Ӧ����ʵ��
��������ļ�ͣ�����ܽ���������ϴ������ԣ������ļ���������������Щ����


**********************************************************************************************/
void delay(unsigned int i);
//�����յ������ݽ���ת��
void convert();

//�жϳ�ʼ������
void interInit();

//����ȫ�ֱ���
bit direction=0;
double arc=12.70;
double speed=2.2;
unsigned char dat[11];


//�������������г�����Ҫ�Ŀ�ܣ���Ҫͨ���Ժ�ı�д��ʵ��
void main()
{
	bit flag=0;

	unsigned char i;
	unsigned char symbal;
	
	
	//���ڳ�ʼ��
	serialInit();
	//lcd1602��ʼ��
	lcdInitial();
	//�жϳ�ʼ��
	interInit();
	
	P0=0x77;
	while(1)
	{

		//ͨ�����ڶ�ȡ��ؿ�������
		if(flag==0)
		{
			if(readByte()=='*')
			{
				for(i=0;i<11;i++)
				{
					dat[i]=readByte();
					
				}
				flag=1;
			}
			sendByte('*');
			for(i=0;i<11;i++)
				{
					sendByte(dat[i]);
					
				}

		}
		
		
		if(flag)
		{
		convert();  //������յ������ݣ�����ת������Ӧ�Ļ��Ⱥ��ٶȡ� 
		
		//ͨ��lcd1602��ʾ�յ�������
		processData(arc,direction,speed,dat);
		display(dat);
			
		//���ò���������г���   
		 run(arc,direction,speed);
			
			//�����־
			sendByte('*');
			flag=0;
		}
		
		
		//�����й����д��������ж�  һ����ͨ������ʵ�ֵ���ͨ��ͣ�ж� ��һ���Ǳ�������ȫ�ļ�ͣ�ж�
		//����߹�һȦ�����������ʾ
	}
	
}

void delay(unsigned int i)
{
	while(--i);
}

//ʵ�����ݵ�ת��
//�����ʽ���� 22.22522.22
void convert()
{
	unsigned int temp=0;
	unsigned char i;
	//������
	arc=0.0;
	for(i=0;i<5;i++)
	{
		if(dat[i]=='.')
			continue;
		temp*=10;
		temp+=(dat[i]-'0');
		
	}
	arc=temp;
	arc=arc*0.01;
	
	//������
	if((dat[5]-'0')>0)
		direction =1;
	else 
		direction =0;
	
	
	//�����ٶ�
	speed=0.0;
	temp=0;
	for(i=0;i<5;i++)
	{
		if(dat[i+6]=='.')
			continue;
		temp*=10;
		temp+=(dat[6+i]-'0');
	}
	speed=temp;
	speed=speed*0.01;
}

//�жϳ�ʼ������
void interInit()
{
	//��ʼ���ж�0
	IT0=1; //���ش�����ʽ
	EX0=1; //���ж�
	EA=1;
}

//�жϺ���
void Stop() interrupt 0
{
	EA=0;
	while(!IE0);
	IE0=0;
	EA=1;
	
}
