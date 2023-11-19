#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

void player_vs_player();
void player_vs_computer();
void board_creating();
void board_marking();
int checking_winner();
void data_saving();

char cells[10]={'O','1','2','3','4','5','6','7','8','9'};    //global variable
int num1[],num2[];
char mark;
int choise_num,selection,result,player=1,num,x=0,y=0,play_turn=1;;
int arry1[9],arry2[9];

struct user
{
    char name[50];
    int moves[5];

}play1,play2;

//------------------------------------------------------------------------------------------------------------------------
void board_creating()
{
    system("cls");   //to clear the console
    printf("\n\t\t---TIC TAC TOE---\n\n");
    printf("\t     --%s as 'O' & %s as 'X'--\n\n",play1.name,play2.name);

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c\n",cells[1],cells[2],cells[3]);        //first row , cells[1]=1
    printf("\t\t_____|_____|_____\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c\n",cells[4],cells[5],cells[6]);        //second row
    printf("\t\t_____|_____|_____\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c\n",cells[7],cells[8],cells[9]);        //third row
    printf("\t\t     |     |     \n\n");
}

//-------------------------------------------------------------------------------------------------------------------------
void board_marking()
{
    if(selection==1 && cells[1]=='1')
        cells[1]=mark;

    else if(selection==2 && cells[2]=='2')
        cells[2]=mark;

    else if(selection==3 && cells[3]=='3')
        cells[3]=mark;

    else if(selection==4 && cells[4]=='4')
        cells[4]=mark;

    else if(selection==5 && cells[5]=='5')
        cells[5]=mark;

    else if(selection==6 && cells[6]=='6')
        cells[6]=mark;

    else if(selection==7 && cells[7]=='7')
        cells[7]=mark;

    else if(selection==8 && cells[8]=='8')
        cells[8]=mark;

    else if(selection==9 && cells[9]=='9')
        cells[9]=mark;

    else
    {
        printf("Invalid Input");
    }
}

