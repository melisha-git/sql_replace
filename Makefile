all :
	rm -rf *.ghc sqlRep;
	g++ main.cpp utils.hpp TaskClass.hpp TaskBookClass.hpp -o sqlRep
	
run :
	./sqlRep