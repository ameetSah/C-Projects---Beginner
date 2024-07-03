#include <graphics.h>
#include <iostream>
#include <cmath>
#include<stdlib.h>

using namespace std;

class GraphingCalculator {
private:
    int x_max;
    char strx[10],stry[10];
    int x_lbl;
    int y_lbl;
    float radius;
    int y_max;
    int x_origin;
    int y_origin;
    int x_scale;
    int y_scale;
    int color;
public:
    GraphingCalculator() {
        x_max = 720;
        y_max = 540;
        x_scale = 30;
        y_scale = 30;
        x_lbl = -(x_max/(2*x_scale));
        y_lbl = -(y_max/(2*y_scale));
        x_origin = x_max/2;
        y_origin = y_max/2;
        color = WHITE;
    }

void draw_xaxis(){
    //line
    line(0, y_origin, x_max, y_origin);

    //x-coordinates
    for (int i = 0; i <= getmaxx(); i += x_scale) {

        line(i, y_origin-2, i, y_origin+2);
        sprintf(strx,"%d",x_lbl);
        if(i%(2*x_scale)==0){

        if(x_lbl<0){
        outtextxy(i-8,y_origin+3, strx);
        }
        else{
            outtextxy(i-3,y_origin+3, strx);
        }
        x_lbl+=2;
      }
    }
}

void draw_yaxis(){
    //y-axis
    line(x_origin, 0, x_origin, y_max);
    //y-coordinates
    for (int i =0; i <=getmaxy(); i += y_scale) {
        line(x_origin-2,i, x_origin+2,i);
        sprintf(stry,"%d",y_lbl);
        if(i%(2*y_scale)==0){

        if(y_lbl<0){
        outtextxy(x_origin-16,y_max-i-5, stry);
        }
        else{
            outtextxy(x_origin-13,y_max-i-5, stry);
        }
        y_lbl+=2;
}
    }
    }

//Evaluate Functions
    double evaluate_trig_function(string function, double x) {
        if (function == "sin(x)"|| function=="sinx") {
            return sin(x);
        } else if (function == "cos(x)"|| function=="cosx") {
            return cos(x);
        } else if (function == "tan(x)"|| function=="tanx") {
            return tan(x);
        }
        else if (function == "cosec(x)"|| function=="cosecx") {
            return 1/sin(x);
        }
        else if (function == "sec(x)"|| function=="secx") {
            return 1/cos(x);
        }
        else if (function == "cot(x)"|| function=="cotx") {
            return 1/tan(x);
        }

        else {
            cout<<"Invalid Input !";
            return 0;
        }
    }
    double evaluate_linear_function(double x,double a, double b){
        return(a*x+b);
    }
    double evaluate_qudratic_function(double x,double a,double b,double c){
        return(a*pow(x,2)+b*x+c);
    }
    double evaluate_power_function(double x,double n){
        return(pow(x,n));
    }
    double evaluate_exponential_function(double x,double a){
        return(pow(a,x));

    }
    double evaluate_cubic_function(double x, double a, double b, double c, double d){
        return(a*pow(x,3)+b*pow(x,2)+c*x+d);
    }
    double evaluate_log_function(double x, double a){
        return(log(x)/log(a));
    }
    double evalutae_mod_function(double x, double a, double b){
              double val = a*x+b;
              if(val>0){
                return val;
              }
              else{
                return -val;
              }
    }

//Drawing Functions
    void draw_trig_function(string function) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_trig_function(function, x) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);

        }
    }
     void draw_linear_function(double a, double b) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_linear_function(x,a,b) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
             setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
     }

     void draw_mod_function(double a, double b) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evalutae_mod_function(x,a,b)*y_scale;
            //putpixel(x_origin + i, y_origin - y, color);

            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }
     void draw_qudratic_function(double a, double b, double c) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_qudratic_function(x,a,b,c) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }

     void draw_exponential_function(double a) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_exponential_function(x,a) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }
     void draw_power_function(double a) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_power_function(x,a) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }
     void draw_cubic_function(double a, double b, double c, double d) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_cubic_function(x,a,b,c,d) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }
    void draw_log_function(double a) {
        double x, y;
        for (int i = -x_origin; i < x_max - x_origin; i++) {
            x = i / (double)x_scale;
            y = evaluate_log_function(x,a) * y_scale;
            //putpixel(x_origin + i, y_origin - y, color);
            setcolor(color);
            circle(x_origin+i, y_origin-y, radius);
            floodfill(x_origin+i, y_origin-y, color);
        }
    }


//Setting parameters.
    void set_color(int new_color) {
        color = new_color;
    }

    void set_thickness(float new_radius){
    radius=new_radius;
    }
};

int main() {
//initialize window 540x720
    initwindow(720, 540, "Graphing Calculator");

//initialize variables
    double a,b,c,d,color_code=1;
    string function;
    char typ,add;



//Infinite loop to continue program.
    while(TRUE){

//creating object of class
    GraphingCalculator calculator;

//setting radius of plot
    calculator.set_thickness(1.9);

//resetting color to white
    setcolor(WHITE);
    calculator.draw_xaxis();
    calculator.draw_yaxis();

//setting color code
    calculator.set_color(color_code);

//Asking user for type of function.
    cout << "Enter type of function:\n   't'- trigonometric\n   'l' - linear\n   'q' - quadratic\n   'c' - cubic\n   'p' - power\n   'e' - exponential\n   'L' - logarithmic\n   'm' - modulus\n";
    cin>>typ;

    if(typ == 't'){
    cout<<"f(x) = ";
    cin>>function;
    calculator.draw_trig_function(function);
    }

    if(typ == 'm'){
    cout<<"f(x) = |ax+b|\n Enter a and b: ";
    cin>>a>>b;
    calculator.draw_mod_function(a,b);
    }

    if(typ == 'l'){
    cout<<"f(x) = ax+b\n Enter a and b: ";
    cin>>a>>b;
    calculator.draw_linear_function(a,b);
    }

    if(typ == 'L'){
    cout<<"f(x) = log_a(x)\n Enter base i.e, a: ";
    cin>>a;
    calculator.draw_log_function(a);
    }

    if(typ == 'q'){
    cout<<"f(x) = ax^2+bx+c\n Enter a,b,c: ";
    cin>>a>>b>>c;
    calculator.draw_qudratic_function(a,b,c);
    }

    if(typ == 'c'){
    cout<<"f(x) = ax^3+bx^2+cx+d\n  Enter a,b,c,d: ";
    cin>>a>>b>>c>>d;
    calculator.draw_cubic_function(a,b,c,d);
    }

    if(typ == 'p'){
    cout<<"f(x) = x^a\n Enter a: ";
    cin>>a;
    calculator.draw_power_function(a);
    }

    if(typ == 'e'){
    cout<<"f(x) = a^x\n Enter a: ";
    cin>>a;
    calculator.draw_exponential_function(a);
    }

//Asking user if they want to continue drawing
    cout<<"Enter 'A' if wanna add graph to the same\n'B' if clear and redraw graph\n'Q' if quit!"<<endl;
    cin>>add;

    if(add=='A'|| add=='a'){
        color_code++;
        continue;

    }
    else if(add=='B'|| add=='b'){
            color_code=1;
            cleardevice();
            system("cls");
            continue;
    }
    else if(add=='Q'){
        system("cls");
        cout<<"Program quited !";

        setcolor(WHITE);
        outtextxy(100, 30, "Press any Key to Quit !");

        break;
    }
}
while (!kbhit()) {
        delay(100);
        }
closegraph();
return 0;
}
