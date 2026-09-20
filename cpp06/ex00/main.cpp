#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        showError("Please pass 1 parameter: <string>.");
        return 1;
    }
    else
    {
        std::string userInput = argv[1];
        if (userInput.empty())
        {
            showError("The <string> argument should not be empty!\n");
            return 1;
        }
        else
        {
            try
            {
                ScalarConverter::convert(userInput);
            }
            catch (const std::exception &e)
            {
                std::cerr << RED << "std::exception failed: " << e.what() << RESET << std::endl;
            }
        }
    }
    return 0; 
}