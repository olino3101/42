    #include "convert.hpp"
    #include <sstream>

    int stoi(std::string str) {
        std::stringstream ss(str);
        long num;
        ss >> num;
        if (ss.fail() || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            throw std::invalid_argument("fails converting s to int");
        return num;
    }

    double stod(std::string str) {
        std::stringstream ss(str);
        long double num;
        ss >> num;
        if (ss.fail() || num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
            throw std::invalid_argument("fails converting s to double");
        return num;
    }

    float stof(std::string str) {
        std::stringstream ss(str);
        double num;
        ss >> num;
        if (ss.fail() || num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
            throw std::invalid_argument("fails converting s to double");
        return num;
    }
    

    Conv::~Conv() {}

    Conv::Conv() {}

    Conv::Conv(std::string str) : str(str) {}

    Conv::Conv(const Conv & other) : str(other.str) {
    }

    Conv& Conv::operator=(const Conv & other) {
        if (&other != this)
            this->str = other.str;
        return *this;
    }

    static bool isFloat(std::string str) {
        try {
            if (str == "nanf" || str == "-inff" || str == "+inff")
                return true;
            stof(str);
            return (str.find('.') != std::string::npos && str[str.size() - 1] == 'f');
        }
        catch (std::exception &e){
            return false;
        }
    }

    static int findprecision(std::string str)
    {
        size_t pos = str.find('.');
        if (pos == std::string::npos)
            return 0;
        return str.length() - pos - 2;
    }

    static void printEx(std::string str, char c) {
        std::cout << "impossible" << std::endl;
        std::cout << "impossible" << std::endl;
        if (c == 'f')
        {
            std::cout << "float " << str << std::endl;
            std::cout << "double "<< str.substr(0, str.length() - 1) << std::endl;
        }
        else if (c == 'd')
        {
            std::cout << "float " << str << "f" << std::endl;
            std::cout << "double "<< str << std::endl;
        }
    }
    
    static void printFloat(std::string str) {
        
        float f;
        try {
            f = stof(str);
        }
        catch (std::exception &e) {
            printEx(str, 'f');
            return ;
        }
        long long i = static_cast<long long>(f);
        if (f > 31 && f < 127)
            std::cout << static_cast<char>(f) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
            std::cout << "Impossible" << std::endl;
        else
            std::cout << "int " << i << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(findprecision(str)) << f << "f" << std::endl;
        std::cout << "double "<< static_cast<double>(f) << std::endl;
    }

    static int isDouble(std::string str) {
        try {
            if (str == "nan" || str == "-inf" || str == "+inf")
                return true;
            stod(str);
            return (str.find('.') != std::string::npos);
        }
        catch (std::exception &e){
            return false;
        }
    }

    static void printDouble(std::string str)
    {
        double d;
        try {
            d = stod(str);
        }
        catch (std::exception &e) {
            printEx(str, 'd');
            return ;
        }
        long long i = static_cast<long long>(d);
        if (d > 31 && d < 127)
            std::cout << static_cast<char>(d) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
            std::cout << "Impossible" << std::endl;
        else
            std::cout << "int " << i << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(findprecision(str)) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double "<< d << std::endl;
    }
    static bool isInt(std::string str) {
        try
        {
            stoi(str);
            return true;
        }
        catch (std::exception &e)
        {
            return false;
        }
    }

    static void printInt(std::string str) {
        int i = stoi(str);
        if (i > 31 && i < 127)
            std::cout << static_cast<char>(i) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int " << i << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double "<< static_cast<double>(i) << std::endl;
    }

    static bool isChar(std::string str) {
        if (str.length() == 1)
            return true;
        return false; 
    }

    static void printChar(std::string str) {
        char c = str[0];
        std::cout << "char " << c << std::endl;
        std::cout << "int " << static_cast<int>(c) << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double "<< static_cast<double>(c) << std::endl;
        return ;
    }

    static void wrongInput() {
        std::cout << "you have put the wrong input" << std::endl;
    }
    void Conv::converter() {
        if (isFloat(str))
            printFloat(str);
        else if (isDouble(str))
            printDouble(str);
        else if (isInt(str))
            printInt(str);
        else if (isChar(str))
            printChar(str);
        else
            wrongInput();
    }