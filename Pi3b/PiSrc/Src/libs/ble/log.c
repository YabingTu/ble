#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include "log.h"

FILE *fp;
int on_log_writing=0;

long getLen(char *fname){
	long len=0;
	if((fp=fopen(fname,"r"))!=NULL)
	{
		if(fseek(fp,0,2)==0){
			len=ftell(fp);				
		}		
		fclose(fp);
	}
	return len;
}
long readBuf(char *fname,char *buf){
	long len=0;
	if((fp=fopen(fname,"r"))!=NULL)
	{
		if(fseek(fp,0,2)==0){
			len=ftell(fp);				
		}		
		fseek(fp,0,0);
		fread(buf,1,len,fp);
		fclose(fp);
	}
	return len;
}
void writeLog(char *fname,char *desc,int ltype){
	char temp[32];
	while(on_log_writing==1){
		usleep(50); // 如果有线程在写入，则调用阻塞
	}
	on_log_writing = 1;	
	memset(temp,0x0,sizeof(temp));
	if((fp=fopen(fname,"a"))!=NULL)
	{
		if(ltype==1){
			fprintf(fp,"[%s][%d][%s]\n",getSystime(temp,0),0,desc);
		}else{
			fprintf(fp,"%s\n",desc);
		}		
		fclose(fp);
	}
	on_log_writing = 0;
}
char* getSystime(char *systime,int style)
{
	time_t nowtime=time(NULL);
	struct tm *ptr=localtime(&nowtime);
	if(style==0)
		strftime(systime,20,"%Y-%m-%d %H:%M:%S",ptr);	
	else if(style==1)
		strftime(systime,11,"%Y%m%d",ptr);
	else if(style==2)
		strftime(systime,9,"%H%M%S",ptr);	
	else if(style==3)
		strftime(systime,3,"%m",ptr);
	else if(style==4)
		strftime(systime,3,"%H",ptr);
	else if(style==5)
		strftime(systime,3,"%M",ptr);	
	else if(style==6)
		strftime(systime,3,"%S",ptr);	
	else if(style==7)
		sprintf(systime,"%ld",nowtime);							
	return systime;
}
char* getRandom(char *randomstr,char *path)
{
	time_t nowtime=time(NULL);
	struct tm *ptr=localtime(&nowtime);
	int ran=0;
	char timebuf[32];
	memset(timebuf,0x0,sizeof(timebuf));
	strftime(timebuf,20,"%Y%m%d%H%M%S",ptr);	
	ran=10000+rand();
	sprintf(randomstr,"%s%s%d.txt",path,timebuf,ran);	
	return randomstr;
}
int getSystimeMSec()  
{  
   struct timeval st;
   gettimeofday(&st, NULL);
   return st.tv_usec;  
}
