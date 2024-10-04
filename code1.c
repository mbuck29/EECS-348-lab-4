#include <stdio.h>
#include <string.h>
#define TYPES_OF_PTS 5

void find_combinations(int current_score, int counts[], int index, int possible_scores[]);
void all_scores(int score);




void all_scores(int score){
    int possible_scores[TYPES_OF_PTS] = {8,7,6,3,2};
    int counts[TYPES_OF_PTS] =  {0,0,0,0,0};
    find_combinations(score, counts, 0, possible_scores);
}

void find_combinations(int current_score, int counts[], int index, int possible_scores[]){
    if(current_score == 0){
        printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d 3pt FG, %d Safety \n", counts[0], counts[1], counts[2], counts[3], counts[4]);
        return;
    }
    if(current_score < 0 || index >= TYPES_OF_PTS){
        return;
    }
    int max_count = current_score / possible_scores[index];
    for(int i = 0; i <= max_count; i++){
        counts[index] = i;
        find_combinations(current_score - i * possible_scores[index], counts, index + 1, possible_scores);
        counts[index] = 0;
        
    }
    
}

int main(){
    
    int user_input;
    printf("Enter 0 or 1 to STOP \n");
    while (1){
        printf("Enter an NFL score: ");
        scanf("%d", &user_input);
        if(user_input <= 1){
            return 0;
        }
        all_scores(user_input);
    }
        

    return 0;
}
