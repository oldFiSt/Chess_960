#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <ctime>
#include <vector>

//обращение по ключу название_мапа[ключ]

int take_value(std::vector<std::pair<std::string, int>> &array, std::string str);
void change_value(std::vector<std::pair<std::string, int>> &array, std::string str);

int main(){

    srand(time(NULL));
    std::vector<std::pair<std::string, int>> cnt_array = {{"Bishop", 2}, {"Pawn", 0}, {"King", 1}, {"Rook", 2}, {"Queen", 1}, {"Knight", 2}};
    
    std::string figure_name[6] = {"Bishop", "Pawn", "King", "Rook", "Queen", "Knight"};

    int random_number = rand() % (14 - 9 + 1) + 9;
    random_number = 14;
    bool l_flag = false, r_flag = false;
    std::string array_figure_first[16] = {"Pawn", "Pawn", "Pawn", "Pawn","Pawn", "Pawn","Pawn", "Pawn"};

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

        for(int i = 10; i < 16; i++){
            int rnd = rand() % (5 - 0 + 0) + 0;
            std::string str = figure_name[rnd];

            if(take_value(cnt_array, str) > 0 && str == "Bishop"){
                array_figure_first[i] = "Bishop";
                change_value(cnt_array, str);
                if(i % 2 == 0){
                    bishop_flag = false;
                }
                else{bishop_flag = true;}
            }

            else if(take_value(cnt_array, str) == 1 && str == "Bishop"){
                if((bishop_flag == false && (i % 2 == 0)) || ((bishop_flag == true) && (i % 2 != 0))){
                    while(rnd < 6 && take_value(cnt_array, str) == 0 && str == "Bishop"){
                        rnd++;
                    }

                    if(rnd == 6){rnd = 5;}
                    array_figure_first[i] = figure_name[rnd];
                    change_value(cnt_array,figure_name[rnd]);
                }

                else if((bishop_flag == false && (i % 2 !=0)) || ((bishop_flag == true && (i % 2 ==0)))){
                    array_figure_first[i] = "Bishop";
                    change_value(cnt_array,"Bishop");
                    if(i % 2 == 0){
                    bishop_flag = false;
                    }
                    else{bishop_flag = true;}
                }
            }

            else if (take_value(cnt_array, str) > 0 && str != "Bishop"){
                array_figure_first[i] = str;
                change_value(cnt_array,str);
            }
            
            else if (take_value(cnt_array, str) == 0 && str == "Bishop"){
                while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0 && str != "Bishop"){
                    rnd++;
                }

                if(rnd == 6){rnd = 5;}
                str = figure_name[rnd];

                if(take_value(cnt_array, str) > 0){
                    array_figure_first[i] = str;
                    change_value(cnt_array, str);
                }
            }

            else if (take_value(cnt_array, str) == 0 && str != "Bishop"){
                while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0 && str != "Bishop"){
                    rnd++;
                }

                if(rnd == 6){rnd = 5;}
                str = figure_name[rnd];

                if(take_value(cnt_array, str) != 0){
                    str = figure_name[rnd];

                    if(str == "Bishop" && take_value(cnt_array, "Bishop") == 2){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str == "Bishop" && take_value(cnt_array, "Bishop") == 1){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str != "Bishop" && take_value(cnt_array, "Bishop") != 0){
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
                }
                else if (take_value(cnt_array, str) == 0){
                    while(take_value(cnt_array, figure_name[rnd]) == 0 && rnd >= 0){
                        rnd--;
                    }

                    if(str == "Bishop" && take_value(cnt_array, "Bishop") == 2){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str == "Bishop" && take_value(cnt_array, "Bishop") == 1){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str != "Bishop" && take_value(cnt_array, "Bishop") != 0){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
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

        for (int i = 8; i < 15; i++){
            int rnd = rand() % (5 - 0 + 0) + 0;
            std::string str = figure_name[rnd];

            if(take_value(cnt_array, str) > 0 && str == "Bishop"){
                array_figure_first[i] = "Bishop";
                change_value(cnt_array, str);
                if(i % 2 == 0){
                    bishop_flag = false;
                }
                else{bishop_flag = true;}
            }

            else if(take_value(cnt_array, str) == 1 && str == "Bishop"){
                if((bishop_flag == false && (i % 2 == 0)) || ((bishop_flag == true) && (i % 2 != 0))){
                    while(rnd < 6 && take_value(cnt_array, str) == 0 && str == "Bishop"){
                        rnd++;
                    }

                    if(rnd == 6){rnd = 5;}
                    array_figure_first[i] = figure_name[rnd];
                    change_value(cnt_array,figure_name[rnd]);
                }

                else if((bishop_flag == false && (i % 2 !=0)) || ((bishop_flag == true && (i % 2 ==0)))){
                    array_figure_first[i] = "Bishop";
                    change_value(cnt_array,"Bishop");
                    if(i % 2 == 0){
                    bishop_flag = false;
                    }
                    else{bishop_flag = true;}
                }
            }

            else if (take_value(cnt_array, str) > 0 && str != "Bishop"){
                array_figure_first[i] = str;
                change_value(cnt_array,str);
            }
            
            else if (take_value(cnt_array, str) == 0 && str != "Bishop"){
                while(rnd < 6 && take_value(cnt_array, figure_name[rnd]) == 0 && str != "Bishop"){
                    rnd++;
                }

                if(rnd == 6){rnd = 5;}
                str = figure_name[rnd];

                if(take_value(cnt_array, str) != 0){
                    str = figure_name[rnd];

                    if(str == "Bishop" && take_value(cnt_array, "Bishop") == 2){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str == "Bishop" && take_value(cnt_array, "Bishop") == 1){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str != "Bishop" && take_value(cnt_array, "Bishop") != 0){
                        array_figure_first[i] = str;
                        change_value(cnt_array, str);
                    }
                }
                else if (take_value(cnt_array, str) == 0){
                    while(take_value(cnt_array, figure_name[rnd]) == 0 && rnd >= 0){
                        rnd--;
                    }

                    if(str == "Bishop" && take_value(cnt_array, "Bishop") == 2){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str == "Bishop" && take_value(cnt_array, "Bishop") == 1){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                        if(i % 2 == 0){
                            bishop_flag = false;
                        }
                        else{bishop_flag = true;}
                    }

                    else if(str != "Bishop" && take_value(cnt_array, "Bishop") != 0){
                        array_figure_first[i] = "Bishop";
                        change_value(cnt_array, "Bishop");
                    }

                }
            }

        }

    }

    if(l_flag == false && r_flag == false){
        int Rook_rnd = rand() % (random_number - 9 + 1) + 8;
        bool bishop_flag = false;
        array_figure_first[Rook_rnd] = "Rook";
        change_value(cnt_array, "Rook");
        array_figure_first[random_number] = "King";
        change_value(cnt_array, "King");
        
        int rnd = rand() % (5 - 1 + 1) + 1;
        std::string str = figure_name[rnd];

        for(int i = 0; i < random_number; i++){

        }
    }

    for(int i = 0; i < 16; i++){
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

