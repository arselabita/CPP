#include "iter.hpp"

template <typename T, typename Function>
void iter(T *arrPtr, const size_t length, Function addVal)
{
    for (int i = 0; i < length; i++)
        addVal(arrPtr[i]);
}
void add(int &num){
    num += num;
}   
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    iter(arr, 5, add);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;

    return 0;
}