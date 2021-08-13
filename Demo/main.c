/* Works with structure and finished Game data Input
  Next BatsMan on -> Demo2 */

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

COORD coord = {0,0};
void gotoxy (int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ppt();
void view();
void date();
void menu();
void inputGameDetails();



struct gameDetails {
    char competitionName[50];
    char venue[50];
    char matchBetween[20];
    char versus[20];
    char tossWonBy[20];
    char electedTo[15];
    char date[15];
} gameDetails;

struct matchDetails {
    int innings;
    int totalRuns;
    float overPlayed;
    float runRate;
} inningsA, inningsB;

struct batsMan {
    char name[30];
    int runs;
    int balls;
    char status[10];
    int fours;
    int sixes;
} batsManTeamA[11], batsManTeamB[11];

struct bowler {
    char name[30];
    float overs;
    int runs;
    int wicket;
    int maiden;
    float iconomy;
    int extra;
} bowlerTeamA[8], bowlerTeamB[8];
    
int main() {
    
    menu();
    return 0;
}

void ppt() {
    
    system("cls");
    
    //game_details
    gotoxy(0,0);
    printf("Competition:");
    gotoxy(35,0);
    printf("Venue:");
    gotoxy(0,2);
    printf("Match Between:");
    gotoxy(35,2);
    printf("Versus:");
    gotoxy(0,4);
    printf("Toss won by:");
    gotoxy(35,4);
    printf("Elected to:");
    gotoxy(0,6);
    printf("Inning of:");
    gotoxy(35,6);
    printf("Date:");
 
    //Batting
    gotoxy(0,8);
    printf("%c",179);
    gotoxy(8,8);
    printf("Batsmanname");
    gotoxy(0,10);
    for(int i=0; i<11; i++)
    printf("%cBatsman %d:\n",179,i+1);
    gotoxy(39,8);
    printf("Runs");
    gotoxy(53,8);
    printf("Balls");
    gotoxy(65,8);
    printf("4s");
    gotoxy(75,8);
    printf("6s");
    
    //matchDetails
    gotoxy(23,22);
    printf("Total Runs: ");
    gotoxy(45,22);
    printf("Over: ");
    gotoxy(60,22);
    printf("Run Rate: ");
    
    //Bowling
    gotoxy(5,24);
    printf("Bowlers");
    gotoxy(35,24);
    printf("overs");
    gotoxy(42,24);
    printf("Maidens");
    gotoxy(50,24);
    printf("Economy");
    gotoxy(58,24);
    printf("No balls");
    gotoxy(68,24);
    printf("BTICO");
    gotoxy(75,24);
    printf("Runs");
    
    //Table
    gotoxy(0,3);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,1);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,5);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(35,0);
    for (int i=0; i<33; i++)
    {
    gotoxy(34,i);
        printf("%c",182);
    }
    gotoxy(0,7);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,21);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,9);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,23);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,25);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,32);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(61,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(61,10+(i+1));
    }
    gotoxy(71,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(71,10+(i+1));
    }
    gotoxy(49,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(49,10+(i+1));
    }
    gotoxy(0,40);
    for(int i=0;i<79;i++)
    {
        printf("%c",205);
    }
}



void inputGameDetails() {
    ppt();
    gotoxy(16,0);
    gets(gameDetails.competitionName);
    gotoxy(47,0);
    gets(gameDetails.venue);
    gotoxy(16,2);
    gets(gameDetails.matchBetween);
    gotoxy(47,2);
    gets(gameDetails.versus);
    gotoxy(16,4);
    gets(gameDetails.tossWonBy);
    gotoxy(47,4);
    gets(gameDetails.electedTo);
    int n;
    gotoxy(16,6);
    scanf("%d", &n);
    if(n == 1)
        inningsA.innings = 1;
    else inningsB.innings = 2; 
    fflush(stdin);
    gotoxy(47,6);
    gets(gameDetails.date);
    return;
}

void menu() {
    system("cls");
    int n;
    printf("\n\n\t\t\t\t\tMENU:\n");
    printf("\n\n\n\t\t\t\t1.New scoresheet:\n");
    printf("\t\t\t\t2.View scoresheet:\n");
    printf("\t\t\t\t3.Exit:\n\t\t");
    printf("\n\t\t\tYour Choise: ");
    scanf("%d", &n);
    fflush(stdin);
    switch(n) {
        case 1: inputGameDetails(); 
                gotoxy(90,6);
                printf("Game Details Saved");
                gotoxy(90,7);
                printf("Press Anything to go Menu");
                getch(); menu(); break;
        case 2: view();
                gotoxy(90, 10);
                printf("Press anything to menu");
                getch(); menu(); break;
        case 3: exit(0); break;
        default: menu();
    }
}

void view() {
    ppt();
    gotoxy(16,0);
    printf("%s",gameDetails.competitionName);
    gotoxy(47,0);
    printf("%s",gameDetails.venue);
    gotoxy(16,2);
    printf("%s",gameDetails.matchBetween);
    gotoxy(47,2);
    printf("%s",gameDetails.versus);
    gotoxy(16,4);
    printf("%s",gameDetails.tossWonBy);
    gotoxy(47,4);
    printf("%s",gameDetails.electedTo);
    gotoxy(47,6);
    printf("%s",gameDetails.date);
}