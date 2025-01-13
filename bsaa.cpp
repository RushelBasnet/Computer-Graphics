#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x0, y0, x1, y1;

    // Input points
    cout << "Enter x0:" << endl;
    cin >> x0;
    cout << "Enter y0:" << endl;
    cin >> y0;
    cout << "Enter x1:" << endl;
    cin >> x1;
    cout << "Enter y1:" << endl;
    cin >> y1;

    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculate differences
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    // Determine step direction
    int sx = (x1 > x0) ? 1 : -1;
    int sy = (y1 > y0) ? 1 : -1;

    // Initialize variables
    int x = x0, y = y0;

    // Check if the slope is shallow or steep
    if (dx > dy) {
        // Shallow slope: iterate over x
        int pk = 2 * dy - dx; // Initial decision variable
        putpixel(x, y, WHITE); // Plot the first point

        for (int i = 0; i < dx; ++i) {
            if (pk < 0) {
                pk += 2 * dy;
            } else {
                y += sy;
                pk += 2 * (dy - dx);
            }
            x += sx;
            putpixel(x, y, WHITE); // Plot the pixel
        }
    } else {
        // Steep slope: iterate over y
        int pk = 2 * dx - dy; // Initial decision variable
        putpixel(x, y, WHITE); // Plot the first point

        for (int i = 0; i < dy; ++i) {
            if (pk < 0) {
                pk += 2 * dx;
            } else {
                x += sx;
                pk += 2 * (dx - dy);
            }
            y += sy;
            putpixel(x, y, WHITE); // Plot the pixel
        }
    }

    // Wait for user input before closing
    getch();
    closegraph();
    return 0;
}
