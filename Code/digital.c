#include<digital.h>
 
 
 //�����������ʾ���ֱ�
 unsigned char numbers[10]={0x00};
 
 void exhibition(unsigned char count)
 {

	 
	 //һ��ת����Ȧ������ʮȦ������ֻ����һ�����������ʾ10���ڵ�����

		com1=EN;
		NUMBER=numbers[count%10];
		shumaDelay(100);
		
 }

 void shumaDelay(unsigned int i)
 {
		while(i--);
 }