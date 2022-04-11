#include <iostream>
#include <stack>
#include <string>

int main(){
    std::stack<int> number_stack;
    std::string expresion, temp = "";
    std::getline(std::cin, expresion);

    for(int i = 0; i < expresion.size(); i++){
        temp = "";

        if(isdigit(expresion[i])){
            temp += expresion[i];
            while(isdigit(expresion[i+1])){
                i++;
                temp += expresion[i];
            }
            number_stack.push(std::stoi(temp));
        }

        if(expresion[i] == '+'){
            int a = 0, b = 0;
            a = number_stack.top(); number_stack.pop();
            b = number_stack.top(); number_stack.pop();
            number_stack.push(a + b);
        }

        if(expresion[i] == '-'){
            int a = 0, b = 0;
            a = number_stack.top(); number_stack.pop();
            b = number_stack.top(); number_stack.pop();
            number_stack.push(b - a);
        }

        if(expresion[i] == '*'){
            int a = 0, b = 0;
            a = number_stack.top(); number_stack.pop();
            b = number_stack.top(); number_stack.pop();
            number_stack.push(a * b);
        }


        if(expresion[i] == '/'){
            int a = 0, b = 0;
            a = number_stack.top(); number_stack.pop();
            b = number_stack.top(); number_stack.pop();
            number_stack.push(b / a);
        }

        if(expresion[i] == ' ')
            continue;
    }

    std::cout << number_stack.top() << '\n';
}
   
