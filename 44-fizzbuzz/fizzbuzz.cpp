#include <iostream>

int main(){
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0){
            if(i % 5 == 0){
                std::cout << "Fizz Buzz";
            }
            else{ 
                std::cout << "Fizz";
            }
        }

        else if(i % 5 == 0){
            std::cout << "Buzz";
        }

        else{
            std::cout << i;
        }

        std::cout << ", ";
    }
}
