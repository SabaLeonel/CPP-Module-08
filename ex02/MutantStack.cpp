#include "MutantStack.hpp"

int main() {
    std::cout << "Demonstrating with int:" << std::endl;
    Array<int> emptyIntArray;
    Array<int> threeElementIntArray(3);
    std::cout << "Integer array size: " << threeElementIntArray.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Demonstrating with std::string:" << std::endl;
    Array<std::string> emptyStringArray;
    Array<std::string> threeElementStringArray(3);
    std::cout << "String array size: " << threeElementStringArray.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Verifying deep copy functionality:" << std::endl;
    Array<int> sourceArray(3);
    Array<int> destinationArray(3);
    sourceArray.setArray(1); // Assuming this sets all elements to 1
    destinationArray = sourceArray;
    if (&sourceArray != &destinationArray) {
        std::cout << "Source Array Contents:" << std::endl;
        sourceArray.printArray();
        std::cout << std::endl;
        std::cout << "Destination Array Contents:" << std::endl;
        destinationArray.printArray();
        std::cout << std::endl;
        std::cout << "Source Array Address: " << &sourceArray << std::endl;
        std::cout << "Destination Array Address: " << &destinationArray << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Testing subscript operator [] for array access:" << std::endl;
    try {
        std::cout << "sourceArray[1] = " << sourceArray[1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "sourceArray[7] = "; // Attempting to access an out-of-bounds index
        std::cout << sourceArray[7] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << std::endl;

    return 0;
}



/*----------- Main of subject  -----------*/
// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }