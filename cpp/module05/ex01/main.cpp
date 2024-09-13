#include "Bureaucrat.hpp"

int main()
{
    

	try {
		Form form("1", 5, 5);
    	Bureaucrat yes("YESSUR", 150);
    	Bureaucrat yesss("YESSSSUR", 100);
    	form.beSigned(yesss);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}