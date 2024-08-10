#include "convert.hpp"

int main()
{
   std::string test1 = "l";
   std::string test2 = "1";
   std::string test3 = "123";
   std::string test4 = "42.0f";
   std::string test5 = "4245645656.0f";
   std::string test6 = "-451";
   std::string test7 = "nanf";
   std::string test8 = "-inff";

    Conv conv(test1);
    conv.converter();
}