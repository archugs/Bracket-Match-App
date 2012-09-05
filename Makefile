all : bracketMatch

bracketMatch : bracketMatch.o stack.o
	g++ bracketMatch.o stack.o -o bracketMatch

bracketMatch.o : bracketMatch.cpp
	g++ -c bracketMatch.cpp

stack.o : stack.cpp
	 g++ -c stack.cpp

clean :
	rm -rf *o bracketMatch
