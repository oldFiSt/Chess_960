#include <iostream> 
#include <ctime>
#include <string> 

int main(){
    srand(time(NULL));
    std::string array[10] = {"eqwe", "eqwe", "ewqe", "rwqer"};
    int random_number = rand() % (13 - 10 + 1) + 10;
    int rnd = rand() % (5 - 1 + 1) + 1;
    int Rook_rnd = rand() % (random_number - 9 + 1) + 8;
    std::cout << rnd << "\n";

    for (int i = 0; i < 10; i++){
        if(array[i].empty()){
            std::cout << "Pysto" << '\n';
        }
    }


}