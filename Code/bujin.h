#ifndef _BUJIN_H_
#define _BUJIN_H_

//�궨�岽���
#define STEP (5.625/24)

//�궨��ߵ͵�ƽ
#define A 0
#define B 1

//�����������ӿ�
#define PORT P1


//�����ܺ���������
void run(double arc,bit direction,double speed);
void bujinDelay(unsigned int i);
#endif
