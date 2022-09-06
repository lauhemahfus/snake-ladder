#include <bits/stdc++.h>
#include <conio.h>
#include "windows.h"

using namespace std;

void player2();
void player3();
void player4();
void player_ai();
int roll_dice();
void show_dice(int n);
void show_SnL(int n);
int game_loop(int prev_score, string name);
void board2(int p1, int p2, string p1_name, string p2_name);
void board3(int p1, int p2, int p3,  string p1_name, string p2_name, string p3_name);
void board4(int p1, int p2, int p3, int p4,  string p1_name, string p2_name, string p3_name, string p4_name);
void main_menu();
void menu_player();
void welcome_page();
void winner(string s);
void team();
void clrscr();

int main(){
    srand(time(0));
    welcome_page();
    getch();
    clrscr();
    team();
    getch();
    clrscr();
    main_menu();
}

void main_menu()
{
    char choice;
    clrscr();
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t How do you want to play";
    cout << "\n\n\n";
    cout << "\t\t\t\t1. Player vs Player\n";
    cout << "\n\t\t\t\t2. Player vs Ai\n";
    cout << "\n\t\t\t\t0. Exit\n";
    cout << "\n\n\n\n\t\t\t\t\tEnter your choice: ";
    choice = getch();
    switch(choice)
    {
        case '1':
            menu_player();
            break;
        case '2':
            player_ai();
            break;
        case '0':
            exit(1);
            break;
        default:
            cout << "\t\t\t\tInvalid input.";
            getch();
            main_menu();
    }
}
void menu_player()
{
    char choice;
    clrscr();
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t How many player you want to play with";
    cout << "\n\n\n";
    cout << "\t\t\t\t1. 2 Player\n";
    cout << "\n\t\t\t\t2. 3 Player\n";
    cout << "\n\t\t\t\t3. 4 Player\n";
    cout << "\n\t\t\t\t0. Back to Main Menu\n";
    cout << "\n\n\n\n\t\t\t\t\tEnter your choice: ";
    choice = getch();
    switch(choice)
    {
        case '1':
            player2();
            break;
        case '2':
            player3();
            break;
        case '3':
            player4();
            break;
        case '0':
            main_menu();
            break;
        default:
            cout << "\t\t\t\tInvalid input.";
            getch();
            menu_player();
    }
}
int roll_dice(){
    return rand()%6 +1;
}

