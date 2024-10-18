#include "Span.hpp"

int main()
{
	try {
		    Span span(7);
    	span.addNumber(4);
    	span.addNumber(8);
    	span.addNumber(10);
    	span.addNumber(45);
    	span.addNumber(12);
    	span.addNumber(1);
    	span.addNumber(6);
    	// span.addNumber(6);

    	span.lotsOfNbr(4);

    	//span.addNumber(4);
    	span.printvec();
    	std::cout << "s " << span.shortestSpan() << std::endl;
    	std::cout << "l " << span.longestSpan() << std::endl;
	}

	catch (std::exception & e) {
    	std::cout << "Erreur: " << e.what() << std::endl;
        }
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
    	std::cout << "Erreur: " << e.what() << std::endl;
        }
	    return 0;
}