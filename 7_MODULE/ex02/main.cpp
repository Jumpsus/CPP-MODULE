#include "Array.hpp"

int main(){
    {
        // TEST1
        std::cout << "=== [Test 1] :Int Array test ===" << std::endl;
        Array<int>   arr1(10);
        Array<int>   arr2(5);

        for(unsigned int i = 0; i < arr1.size(); i++){
            arr1[i] = i + 1;
        }

        std::cout << std::endl << "Fill new array" << std::endl;
        std::cout << "arr1 : ";
        arr1.display();
        std::cout << "arr2 : ";
        arr2.display();

        std::cout << std::endl << "Copy arr1 to arr2" << std::endl;
        arr2 = arr1;

        std::cout << "arr1 : ";
        arr1.display();
        std::cout << "arr2 : ";
        arr2.display();

        std::cout << std::endl << "Change Value in arr2 (arr1 shouldn't change)" << std::endl;
        for(unsigned int i = 0; i < arr2.size(); i++){
            arr2[i] = arr2[i] * arr2[i];
        }

        std::cout << "arr1 : ";
        arr1.display();
        std::cout << "arr2 : ";
        arr2.display();
    }
    {
        try{
            // TEST2 String
            std::cout << "=== [Test 2] :String Array test ===" << std::endl;
            Array<std::string>  arr1(10);
            Array<std::string>  arr2;

            std::cout << "Fill new Array" << std::endl;
            for (unsigned int i = 0; i < arr1.size(); i++){
                arr1[i] = "Sample";
            }
            std::cout << "arr1 : ";
            arr1.display();
            std::cout << "arr2 : ";
            arr2.display();

            std::cout << std::endl << "Copy arr1 to arr2" << std::endl;
            arr2 = arr1;

            std::cout << "arr1 : ";
            arr1.display();
            std::cout << "arr2 : ";
            arr2.display();

            std::cout << std::endl << "Try Array Out of Range arr1[10]" << std::endl;
            arr1[10] = "I am out of range";
        }
        catch(std::exception &exception){
            std::cout << exception.what() << std::endl;
        }
    }

}