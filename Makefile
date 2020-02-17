SOURCE = *.cpp givenFiles/DeckBuilder.cpp
ITEM = main

run : compile
	./$(ITEM)
	make clean

debug : $(ITEM)
	gdb $(ITEM)

compile : $(SOURCE)
	g++ -std=c++11 -Wall -g3 -o $(ITEM) $(SOURCE)

clean :
	-rm -rf *.o

compress: $(SOURCE)
	rm -r $(ITEM)
	mkdir final
	cp * final

memcheck: compile
	valgrind --leak-check=full ./$(ITEM)
