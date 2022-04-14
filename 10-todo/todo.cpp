#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <string.h>

enum modes{add, rm, ls};
int mode = ls;

int main(int argc, char **argv){
    std::fstream todolist ("todolist");
    std::string line = "";

    if(argc > 1){
        if(strcmp(argv[1], "-a") == 0)
            mode = add;
        if(strcmp(argv[1], "-r") == 0)
            mode = rm;
        if(strcmp(argv[1], "-l") == 0)
            mode = ls;
    }

    switch (mode){
        case ls:
            if(todolist.is_open()){
                int counter = 1;
                while(std::getline(todolist, line)){
                    std::cout << counter << ". " <<  line << std::endl;
                    counter++;
                }       
                todolist.close();
            }
            break;
        case add:
            if(todolist.is_open()){
                todolist.seekp(0, std::ios::end);
                for(int i = 2; i < argc; i++){
                    line += argv[i];   
                }
                todolist << line << '\n';
                todolist.close();
            }
            break;
        case rm:
            std::ofstream new_todolist ("newtodolist");
            int counter = 1;
            while(std::getline(todolist, line)){
                if(!(counter == std::stoi(argv[2]))) 
                    new_todolist << line << '\n';
                counter++;
            }

            remove("todolist");
            rename("newtodolist", "todolist");
    }
}
