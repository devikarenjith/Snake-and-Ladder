#include<stdio.h>
#include<stdlib.h>

/****FUNCTIONS USED IN THIS CODE****/
void PLAY();
void QUIT();
void MOVE(int, int*);
void PRINTSNAKESANDLADDERS();
void PRINT(int*);
void WON();
void QUIT();



/****PRINTS THE POSITIONS OF SNAKES AND LADDERS****/
void PRINTSNAKESANDLADDERS()
{
	char indent[]="\t\t\t\t\t\t\t";
	printf("%sSNAKES\n",indent);
	printf("%s27-5\n%s40-3\n%s43-18\n%s54-31\n%s66-45\n%s76-58\n%s99-41\n%s89-53\n\n",indent,indent,indent,indent,indent,indent,indent,indent);
	printf("%sLADDERS\n",indent);
	printf("%s4-25\n%s13-46\n%s42-63\n%s33-49\n%s50-69\n%s62-81\n%s74-92\n",indent,indent,indent,indent,indent,indent,indent);
}




void WON()
{
    int input;
    char ch;
    for(int i=0;i<18;i++)
        printf("\n");
    printf("\t\t\t\t\t\t\t1. START A NEW GAME\n");
    printf("\t\t\t\t\t\t\t2. QUIT THE GAME\n");
    printf("\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&input);
    if(input==1)
	    PLAY();
    else if(input==2)
	    QUIT();
    else
    {
            system("clear");
            for(int i=0;i<17;i++)
                    printf("\n");
            printf("\t\t\t\t\t\t\t     OOPS:0\n");
            printf("\t\t\t\t\t\t\tEntered invalid input!!\n");
            printf("\t\t\t\t\t\t\tPlease try again\n");
            ch=getchar();
	    WON();
    }
}




/****PRINTS THE PRESENT VIEW OF THE BOARD****/
void PRINT(int* curpos)
{
    if(curpos[1]>99)
    {
        for(int i=0;i<18;i++)
            printf("\n");
        printf("\t\t\t\t\t\t\tHURRAY!!PLAYER 2 HAS WON THE GAME!!");
        char ch=getchar();
        system("clear");
        WON();
        return;
    }

    if(curpos[0]>99)
    {
        for(int i=0;i<18;i++)
            printf("\n");
        printf("\t\t\t\t\t\t\tHURRAY!!PLAYER 1 HAS WON THE GAME!!");
        char ch=getchar();
        system("clear");
        WON();
        return;
    }

    char ch;
    printf("\t\t\t\t\t\t\tPRESENT VIEW OF THE BOARD\n");
    PRINTSNAKESANDLADDERS();
    if(curpos[0]==0)
        printf("\t\t\t\t\t\t\tPlayer 1 has not yet entered\n");


    if(curpos[1]==0)
        printf("\t\t\t\t\t\t\tPlayer 2 has not yet entered\n");
 
    int num;
    printf("\n\n");
    for(int i=10;i>=1;i--)
    {
        if(i%2!=0)
            num=10*(i-1)+1;
        else
            num=10*i;
            
	printf("\t\t\t");
        for(int j=1;j<=10;j++)
        {
            if(curpos[0]==num && curpos[1]==num)
                printf("P1 P2    ");
            else if(num==curpos[0])
                printf("   P1    ");
            else if(num==curpos[1])
                printf("   P2    ");
            else
                printf("%5d    ",num);
                
            if(i%2==0)
                num--;
            else
                num++;
        }
        printf("\n");
        printf("\t\t\t--------------------------------------------------------------------------------------\n");
    }
    ch=getchar();
}



/****MOVES THE PLAYERS IN THE BOARD****/
void MOVE(int p,int* curpos)
{
   int dice=rand()%6 + 1;
   system("clear");
   for(int i=0;i<5;i++)
	   printf("\n");
   printf("\t\t\t\t\t\t\t    The dice value is: %d\n",dice);
   curpos[p-1]=dice+curpos[p-1];
   switch(curpos[p-1])
   {
	   case 4:
                   curpos[p-1]=25;
                   break;
	   case 13:
		   curpos[p-1]=46;
		   break;
	   case 27:
                   curpos[p-1]=5;
                   break;
	   case 33:
                   curpos[p-1]=49;
                   break;
	   case 40:
                   curpos[p-1]=3;
                   break;
	   case 42:
                   curpos[p-1]=63;
                   break;
	   case 43:
                   curpos[p-1]=18;
                   break;
	   case 50:
                   curpos[p-1]=69;
                   break;
	   case 54:
                   curpos[p-1]=31;
                   break;
	   case 62:
                   curpos[p-1]=81;
                   break;
	   case 66:
                   curpos[p-1]=45;
                   break;
	   case 76:
                   curpos[p-1]=58;
                   break;
	   case 89:
                   curpos[p-1]=53;
                   break;
	   case 99:
                   curpos[p-1]=41;
                   break;
   }
   PRINT(curpos);
}




/****QUITS THE GAME****/
void QUIT()
{
    system("clear");
    char ch;
    for(int i=0;i<18;i++)
	    printf("\n");
    printf("\t\t\t\t\t\t\tTHANK YOU FOR PLAYING\n\t\t\t\t\t\t\t     SEE U LATER\n");
    ch=getchar();
    system("clear");
    exit(0);
}




/****CALLS THE FUNCTION MOVES****/
void PLAY()
{
    int curpos[2]={0};
    char junk;
    char ch;
    int input;

    while(1)
    {
        system("clear");
        for(int i=0;i<13;i++)
                printf("\n");
        printf("\t\t\t\t\t\t\t     OPTIONS\n");
        printf("\t\t\t\t\t\t\t1. Player 1 plays\n");
        printf("\t\t\t\t\t\t\t2. Player 2 plays\n");
        printf("\t\t\t\t\t\t\t3. Quit the game\n");
        printf("\t\t\t\t\t\t\tEnter your choice: ");

        scanf("%d",&input);
        junk=getchar();

        if(input==1)
            MOVE(1,curpos);
        else if(input==2)
            MOVE(2,curpos);
        else if(input==3)
            QUIT();
        else
        {
            system("clear");
            for(int i=0;i<17;i++)
                    printf("\n");
            printf("\t\t\t\t\t\t\t     OOPS:0\n");
            printf("\t\t\t\t\t\t\tEntered invalid input!!\n");
            printf("\t\t\t\t\t\t\tPlease try again\n");
            ch=getchar();
        }
    }
}

void main()
{
    PLAY();
}

