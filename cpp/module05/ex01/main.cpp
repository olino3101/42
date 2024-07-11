#include "Bureaucrat.hpp"

int main()
{
    Form form("1", 5, 5);
    Bureaucrat yes("YESSUR", 150);
    Bureaucrat yesss("YESSSSUR", 100);
    form.beSigned(yesss);
}