//---------------------------------------------------------------------------------------------------------------------------
int checking_winner()
{
    if(cells[1]==cells[2] && cells[2]==cells[3])
        return 1;     //result 1 for game is over with result
    else if(cells[4]==cells[5] && cells[5]==cells[6])      //horizontal
        return 1;
    else if(cells[7]==cells[8] && cells[8]==cells[9])
        return 1;


    else if(cells[1]==cells[4] && cells[4]==cells[7])
        return 1;
    else if(cells[2]==cells[5] && cells[5]==cells[8])      //vertical
        return 1;
    else if(cells[3]==cells[6] && cells[6]==cells[9])
        return 1;


    else if(cells[1]==cells[5] && cells[5]==cells[9])
        return 1;
    else if(cells[3]==cells[5] && cells[5]==cells[7])      //diagonal
        return 1;

    else if(cells[1]!='1' && cells[2]!='2' && cells[3]!='3' && cells[4]!='4' && cells[5]!='5' && cells[6]!='6' &&
            cells[7]!='7' && cells[8]!='8' && cells[9]!='9')     //not match each one
        return 0;    //result 0 for game is over with no result

    else
        return -1;   //result -1 for game is in progress
}
//------------------------------------------------------------------------------------------------------------------------
void player_vs_player()
{
    system("cls");
    printf("\n\t\t---TIC TAC TOE---\n\n");
    printf("--Player vs Player--\n\n");

    printf("Player 1 name: ");
    scanf("%s",play1.name);

    printf("Player 2 name: ");
    scanf("%s",play2.name);
    printf("\n");
    system("pause");    //waiting some time

    int j=0,k=0;

    do
    {
       if(cells[0]=='O')
       {
            board_creating();

            player=(player%2)? 1:2;    //change player    1%2=1  , 2%2=0
            printf(" %s,enter a number : ",play1.name);

            scanf("%d",&selection);      //take player input
            mark=(player==1)? 'O':'X';   //choose mark

            // check number is valid
            while(1>selection || selection>9)
            {
                printf(" Enter a valid number !\n\n");
                printf(" %s,enter a number : ",play1.name);
                scanf("%d",&selection);
            }

            //check selection is already taken
            while(cells[selection]=='O' || cells[selection]=='X')
            {
                printf(" Enter a not taken number !\n\n");
                printf(" %s,enter a number : ",play1.name);
                scanf("%d",&selection);
            }

            //moves save in move[5]
            if(j==k)
            {
                arry1[j]=selection;
            }
            j++;
            k++;

            board_marking(selection,mark);   //mark X or O in the board
            result=checking_winner();   //get result
            player++;
            cells[0]='X';
       }
       else
       {
            board_creating();
            player=(player%2)? 1:2;    //change player    1%2=1  , 2%2=0
            printf(" %s,enter a number : ",play2.name);
            scanf("%d",&selection);      //take player input
            mark=(player==1)? 'O':'X';   //choose mark

            // check number is valid
            while(1>selection || selection>9)
            {
                printf(" Enter a valid number !\n\n");
                printf(" %s,enter a number : ",play2.name);
                scanf("%d",&selection);
            }

            //check selection is already taken
            while(cells[selection]=='O' || cells[selection]=='X')
            {
                printf(" Enter a not taken number !\n\n");
                printf(" %s,enter a number : ",play2.name);
                scanf("%d",&selection);
            }

            //moves save in move[5]
            if(j==k)
            {
                arry2[j]=selection;
            }
            j++;
            k++;

            board_marking(selection,mark);   //mark X or O in the board
            result=checking_winner();   //get result
            player++;
            cells[0]='O';
       }

    }while(result==-1);

    if(result==1)  //mention draw or win
     {   if((--x%2)==0)
         {  if(cells[0]=='X')
            {   printf("--- %s is the WINNER ---\n",play1.name);
                printf("\n");
                system("pause");
                system("cls");
            }else{
                printf("--- %s is the WINNER ---\n",play2.name);
                printf("\n");
                system("pause");
                system("cls");
            }
         }else{
            if(cells[0]=='O')
            {   printf("--- %s is the WINNER ---\n",play2.name);
                printf("\n");
                system("pause");
                system("cls");
            }else{
                printf("--- %s is the WINNER ---\n",play1.name);
                printf("\n");
                system("pause");
                system("cls");
            }
          }
     }
     else
     {
         printf("---Draw Again---\n");
         printf("\n");
         system("pause");
         system("cls");
     }

    data_saving();
}

//-------------------------------------------------------------------------------------------------------------------------
void player_vs_computer()
{
    system("cls");
    printf("\n\t\t---TIC TAC TOE---\n\n");
    printf("--Player vs computer--\n\n");

    printf("Player 1 name: ");
    scanf("%s",play1.name);

    strcpy(play2.name,"Computer");
    printf("Player 2 name: %s",play2.name);
    printf("\n\n");
    system("pause");    //waiting some time

    int j=0,k=0;

    do
    {
       if(cells[0]=='O')
       {
            board_creating();

            player=(player%2)? 1:2;    //change player    1%2=1  , 2%2=0
            printf(" %s,enter a number : ",play1.name);

            scanf("%d",&selection);      //take player input
            mark=(player==1)? 'O':'X';   //choose mark

            // check number is valid
            while(1>selection || selection>9)
            {
                printf(" Enter a valid number !\n\n");
                printf(" %s,enter a number : ",play1.name);
                scanf("%d",&selection);
            }

            //check selection is already taken
            while(cells[selection]=='O' || cells[selection]=='X')
            {
                printf(" Enter a not taken number !\n\n");
                printf(" %s,enter a number : ",play1.name);
                scanf("%d",&selection);
            }

            //moves save in move[5]
            if(j==k)
            {
                arry1[j]=selection;
            }
            j++;
            k++;

            board_marking(selection,mark);   //mark X or O in the board
            result=checking_winner();   //get result
            player++;
            cells[0]='X';
       }
       else
       {
            board_creating();
            player=(player%2)? 1:2;    //change player    1%2=1  , 2%2=0
            strcpy(play2.name,"Computer");
            printf("\n");
            printf(" %s,enter a number : \n",play2.name);

            selection=rand()%10;    //take random number less than 10

            mark=(player==1)? 'O':'X';   //choose mark

            //check selection is already taken
            while(cells[selection]=='O' || cells[selection]=='X')
            {
                printf(" Enter a not taken number !\n\n");
                printf(" %s,enter a number : \n",play2.name);
                selection=rand()%10;
            }

            //moves save in move[5]
            if(j==k)
            {
                arry2[j]=selection;
            }
            j++;
            k++;

            board_marking();  //mark X or O in the board
            result=checking_winner();   //get result
            player++;
            cells[0]='O';
       }

    }while(result==-1);

    if(result==1)  //mention draw or win
     {   if((--y%2)==0)
         {  if(cells[0]=='X')
            {   printf("--- %s is the WINNER ---\n",play1.name);
                printf("\n");
                system("pause");
                system("cls");
            }else{
                printf("--- %s is the WINNER ---\n",play2.name);
                printf("\n");
                system("pause");
                system("cls");
            }
         }else{
            if(cells[0]=='O')
            {   printf("--- %s is the WINNER ---\n",play2.name);
                printf("\n");
                system("pause");
                system("cls");
            }else{
                printf("--- %s is the WINNER ---\n",play1.name);
                printf("\n");
                system("pause");
                system("cls");
            }
          }
     }
     else
     {
         printf("---Draw Again---\n");
         printf("\n");
         system("pause");
         system("cls");
     }

    data_saving();

}

