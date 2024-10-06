#include "Serializer.hpp"

int main ()
{
    Serializer::Data data;

    data.i = 42;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw: " << raw << std::endl;
    std::cout << "data: " << Serializer::deserialize(raw)->i << std::endl;
    return 0;
}
