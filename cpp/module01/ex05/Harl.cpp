#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
    "enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void Harl::warning( void )
{
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming"
    "for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout <<  "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    int i = 0;
<<<<<<< HEAD
    void (Harl::*Ptrs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
=======
    void (Harl::*Ptrs[])() = {debug, info, warning, error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
>>>>>>> 6964f94d58263b4200d518278a68f79af47ea6f0
    while (i != 4 && levels[i].compare(level))
        i++;
    if (i == 4)
        std::cout << "wrong levels";
    else
        (this->*Ptrs[i])();

}