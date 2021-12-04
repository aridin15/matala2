#include <stdio.h>
#define Max 10
#define True 1
#define Flase -1

int find_min(int x,int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}

void init_mat(int(*arr_ptr)[Max]){
    for(int i = 0 ; i < Max ; i++){
        for(int j = 0 ; j < Max ; j++){
            scanf("%d", &(*(*(arr_ptr + i) + j)));
        }
    }
}

int shortest_route(int(*arr_ptr)[Max],int i,int j){
    for (int i = 0 ; i < Max ; i++){
        for (int j = 0; j < Max ; j++){
            for (int k = 0; k < Max; k++){
                if ((*(*(arr_ptr + j) + k)) == 0 && j != k){
                    if((*(*(arr_ptr + j) + i) != 0 && *(*(arr_ptr + i) + k) != 0)){
                        *(*(arr_ptr + j) + k) = *(*(arr_ptr + j) + i) + *(*(arr_ptr + i) + k);
                    }
                    else{
                        continue;
                    }
                }
                if(*(*(arr_ptr + j) + k) != 0){
                    if((*(*(arr_ptr + j) + i) != 0 && *(*(arr_ptr + i) + k) != 0)){
                         *(*(arr_ptr + j) + k) = find_min( *(*(arr_ptr + j) + k) ,*(*(arr_ptr + j) + i) + *(*(arr_ptr + i) + k) );
                    }
                }
            }
        }
    }
    return *(*(arr_ptr + i) + j);
}

void path_exist(int(*arr_ptr)[Max], int i,int j){
    if( *(*(arr_ptr +i ) + j) != 0 ){
        printf("True\n");
    }
    else{
        printf("Flase\n");
    }
}


