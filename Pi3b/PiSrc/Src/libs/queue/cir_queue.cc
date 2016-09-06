/*************************************************************************
	> File Name:cir_queue.cpp
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年08月24日 星期三 16时45分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#include "cir_queue.h"

using namespace std;
sem_t queue_sem;
/*
 * \Func
 *
 */
void init_cir_queue(cir_queue_t *q)
{    
  int res;

  /* Create semaphore */
  res = sem_init(&queue_sem, 0, QUE_SIZE);
  if (res != 0)
  {
    perror("Semaphore init failed.\n");
    exit(EXIT_FAILURE);
  }
  memset(q->data, 0, QUE_SIZE*sizeof(DataType));

  q->front = q->rear = 0;
  q->count = 0;
}

/*
 * \Func
 *
 */
int is_empty_cir_queue(cir_queue_t *q)
{
  int empty_flag;

  sem_wait(&queue_sem);    

  empty_flag = q->front == q->rear;

  sem_post(&queue_sem);

  return empty_flag;
}

/*
 * \Func
 *
 */
int is_full_cir_queue(cir_queue_t *q)
{
  int full_flag;

  sem_wait(&queue_sem);    

  full_flag = q->rear == QUE_SIZE - 1 + q->front;

  sem_post(&queue_sem);

  return full_flag;
}

/*
 * \Func
 *
 */
void push_cir_queue(cir_queue_t *q, DataType x)
{

  if (is_full_cir_queue(q))
  {
    printf("queue overflow.\n");
    return ;
  }

  sem_wait(&queue_sem);    

  q->count++;
  q->data[q->rear] = x;
  q->rear = (q->rear+1) % QUE_SIZE;

  sem_post(&queue_sem);
    
}

/*
 * \Func
 *
 */
DataType pop_cir_queue(cir_queue_t *q)
{
  DataType temp;

  if (is_empty_cir_queue(q))
  {
    printf("queue empty.\n");
    return 0;
  }

  sem_wait(&queue_sem);    

  temp = q->data[q->front];
  q->data[q->front] = 0;
  q->count--;
  q->front = (q->front+1) % QUE_SIZE;

  sem_post(&queue_sem);

  return temp;
}

/*
 * \Func
 *
 */
DataType top_cir_queue(cir_queue_t *q)
{
  DataType x; 

  if (is_empty_cir_queue(q))
  {
    printf("queue is empty.\n");
    return 0;
  }

  sem_wait(&queue_sem);    

  x = q->data[q->front];

  sem_post(&queue_sem);

  return x;
}

void destroy_cir_queue(cir_queue_t *q)
{ 
  sem_destroy(&queue_sem);

  return;    
}

void print_queue(cir_queue_t* q)
{
  int index;
  if (is_empty_cir_queue(q))
  {
    printf("queue is empty.\n");
    return;
  }
  sem_wait(&queue_sem);    
  for (index = 0; index < QUE_SIZE; index++)
  {
    printf(" %d ", q->data[index]);
  }
  sem_post(&queue_sem);

  return;
}
