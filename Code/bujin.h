#ifndef _BUJIN_H_
#define _BUJIN_H_

//�궨�岽���
#define STEP (5.625/64)

//�궨��ߵ͵�ƽ
#define A 0
#define B 1

//�����������ӿ�
#define PORT P2

//����һȦ��Ҫ���������
#define COUNT 4096

//�����ܺ���������
void run(double arc,bit direction,double speed);
void bujinDelay_n_100us(unsigned int i);
void delay100us(void);
#endif
