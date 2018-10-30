#######################
# Makefile
#######################

# target
TARGET := main

# compile and lib parameter
CC      := g++
LDFLAGS := -L.
LIBS    := libwxcloud.a -lrt -lpthread
DEFINES :=
INCLUDE := -I.
CFLAGS  := 
CXXFLAGS:= 

# link
$(TARGET):main.o
	$(CC) -o $@ $^ $(LIBS)
#compile
main.o:main.cpp
	$(CC) -c $^ -o $@

# clean
clean:
	rm -fr *.o
	rm -fr $(TARGET)
