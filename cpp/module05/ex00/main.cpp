#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat yes("YESSUR", 1500);
		yes.DownGrade();
		std::cout << yes.GetGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat yesss("YESSSSUR", 1);
		yesss.UpGrade();
		std::cout << yesss.GetGrade() << std::endl;
	}

	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat yess("YESSSSUR", 50);
		yess.UpGrade();
		std::cout << yess.GetGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}