.SUFFIXES : .cc
.SUFFIXES : .c
.SUFFIXES : .cpp

INCDIR =
LIBDIR =

CC = g++

CXXFLAGS = -g

LIBS = -lm

OBJS = main.o avltree.o avlnode.o bstnode.o bstree.o functions.o contact.o

TARGET = Final

$(TARGET): $(OBJS)
	$(CC) -std=c++11 -o $@ $(OBJS) $(LIBDIR) $(LIBS)

.cc.o:
	$(CC) -std=c++11 -c $(CXXFLAGS) $(INCDIR) $<

.c.o:
	$(CC) -std=c++11 -c $(CXXFLAGS) $(INCDIR) $<

.cpp.o:
	$(CC) -std=c++11  -c $(CXXFLAGS) $(INCDIR) $<

clean:
	rm -f $(OBJS) $(TARGET) core



