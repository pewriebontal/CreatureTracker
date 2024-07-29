CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES= creature.cpp creature_tracker.cpp creature_type_stats.cpp hash_table.h bs_tree.h main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=CreatureTracker

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
