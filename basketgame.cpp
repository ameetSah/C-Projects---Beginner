#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

// Function to draw the scene
void drawScene() {
    // Drawing ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 500, 900, 530);

    // Drawing poles
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(700, 200, 750, 500);

    //basket mouth
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    bar(695, 220, 700, 250);
    bar(620, 230, 695, 240);

    //Basket net
    setcolor(WHITE);
    line(625, 240, 640, 290);
    line(695, 240, 680, 290);
    line(640, 290, 680, 290);
}

int main() {
    // Initialize graphics window
    initwindow(800, 600, "Basketball Game");

    char playAgain;
    bool goalAchieved;

    do {

        drawScene(); // Draw the scene

        // Draw the basketball
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(100, 500, 15);
        floodfill(100, 500, YELLOW);

        // Prompt user for angle and velocity
        cout << "Enter launch angle (in degrees): ";
        int launchAngle;
        cin >> launchAngle;

        cout << "Enter launch velocity (in pixels per second): ";
        int launchVelocity;
        cin >> launchVelocity;

        // Convert angle to radians
        double radAngle = launchAngle * M_PI / 180.0;

        // Define constants for gravity and time interval
        const double GRAVITY = 9.81;
        const double TIME_INTERVAL = 0.1;

        // Define starting position and velocity of the basketball
        int xPosition = 100;
        int yPosition = 500;
        double xVelocity = launchVelocity * cos(radAngle);
        double yVelocity = -launchVelocity * sin(radAngle);

        // Start animation loop
        while (yPosition <= 500) {
            // Update position of the basketball
            xPosition += round(xVelocity * TIME_INTERVAL);
            yPosition += round(yVelocity * TIME_INTERVAL + 0.5 * GRAVITY * TIME_INTERVAL * TIME_INTERVAL);
            yVelocity += round(GRAVITY * TIME_INTERVAL);

            // Clear the screen
            cleardevice();

            // Redraw the scene
            drawScene();

            // Draw the basketball
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            circle(xPosition, yPosition, 15);
            floodfill(xPosition, yPosition, YELLOW);

            // Check for collision with the hoop
            if (yPosition > 230 && yPosition < 240 && xPosition > 635 && xPosition < 685) {
                goalAchieved = true;
                break;
            }

            // Delay for smooth animation
            delay(25);
        }

        // Display result
        if (goalAchieved) {
            outtextxy(350, 250, "Goal!");
        } else {
            outtextxy(350, 250, "Try Again!");
        }

        // Prompt user to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;

        // Reset variables for the next round
        goalAchieved = false;

      cleardevice(); // Clear the screen


    } while (playAgain == 'y' || playAgain == 'Y');

    // Close the graphics window
    setcolor(BLUE);
    outtextxy(320, 100, "Press any key to quit!");
    getch();
    closegraph();

    return 0;
}
