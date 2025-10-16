#include <iostream> 
#include <ctime>

int main(){
    srand(time(NULL));
    std::string array_figure_first[16] = {"Pawn", "Pawn", "Pawn", "Pawn","Pawn", "Pawn","Pawn", "Pawn"};
    
    
    bool is_Bishop = false;
    // array_figure_first[rook_first] = "Rook";
    // array_figure_first[rook_second] = "Rook";
    // array_figure_first[random_number] = "King";


    for (int i = 0; i< 1000; i++){
        bool is_Bishop = false;
        int random_number = rand() % (13 - 10 + 1) + 10; // 13 12 11 10
        int rook_first = rand() % (random_number - 8) + 8; // 8 9 
        int rook_second = rand() % (15 - random_number) + (random_number + 1) ;
        
        int bishop_first = rand() % (15 - 8 + 1) + 8;
        int bishop_second = rand() % (15 - 8 + 1) + 8;
        if(bishop_first % 2 == 0 && rook_first != bishop_first && rook_second != bishop_first && bishop_first != random_number){
            array_figure_first[bishop_first] = "Bishop";
            is_Bishop = false;
        }

        else if(bishop_first % 2 == 1 && rook_first != bishop_first && rook_second != bishop_first && bishop_first != random_number){
            array_figure_first[bishop_first] = "Bishop";
            is_Bishop = true;
        }
     
        else if(bishop_first == rook_first || bishop_first == rook_second || bishop_first == random_number){
            while((bishop_first == rook_first || bishop_first == rook_second || bishop_first == random_number) && bishop_first < 15){
                 bishop_first++;
            }

            if (bishop_first == rook_first || bishop_first == rook_second || bishop_first == random_number){
                while((bishop_first == rook_first || bishop_first == rook_second || bishop_first == random_number) && bishop_first > 8){
                    bishop_first--;    
                }
            }
        }

        if(bishop_second == bishop_first || bishop_second == rook_second|| bishop_second == rook_first || bishop_second == random_number){
            if(is_Bishop == false){//первый черный
                while(((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 0) && bishop_second < 15 ){
                        bishop_second++;
                }

                if ((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 0){
                    while(((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 0) && bishop_second > 8){
                        bishop_second--;
                    }      
                }
            }

            else{
                while(((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 1) && bishop_second < 15){
                        bishop_second++;
                }

                if ((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 1)
                {
                    while(((bishop_second == bishop_first || bishop_second == rook_first || bishop_second == rook_second || 
                        bishop_second == random_number) || bishop_second % 2 == 1) && bishop_second > 8){
                        bishop_second--;
                    } 
                }
            }


        }

        if (random_number == bishop_second){
            std::cout << "HYEWYE";
        }
        if (bishop_second == rook_first || bishop_second == rook_second){
            std::cout << "qwewqe";
        }
        
        std::cout << random_number << ' ' << rook_first << ' ' << rook_second << ' ' << bishop_first << ' ' << bishop_second << '\n';
    }


}