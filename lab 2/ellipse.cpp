#include <iostream>
#include <graphics.h> // Graphics library for drawing (if available)

// Function to plot points in all four quadrants
void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

// Midpoint Ellipse Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int rx2 = rx * rx, ry2 = ry * ry;
    int p1 = ry2 - (rx2 * ry) + (0.25 * rx2); // Initial decision parameter for region 1

    // Region 1: ellipse is more stretched along the x-axis
    while (2 * ry2 * x < 2 * rx2 * y) {
        plotEllipsePoints(xc, yc, x, y);
        if (p1 < 0) {
            x++;
            p1 += 2 * ry2 * x + ry2;
        } else {
            x++;
            y--;
            p1 += 2 * ry2 * x - 2 * rx2 * y + ry2;
        }
    }

    // Region 2: ellipse is more stretched along the y-axis
    int p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2; // Initial decision parameter for region 2

    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        if (p2 > 0) {
            y--;
            p2 -= 2 * rx2 * y + rx2;
        } else {
            x++;
            y--;
            p2 += 2 * ry2 * x - 2 * rx2 * y + rx2;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr); // Initialize graphics mode

    int xc, yc, rx, ry;
    std::cout << "Enter the center of the ellipse (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the semi-major axis (rx): ";
    std::cin >> rx;
    std::cout << "Enter the semi-minor axis (ry): ";
    std::cin >> ry;

    drawEllipse(xc, yc, rx, ry); // Draw the ellipse

    getch(); // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}

