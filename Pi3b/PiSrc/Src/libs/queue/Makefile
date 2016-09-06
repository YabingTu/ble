OS_TYPE=LINUX
PTE_INCLUDE=/com/
SUSIINC=/usr/include
SUSILIBS=/usr/lib
SYSLIB=/usr/lib
INCLUDE=$(PTE_INCLUDE) -I/usr/include -I$(SUSIINC)

CC=g++
SOURCES=cir_queue.cc
OBJECTS=cir_queue.o
LIB=../../lib/libqueue.so


all:
	$(CC) -I$(INCLUDE) -fPIC -c $(SOURCES)
	$(CC) $(OBJECTS) -fPIC -shared -o $(LIB) -L$(SUSILIBS) -L$(SYSLIB)
	rm *.o;
.PHONY:clean
clean:
	-rm $(LIB);
