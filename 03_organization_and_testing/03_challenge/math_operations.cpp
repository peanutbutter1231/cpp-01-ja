#include "math_operations.h"
#include <iostream>

// float MathOps::addition(float a, float b){
//     float result;
//     result = a + b;
//     return result;
// }
// float MathOps::subtraction(float a, float b){
//     float result;
//     result = a - b;
//     return result;
// }
// float MathOps::multiplication(float a, float b){
//     float result;
//     result = a * b;
//     return result;
// }
// float MathOps::division(float a, float b){
//     float result;
//     if(b == 0){
//         std::cout << "Error!" << std::endl;
//     }
//     result = a / b;
//     return result;
// }

namespace MathOps
{
    float addition(float a, float b)
    {
        float result;
        result = a + b;
        return result;
    }

    float subtraction(float a, float b)
    {
        float result;
        result = a - b;
        return result;
    }

    float multiplication(float a, float b)
    {
        float result;
        result = a * b;
        return result;
    }

    float division(float a, float b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        else
        {
            float result;
            result = a / b;
            return result;
        }
    }
}
