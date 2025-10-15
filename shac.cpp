#include <iostream>
#include <string>
#include <ctime>
//ладьи по разным сторонам
//слоны на разных цветах
//черный симметричны белым
//bishop - слон; Knight - конь


int main(int argc, char *argv[])
{
    srand(time(NULL));

    int cnt = 0;

    std::string Player1 = "white", Player2 = "black";
    bool l_flag = false;
    bool r_flag = false;
    int random_number = rand() % (14 - 9 + 1) + 9;
    random_number = 9;

    std::cout << random_number;
    int color_array[16] = {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0};
    std::string array_figure_first[16] = {"Pawn", "Pawn", "Pawn", "Pawn","Pawn", "Pawn","Pawn", "Pawn"};
    std::string array_figure_name[6] = {"Pawn", "King", "Rook", "Queen", "Bishop", "Knight"};

    int cnt_array[6][2] =               {{8, 0}, {1, 1}, {2, 2}, {1, 3}, {2, 4}, {2, 5}};

    array_figure_first[random_number] = "King";
    cnt_array[1][0]--;// удаление короля

    bool is_Bishop = false;
    if (random_number == 9){array_figure_first[8] = "Rook"; l_flag = true; cnt_array[2][0]--;};
    if (random_number == 14){array_figure_first[15] = "Rook"; r_flag = true; cnt_array[2][0]--;};
    
    bool flag = false;
    if (l_flag){

        for(int i = 10; i < 16; i++){

            if (flag){
                flag = false;
                continue;
            }
            
            else{

            
            int rnd = rand() % (5 - 2 + 1) + 2;

            if (rnd == 4 && cnt_array[rnd][0] == 2)
            {
                if(color_array[i]){is_Bishop = false;}
                else if(color_array[i] == 0){is_Bishop = true;}
                cnt_array[rnd][0]--;
                array_figure_first[i] = array_figure_name[rnd];
            }

            else if (rnd == 4 && cnt_array[rnd][0] == 1 && ((color_array[i] == 1 && is_Bishop == true) || (color_array[i] == 0 && is_Bishop == false)))
            {
                if(color_array[i]){is_Bishop = false;}
                else if(color_array[i] == 0){is_Bishop = true;}
                cnt_array[rnd][0]--;
                array_figure_first[i] = array_figure_name[rnd];
            }

            else if (rnd == 4 && cnt_array[rnd][0] == 1 && ((color_array[i] == 1 && is_Bishop == false) || (color_array[i] == 0 && is_Bishop == true)) && rnd <= 14)
            {
                flag = true;
                cnt_array[rnd][0]--;
                array_figure_first[i+1] = array_figure_name[rnd];

                if (cnt_array[rnd+1][0] == 0 && cnt_array[rnd+2][0] == 0){
                    while(rnd > 0 && cnt_array[rnd][0] == 0){
                        rnd--;
                    }

                    array_figure_first[i] = array_figure_name[rnd];
                    cnt_array[rnd][0]--;
                }

                else if (cnt_array[rnd+1][0] > 0){
                    array_figure_first[i] = array_figure_name[rnd+1];
                    cnt_array[rnd][0]--;
                }
                
                else if (cnt_array[rnd+2][0] > 0){
                    array_figure_first[i] = array_figure_name[rnd+2];
                    cnt_array[rnd][0]--;
                }
            }

            else if (cnt_array[rnd][0] > 0){
                array_figure_first[i] = array_figure_name[rnd];
                cnt_array[rnd][0]--;
            }

            else if (cnt_array[rnd][0] == 0){
                while(rnd < 6 && cnt_array[rnd][0] == 0){
                    rnd++;
                }

                if(rnd == 6){
                    rnd = 5;
                }

                if(rnd == 4 && cnt_array[rnd][0] == 2){
                    if(color_array[i]){is_Bishop = false;}
                    else if(color_array[i] == 0){is_Bishop = true;}
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                else if(rnd == 4 && cnt_array[rnd][0] == 1 && ((color_array[i] == 1 && is_Bishop == true) || (color_array[i] == 0 && is_Bishop == false))){
                    if(color_array[i]){is_Bishop = false;}
                    else if(color_array[i] == 0){is_Bishop = true;}
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                else if(rnd != 4 && cnt_array[rnd][0] > 0)
                {
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                else{
                    while(rnd > 0 && cnt_array[rnd][0] == 0){
                        rnd--;
                    }

                    if(rnd == 4 && cnt_array[rnd][0] == 2){
                    if(color_array[i]){is_Bishop = false;}
                    else if(color_array[i] == 0){is_Bishop = true;}
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                
                else if(rnd == 4 && cnt_array[rnd][0] == 1 && ((color_array[i] == 1 && is_Bishop == true) || (color_array[i] == 0 && is_Bishop == false))){
                    if(color_array[i]){is_Bishop = false;}
                    else if(color_array[i] == 0){is_Bishop = true;}
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                else if (rnd == 4 && cnt_array[rnd][0] == 1 && ((color_array[i] == 1 && is_Bishop == false) || (color_array[i] == 0 && is_Bishop == true)) && rnd <= 14)
                {
                flag = true;
                cnt_array[rnd][0]--;
                array_figure_first[i+1] = array_figure_name[rnd];

                if (cnt_array[rnd+1][0] == 0 && cnt_array[rnd+2][0] == 0){
                    while(rnd > 0 && cnt_array[rnd][0] == 0){
                        rnd--;
                    }

                    array_figure_first[i] = array_figure_name[rnd];
                    cnt_array[rnd][0]--;
                }

                else if (cnt_array[rnd+1][0] > 0){
                    array_figure_first[i] = array_figure_name[rnd+1];
                    cnt_array[rnd][0]--;
                }
                
                else if (cnt_array[rnd+2][0] > 0){
                    array_figure_first[i] = array_figure_name[rnd+2];
                    cnt_array[rnd][0]--;
                }
                }

                else if(rnd != 4 && cnt_array[rnd][0] > 0)
                {
                    cnt_array[rnd][0]--;
                    array_figure_first[i] = array_figure_name[rnd];
                }

                }
  
            }

            }
            

    };

    if (random_number == 9){
        for(int i = 0; i < 16; i++)
        {
           std::cout << array_figure_first[i] << ' ';
        }
    }
    }
}


