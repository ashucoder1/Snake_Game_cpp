
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