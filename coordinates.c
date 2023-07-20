#include <stdio.h>

typedef struct coordinates{
    float x;
    float y;    
}coo;



int main(){
    int n;
    printf("enter a number of coordinates: ");
    scanf("%d",&n);
    coo T[n];
    printf("enter T\n");
    for(int i = 0; i < n; i++){
        printf("T.x[%d]: ",i);
        scanf("%f",&T[i].x);
        printf("T.y[%d]: ",i);
        scanf("%f",&T[i].y);
    }
    coo a;
    coo b;
    for(int i = 0; i < n ; i++)
        for(int j = i + 1; j < n ; j++){
            if(T[i].x > T[j].x){
                a = T[i];
                T[i] = T[j];
                T[j] = a;                 
            }
            if(T[i].x == T[j].x){
                if(T[i].y > T[j].y){
                    b = T[i];
                    T[i] = T[j];
                    T[j] = b;
                }
            }
        }

    int c = 0;
    int cr = 0;
    int cal1;
    int cal2;
    for(int i = 0; i < n - 3; i++)
        for(int j = i + 1; j < n - 2 ; j++)
            for(int r = j + 1; r < n - 1; r++)
                for(int k = r + 1; k < n; k++){  
                    if(T[i].x == T[j].x && T[i].y != T[j].y && T[i].x != T[r].x && T[i].y == T[r].y && T[i].x != T[k].x && T[i].y != T[k].y )
                        if(T[j].x != T[r].x && T[j].y != T[r].y && T[j].x != T[k].x && T[j].y == T[k].y)
                            if(T[r].x == T[k].x && T[r].y != T[k].y){
                                c++;
                                printf("this is rectangle: a = (%.0f,%.0f) b = (%.0f,%.0f)  c = (%.0f,%.0f)  d = (%.0f,%.0f)\n",T[i].x,T[i].y,T[j].x,T[j].y,T[r].x,T[r].y,T[k].x,T[k].y);
                            }
                    if(T[i].x != T[k].x && T[i].y == T[k].y && T[i].x != T[j].x && T[i].x != T[r].x && T[i].y != T[j].y && T[i].y != T[r].y)
                        if(T[j].x == T[r].x && T[j].y != T[r].y && T[j].x != T[k].x && T[j].y != T[k].y)
                            if(T[r].x != T[k].x && T[r].y != T[k].y){     
                                if(((T[k].x - T[i].x) / 2) == ( (T[r].y - T[j].y) / 2)){            
                                    if(T[j].y + ((T[r].y - T[j].y) / 2) == T[i].y){
                                        cr++;
                                        printf("this is inverted rectangle: a = (%.0f,%.0f) b = (%.0f,%.0f)  c = (%.0f,%.0f)  d = (%.0f,%.0f)\n",T[i].x,T[i].y,T[j].x,T[j].y,T[r].x,T[r].y,T[k].x,T[k].y);
                                    }
                                }
                            }
                }
    printf("c = %d\n",c);
    printf("cr = %d\n",cr);
}
