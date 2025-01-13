
#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

int main()
{
	int x0=100;
int	y0=100;
int	x1=200;
int	y1=200;


	cout << "Enter x0: ";
    cin >> x0 ;
    cout<<"enter y0:"<<endl;
    cin>>y0;
    cout << "Enter x1: "<<endl;
    cin>>x1;
    cout<<"enter y1:"<<endl;
    cin >> y1;

	double dx = x1 - x0;
    double dy = y1 - y0;
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);    
    double xincr = dx / steps;
    double yincr = dy / steps;    
    cout << "Rasterizing the line..." << endl;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    double x = x0;
    double y = y0;
    for (int i = 0; i <= steps; ++i) {
        putpixel(round(x), round(y), WHITE); 
        x += xincr; 
        y += yincr; 
    }

}
