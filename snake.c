#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=40,width=100,x,y,fruitx,fruity,flag,gameend,score=0;
// x & y for snake coordinate,
int tailx[100],taily[100];
int piece=0;
void makelogic()   //to control flag input and direction
{
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx=tailx[0];
    prevy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<=piece;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
        case 1:
        {
            x--;
            break;
        }
        case 2:
        {
            x++;
            break;
        }
        case 3:
        {
            y--;
            break;
        }
        case 4:
        {
            y++;
            break;
        }
    }
    if(x==0 || x==height ||y==0 || y==width)
    {
        gameend=1;
    }
    if(x==fruitx && y==fruity)
    {
        label3:
        fruitx=rand()%height;  //always less than 20 
        if(fruitx==0)
        goto label3;

        label4:
        fruity=rand()%width;  // remainder is always less than 20
        if(fruity==0)
        goto label4;
    }
}
void input()  //for keyboard movement of sanke
{
    if(kbhit())
    {
        switch(getch())
        {
            case'w':
            {
                flag=1;
                break;
            }
            case's':
            {
                flag=2;
                break;
            }    
        
            case'a':
            {
                flag=3;
                break;
            }
            case'd':
            {
                flag=4;
                break;
            }
        }    
    }
}
void setup()   //function for snake position
{
    x=height/2;
    y=width/2;

    label1:
    fruitx=rand()%height;  //always less than 20 
    if(fruitx==0)
    goto label1;

    label2:
    fruity=rand()%width;  // remainder is always less than 20
    if(fruity==0)
    goto label2;
    gameend=0;
    score++;
    piece++;
}
void draw()   //function for border
{
    system("cls");    //alternative of clrscr();  ,  to make frames overlap
    int i,j,k,ch;  // i for height, j for width
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0 || i==height || j==0 || j==width) //print boundary only
            {
                printf("*");
            }
            else
            {
                if(i==x && j==y)
                {
                    printf("0");
                }
                else if(i==fruitx && j==fruity)
                {
                    printf("@");
                }
                else
                {
                    ch=0;
                
                    if(ch==0)
                    {
                    printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }    
printf("Your score is  %d",score);    //check \t;
}
int main()
{
    setup();
    while(gameend!=1)
    {
        input();
        draw();
        makelogic();
    }
}