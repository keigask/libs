FLAGS = -Wall -Wextra -Iinclude

all: bin/params_tester

clean:
	rm -f bin/* ; > bin/.keep
	rm -f obj/* ; > obj/.keep

# Object files.

obj/params.o: src/params.cpp include/params.hpp
	g++ $(FLAGS) src/params.cpp -c -o obj/params.o

obj/params_tester.o: src/params_tester.cpp 
	g++ $(FLAGS) src/params_tester.cpp -c -o obj/params_tester.o


# Binaries. 
bin/params_tester: obj/params.o obj/params_tester.o 
	g++ $(FLAGS) obj/params.o obj/params_tester.o -o bin/params_tester
