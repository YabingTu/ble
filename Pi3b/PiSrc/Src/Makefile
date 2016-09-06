DEBUG_DIR    =    ./debug
CC           =     g++
CFLAGS       =    -D_REENTRANT -lpthread -g -Wall -O2 -fmessage-length=0
LIB_ANI      =    ./anicloud/libs/libdevice_agent.a
LIB_LAL      =    ./lib/
TARGET       =    $(DEBUG_DIR)/device-demo

OBJECTS = AniMain.o devicecontroller.o 

device: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIB_ANI)  -L  $(LIB_LAL) -lled -L $(LIB_LAL) -lqueue -o $(TARGET) $(CFLAGS)
	rm *.o

.PHONY:clean
clean:
	rm -f $(OBJS) $(TARGET)
