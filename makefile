FLAGS = -Wall -Wextra -Iinclude

all: bin/params_tester

clean:
	rm -f bin/* ; > bin/.keep

bin/params_tester: src/params.cpp src/params_tester.cpp include/params.hpp
	g++ $(FLAGS) src/params.cpp src/params_tester.cpp -o bin/params_tester
