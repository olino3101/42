#include "Harl.hpp"

void Harl::debug( void )
{
    cout << "[ DEBUG ]" << endl;
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void Harl::info( void )
{
    cout << "[ INFO ]" << endl;
    cout << "I cannot believe adding extra bacon costs more money. You didn't put"
    "enough bacon in my burger ! If you did, I wouldn't be asking for more !" << endl;
}
void Harl::warning( void )
{
    cout << "[ WARNING ]" << endl;
    cout <<  "I think I deserve to have some extra bacon for free. I've been coming"
    "for years whereas you started working here since last month." << endl;
}
void Harl::error( void )
{
    cout << "[ ERROR ]" << endl;
    cout <<  "This is unacceptable ! I want to speak to the manager now." << endl;
}

void Harl::complain( std::string level )
{
    int i = 0;
    string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i != 4 && levels[i].compare(level))
        i++;
    do
    {
        switch(i)
        {
            case 0:
            this->debug();
            break;

            case 1:
            this->info();
            break;

            case 2:
            this->warning();
            break;

            case 3:
            this->error();
            break;

            default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
        }
        i++;
    }  while (i < 4);


}