#include <iostream> 
#include <ctime>
#include <string> 
#include <vector>

int take_value(std::vector<std::pair<std::string, int>> &array, std::string str);
void change_value(std::vector<std::pair<std::string, int>> &array, std::string str);

int main(){
    srand(time(NULL));
    std::string array[10] = {"eqwe", "eqwe", "ewqe", "rwqer"};
    // int random_number = rand() % (13 - 10 + 1) + 10;
    // int rnd = rand() % (5 - 1 + 1) + 1;
    // int Rook_rnd = rand() % (random_number - 9 + 1) + 8;
    // std::cout << rnd << "\n";
    std::vector<std::pair<std::string, int>> cnt_array = {{"Bishop", 2}, {"Pawn", 0}, {"King", 1}, {"Rook", 2}, {"Queen", 1}, {"Knight", 2}};
    std::string array_figure_first[16] = {"Pawn", "Pawn", "Pawn", "Pawn","Pawn", "Pawn","Pawn", "Pawn"};
    std::string figure_name[6] = {"Bishop", "Pawn", "King", "Rook", "Queen", "Knight"};
    bool l_flag = false, r_flag = false;
    int random_number = rand() % (14 - 9 + 1) + 9;
    // random_number = 9;
    // random_number = 14;

    if (random_number == 9){
        l_flag = true;
    }

    
    if (random_number == 14){
        r_flag = true;
    }

    

    if(l_flag){
        bool bishop_flag = false;
        array_figure_first[8] = "Rook";
        change_value(cnt_array, "Rook");
        array_figure_first[9] = "King";
        change_value(cnt_array, "King");
        int bishop_first = rand() % (15 - 10 + 1) + 10;
        if(bishop_first % 2 == 0){bishop_flag = false;}
        else{bishop_flag = true;}
        int bishop_second = rand() % (15 - 10 + 1) + 10;
        if(bishop_flag == false && bishop_second % 2 == 0){
            bishop_second++;
        }
        else if(bishop_flag == true && bishop_second % 2 != 0){
            bishop_second--;
        }

        array_figure_first[bishop_first] = "Bishop";
        change_value(cnt_array, "Bishop");
        array_figure_first[bishop_second] = "Bishop";
        change_value(cnt_array, "Bishop");

        
        for(int i = 10; i < 16; i++){
            if(array_figure_first[i] == "Bishop"){
                continue;
            }
            else{
                int rnd = rand() % (5 - 1 + 1) + 1;
                std::string str = figure_name[rnd];

                if (take_value(cnt_array, str) > 0){
                    array_figure_first[i] = str;
                    change_value(cnt_array, str);
                }

                else{

                    while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0){
                        rnd++;
                    }
                    if(rnd == 6){rnd = 5;}
                    str = figure_name[rnd];

                    if(take_value(cnt_array, str) == 0){
                        while(take_value(cnt_array, figure_name[rnd]) == 0 && rnd >= 1){
                            rnd--;
                        }
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
                    else{
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
            
                }

            } 
   
        }
   
    }

    if(r_flag){
        bool bishop_flag = false;
        array_figure_first[15] = "Rook";
        change_value(cnt_array, "Rook");
        array_figure_first[14] = "King";
        change_value(cnt_array, "King");
        int bishop_first = rand() % (13 - 8 + 1) + 8;
        if(bishop_first % 2 == 0){bishop_flag = false;}
        else{bishop_flag = true;}
        int bishop_second = rand() % (13 - 8 + 1) + 8;
        if(bishop_flag == false && bishop_second % 2 == 0){
            bishop_second++;
        }
        else if(bishop_flag == true && bishop_second % 2 != 0){
            bishop_second--;
        }

        array_figure_first[bishop_first] = "Bishop";
        change_value(cnt_array, "Bishop");
        array_figure_first[bishop_second] = "Bishop";
        change_value(cnt_array, "Bishop");

        
        for(int i = 8; i < 14; i++){
            if(array_figure_first[i] == "Bishop"){
                continue;
            }
            else{
                int rnd = rand() % (5 - 1 + 1) + 1;
                std::string str = figure_name[rnd];

                if (take_value(cnt_array, str) > 0){
                    array_figure_first[i] = str;
                    change_value(cnt_array, str);
                }

                else{

                    while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0){
                        rnd++;
                    }
                    if(rnd == 6){rnd = 5;}
                    str = figure_name[rnd];

                    if(take_value(cnt_array, str) == 0){
                        while(take_value(cnt_array, figure_name[rnd]) == 0 && rnd >= 1){
                            rnd--;
                        }
                        str = array_figure_first[rnd];
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
                    else{
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
            
                }

            } 
   
        }
   
    }

    if (l_flag == false && r_flag == false){
        
        bool is_Bishop = false;
        int random_number = rand() % (13 - 10 + 1) + 10; // 13 12 11 10
        int rook_first = rand() % (random_number - 8) + 8; // 8 9 
        int rook_second = rand() % (15 - random_number) + (random_number + 1) ;
        int bishop_first = rand() % (15 - 8 + 1) + 8;
        int bishop_second = rand() % (15 - 8 + 1) + 8;

        array_figure_first[random_number] = "King";
        change_value(cnt_array, "King");
        array_figure_first[rook_first] = "Rook";
        change_value(cnt_array, "Rook");
        array_figure_first[rook_second] = "Rook";
        change_value(cnt_array, "Rook");


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

        array_figure_first[bishop_first] = "Bishop";
        change_value(cnt_array, "Bishop");
        array_figure_first[bishop_first] = "Bishop";
        change_value(cnt_array, "Bishop");

        for(int i = 8; i < 16; i++){
            if(array_figure_first[i].empty()){
                int rnd = rand() % (5 - 1 + 1) + 1;
                std::string str = figure_name[rnd];
                
                if (take_value(cnt_array, str) > 0){
                    array_figure_first[i] = str;
                    change_value(cnt_array, str);
                }
                else{

                    while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0){
                        rnd++;
                    }
                    if(rnd == 6){rnd = 5;}
                    str = figure_name[rnd];

                    if(take_value(cnt_array, str) == 0){
                        while(take_value(cnt_array, figure_name[rnd]) == 0 && rnd >= 1){
                            rnd--;
                        }
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
                    else{
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
            
                }
            }

            else
            {
                continue;
            }
        }
    }

    for (int i = 8; i < 16; i++){
        std::cout << array_figure_first[i] << ' ';
    } 



}


int take_value(std::vector<std::pair<std::string, int>> &array, std::string str){
    std::vector<std::pair<std::string, int>> :: iterator it = array.begin();
    for(int i = 0; i < array.size(); i++){
        if(it -> first == str){
            return it->second;
        }
        it++;
    }  
}

void change_value(std::vector<std::pair<std::string, int>> &array, std::string str)
{
    std::vector<std::pair<std::string, int>> :: iterator it = array.begin();
    for(int i = 0; i < array.size(); i++){
        if(it -> first == str){
            it->second -= 1;
            return;
        }
        it++;
    } 
}