//-------------------------------------------------------------------------------------------------------------------------
void data_saving()
{
    FILE *save_data;
    save_data=fopen("savemoves.txt","a");

    if(save_data == NULL)
    {
        printf("File can't be find !\n");
        return 0;
    }
    else
    {
        for(int i=0;i<9;i++)
        {
            if(arry1[i]!=0)
            {
                fprintf(save_data,"Movement of player %s : %d\n",play1.name,arry1[i]);
            }
            if(arry2[i]!=0)
            {
                fprintf(save_data,"Movement of player %s : %d\n",play2.name,arry2[i]);
            }
        }
    }
    save_data=fopen("savemoves.txt","w");
    fclose(save_data);
}

//-------------------------------------------------------------------------------------------------------------------------
int main()
{
    printf("\n\t\t---TIC TAC TOE---\n\n");
    printf("1.Player vs Player\n");
    printf("2.Player vs Computer\n");
    printf("3.Exit\n\n");
    printf("Enter your choice 1 or 2 or 3 :  ");
    scanf("%d",&choise_num);

    if(choise_num==1)
    {
        num1[x]=choise_num;
        x++;
    }
    else if(choise_num==2)
    {
        num1[y]=choise_num;
        y++;
    }
    else
    {
        exit(0);
    }

    while(choise_num==1 || choise_num==2 ||choise_num==3 )
    {
        if(choise_num==1)
        {
            if((cells[1]!='1' || cells[2]!='2' || cells[3]!='3' || cells[4]!='4' || cells[5]!='5' || cells[6]!='6' ||
            cells[7]!='7' || cells[8]!='8' || cells[9]!='9'))
            {
                cells[1]='1';
                cells[2]='2';
                cells[3]='3';
                cells[4]='4';
                cells[5]='5';
                cells[6]='6';
                cells[7]='7';
                cells[8]='8';
                cells[9]='9';
            }
            player_vs_player();
        }
        if(choise_num==2)
        {
            if((cells[1]!='1' || cells[2]!='2' || cells[3]!='3' || cells[4]!='4' || cells[5]!='5' || cells[6]!='6' ||
            cells[7]!='7' || cells[8]!='8' || cells[9]!='9'))
            {
                cells[1]='1';
                cells[2]='2';
                cells[3]='3';
                cells[4]='4';
                cells[5]='5';
                cells[6]='6';
                cells[7]='7';
                cells[8]='8';
                cells[9]='9';
            }
            player_vs_computer();
        }

        printf("\n\t\t---TIC TAC TOE---\n\n");
        printf("1.Player vs Player\n");
        printf("2.Player vs Computer\n");
        printf("3.Exit\n\n");
        printf("Enter your choice 1 or 2 or 3 :  ");
        scanf("%d",&choise_num);

        if(choise_num==1)
        {
            num1[x]=choise_num;
            x++;
        }
        else if(choise_num==2)
        {
            num1[y]=choise_num;
            y++;
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}


