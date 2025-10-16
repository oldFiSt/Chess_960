#include <iostream>
#include <vector> 
#include <string>


int take_value(std::vector<std::pair<std::string, int>> &array, std::string);
void change_value(std::vector<std::pair<std::string, int>> &array, std::string str);

int main(){
    std::vector<std::pair<std::string, int>> cnt_array = {{"Bishop", 2}, {"Pawn", 0}, {"King", 1}, {"Rook", 2}, {"Queen", 1}, {"Knight", 1}};
    std::vector<std::pair<std::string, int>> :: iterator it = cnt_array.begin();
    std::string figure_name[6] = {"Pawn", "King", "Rook", "Queen", "Bishop", "Knight"};
    for(int i = 0; i < cnt_array.size(); i++){
        std::cout << it->first << ' ' << it->second << '\n';
        it++;
    }

    for (int i = 0; i < 6; i++){
        int n = 2;
        std::string str = figure_name[2];
        std::cout << take_value(cnt_array, str);
    };

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