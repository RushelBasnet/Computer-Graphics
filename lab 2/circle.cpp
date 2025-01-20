#include <iostream>
#include <graphics.h> // Graphics library for drawing (if available)

// Function to plot points in all octants
void plotCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r; // Initial decision parameter

    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr); // Initialize graphics mode

    int xc, yc, r;
    std::cout << "Enter the center of the circle (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    drawCircle(xc, yc, r); // Draw the circle

    getch(); // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}

