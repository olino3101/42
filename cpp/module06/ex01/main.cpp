#include "data.hpp"

uintptr_t serialize(Data* ptr) {
    uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
    return value;
}

Data* deserialize(uintptr_t raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    return data;
}

int main()
{
    Data data;
    Data *newdata = deserialize(serialize(&data));

    std::cout << &data << std::endl;
    std::cout << newdata << std::endl;
    std::cout << data.value << std::endl;
    std::cout << newdata->value << std::endl;  
}