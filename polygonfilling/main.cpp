#include <stdio.h>
#include<stdlib.h>
int z=0;
void floodfill(int r[5][5], int x, int y)
{  z++;
    if( r[x][y]==2){
        r[x][y]=3;
        floodfill(r,x+1,y);
        floodfill(r,x-1,y);
        floodfill(r,x,y+1);
        floodfill(r,x,y-1);

    }
}
main()
{
    int r[5][5] = {{0, 1, 0, 0, 0},
                   {1, 2, 1, 0, 0},
                   {1, 2, 2, 1, 0},
                   {1, 2, 2, 2, 1},
                   {0, 1, 1, 1, 0}};
    printf("before filling\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
    floodfill(r,1,1);
    printf("\n after filling \n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }

    printf("numver of recursive calls=%d",z);
}
