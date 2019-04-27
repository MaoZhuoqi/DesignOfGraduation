#include<reg51.h>
#include<Lcd1602.h>

/*
��ʼ������
*/
void lcdInitial()
{
	
	lcdWriteCommon(0x38);//����8λ��ʽ������
	lcdWriteCommon(0x0c);//������ʾ���ع��.����˸
	lcdWriteCommon(0x06);//�趨���뷽ʽ����������λ
	lcdWriteCommon(0x01);//�����Ļ��ʾ
	//lcdWriteCommon(0x80);  //�������
	delay40us(200);//�ȴ��������
	
}

//��оƬ��д������
//�����ش������ݽ���
void lcdWriteCommon(unsigned char common)
{
	
	lcdE=0;  //ʹ��
	lcdRS=0;  //д������
	lcdRW=0;  //д������
	
	INTERFACE=common;  //��������
	delay40us(50);
	
	lcdE=1;   //�����ش���
	delay40us(5);
	lcdE=0;//����ʹ��



}

//д������
void lcdWriteData(unsigned char dat)
{
	lcdE=0; //ʹ��
	lcdRS=1; //ѡ������
	lcdRW=0; //ѡ��д��
	
	INTERFACE=dat;  //��������
	delay40us(50);  //�ȴ������ȶ�
	
	lcdE=1;
	delay40us(5);
	lcdE=0;  //����ʹ��
	
}

//��ʾ����ַ�
void display(unsigned char x,unsigned char y,unsigned char dat)
{
	unsigned char address=0;
	
	if(y==1)
		address+=0x80;//��1�е���ʼ��ַ��������ؿ���λ
	else
		address+=0xc0;//��2�е���ʼ��ַ��������ؿ���λ
	address+=x;
	
	lcdWriteCommon(address);
	lcdWriteData(dat);
}
//��ʱ����
void delay40us(unsigned char time)
{
	unsigned char i,j;
	for(i=time ;i>0;i--)
		for(j=0;j<2;j++);
						
}
