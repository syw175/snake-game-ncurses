all: snake

snake: snake.o frontend.o backend.o
	cc -Wall -o snake snake.o backend.o frontend.o -lncurses

frontend.o: frontend.c frontend.h
	cc -Wall -c frontend.c frontend.h -lncurses

backend.o: backend.h backend.c
	cc -Wall -c  backend.c backend.h

clean:
	rm -f snake *.o
	rm -f frontend *.gch
	rm -f backend *.gch
    


# # make: *** No rule to make target `frontend.h', needed by `frontend.o'.  Stop.

# # testDriver: testDriver.o dataStructure.o
# # 	gcc -o testDriver testDriver.o dataStructure.o 
# # all: td

# # td: testDriver.o List.o Node.o
# # 	g++ -Wall -o td testDriver.o List.o Node.o

# # testDriver.o: testDriver.cpp List.h Node.h
# # 	g++ -Wall -c testDriver.cpp

# # List.o: List.h List.cpp Node.h
# # 	g++ -Wall -c List.cpp

# # Node.o: Node.h Node.cpp
# # 	g++ -Wall -c Node.cpp

# # clean:
# # 	rm -f td *.o