void player2(){
    clrscr();
    string p1_name , p2_name;
    cout << "\n\n\n\n";
    cout << "\n\t\t\tEnter Player 1 Name: "; cin >> p1_name;
    cout << "\n\t\t\tEnter Player 2 Name: "; cin >> p2_name;
    clrscr();
    int p1_score =0, p2_score =0;
    while(1){
        clrscr();
        board2(p1_score, p2_score, p1_name, p2_name);
        p1_score = game_loop(p1_score, p1_name);
        clrscr();
        board2(p1_score, p2_score, p1_name, p2_name);
        if(p1_score== 100){
            winner(p1_name);
        }
        p2_score = game_loop(p2_score, p2_name);
        if(p2_score== 100){
            winner(p2_name);
        }
    }
}
void player3(){
    clrscr();
    string p1_name , p2_name, p3_name;
    cout << "\n\n\n\n";
    cout << "\n\t\t\tEnter Player 1 Name: "; cin >> p1_name;
    cout << "\n\t\t\tEnter Player 2 Name: "; cin >> p2_name;
    cout << "\n\t\t\tEnter Player 3 Name: "; cin >> p3_name;
    int p1_score =0, p2_score =0, p3_score =0;
    while(1){
        clrscr();
        board3(p1_score, p2_score,p3_score, p1_name, p2_name, p3_name);
        p1_score = game_loop(p1_score, p1_name);
        if(p1_score== 100){
            clrscr();
            winner(p1_name);
        }
        clrscr();
        board3(p1_score, p2_score,p3_score, p1_name, p2_name, p3_name);
        p2_score = game_loop(p2_score, p2_name);
        if(p2_score== 100){
            clrscr();
            winner(p2_name);
        }
        clrscr();
        board3(p1_score, p2_score,p3_score, p1_name, p2_name, p3_name);
        p3_score = game_loop(p3_score, p3_name);
        if(p3_score== 100){
            clrscr();
            winner(p3_name);
        }
    }
}
void player4(){
    clrscr();
    string p1_name , p2_name, p3_name, p4_name;
    cout << "\n\n\n\n";
    cout << "\t\t\tEnter Player 1 Name: "; cin >> p1_name;
    cout << "\n\t\t\tEnter Player 2 Name: "; cin >> p2_name;
    cout << "\n\t\t\tEnter Player 3 Name: "; cin >> p3_name;
    cout << "\n\t\t\tEnter Player 4 Name: "; cin >> p4_name;
    int p1_score =0, p2_score =0, p3_score =0, p4_score =0;
    while(1){
        clrscr();
        board4(p1_score, p2_score,p3_score,p4_score, p1_name, p2_name, p3_name, p4_name);
        p1_score = game_loop(p1_score, p1_name);
        if(p1_score== 100){
            clrscr();
            winner(p1_name);
        }
        clrscr();
        board4(p1_score, p2_score,p3_score,p4_score, p1_name, p2_name, p3_name, p4_name);
        p2_score = game_loop(p2_score, p2_name);
        if(p2_score== 100){
            clrscr();
            winner(p2_name);
        }
        clrscr();
        board4(p1_score, p2_score,p3_score,p4_score, p1_name, p2_name, p3_name, p4_name);
        p3_score = game_loop(p3_score, p3_name);
        if(p3_score== 100){
            clrscr();
            winner(p3_name);
        }
        clrscr();
        board4(p1_score, p2_score,p3_score,p4_score, p1_name, p2_name, p3_name, p4_name);
        p4_score = game_loop(p4_score, p4_name);
        if(p4_score== 100){
            clrscr();
            winner(p4_name);
        }
    }
}
void player_ai(){
    clrscr();
    string p1_name , p2_name;
    cout << "\n\n\n\n";
    cout << "\t\t\tEnter Player 1 Name: "; cin >> p1_name;
    p2_name = "AI";
    clrscr();
    int p1_score =0, p2_score =0;
    while(1){
        clrscr();
        board2(p1_score, p2_score, p1_name, p2_name);
        p1_score = game_loop(p1_score, p1_name);
        clrscr();
        board2(p1_score, p2_score, p1_name, p2_name);
        if(p1_score== 100){
            winner(p1_name);
        }
        p2_score = game_loop(p2_score, p2_name);
        if(p2_score== 100){
            winner(p2_name);
        }
    }
}
int game_loop(int prev_score, string name){
        int x;
        cout << name << " Roll: " <<endl;
        getch();
        x = roll_dice();
        if(prev_score != 0){
            show_dice(x);
            if(prev_score+x <= 100) prev_score+=x;
            if(prev_score == 7){
                show_SnL(1);
                prev_score = 48;
            }
            else if (prev_score == 57){
                show_SnL(1);
                prev_score = 85;
            }
            else if (prev_score == 68){
                show_SnL(1);
                prev_score = 94;
            }
            else if (prev_score == 45){
                show_SnL(0);
                prev_score = 2;
            }
            else if (prev_score == 62){
                show_SnL(0);
                prev_score = 22;
            }
            else if (prev_score == 88){
                show_SnL(0);
                prev_score = 11;
            }
            else if (prev_score == 98){
                show_SnL(0);
                prev_score = 32;
            }
        }else{
            show_dice(x);
            if(x == 1){
                x = roll_dice();
                prev_score+=x;
                show_dice(x);
            }
        }
        return prev_score;
}
void show_dice(int n){
    switch(n){
    case 1:
         cout << " -------\n";
         cout << " |     |\n";
         cout << " |  *  |\n";
         cout << " |     |\n";
         cout << " -------\n";
         break;
    case 2:
         cout << " -------\n";
         cout << " | *   |\n";
         cout << " |     |\n";
         cout << " |    *|\n";
         cout << " -------\n";
         break;
    case 3:
         cout << " -------\n";
         cout << " |*    |\n";
         cout << " |  *  |\n";
         cout << " |    *|\n";
         cout << " -------\n";
         break;
    case 4:
         cout << " -------\n";
         cout << " |*   *|\n";
         cout << " |     |\n";
         cout << " |*   *|\n";
         cout << " -------\n";
         break;
    case 5:
         cout << " -------\n";
         cout << " |*   *|\n";
         cout << " |  *  |\n";
         cout << " |*   *|\n";
         cout << " -------\n";
         break;
    case 6:
         cout << " -------\n";
         cout << " |*   *|\n";
         cout << " |*   *|\n";
         cout << " |*   *|\n";
         cout << " -------\n";
         break;
    }
    getch();
}
void show_SnL(int n){
    switch(n){
    case 0:
        cout << " -------------------\n";
        cout << "|       y           |\n";
        cout << "|     ('')          |\n";
        cout << "|      ).)          |\n";
        cout << "|     /./.--..      |\n";
        cout << "|    (._..--).)     |\n";
        cout << "|          (.(__/   |\n";
        cout << "|           '--'    |\n";
        cout << " -------------------\n";
         break;
    case 1:
        cout << "-----------------\n";
        cout << "|         //  // |\n";
        cout << "|        //==//  |\n";
        cout << "|       //==//   |\n";
        cout << "|      //==//    |\n";
        cout << "|     //==//     |\n";
        cout << "|    //  //      |\n";
        cout << "-----------------\n";
         break;
    }

    getch();
}
void board2(int p1, int p2, string p1_name, string p2_name)
{
    string sc[101];
    for(int i =0;i<=100;i++){
        if(i<10) sc[i] = "0"+to_string(i);
        else sc[i] = to_string(i);
    }
    sc[p1] = "\033[1;39;41mP1\033[0m";
    sc[p2] = "\033[1;39;44mP2\033[0m";
    printf("\n\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
    printf("|           |           |           |           |           |           |           |           |           |           |\n");
    printf("|    %s     |    %s     |    %s     |  _ %s _   |    %s     |    %s     |    %s     |  %s y     |     %s    |    %s    |\n",sc[91].c_str(), sc[92].c_str(), sc[93].c_str(), sc[94].c_str(), sc[95].c_str(), sc[96].c_str(), sc[97].c_str(), sc[98].c_str(), sc[99].c_str(), sc[100].c_str());
    printf("|           |           |           |/ /__/ /   |           |           |           |   ('')    |           |           |\n");
    printf("|-----------------------------------/-/__/-/---------------------------------------------).)----------------------------|\n");
    printf("|           |           |          / /__/ /     |           |           |           |   /./.--. |           |           |\n");
    printf("|    %s     |    %s     |  y %s   / /__/ / %s   |    %s     | _  %s_    |    %s     |%s( _.--).)|    %s     |    %s     |\n",sc[90].c_str(), sc[89].c_str(), sc[88].c_str(), sc[87].c_str(), sc[86].c_str(), sc[85].c_str(), sc[84].c_str(), sc[83].c_str(), sc[82].c_str(), sc[81].c_str());
    printf("|           |           |('')    / /__/ /       |           |\\ \\__\\ \\   |           |       /./ |           |           |\n");
    printf("|-------------------------).)---/-/__/-/----------------------\\-\\__\\-\\---------------------/./--------------------------|\n");
    printf("|           |           |/./   / /__/ /         |           |  \\ \\__\\ \\ |           |     (.(   |           |           |\n");
    printf("|    %s     |    %s     /./ %s/ /__/ /   %s     |    %s     | %s\\ \\__\\ \\|    %s     |   %s \\.\\  |    %s     |    %s     |\n",sc[71].c_str(), sc[72].c_str(), sc[73].c_str(), sc[74].c_str(), sc[75].c_str(), sc[76].c_str(), sc[77].c_str(), sc[78].c_str(), sc[79].c_str(), sc[80].c_str());
    printf("|          .--.__.--.__/./   / /__/ /       .--.__.--.__.--.__.--.__.--.__.--.__.--.__.--.__).\\ |           |           |\n");
    printf("|---------(.(------'.__./---/-/__/-/-------(.(-------------.__.--.__.--.__.--.__-------.__..__.)------------------------|\n");
    printf("|          ).)          |  / /__/ / |       ).) |           |      \\ \\__\\ \\         |           |           |           |\n");
    printf("|    %s   (.(    %s     | /_/%s/_/  |    %s/./  |    %s     |    %s \\ \\__\\ \\ %s     |    %s     |  y %s     |    %s     |\n",sc[70].c_str(), sc[69].c_str(), sc[68].c_str(), sc[67].c_str(), sc[66].c_str(), sc[65].c_str(), sc[64].c_str(), sc[63].c_str(), sc[62].c_str(), sc[61].c_str());
    printf("|          ).)          |           |     /./   |           |        \\ \\__\\ \\       |           |('')       |           |\n");
    printf("|---------/./----------------------------(.(--------------------------\\-\\__\\-\\--------------------).)-------------------|\n");
    printf("|        /./|           |           |     ).)   |           |          \\ \\__\\ \\     |           |/./        |           |\t\t Score\n");
    printf("|    %s /./ |    %s     |    %s     |  %s/./    |    %s     |    %s     \\_\\%s\\_\\    |    %s     /./  %s     |    %s     |\n",sc[51].c_str(), sc[52].c_str(), sc[53].c_str(), sc[54].c_str(), sc[55].c_str(), sc[56].c_str(), sc[57].c_str(), sc[58].c_str(), sc[59].c_str(), sc[60].c_str());
    printf("|      (.(  |         __..--.__.--.__   /./     |           |           |           |          (.(          |           |\n");
    printf("|-------\\.\\----------(.(-----------).)-(.(------------------------------------------------------\\.\\---------------------|\n");
    printf("|        \\.\\|         ).)          /.(__).\\     |           |  y        |           |           |\\.\\        |           |  P1: %s\t: %d\n", p1_name.c_str(), p1);
    printf("|    %s   \\.\\    %s  /./|_   %s_  (___..___) %s |    %s     |('') %s    |     %s    |     %s    | ).)%s     |    %s     |\n",sc[50].c_str(), sc[49].c_str(), sc[48].c_str(), sc[47].c_str(), sc[46].c_str(), sc[45].c_str(), sc[44].c_str(), sc[43].c_str(), sc[42].c_str(), sc[41].c_str());
    printf("|          ).)      /./ |\\ \\__\\ \\   |           |           |(.(        |           |           |/./        |           |  P2: %s\t: %d\n", p2_name.c_str(), p2);
    printf("|---------/./------(.(----\\-\\__\\-\\----------------------------).)-------------------------------/./---------------------|\n");
    printf("|        /./|       ).) |  \\ \\__\\ \\ |           |            (.(        |           |          /./          |           |\n");
    printf("|    %s /./ |    %s( /  | %s\\ \\__\\ \\|     %s    |    %s     | \\.\\ %s    |    %s     |    %s   /./    %s     |    %s     |\n",sc[31].c_str(), sc[32].c_str(), sc[33].c_str(), sc[34].c_str(), sc[35].c_str(), sc[36].c_str(), sc[37].c_str(), sc[38].c_str(), sc[39].c_str(), sc[40].c_str());
    printf("|      /./  |       '   |    \\ \\__\\ \\           |           |  ).)__.--._.--._.--.  |        (.(|           |           |\n");
    printf("|-----(.(---------------------\\-\\__\\-\\------------------------(__.-------------(.(------------\\.\\-----------------------|\n");
    printf("|      \\.\\  |           |      \\ \\__\\ \\         |           |           |       ).) |          \\.\\          |           |\n");
    printf("|    %s \\.\\ |    %s     |    %s \\ \\__\\ \\  %s    |    %s     |    %s     |    %s/./  |    %s     \\.\\  %s     |    %s     |\n",sc[30].c_str(), sc[29].c_str(), sc[28].c_str(), sc[27].c_str(), sc[26].c_str(), sc[25].c_str(), sc[24].c_str(), sc[23].c_str(), sc[22].c_str(), sc[21].c_str());
    printf("|        \\.\\|           |        \\ \\__\\ \\       |           |           |     /./   |           |)/         |           |\n");
    printf("|---------).)---------------------\\-\\__\\-\\-----------------------------------(.(----------------------------------------|\n");
    printf("|        /./|           |          \\ \\__\\ \\     |           |           |     \\.\\   |           |           |           |\n");
    printf("|    %s ( / |    %s     |    %s     \\ \\__\\ \\ %s |    %s     |    %s     |   %s \\.\\  |    %s     |    %s     |    %s     |\n",sc[11].c_str(), sc[12].c_str(), sc[13].c_str(), sc[14].c_str(), sc[15].c_str(), sc[16].c_str(), sc[17].c_str(), sc[18].c_str(), sc[19].c_str(), sc[20].c_str());
    printf("|        '  |           |           |\\ \\__\\ \\   |           |           |       ).)__.--._.--._.--.         |           |\n");
    printf("|-------------------------------------\\-\\__\\-\\---------------------------------(__.--------------).)--------------------|\n");
    printf("|           |           |           |  \\_\\  \\_\\ |           |           |           |           |\\.\\        |           |\n");
    printf("|    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     | ).)%s(\\_  |    %s     |\n",sc[10].c_str(), sc[9].c_str(), sc[8].c_str(), sc[7].c_str(), sc[6].c_str(), sc[5].c_str(), sc[4].c_str(), sc[3].c_str(), sc[2].c_str(), sc[1].c_str());
    printf("|           |           |           |           |           |           |           |           |(.(_.-.)_) |           |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
}
void board3(int p1, int p2, int p3, string p1_name, string p2_name, string p3_name)
{
    string sc[101];
    for(int i =0;i<=100;i++){
        if(i<10) sc[i] = "0"+to_string(i);
        else sc[i] = to_string(i);
    }
    sc[p1] = "\033[1;39;41mP1\033[0m";
    sc[p2] = "\033[1;39;44mP2\033[0m";
    sc[p3] = "\033[1;39;42mP3\033[0m";
    printf("\n\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
    printf("|           |           |           |           |           |           |           |           |           |           |\n");
    printf("|    %s     |    %s     |    %s     |  _ %s _   |    %s     |    %s     |    %s     |  %s y     |     %s    |    %s    |\n",sc[91].c_str(), sc[92].c_str(), sc[93].c_str(), sc[94].c_str(), sc[95].c_str(), sc[96].c_str(), sc[97].c_str(), sc[98].c_str(), sc[99].c_str(), sc[100].c_str());
    printf("|           |           |           |/ /__/ /   |           |           |           |   ('')    |           |           |\n");
    printf("|-----------------------------------/-/__/-/---------------------------------------------).)----------------------------|\n");
    printf("|           |           |          / /__/ /     |           |           |           |   /./.--. |           |           |\n");
    printf("|    %s     |    %s     |  y %s   / /__/ / %s   |    %s     | _  %s_    |    %s     |%s( _.--).)|    %s     |    %s     |\n",sc[90].c_str(), sc[89].c_str(), sc[88].c_str(), sc[87].c_str(), sc[86].c_str(), sc[85].c_str(), sc[84].c_str(), sc[83].c_str(), sc[82].c_str(), sc[81].c_str());
    printf("|           |           |('')    / /__/ /       |           |\\ \\__\\ \\   |           |       /./ |           |           |\n");
    printf("|-------------------------).)---/-/__/-/----------------------\\-\\__\\-\\---------------------/./--------------------------|\n");
    printf("|           |           |/./   / /__/ /         |           |  \\ \\__\\ \\ |           |     (.(   |           |           |\n");
    printf("|    %s     |    %s     /./ %s/ /__/ /   %s     |    %s     | %s\\ \\__\\ \\|    %s     |   %s \\.\\  |    %s     |    %s     |\n",sc[71].c_str(), sc[72].c_str(), sc[73].c_str(), sc[74].c_str(), sc[75].c_str(), sc[76].c_str(), sc[77].c_str(), sc[78].c_str(), sc[79].c_str(), sc[80].c_str());
    printf("|          .--.__.--.__/./   / /__/ /       .--.__.--.__.--.__.--.__.--.__.--.__.--.__.--.__).\\ |           |           |\n");
    printf("|---------(.(------'.__./---/-/__/-/-------(.(-------------.__.--.__.--.__.--.__-------.__..__.)------------------------|\n");
    printf("|          ).)          |  / /__/ / |       ).) |           |      \\ \\__\\ \\         |           |           |           |\n");
    printf("|    %s   (.(    %s     | /_/%s/_/  |    %s/./  |    %s     |    %s \\ \\__\\ \\ %s     |    %s     |  y %s     |    %s     |\n",sc[70].c_str(), sc[69].c_str(), sc[68].c_str(), sc[67].c_str(), sc[66].c_str(), sc[65].c_str(), sc[64].c_str(), sc[63].c_str(), sc[62].c_str(), sc[61].c_str());
    printf("|          ).)          |           |     /./   |           |        \\ \\__\\ \\       |           |('')       |           |\n");
    printf("|---------/./----------------------------(.(--------------------------\\-\\__\\-\\--------------------).)-------------------|\n");
    printf("|        /./|           |           |     ).)   |           |          \\ \\__\\ \\     |           |/./        |           |\t\t Score\n");
    printf("|    %s /./ |    %s     |    %s     |  %s/./    |    %s     |    %s     \\_\\%s\\_\\    |    %s     /./  %s     |    %s     |\n",sc[51].c_str(), sc[52].c_str(), sc[53].c_str(), sc[54].c_str(), sc[55].c_str(), sc[56].c_str(), sc[57].c_str(), sc[58].c_str(), sc[59].c_str(), sc[60].c_str());
    printf("|      (.(  |         __..--.__.--.__   /./     |           |           |           |          (.(          |           |\n");
    printf("|-------\\.\\----------(.(-----------).)-(.(------------------------------------------------------\\.\\---------------------|\n");
    printf("|        \\.\\|         ).)          /.(__).\\     |           |  y        |           |           |\\.\\        |           |  P1: %s\t: %d\n", p1_name.c_str(), p1);
    printf("|    %s   \\.\\    %s  /./|_   %s_  (___..___) %s |    %s     |('') %s    |     %s    |     %s    | ).)%s     |    %s     |\n",sc[50].c_str(), sc[49].c_str(), sc[48].c_str(), sc[47].c_str(), sc[46].c_str(), sc[45].c_str(), sc[44].c_str(), sc[43].c_str(), sc[42].c_str(), sc[41].c_str());
    printf("|          ).)      /./ |\\ \\__\\ \\   |           |           |(.(        |           |           |/./        |           |  P2: %s\t: %d\n", p2_name.c_str(), p2);
    printf("|---------/./------(.(----\\-\\__\\-\\----------------------------).)-------------------------------/./---------------------|\n");
    printf("|        /./|       ).) |  \\ \\__\\ \\ |           |            (.(        |           |          /./          |           |  P3: %s\t: %d\n", p3_name.c_str(), p3);
    printf("|    %s /./ |    %s( /  | %s\\ \\__\\ \\|     %s    |    %s     | \\.\\ %s    |    %s     |    %s   /./    %s     |    %s     |\n",sc[31].c_str(), sc[32].c_str(), sc[33].c_str(), sc[34].c_str(), sc[35].c_str(), sc[36].c_str(), sc[37].c_str(), sc[38].c_str(), sc[39].c_str(), sc[40].c_str());
    printf("|      /./  |       '   |    \\ \\__\\ \\           |           |  ).)__.--._.--._.--.  |        (.(|           |           |\n");
    printf("|-----(.(---------------------\\-\\__\\-\\------------------------(__.-------------(.(------------\\.\\-----------------------|\n");
    printf("|      \\.\\  |           |      \\ \\__\\ \\         |           |           |       ).) |          \\.\\          |           |\n");
    printf("|    %s \\.\\ |    %s     |    %s \\ \\__\\ \\  %s    |    %s     |    %s     |    %s/./  |    %s     \\.\\  %s     |    %s     |\n",sc[30].c_str(), sc[29].c_str(), sc[28].c_str(), sc[27].c_str(), sc[26].c_str(), sc[25].c_str(), sc[24].c_str(), sc[23].c_str(), sc[22].c_str(), sc[21].c_str());
    printf("|        \\.\\|           |        \\ \\__\\ \\       |           |           |     /./   |           |)/         |           |\n");
    printf("|---------).)---------------------\\-\\__\\-\\-----------------------------------(.(----------------------------------------|\n");
    printf("|        /./|           |          \\ \\__\\ \\     |           |           |     \\.\\   |           |           |           |\n");
    printf("|    %s ( / |    %s     |    %s     \\ \\__\\ \\ %s |    %s     |    %s     |   %s \\.\\  |    %s     |    %s     |    %s     |\n",sc[11].c_str(), sc[12].c_str(), sc[13].c_str(), sc[14].c_str(), sc[15].c_str(), sc[16].c_str(), sc[17].c_str(), sc[18].c_str(), sc[19].c_str(), sc[20].c_str());
    printf("|        '  |           |           |\\ \\__\\ \\   |           |           |       ).)__.--._.--._.--.         |           |\n");
    printf("|-------------------------------------\\-\\__\\-\\---------------------------------(__.--------------).)--------------------|\n");
    printf("|           |           |           |  \\_\\  \\_\\ |           |           |           |           |\\.\\        |           |\n");
    printf("|    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     | ).)%s(\\_  |    %s     |\n",sc[10].c_str(), sc[9].c_str(), sc[8].c_str(), sc[7].c_str(), sc[6].c_str(), sc[5].c_str(), sc[4].c_str(), sc[3].c_str(), sc[2].c_str(), sc[1].c_str());
    printf("|           |           |           |           |           |           |           |           |(.(_.-.)_) |           |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
}
void board4(int p1, int p2, int p3, int p4,  string p1_name, string p2_name, string p3_name, string p4_name)
{
    string sc[101];
    for(int i =0;i<=100;i++){
        if(i<10) sc[i] = "0"+to_string(i);
        else sc[i] = to_string(i);
    }
    sc[p1] = "\033[1;39;41mP1\033[0m";
    sc[p2] = "\033[1;39;44mP2\033[0m";
    sc[p3] = "\033[1;39;42mP3\033[0m";
    sc[p4] = "\033[1;39;43mP4\033[0m";
    printf("\n\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
    printf("|           |           |           |           |           |           |           |           |           |           |\n");
    printf("|    %s     |    %s     |    %s     |  _ %s _   |    %s     |    %s     |    %s     |  %s y     |     %s    |    %s    |\n",sc[91].c_str(), sc[92].c_str(), sc[93].c_str(), sc[94].c_str(), sc[95].c_str(), sc[96].c_str(), sc[97].c_str(), sc[98].c_str(), sc[99].c_str(), sc[100].c_str());
    printf("|           |           |           |/ /__/ /   |           |           |           |   ('')    |           |           |\n");
    printf("|-----------------------------------/-/__/-/---------------------------------------------).)----------------------------|\n");
    printf("|           |           |          / /__/ /     |           |           |           |   /./.--. |           |           |\n");
    printf("|    %s     |    %s     |  y %s   / /__/ / %s   |    %s     | _  %s_    |    %s     |%s( _.--).)|    %s     |    %s     |\n",sc[90].c_str(), sc[89].c_str(), sc[88].c_str(), sc[87].c_str(), sc[86].c_str(), sc[85].c_str(), sc[84].c_str(), sc[83].c_str(), sc[82].c_str(), sc[81].c_str());
    printf("|           |           |('')    / /__/ /       |           |\\ \\__\\ \\   |           |       /./ |           |           |\n");
    printf("|-------------------------).)---/-/__/-/----------------------\\-\\__\\-\\---------------------/./--------------------------|\n");
    printf("|           |           |/./   / /__/ /         |           |  \\ \\__\\ \\ |           |     (.(   |           |           |\n");
    printf("|    %s     |    %s     /./ %s/ /__/ /   %s     |    %s     | %s\\ \\__\\ \\|    %s     |   %s \\.\\  |    %s     |    %s     |\n",sc[71].c_str(), sc[72].c_str(), sc[73].c_str(), sc[74].c_str(), sc[75].c_str(), sc[76].c_str(), sc[77].c_str(), sc[78].c_str(), sc[79].c_str(), sc[80].c_str());
    printf("|          .--.__.--.__/./   / /__/ /       .--.__.--.__.--.__.--.__.--.__.--.__.--.__.--.__).\\ |           |           |\n");
    printf("|---------(.(------'.__./---/-/__/-/-------(.(-------------.__.--.__.--.__.--.__-------.__..__.)------------------------|\n");
    printf("|          ).)          |  / /__/ / |       ).) |           |      \\ \\__\\ \\         |           |           |           |\n");
    printf("|    %s   (.(    %s     | /_/%s/_/  |    %s/./  |    %s     |    %s \\ \\__\\ \\ %s     |    %s     |  y %s     |    %s     |\n",sc[70].c_str(), sc[69].c_str(), sc[68].c_str(), sc[67].c_str(), sc[66].c_str(), sc[65].c_str(), sc[64].c_str(), sc[63].c_str(), sc[62].c_str(), sc[61].c_str());
    printf("|          ).)          |           |     /./   |           |        \\ \\__\\ \\       |           |('')       |           |\n");
    printf("|---------/./----------------------------(.(--------------------------\\-\\__\\-\\--------------------).)-------------------|\n");
    printf("|        /./|           |           |     ).)   |           |          \\ \\__\\ \\     |           |/./        |           |\t\t Score\n");
    printf("|    %s /./ |    %s     |    %s     |  %s/./    |    %s     |    %s     \\_\\%s\\_\\    |    %s     /./  %s     |    %s     |\n",sc[51].c_str(), sc[52].c_str(), sc[53].c_str(), sc[54].c_str(), sc[55].c_str(), sc[56].c_str(), sc[57].c_str(), sc[58].c_str(), sc[59].c_str(), sc[60].c_str());
    printf("|      (.(  |         __..--.__.--.__   /./     |           |           |           |          (.(          |           |\n");
    printf("|-------\\.\\----------(.(-----------).)-(.(------------------------------------------------------\\.\\---------------------|\n");
    printf("|        \\.\\|         ).)          /.(__).\\     |           |  y        |           |           |\\.\\        |           |  P1: %s\t: %d\n", p1_name.c_str(), p1);
    printf("|    %s   \\.\\    %s  /./|_   %s_  (___..___) %s |    %s     |('') %s    |     %s    |     %s    | ).)%s     |    %s     |\n",sc[50].c_str(), sc[49].c_str(), sc[48].c_str(), sc[47].c_str(), sc[46].c_str(), sc[45].c_str(), sc[44].c_str(), sc[43].c_str(), sc[42].c_str(), sc[41].c_str());
    printf("|          ).)      /./ |\\ \\__\\ \\   |           |           |(.(        |           |           |/./        |           |  P2: %s\t: %d\n", p2_name.c_str(), p2);
    printf("|---------/./------(.(----\\-\\__\\-\\----------------------------).)-------------------------------/./---------------------|\n");
    printf("|        /./|       ).) |  \\ \\__\\ \\ |           |            (.(        |           |          /./          |           |  P3: %s\t: %d\n", p3_name.c_str(), p3);
    printf("|    %s /./ |    %s( /  | %s\\ \\__\\ \\|     %s    |    %s     | \\.\\ %s    |    %s     |    %s   /./    %s     |    %s     |\n",sc[31].c_str(), sc[32].c_str(), sc[33].c_str(), sc[34].c_str(), sc[35].c_str(), sc[36].c_str(), sc[37].c_str(), sc[38].c_str(), sc[39].c_str(), sc[40].c_str());
    printf("|      /./  |       '   |    \\ \\__\\ \\           |           |  ).)__.--._.--._.--.  |        (.(|           |           |  P4: %s\t: %d\n", p4_name.c_str(), p4);
    printf("|-----(.(---------------------\\-\\__\\-\\------------------------(__.-------------(.(------------\\.\\-----------------------|\n");
    printf("|      \\.\\  |           |      \\ \\__\\ \\         |           |           |       ).) |          \\.\\          |           |\n");
    printf("|    %s \\.\\ |    %s     |    %s \\ \\__\\ \\  %s    |    %s     |    %s     |    %s/./  |    %s     \\.\\  %s     |    %s     |\n",sc[30].c_str(), sc[29].c_str(), sc[28].c_str(), sc[27].c_str(), sc[26].c_str(), sc[25].c_str(), sc[24].c_str(), sc[23].c_str(), sc[22].c_str(), sc[21].c_str());
    printf("|        \\.\\|           |        \\ \\__\\ \\       |           |           |     /./   |           |)/         |           |\n");
    printf("|---------).)---------------------\\-\\__\\-\\-----------------------------------(.(----------------------------------------|\n");
    printf("|        /./|           |          \\ \\__\\ \\     |           |           |     \\.\\   |           |           |           |\n");
    printf("|    %s ( / |    %s     |    %s     \\ \\__\\ \\ %s |    %s     |    %s     |   %s \\.\\  |    %s     |    %s     |    %s     |\n",sc[11].c_str(), sc[12].c_str(), sc[13].c_str(), sc[14].c_str(), sc[15].c_str(), sc[16].c_str(), sc[17].c_str(), sc[18].c_str(), sc[19].c_str(), sc[20].c_str());
    printf("|        '  |           |           |\\ \\__\\ \\   |           |           |       ).)__.--._.--._.--.         |           |\n");
    printf("|-------------------------------------\\-\\__\\-\\---------------------------------(__.--------------).)--------------------|\n");
    printf("|           |           |           |  \\_\\  \\_\\ |           |           |           |           |\\.\\        |           |\n");
    printf("|    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     |    %s     | ).)%s(\\_  |    %s     |\n",sc[10].c_str(), sc[9].c_str(), sc[8].c_str(), sc[7].c_str(), sc[6].c_str(), sc[5].c_str(), sc[4].c_str(), sc[3].c_str(), sc[2].c_str(), sc[1].c_str());
    printf("|           |           |           |           |           |           |           |           |(.(_.-.)_) |           |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
}
void welcome_page()
{
    cout << "          .--.--.                                ,-.                                                                            \n";
    cout << "         /  /    '.                          ,--/ /|                                                                            \n";
    cout << "        |  :  /`. /      ,---,             ,--. :/ |                                                                            \n";
    cout << "        ;  |  |--`   ,-+-. /  |            :  : ' /                                                                             \n";
    cout << "        |  :  ;_    ,--.'|'   |  ,--.--.   |  '  /      ,---.                                                                   \n";
    cout << "         \\  \\    `.|   |  ,'' | /       \\  '  |  :     /     \\                                                                  \n";
    cout << "          `----.   \\   | /  | |.--.  .-. | |  |   \   /    /  |                                                                 \n";
    cout << "          __ \\  \\  |   | |  | | \\__\\/: . . '  : |. \\ .    ' / |                      /^\\/^\\                                     \n";
    cout << "         /  /`--'  /   | |  |/  ,' .--.; | |  | ' \\ \\'   ;   /|                    _|__|  O|                                    \n";
    cout << "        '--'.     /|   | |--'  /  /  ,.  | '  : |--' '   |  / |           \\/     /~     \\_/ \\                                   \n";
    cout << "          `--'---' |   |/     ;  :   .'   \\;  |,'    |   :    |            \\____|__________/  \\                                 \n";
    cout << "                   '---'      |  ,     .-./'--'       \\   \\  /                   \\_______      \\                                \n";
    cout << "                               `--`---' ___// /        `----'            ,---,           `\\   0 \\                 \\             \n";
    cout << "                                 // /     // /               ,---,     ,---.'|            |   0 |                  \\            \n";
    cout << "                                // /____ // /            ,-+-. /  |    |   | :          /    0 /                    \\           \n";
    cout << "                               // /____ // / ,--.--.    ,--.'|'   |    |   | |         /   0 /                       \\\\         \n";
    cout << "                              // /     // / /       \\  |   |  ,'' |  ,--.__| |       /   0  /                         \\ \\       \n";
    cout << "                             // /____ // / .--.  .-. | |   | /  | | /   ,'   |      /  0  /                            \\  \\     \n";
    cout << "                            // /____ // /   \\__\\/: . . |   | |  | |.   '  /  |    /  0  /             _----_            \\  o\\   \n";
    cout << "                           // /     // /    ,' .--.; | |   | |  |/ '   ; |:  |   /  0  /           _-~    o ~-_         |  o|   \n";
    cout << "                          // /____ // /    /  /  ,.  | |   | |--'  |   | '/  '  (   0  (        _-~    _--_ o  ~-_     _/  o|   \n";
    cout << "                         // /____ // /    ;  :   .'   \\|   |/      |   :    :|   \\   0  ~-____-~    _-~    ~-_o   ~-_-~    /    \n";
    cout << "                        // /     // /     |  ,     .-./'---'        \\   \\  /      ~-_  0        _-~          ~-_ o     _-~      \n";
    cout << "                       // /____ // /       `--`---'     ,--,         `----'          ~--__0___-~                ~-_o_-~         \n";
    cout << "                      // /____ // /                  ,---.'|                                                                    \n";
    cout << "                     // /     // /                   |   | :                                                                    \n";
    cout << "                    // /____ // /                    :   : |                    ,---,      ,---,                                \n";
    cout << "                   // /____ // /                     |   ' :                  ,---.'|    ,---.'|            __  ,-.             \n";
    cout << "                  // /     // /                      ;   ; '                  |   | :    |   | :          ,' ,'/ /|             \n";
    cout << "                 // /____ // /                       '   | |__   ,--.--.      |   | |    |   | |   ,---.  '  | |' |             \n";
    cout << "                // /____ // /                        |   | :.'| /       \\   ,--.__| |  ,--.__| |  /     \\ |  |   ,'             \n";
    cout << "               // /     // /                         '   :    ;.--.  .-. | /   ,'   | /   ,'   | /    /  |'  :  /               \n";
    cout << "              // /____ // /                          |   |  ./  \\__\\/: . ..   '  /  |.   '  /  |.    ' / ||  | '                \n";
    cout << "             // /____ // /                           ;   : ;    ,' .--.; |'   ; |:  |'   ; |:  |'   ;   /|;  : |                \n";
    cout << "            // /     // /                            |   ,/    /  /  ,.  ||   | '/  '|   | '/  ''   |  / ||  , ;                \n";
    cout << "           // /____ // /                             '---'    ;  :   .'   \\   :    :||   :    :||   :    | ---'                 \n";
    cout << "          // /____ // /                                       |  ,     .-./\\   \\  /   \\   \\  /   \\   \\  /                       \n";
    cout << "         // /     // /                                         `--`---'     `----'     `----'     `----'                        \n\n\n";
}
void winner(string s){
    clrscr();
    cout << "\n\n\n                                   _   _     _   _   o _____ o   ____    \n";
    cout << "         __        __     ___     |0\\ |0|   |0\\ |0|  \\|0___0|/o |0 _0\\ o \n";
    cout << "         \\0\\      /0/    |_0_|   <|  \\| |> <|  \\| |>  |  _|    \\| |_) |/ \n";
    cout << "         /\\ \\ /\\ / /\\     | |    0| |\\  |0 0| |\\  |0  | |___    |  _ <   \n";
    cout << "        o  \\ V  V /  o  o/| |\\o   |_| \\_|   |_| \\_|   |_____|   |_| \_\\  \n";
    cout << "        .-,_\\ /\\ /_,-.-,_|___|_,-.||   \\\\,-.||   \\\\,-.<<   >>   //   \\\\_ \n";
    cout << "         \\_)-'  '-(_/ \\_)-' '-(_/ (_ )  (_/ (__)  (_/(__) (__) (__)  (__)    _.-''-._\n";
    cout << "     _.--.__..--.__..--.__..--.__..--.__..--.__..--.__..--.__..--.__..--.__./      x_;__/\n";
    cout << "    /_.--.__..0--.__.0--.__.0--.__.0--.__.0--.__.0--.__.0--.__.0--.__.0--.__.-..__../   \\\n\n\n";
    cout << "\n\n\n\n\t\t\t\t THE WINNER IS " << s << "\n\n";
    cout << "\n\n\n\n\t\t\t\t\tPress 0 to exit. 1 to Main  Menu\n";
    char choice = getch();
    switch(choice)
    {
        case '1':
            main_menu();
            break;
        case '0':
            exit(1);
            break;
    }

}
void team(){
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t __  __               _            _             \n";
    cout << "\t\t\t|  \\/  |             | |          | |            \n";
    cout << "\t\t\t| \\  / |   __ _    __| |   ___    | |__    _   _ \n";
    cout << "\t\t\t| |\\/| |  / _` |  / _` |  / _ \\   | '_ \\  | | | |\n";
    cout << "\t\t\t| |  | | | (_| | | (_| | |  __/   | |_) | | |_| |\n";
    cout << "\t\t\t|_|  |_|  \\__,_|  \\__,_|  \\___|   |_.__/   \\__, |\n";
    cout << "\t\t\t                                            __/ |\n";
    cout << "\t\t\t                                           |___/ \n";
    cout << "\t\t\t _                __   _               ____    _                            _____                         \n";
    cout << "\t\t\t| |              / _| | |             / __ \\  ( )                          / ____|                        \n";
    cout << "\t\t\t| |        ___  | |_  | |_   ______  | |  | | |/  __   __   ___   _ __    | |  __    __ _   _ __     __ _ \n";
    cout << "\t\t\t| |       / _ \\ |  _| | __| |______| | |  | |     \\ \\ / /  / _ \\ | '__|   | | |_ |  / _` | | '_ \\   / _` |\n";
    cout << "\t\t\t| |____  |  __/ | |   | |_           | |__| |      \\ V /  |  __/ | |      | |__| | | (_| | | | | | | (_| |\n";
    cout << "\t\t\t|______|  \\___| |_|    \\__|           \\____/        \\_/    \\___| |_|       \\_____|  \\__,_| |_| |_|  \\__, |\n";
    cout << "\t\t\t                                                                                                     __/ |\n";
    cout << "\t\t\t                                                                                                    |___/ \n";
    }

void clrscr()
{
    system("@cls||clear");
}
