CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -std=gnu99
TARGET = ble
# C文件
SRCS = serial.c
# 头文件查找路径
INC = -I ../../arch/Pi3b/include/wiringPi/
# 库文件和库查找路径
LDFLAGS = -L ../../arch/Pi3b/libs/ -lwiringPi
# 链接为可执行文件
$(TARGET):$(OBJS)
	$(CC)  $(INC) $(LDFLAGS) $(SRCS) -o $(TARGET)
clean:
	rm -rf $(TARGET) $(OBJS)
