#include <stdio.h>

#define ROWS 20
#define COLS 40

char a[ROWS][COLS];

// Function to clear the canvas
void clearCanvas(){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            a[i][j]='_';
        }
    }
}

void display(){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}

void drawLine()
{
    int row,i;

    printf("Enter row number: ");
    scanf("%d",&row);

    for(i=0;i<COLS;i++){
        a[row][i]='*';
    }
}

void drawRectangle()
{
    int r,c,h,w,i,j;

    printf("Enter starting row, starting column, height, and width: ");
    scanf("%d%d%d%d",&r,&c,&h,&w);

    for(i=r;i<r+h;i++){
        for(j=c;j<c+w;j++){
            if(i<ROWS && j<COLS)
                a[i][j]='*';
        }
    }
}

void drawTriangle()
{
    int r,c,h,i,j;

    printf("Enter row column height: ");
    scanf("%d%d%d",&r,&c,&h);

    for(i=0;i<h;i++){
        for(j=0;j<=i;j++)
        {
            if(r+i<ROWS && c+j<COLS)
                a[r+i][c+j]='*';
        }
    }
}

void drawCircle()
{
    int x,y,r,i,j;

    printf("Enter center row center column radius: ");
    scanf("%d%d%d",&x,&y,&r);

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            int dx=i-x;
            int dy=j-y;

            if(dx*dx+dy*dy<=r*r){
                a[i][j]='*';
            }
        }
    }
}

void deleteArea()
{
    int r,c,h,w,i,j;

    printf("Enter row column height width: ");
    scanf("%d%d%d%d",&r,&c,&h,&w);

    for(i=r;i<r+h;i++){
        for(j=c;j<c+w;j++){
            if(i<ROWS && j<COLS)
                a[i][j]='_';
        }
    }
}

int main(){
    int ch;
    clearCanvas();

    do
    {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: drawLine(); break;
            case 2: drawRectangle(); break;
            case 3: drawTriangle(); break;
            case 4: drawCircle(); break;
            case 5: deleteArea(); break;
            case 6: display(); break;
            case 7: printf("Program Ended\n"); break;
            default: printf("Invalid Choice\n");
        }

    }while(ch!=7);

    return 0;
}
