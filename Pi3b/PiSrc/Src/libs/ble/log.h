#ifndef NCLOG
#define NCLOG
void writeLog(char *fname,char *desc,int ltype);
char *getSystime(char *systime,int style);
char *getRandom(char *randomstr,char *path);
int getSystimeMSec();
long readBuf(char *fname,char *buf);
long getLen(char *fname);
#endif
