#include "data.hpp"

unsigned long serialize(Data* ptr) {
    unsigned long value = reinterpret_cast<unsigned long>(ptr);
    return value;
}

Data* deserialize(unsigned long raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    return data;
}

int main()
{
    Data data;
    data.value = 10;

	unsigned long serializedData = serialize(&data);
    Data *newdata = deserialize(serializedData);

    std::cout << &data << std::endl;
    std::cout << newdata << std::endl;
    std::cout << data.value << std::endl;
    std::cout << newdata->value << std::endl;  
}