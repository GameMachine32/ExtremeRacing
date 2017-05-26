/*
   Extreme racing game
   Feel free to change this source code to make it better.
*/
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
int ry1 = 30, ry2 = 90, ry3 = 150, ry4 = 210, ry5 = 270, ry6 = 330, ry7 = 390, ry8 = 450;
void placerect(int x, int y, int sizex, int sizey, int color)
{
    int newx = x;
    for (int i = 0; i < sizey; i++) {
        for (int j = 0; j < sizex; j++) {
            putpixel(newx, y, color);
            newx++;
        }
        newx = x;
        y++;
    }
}
void animateroad()
{
    placerect(230, ry1, 10, 30, 15);
    placerect(230, ry2, 10, 30, 15);
    placerect(230, ry3, 10, 30, 15);
    placerect(230, ry4, 10, 30, 15);
    placerect(230, ry5, 10, 30, 15);
    placerect(230, ry6, 10, 30, 15);
    placerect(230, ry7, 10, 30, 15);
    placerect(230, ry8, 10, 30, 15);
}
int main(void)
{
    int x = 300, y = 400, ex = rand() % 150 + 100, ey = 1, score = 1;
    double speed = 1;
    string newscore;
    initwindow(500, 500, "Extreme Racer");
    for (;;) {
        newscore = score;
        if (GetAsyncKeyState(VK_LEFT)) {
            if (not(x < 150)) {
                x -= 15;
            }
        }
        else if (GetAsyncKeyState(VK_RIGHT)) {
            if (not(x > 350)) {
                x += 15;
            }
        }
        // Draws the graphics
        animateroad();
        circle(x, y, 20);
        circle(ex, ey, 20);
        rectangle(101, 1, 400, 500);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1, 100, WHITE);
        floodfill(450, 100, WHITE);
        setfillstyle(SOLID_FILL, 7);
        floodfill(250, 250, WHITE);
        floodfill(200, 250, WHITE);
        // Moves the ball down by the speed int
        ey += speed;
        // Changes the speed by 0.1
        speed += 0.1;
        // Detect if the ball is at the bottom of the screen
        if (ey > 500) {
            // Change score by 1
            score = score + 1;
            // Move the ball to the top of the screen
            ey = 1;
            // Set x pos to random
            ex = rand() % 260 + 100;
        }
        // Lots of math to detect collision
        if (x == ex && y <= ey || x == ex + 1 && y <= ey || x == ex + 2 && y <= ey || x == ex + 3 && y <= ey || x == ex + 4 && y <= ey || x == ex + 5 && y <= ey + 5 || x == ex + 6 && y <= ey || x == ex + 7 && y <= ey || x == ex + 8 && y <= ey || x == ex + 9 && y <= ey || x == ex + 10 && y <= ey || x == ex + 11 && y <= ey || x == ex + 12 && y <= ey || x == ex + 13 && y <= ey || x == ex + 14 && y <= ey || x == ex + 15 && y <= ey || x == ex + 16 && y <= ey || x == ex + 17 && y <= ey || x == ex + 18 && y <= ey || x == ex + 19 && y <= ey || x == ex + 20 && y <= ey || x == ex - 1 && y <= ey || x == ex - 2 && y <= ey || x == ex - 3 && y <= ey || x == ex - 4 && y <= ey || x == ex - 5 && y <= ey || x == ex - 6 && y <= ey || x == ex - 7 && y <= ey || x == ex - 8 && y <= ey || x == ex - 9 && y <= ey || x == ex - 10 && y <= ey || x == ex - 11 && y <= ey || x == ex - 12 && y <= ey || x == ex - 13 && y <= ey || x == ex - 14 && y <= ey || x == ex - 15 && y <= ey || x == ex - 16 && y <= ey || x == ex - 17 && y <= ey || x == ex - 18 && y <= ey || x == ex - 19 && y <= ey || x == ex - 20 && y <= ey) {
            // Makes sure the ball is not at the bottom of the screen
            if (not(ey > 450)) {
                cleardevice();
                outtextxy(200, 200, "Game over :(");
                getch();
                exit(0);
            }
        }
        // Makes sure that the ball does not go too fast
        if (speed > 2) {
            speed = 10;
        }
        ry1 += 5;
        ry2 += 5;
        ry3 += 5;
        ry4 += 5;
        ry5 += 5;
        ry6 += 5;
        ry7 += 5;
        ry8 += 5;
        if (ry1 > 500) {
            ry1 = 0;
        }
        if (ry2 > 500) {
            ry2 = 0;
        }
        if (ry3 > 500) {
            ry3 = 0;
        }
        if (ry4 > 500) {
            ry4 = 0;
        }
        if (ry5 > 500) {
            ry5 = 0;
        }
        if (ry6 > 500) {
            ry6 = 0;
        }
        if (ry7 > 500) {
            ry7 = 0;
        }
        if (ry8 > 500) {
            ry8 = 0;
        }
        Sleep(15);
        swapbuffers();
        cleardevice();
    }
}
