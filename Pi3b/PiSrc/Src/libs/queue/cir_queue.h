/*************************************************************************
	> File Name:cir_queue.h
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年08月24日 星期三 14时18分15秒
 ************************************************************************/

#ifndef _CIR_QUEUE_H
#define _CIR_QUEUE_H

#define QUE_SIZE 8
typedef int DataType;
typedef struct cir_queue_t
{
  DataType data[QUE_SIZE];
  int front;
  int rear;
  int count;
}cir_queue_t;

extern sem_t queue_sem; 

void init_cir_queue(cir_queue_t* q);
int is_empty_cir_queue(cir_queue_t* q);
int is_full_cir_queue(cir_queue_t* q);
void push_cir_queue(cir_queue_t* q, DataType x);
DataType pop_cir_queue(cir_queue_t* q);
DataType top_cir_queue(cir_queue_t* q);
void destroy_cir_queue(cir_queue_t* q);
void print_queue(cir_queue_t* q);

#endif
