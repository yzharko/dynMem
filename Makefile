out: main.o
	g++ $^ -o $@

main.o:	main.cpp
	g++ -c $^

clean:
	rm *.o out
