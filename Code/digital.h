#ifndef __DIGITAL_H_
#define __DIGITAL_H_
#include<reg51.h>

//�����������ƶ�
sbit com1=P2^1;


//����ʹ�ܵ�λ
#define EN 1

//�����������io��
#define NUMBER P1

//������غ���
 void exhibition(unsigned char count);
  void shumaDelay(unsigned int i);

#endif