/*************************************************************************
	> File Name:main.c
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年08月24日 星期三 14时19分01秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include<iostream>
#include "./anicloud/include/device.h"
#include "./anicloud/include/device_agent.h"
#include "./libs/hard/led.h"
#include "./libs/queue/cir_queue.h"
using namespace std;
void *thread_queue_agent(void *cirqueue);
void *thread_queue_controller(void *cirqueue);

/*
 * \Func
 * main
 */
int main(int argc, char* argv[])
{
  int res;
  cir_queue_t cq;
  DataType e;
  pthread_t a_thread, b_thread;
  void* thread_result;

  init_cir_queue(&cq);
  print_queue(&cq);
        push_cir_queue(&cq,1);
        push_cir_queue(&cq,2);
        push_cir_queue(&cq,3);
        push_cir_queue(&cq,4);
        push_cir_queue(&cq,5);
        push_cir_queue(&cq,6);
        push_cir_queue(&cq,7);
  res = pthread_create(&a_thread, NULL, thread_queue_agent, (void*)&cq);
  if (res != 0)
  {
    perror("Thread creation failed.");
    exit(EXIT_FAILURE);
  }
  res = pthread_create(&b_thread, NULL, thread_queue_controller, (void*)&cq);
  if (res != 0)
  {
    perror("Thread creation failed.");
    exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0)
  {
    perror("Thread join failed.");
    exit(EXIT_FAILURE);
  }
 res = pthread_join(b_thread, &thread_result);
  if (res != 0)
  {
    perror("Thread join failed.");
    exit(EXIT_FAILURE);
  }
  destroy_cir_queue(&cq);
  exit(EXIT_SUCCESS);
}


void *thread_queue_agent(void *cirqueue)
{
    int i = 0;
    while(1){

    }
}
void *thread_queue_controller(void *cirqueue)
{
    while(1){
        pop_cir_queue((cir_queue_t*)cirqueue);
        print_queue((cir_queue_t*)cirqueue);
        sleep(2);

    }
}
