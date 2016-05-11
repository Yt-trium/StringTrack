CC=gcc
CFLAGS=-g -Wall
LDFLAGS=

all : StringTrack

StringTrack : stringTrack.o main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%o : %.c
	$(CC) -c $^ -o $@ $(FLAGS)

clear :
	rm *.o

clean : clear
	rm StringTrack

test : all
	./StringTrack test_file test_str

perf : all
	eval time ./StringTrack test_file_big test_str
	
	
val : all
	valgrind ./StringTrack test_file test_str
