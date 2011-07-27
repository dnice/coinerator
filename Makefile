CC=g++
INCLUDES = -I /home/dnice/Projects/coinerator/includes/json/
LIBS = -l curl /home/dnice/Projects/coinerator/libs/libjson_linux-gcc-4.5.2_libmt.so -lm
SRCS = ./coinerator.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = coinerator
all: $(MAIN)
$(MAIN): $(OBJS)
	$(CC) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)
clean:
	rm -R *.o $(MAIN)

