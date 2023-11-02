#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include  <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
int h_score[5] = { 0,0,0,0,0 };
int alien_cnt = 0;
int score = 0;
int spaceship_ball_x, spaceship_ball_y;
int sv_r, sv_r1, sv_r2, sv_r3, sv_r4, sv_r5, sv_r6, sv_r7, sv_r8, sv_r9;       //sv_r means the variable used to store the value of r
int sv_by, sv_by1, sv_by2, sv_by3, sv_by4, sv_by5, sv_by6, sv_by7, sv_by8, sv_by9;    // sv_by = box_y of aliens to save in file
void spaceship_reset(int& ball_x, int& ball_y)
{
    myLine(ball_x + 40, ball_y - 10, ball_x + 40, ball_y - 40, RGB(12, 12, 12));
    myLine(ball_x + 110, ball_y - 10, ball_x + 110, ball_y - 40, RGB(12, 12, 12));

    myLine(ball_x + 60, ball_y - 10, ball_x + 60, ball_y - 25, RGB(12, 12, 12));
    myLine(ball_x + 90, ball_y - 10, ball_x + 90, ball_y - 25, RGB(12, 12, 12));

    myRect(ball_x + 72, ball_y - 20, ball_x + 77, ball_y + 20, RGB(12, 12, 12), RGB(12, 12, 12));

    myEllipse(ball_x + 150, ball_y - 30, ball_x + 160, ball_y + 40, RGB(12, 12, 12), RGB(12, 12, 12));
    myEllipse(ball_x - 10, ball_y - 30, ball_x, ball_y + 40, RGB(12, 12, 12), RGB(12, 12, 12));

    myEllipse(ball_x + 20, ball_y - 10, ball_x + 130, ball_y, RGB(12, 12, 12), RGB(12, 12, 12));
    myEllipse(ball_x, ball_y, ball_x + 150, ball_y + 20, RGB(12, 12, 12), RGB(12, 12, 12));

    myRect(ball_x, ball_y, ball_x + 150, ball_y - 42, RGB(12, 12, 12), RGB(12, 12, 12));
}
void stars() {
    myEllipse(100, 100, 102, 102, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(100, 0, 102, 2, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(165, 49, 167, 51, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(230, 98, 232, 100, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(295, 147, 297, 149, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(360, 196, 362, 198, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(425, 245, 427, 247, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(490, 294, 492, 296, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(555, 343, 557, 345, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(620, 392, 622, 394, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(685, 441, 687, 443, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(750, 490, 752, 492, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(815, 539, 817, 541, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(880, 588, 882, 590, RGB(0, 48, 100), RGB(0, 48, 100));
    myEllipse(945, 637, 947, 639, RGB(0, 48, 100), RGB(0, 48, 100));
}
void alien_reset(int& a, int& box_y)
{
    myEllipse(a, box_y, a + 75, box_y + 50, RGB(12, 12, 12), RGB(12, 12, 12));
    myEllipse(a + 15, box_y, a + 30, box_y + 20, RGB(12, 12, 12), RGB(12, 12, 12));
    myEllipse(a + 50, box_y, a + 65, box_y + 20, RGB(12, 12, 12), RGB(12, 12, 12));
}
void aliens(int& x, int& y, int win_y, int fire_x, int fire_y, int& a, bool& PB, int speed, int& count, int& ball_x, int& ball_y)
{
    y += 1;
    if (y + 50 >= win_y + 1000)
    {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        count--;
    }
    if ((y <= ball_y + 55) && ((y >= ball_y - 30) && ((ball_x >= a) && (ball_x <= a + 75))))
    {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);
        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if ((y + 50 <= ball_y + 55) && ((y + 50 >= ball_y - 30) && ((ball_x >= a) && (ball_x <= a + 75))))
    {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);
        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if ((y + 50 <= ball_y + 55) && ((y + 50 >= ball_y - 30) && ((ball_x + 150 >= a) && (ball_x + 150 <= a + 75))))
    {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);

        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if ((y <= ball_y + 55) && ((y >= ball_y - 30) && ((ball_x + 150 >= a) && (ball_x + 150 <= a + 75))))
    {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);

        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if (((ball_x + 60 >= a) && (ball_x + 60 <= a + 75)) && ((y + 50 <= ball_y - 10) && (y + 60 >= ball_y - 25))) {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);

        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if ((y <= ball_y + 15) && ((y >= ball_y - 10) && ((ball_x + 130 >= a) && (ball_x + 20 <= a + 75)))) {
        y = 0;
        a = (rand() % 1500 + rand() % 50);
        spaceship_reset(ball_x, ball_y);
        ball_y = 820;
        ball_x = 780;
        count--;
    }
    if (((y + 50 >= fire_y - speed) && (PB == true) && ((fire_x >= a) && (fire_x <= a + 75)))) {        // disappear alien on bullet hit
        if (y <= fire_y)
        {
            y = 0;
            a = (rand() % 1500 + rand() % 50);
            PB = false;
            score += 1;
            alien_cnt += 1;
        }
    }
    myEllipse(a, y, a + 75, y + 50, RGB(0, 255, 0), RGB(0, 255, 0));             // draw alien
    myEllipse(a + 15, y, a + 30, y + 20, RGB(255, 0, 0), RGB(255, 0, 0));        // with eyes and stuff
    myEllipse(a + 50, y, a + 65, y + 20, RGB(255, 0, 0), RGB(255, 0, 0));

}


int main() {

    int win_x, win_y;
    int box_x, box_y, box_x1, box_y1, box_x2, box_y2, box_x3, box_y3, box_x4, box_y4;
    int box_x5, box_y5, box_x6, box_y6, box_x7, box_y7, box_x8, box_y8, box_x9, box_y9;
    int r, r1, r2, r3, r4, r5, r6, r7, r8, r9;
    int ball_x, ball_y;
    bool dir = false;
    bool flag = true;
    int extra = 0;
    char demo[] = "demo";
    bool pressed = false;
    bool lives = true;
    int count = 3;
    bool pb = false;
    int fire_x = 0;
    int fire_y = 0;
    int fire_y2 = 0;
    bool PB = false;

    bool PB1 = false;

    bool doo = false;

    char intro[15] = { 'S','P','A','C','E',' ','I','N','V','A','D','E','R','S','\0'};

    char lives3[] = "3";
    char lives2[] = "2";
    char lives1[] = "1";
    char lives0[] = "0";
    char lives_logo[7] = { 'L','i','v','e','s',':','\0' };
    char score_logo[7] = { 'S','c','o','r','e',':','\0' };


    // initialing score for printing as integer cannot be printed therfore char is used
    char scre0[] = { "0" }, scre1[] = { "1" }, scre2[] = { "2" }, scre3[] = { "3" }, scre4[] = { "4" }, scre5[] = { "5" }, scre6[] = { "6" };
    char scre7[] = { "7" }, scre8[] = { "8" }, scre9[] = { "9" };
    char scre10[3] = { "10" }, scre11[3] = { "11" }, scre12[3] = { "12" }, scre13[3] = { "13" }, scre14[3] = { "14" }, scre15[3] = { "15" },
        scre16[3] = { "16" }, scre17[3] = { "17" }, scre18[3] = { "18" }, scre19[3] = { "19" }, scre20[3] = { "20" }, scre21[3] = { "21" },
        scre22[3] = { "22" }, scre23[3] = { "23" }, scre24[3] = { "24" }, scre25[3] = { "25" }, scre26[3] = { "26" }, scre27[3] = { "27" },
        scre28[3] = { "28" }, scre29[3] = { "29" }, scre30[3] = { "30" }, scre31[3] = { "31" }, scre32[3] = { "32" }, scre33[3] = { "33" },
        scre34[3] = { "34" }, scre35[3] = { "35" }, scre36[3] = { "36" }, scre37[3] = { "37" }, scre38[3] = { "38" }, scre39[3] = { "39" },
        scre40[3] = { "40" }, scre41[3] = { "41" }, scre42[3] = { "42" }, scre43[3] = { "43" }, scre44[3] = { "44" }, scre45[3] = { "45" },
        scre46[3] = { "46" }, scre47[3] = { "47" }, scre48[3] = { "48" }, scre49[3] = { "49" }, scre50[3] = { "50" }, scre51[3] = { "51" },
        scre52[3] = { "52" }, scre53[3] = { "53" }, scre54[3] = { "54" }, scre55[3] = { "55" }, scre56[3] = { "56" }, scre57[3] = { "57" },
        scre58[3] = { "58" }, scre59[3] = { "59" }, scre60[3] = { "60" }, scre61[3] = { "61" }, scre62[3] = { "62" }, scre63[3] = { "63" },
        scre64[3] = { "64" }, scre65[3] = { "65" }, scre66[3] = { "66" }, scre67[3] = { "67" }, scre68[3] = { "68" }, scre69[3] = { "69" },
        scre70[3] = { "70" }, scre71[3] = { "71" }, scre72[3] = { "72" }, scre73[3] = { "73" }, scre74[3] = { "74" }, scre75[3] = { "75" },
        scre76[3] = { "76" }, scre77[3] = { "77" }, scre78[3] = { "78" }, scre79[3] = { "79" }, scre80[3] = { "80" }, scre81[3] = { "81" },
        scre82[3] = { "82" }, scre83[3] = { "83" }, scre84[3] = { "84" }, scre85[3] = { "85" }, scre86[3] = { "86" }, scre87[3] = { "87" },
        scre88[3] = { "88" }, scre89[3] = { "89" }, scre90[3] = { "90" }, scre91[3] = { "91" }, scre92[3] = { "92" }, scre93[3] = { "93" },
        scre94[3] = { "94" }, scre95[3] = { "95" }, scre96[3] = { "96" }, scre97[3] = { "97" }, scre98[3] = { "98" }, scre99[3] = { "99" };
    char scre100[4] = { "100" }, scre101[4] = { "101" }, scre102[4] = { "102" }, scre103[4] = { "103" }, scre104[4] = { "104" },
        scre105[4] = { "105" }, scre106[4] = { "106" };


    //system("pause");

    GetMaxWindowCoordinates(win_x, win_y);
    int speed = 0;
    char rui;

    ifstream myfile_o("save_game.txt");
    myfile_o >> h_score[0];
    myfile_o >> h_score[1];
    myfile_o >> h_score[2];
    myfile_o >> h_score[3];
    myfile_o >> h_score[4];y

    myDrawTextWithFont(600, 0, 150, intro, RGB(255, 0, 0), RGB(0, 0, 0));        // Printing "Space invaders" on intro screen
    myDrawTextWithFont(600, 0, 150, intro, RGB(255, 0, 0), RGB(0, 0, 0));
    myDrawTextWithFont(600, 0, 150, intro, RGB(255, 0, 0), RGB(0, 0, 0));
    myDrawTextWithFont(600, 0, 150, intro, RGB(255, 0, 0), RGB(0, 0, 0));

    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << "TOP HIGH SCORES " << endl << endl;
    cout << "1. " << h_score[0] << endl;
    cout << "2. " << h_score[1] << endl;
    cout << "3. " << h_score[2] << endl;
    cout << "4. " << h_score[3] << endl;
    cout << "5. " << h_score[4] << endl;

    cout << endl << endl << endl;
    cout << "Rules of the game " << endl << endl;
    cout << "Killing Alien                                +1 Point " << endl;
    cout << "Hitting an Alien                             -1 Lives " << endl;
    cout << "Alien crosses the bottom line                -1 Lives " << endl << endl;
    cout << "Note : Maximum aliens you can kill is 50              " << endl;
    cout << endl << endl << endl;

    cout << "Would you like to start from the last save game or start a new game ?" << endl;
    cout << "Press 'n' to start a new game " << endl;
    cout << "Press 'r' to resume from the last save game " << endl;
    cin >> rui;
    if (rui == 'r') {                    // input values from the last save game if user chooses to resume from last save game
        myfile_o >> alien_cnt;
        myfile_o >> score;
        myfile_o >> count;
        myfile_o >> ball_x;
        myfile_o >> ball_y;
        myfile_o >> box_y;
        myfile_o >> box_y1;
        myfile_o >> box_y2;
        myfile_o >> box_y3;
        myfile_o >> box_y4;
        myfile_o >> box_y5;
        myfile_o >> box_y6;
        myfile_o >> box_y7;
        myfile_o >> box_y8;
        myfile_o >> box_y9;
        myfile_o >> r;
        myfile_o >> r1;
        myfile_o >> r2;
        myfile_o >> r3;
        myfile_o >> r4;
        myfile_o >> r5;
        myfile_o >> r6;
        myfile_o >> r7;
        myfile_o >> r8;
        myfile_o >> r9;
        myfile_o.close();
        ClearScreen();
    }
    else {                            // starting a new game from initial spawn points
        ball_x = 779;              // spaceship spawn point
        ball_y = 849;

        box_y = 0;            // spawn y-coordinates of enemies    
        box_y1 = 0;
        box_y2 = 0;
        box_y3 = 0;
        box_y4 = 0;
        box_y5 = 0;
        box_y6 = 0;
        box_y7 = 0;
        box_y8 = 0;
        box_y9 = 0;

        r = 100;                  // spawn x-coordinates of enemies
        r1 = 250;
        r2 = 400;
        r3 = 550;
        r4 = 700;
        r5 = 850;
        r6 = 1000;
        r7 = 1150;
        r8 = 1300;
        r9 = 1450;
        ClearScreen();
    }



    PlaceCursor(0, 0);
    while (extra == 0) {

        // Printing the Boundaries
        // The Box                                                    
        myRect(1700, 0, 1705, 150, RGB(255, 0, 255), RGB(255, 0, 0));
        myRect(1700, 150, 1870, 155, RGB(255, 0, 255), RGB(255, 0, 0));
        //left line
        myRect(0, 0, 20, 1000, RGB(176, 141, 87), RGB(176, 141, 87));
        myRect(0, 0, 2000, 20, RGB(176, 141, 87), RGB(176, 141, 87));
        //right line
        myRect(1870, 0, 2000, 1000, RGB(176, 141, 87), RGB(176, 141, 87));
        //bottom line
        myRect(0, 965, 2000, 985, RGB(176, 141, 87), RGB(176, 141, 87));


        // Printing lives
        myDrawTextWithFont(1720, 40, 30, lives_logo, RGB(0, 255, 0), RGB(20, 20, 20));         // printing the word 'lives'
        switch (count) {
        case 3:
            myDrawTextWithFont(1780, 40, 30, lives3, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 2:
            myDrawTextWithFont(1780, 40, 30, lives3, RGB(0, 0, 0), RGB(0, 0, 0));              // overwriting previous piece of shit
            myDrawTextWithFont(1780, 40, 30, lives2, RGB(0, 255, 0), RGB(20, 20, 20));         // printing new amount of lives
            break;
        case 1:
            myDrawTextWithFont(1780, 40, 30, lives2, RGB(0, 0, 0), RGB(0, 0, 0));              // overwriting previous piece of shit
            myDrawTextWithFont(1780, 40, 30, lives1, RGB(0, 255, 0), RGB(20, 20, 20));         // printing new amount of lives
            break;
        case 0:
            myDrawTextWithFont(1780, 40, 30, lives1, RGB(0, 0, 0), RGB(0, 0, 0));              // overwriting previous piece of shit
            myDrawTextWithFont(1780, 40, 30, lives0, RGB(0, 255, 0), RGB(20, 20, 20));         // printing new amount of lives
            break;
        }

        stars();

        // Printing Score
        myDrawTextWithFont(1720, 70, 30, score_logo, RGB(0, 255, 0), RGB(20, 20, 20));
        switch (score) {
        case 0:
            myDrawTextWithFont(1790, 70, 30, scre0, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 1:
            myDrawTextWithFont(1790, 70, 30, scre1, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 2:
            myDrawTextWithFont(1790, 70, 30, scre2, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 3:
            myDrawTextWithFont(1790, 70, 30, scre3, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 4:
            myDrawTextWithFont(1790, 70, 30, scre4, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 5:
            myDrawTextWithFont(1790, 70, 30, scre5, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 6:
            myDrawTextWithFont(1790, 70, 30, scre6, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 7:
            myDrawTextWithFont(1790, 70, 30, scre7, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 8:
            myDrawTextWithFont(1790, 70, 30, scre8, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 9:
            myDrawTextWithFont(1790, 70, 30, scre9, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 10:
            myDrawTextWithFont(1790, 70, 30, scre10, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 11:
            myDrawTextWithFont(1790, 70, 30, scre11, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 12:
            myDrawTextWithFont(1790, 70, 30, scre12, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 13:
            myDrawTextWithFont(1790, 70, 30, scre13, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 14:
            myDrawTextWithFont(1790, 70, 30, scre14, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 15:
            myDrawTextWithFont(1790, 70, 30, scre15, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 16:
            myDrawTextWithFont(1790, 70, 30, scre16, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 17:
            myDrawTextWithFont(1790, 70, 30, scre17, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 18:
            myDrawTextWithFont(1790, 70, 30, scre18, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 19:
            myDrawTextWithFont(1790, 70, 30, scre19, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 20:
            myDrawTextWithFont(1790, 70, 30, scre20, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 21:
            myDrawTextWithFont(1790, 70, 30, scre21, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 22:
            myDrawTextWithFont(1790, 70, 30, scre22, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 23:
            myDrawTextWithFont(1790, 70, 30, scre23, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 24:
            myDrawTextWithFont(1790, 70, 30, scre24, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 25:
            myDrawTextWithFont(1790, 70, 30, scre25, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 26:
            myDrawTextWithFont(1790, 70, 30, scre26, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 27:
            myDrawTextWithFont(1790, 70, 30, scre27, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 28:
            myDrawTextWithFont(1790, 70, 30, scre28, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 29:
            myDrawTextWithFont(1790, 70, 30, scre29, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 30:
            myDrawTextWithFont(1790, 70, 30, scre30, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 31:
            myDrawTextWithFont(1790, 70, 30, scre31, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 32:
            myDrawTextWithFont(1790, 70, 30, scre32, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 33:
            myDrawTextWithFont(1790, 70, 30, scre33, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 34:
            myDrawTextWithFont(1790, 70, 30, scre34, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 35:
            myDrawTextWithFont(1790, 70, 30, scre35, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 36:
            myDrawTextWithFont(1790, 70, 30, scre36, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 37:
            myDrawTextWithFont(1790, 70, 30, scre37, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 38:
            myDrawTextWithFont(1790, 70, 30, scre38, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 39:
            myDrawTextWithFont(1790, 70, 30, scre39, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 40:
            myDrawTextWithFont(1790, 70, 30, scre40, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 41:
            myDrawTextWithFont(1790, 70, 30, scre41, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 42:
            myDrawTextWithFont(1790, 70, 30, scre42, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 43:
            myDrawTextWithFont(1790, 70, 30, scre43, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 44:
            myDrawTextWithFont(1790, 70, 30, scre44, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 45:
            myDrawTextWithFont(1790, 70, 30, scre45, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 46:
            myDrawTextWithFont(1790, 70, 30, scre46, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 47:
            myDrawTextWithFont(1790, 70, 30, scre47, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 48:
            myDrawTextWithFont(1790, 70, 30, scre48, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 49:
            myDrawTextWithFont(1790, 70, 30, scre49, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 50:
            myDrawTextWithFont(1790, 70, 30, scre50, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 51:
            myDrawTextWithFont(1790, 70, 30, scre51, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 52:
            myDrawTextWithFont(1790, 70, 30, scre52, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 53:
            myDrawTextWithFont(1790, 70, 30, scre53, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 54:
            myDrawTextWithFont(1790, 70, 30, scre54, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 55:
            myDrawTextWithFont(1790, 70, 30, scre55, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 56:
            myDrawTextWithFont(1790, 70, 30, scre56, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 57:
            myDrawTextWithFont(1790, 70, 30, scre57, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 58:
            myDrawTextWithFont(1790, 70, 30, scre58, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 59:
            myDrawTextWithFont(1790, 70, 30, scre59, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 60:
            myDrawTextWithFont(1790, 70, 30, scre60, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 61:
            myDrawTextWithFont(1790, 70, 30, scre61, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 62:
            myDrawTextWithFont(1790, 70, 30, scre62, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 63:
            myDrawTextWithFont(1790, 70, 30, scre63, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 64:
            myDrawTextWithFont(1790, 70, 30, scre64, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 65:
            myDrawTextWithFont(1790, 70, 30, scre65, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 66:
            myDrawTextWithFont(1790, 70, 30, scre66, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 67:
            myDrawTextWithFont(1790, 70, 30, scre67, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 68:
            myDrawTextWithFont(1790, 70, 30, scre68, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 69:
            myDrawTextWithFont(1790, 70, 30, scre69, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 70:
            myDrawTextWithFont(1790, 70, 30, scre70, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 71:
            myDrawTextWithFont(1790, 70, 30, scre71, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 72:
            myDrawTextWithFont(1790, 70, 30, scre72, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 73:
            myDrawTextWithFont(1790, 70, 30, scre73, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 74:
            myDrawTextWithFont(1790, 70, 30, scre74, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 75:
            myDrawTextWithFont(1790, 70, 30, scre75, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 76:
            myDrawTextWithFont(1790, 70, 30, scre76, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 77:
            myDrawTextWithFont(1790, 70, 30, scre77, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 78:
            myDrawTextWithFont(1790, 70, 30, scre78, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 79:
            myDrawTextWithFont(1790, 70, 30, scre79, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 80:
            myDrawTextWithFont(1790, 70, 30, scre80, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 81:
            myDrawTextWithFont(1790, 70, 30, scre81, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 82:
            myDrawTextWithFont(1790, 70, 30, scre82, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 83:
            myDrawTextWithFont(1790, 70, 30, scre83, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 84:
            myDrawTextWithFont(1790, 70, 30, scre84, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 85:
            myDrawTextWithFont(1790, 70, 30, scre85, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 86:
            myDrawTextWithFont(1790, 70, 30, scre86, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 87:
            myDrawTextWithFont(1790, 70, 30, scre87, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 88:
            myDrawTextWithFont(1790, 70, 30, scre88, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 89:
            myDrawTextWithFont(1790, 70, 30, scre89, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 90:
            myDrawTextWithFont(1790, 70, 30, scre90, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 91:
            myDrawTextWithFont(1790, 70, 30, scre91, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 92:
            myDrawTextWithFont(1790, 70, 30, scre92, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 93:
            myDrawTextWithFont(1790, 70, 30, scre93, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 94:
            myDrawTextWithFont(1790, 70, 30, scre94, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 95:
            myDrawTextWithFont(1790, 70, 30, scre95, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 96:
            myDrawTextWithFont(1790, 70, 30, scre96, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 97:
            myDrawTextWithFont(1790, 70, 30, scre97, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 98:
            myDrawTextWithFont(1790, 70, 30, scre98, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 99:
            myDrawTextWithFont(1790, 70, 30, scre99, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 100:
            myDrawTextWithFont(1790, 70, 30, scre100, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 101:
            myDrawTextWithFont(1790, 70, 30, scre101, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 102:
            myDrawTextWithFont(1790, 70, 30, scre102, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 103:
            myDrawTextWithFont(1790, 70, 30, scre103, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 104:
            myDrawTextWithFont(1790, 70, 30, scre104, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 105:
            myDrawTextWithFont(1790, 70, 30, scre105, RGB(0, 255, 0), RGB(20, 20, 20));
            break;
        case 106:
            myDrawTextWithFont(1790, 70, 30, scre106, RGB(0, 255, 0), RGB(20, 20, 20));
            break;







        }


        //Aliens Reset            // Placing black aliens after alien has moved (refreshing screen)
        alien_reset(r, box_y);
        alien_reset(r1, box_y1);
        alien_reset(r2, box_y2);
        alien_reset(r3, box_y3);
        alien_reset(r4, box_y4);
        alien_reset(r5, box_y5);
        alien_reset(r6, box_y6);
        alien_reset(r7, box_y7);
        alien_reset(r8, box_y8);
        alien_reset(r9, box_y9);

        //Aliens
        // 1st row of aliens
        aliens(box_x, box_y, win_y, fire_x, fire_y, r, PB, speed, count, ball_x, ball_y); sv_r = r; sv_by = box_y;
        aliens(box_x1, box_y1, win_y, fire_x, fire_y, r1, PB, speed, count, ball_x, ball_y); sv_r1 = r1; sv_by1 = box_y1;
        aliens(box_x2, box_y2, win_y, fire_x, fire_y, r2, PB, speed, count, ball_x, ball_y); sv_r2 = r2; sv_by2 = box_y2;
        aliens(box_x3, box_y3, win_y, fire_x, fire_y, r3, PB, speed, count, ball_x, ball_y); sv_r3 = r3; sv_by3 = box_y3;
        aliens(box_x4, box_y4, win_y, fire_x, fire_y, r4, PB, speed, count, ball_x, ball_y); sv_r4 = r4; sv_by4 = box_y4;
        aliens(box_x5, box_y5, win_y, fire_x, fire_y, r5, PB, speed, count, ball_x, ball_y); sv_r5 = r5; sv_by5 = box_y5;
        aliens(box_x6, box_y6, win_y, fire_x, fire_y, r6, PB, speed, count, ball_x, ball_y); sv_r6 = r6; sv_by6 = box_y6;
        aliens(box_x7, box_y7, win_y, fire_x, fire_y, r7, PB, speed, count, ball_x, ball_y); sv_r7 = r7; sv_by7 = box_y7;
        aliens(box_x8, box_y8, win_y, fire_x, fire_y, r8, PB, speed, count, ball_x, ball_y); sv_r8 = r8; sv_by8 = box_y8;
        aliens(box_x9, box_y9, win_y, fire_x, fire_y, r9, PB, speed, count, ball_x, ball_y); sv_r9 = r9; sv_by9 = box_y9;

        int a = CheckKeyPressed();
        int b = CheckKeyPressed1();

        ///////////////////// Bullets////////////////
        if ((a == 32) && (doo == false)) {
            PB = true;
            fire_x = ball_x + 72;
            fire_y = ball_y - 40;
            fire_y2 = ball_y;
            doo = true;
        }
        if (PB == true) {
            myEllipse(fire_x, fire_y - speed, fire_x + 5, fire_y2 - speed, RGB(12, 12, 12), RGB(12, 12, 12));
            speed += 50;
            myEllipse(fire_x, fire_y - speed, fire_x + 5, fire_y2 - speed, RGB(255, 69, 69), RGB(255, 69, 69));
        }
        if (PB == false) {
            myEllipse(fire_x, fire_y - speed, fire_x + 5, fire_y2 - speed, RGB(12, 12, 12), RGB(12, 12, 12));
            doo = false;
            speed = 0;
        }
        if (fire_y2 - speed <= 4) {
            PB = false;
            doo = false;
            speed = 0;
        }




        bool ext_game_flg = false;
        // Moving Spaceship left,right,upwards and downwards (Also keeping them within the frame).
        if (a == LEFTKEY) {
            if (ball_x > 5) {
                spaceship_reset(ball_x, ball_y);
                ball_x -= 40;
            }
        }
        else if (a == RIGHTKEY) {
            if (ball_x < 1750) {
                spaceship_reset(ball_x, ball_y);
                ball_x += 40;
            }
        }
        else if (a == UPKEY) {
            if (ball_y > 50) {
                spaceship_reset(ball_x, ball_y);
                ball_y -= 40;
            }
        }
        else if (a == DOWNKEY) {
            if (ball_y < 900) {
                spaceship_reset(ball_x, ball_y);
                ball_y += 40;
            }
        }


        else if (a == 27) {                        // Pausing game and saving game
            ClearScreen();
            ofstream myfile("save_game.txt");
            char kbhit;
            cout << "The game has been paused ";
            cout << endl << "Press 'r' key to continue playing the game ";
            cout << endl << "Press 's' key to save the game " << endl;
            kbhit = getchar();
            switch (kbhit) {
            case 's':
////////////// ////////////save game here //////////////// /////////////////
                myfile << h_score[0] << endl << h_score[1] << endl << h_score[2] << endl << h_score[3] << endl;
                myfile << h_score[4] << endl << alien_cnt << endl;
                myfile << score << endl << count << endl;
                myfile << spaceship_ball_x << endl;
                myfile << spaceship_ball_y << endl;
                myfile << sv_by << endl << sv_by1 << endl << sv_by2 << endl << sv_by3 << endl << sv_by4 << endl;
                myfile << sv_by5 << endl << sv_by6 << endl << sv_by7 << endl << sv_by8 << endl << sv_by9 << endl;
                myfile << sv_r << endl << sv_r2 << endl << sv_r3 << endl << sv_r4 << endl << sv_r5 << endl;
                myfile << sv_r6 << endl << sv_r7 << endl << sv_r8 << endl << sv_r9 << endl;

                ClearScreen();
                myfile.close();
                Sleep(500);
                cout << "Would you like to continue or exit the game ? " << endl;
                cout << "Press 'r' to resume the game and 'e' to exit the game " << endl;
                char uy;
                cin >> uy;
                if (uy == 'e') {
                    ext_game_flg = true;
                    break;
                }
            case 'r':
                ClearScreen();
                break;
            }

        }
        if (ext_game_flg == true) {
            int temp1, temp2, temp3, temp4;
            if (score > h_score[4] && score < h_score[3]) {
                h_score[4] = score;
            }
            if (score > h_score[3] && score < h_score[2]) {
                temp1 = h_score[3];
                h_score[3] = score;
                h_score[4] = temp1;
            }
            if (score > h_score[2] && score < h_score[1]) {
                temp1 = h_score[2];
                temp2 = h_score[3];
                h_score[2] = score;
                h_score[3] = temp1;
                h_score[4] = temp2;
            }
            if (score > h_score[1] && score < h_score[0]) {
                temp1 = h_score[1];
                temp2 = h_score[2];
                temp3 = h_score[3];
                h_score[1] = score;
                h_score[2] = temp1;
                h_score[3] = temp2;
                h_score[4] = temp3;
            }
            if (score > h_score[0]) {
                temp1 = h_score[0];
                temp2 = h_score[1];
                temp3 = h_score[2];
                temp4 = h_score[3];
                h_score[0] = score;
                h_score[1] = temp1;
                h_score[2] = temp2;
                h_score[3] = temp3;
                h_score[4] = temp4;
            }
            break;
        }

        //spaceship                  // Printing SpaceShip
        myRect(ball_x, ball_y - 30, ball_x + 150, ball_y + 55, RGB(12, 12, 12), RGB(12, 12, 12));
        myLine(ball_x + 40, ball_y - 10, ball_x + 40, ball_y - 40, RGB(255, 255, 51));
        myLine(ball_x + 110, ball_y - 10, ball_x + 110, ball_y - 40, RGB(255, 255, 51));
        myLine(ball_x + 60, ball_y - 10, ball_x + 60, ball_y - 25, RGB(255, 0, 0));
        myLine(ball_x + 90, ball_y - 10, ball_x + 90, ball_y - 25, RGB(255, 0, 0));
        myRect(ball_x + 72, ball_y - 20, ball_x + 77, ball_y + 20, RGB(150, 0, 0), RGB(150, 0, 0));
        myEllipse(ball_x + 150, ball_y - 30, ball_x + 160, ball_y + 40, RGB(100, 100, 100), RGB(100, 100, 100));
        myEllipse(ball_x - 10, ball_y - 30, ball_x, ball_y + 40, RGB(100, 100, 100), RGB(100, 100, 100));
        myEllipse(ball_x + 20, ball_y - 10, ball_x + 130, ball_y, RGB(72, 23, 23), RGB(72, 23, 23));
        myEllipse(ball_x, ball_y, ball_x + 150, ball_y + 20, RGB(100, 100, 100), RGB(100, 100, 100));
        myEllipse(ball_x, ball_y, ball_x + 150, ball_y + 45, RGB(12, 12, 12), RGB(12, 12, 12));

        //coordinates of the spaceship for save game
        spaceship_ball_x = ball_x;
        spaceship_ball_y = ball_y;

        if (count <= 0 || alien_cnt >= 50) {
            int temp1, temp2, temp3, temp4;
            if (score > h_score[4] && score < h_score[3]) {
                h_score[4] = score;
            }
            if (score > h_score[3] && score < h_score[2]) {
                temp1 = h_score[3];
                h_score[3] = score;
                h_score[4] = temp1;
            }
            if (score > h_score[2] && score < h_score[1]) {
                temp1 = h_score[2];
                temp2 = h_score[3];
                h_score[2] = score;
                h_score[3] = temp1;
                h_score[4] = temp2;
            }
            if (score > h_score[1] && score < h_score[0]) {
                temp1 = h_score[1];
                temp2 = h_score[2];
                temp3 = h_score[3];
                h_score[1] = score;
                h_score[2] = temp1;
                h_score[3] = temp2;
                h_score[4] = temp3;
            }
            if (score > h_score[0]) {
                temp1 = h_score[0];
                temp2 = h_score[1];
                temp3 = h_score[2];
                temp4 = h_score[3];
                h_score[0] = score;
                h_score[1] = temp1;
                h_score[2] = temp2;
                h_score[3] = temp3;
                h_score[4] = temp4;
            }
            ofstream myfile("save_game.txt");
            myfile << h_score[0] << endl << h_score[1] << endl << h_score[2] << endl << h_score[3] << endl;
            myfile << h_score[4] << endl;
            myfile.close();
            break;
        }


    }


    ClearScreen();
    cout << endl << endl << endl << endl << endl << "                     ";
    cout << "The game is over. " << endl << "                     ";
    cout << "Your Score : " << score << endl << endl << endl << endl;



    system("pause");
}