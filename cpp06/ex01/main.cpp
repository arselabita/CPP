#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
        Data data;

        data.age = 23;
        data.name = "Arsela";

        std::cout << "Original: " << &data << std::endl;
        
        uintptr_t addressValue = Serializer::serialize(&data);
        std::cout << "Address value: " << addressValue << std::endl;

        Data *restoreValue = Serializer::deserialize(addressValue);
        std::cout << "Restored value: " << restoreValue << std::endl;

        if (restoreValue == &data) {
            std::cout << "Successful!" << std::endl;
            std::cout << "The value of age and name: \n age:" << data.age << "\n name: " << data.name << std::endl;
        } else {
            std::cout << "Failure!" << std::endl;
        }

    return 0;
}