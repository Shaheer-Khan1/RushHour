//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
    	int arrx[250],arry[200];
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 16, yI = 791.5;
float sx=10,sy=800,radius=8;
float sx1=40.5;
void drawCar() {
	//void DrawCircle(float sx, float sy, float radius, float*color)
	DrawSquare(xI, yI, 19, colors[ORANGE]);         //main car
	DrawCircle(sx ,sy , radius, colors[BLACK]);    //
	DrawCircle(sx1 ,sy , radius, colors[BLACK]);   //
	glutPostRedisplay();


}

bool pickup=true;
bool drop=true;
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 100 || key == 'D') //Key for placing the bomb
			{
		drop=false;

	}
	if(key == 32){  //SpaceBar ASCII
	         pickup=false;
	         if (key!=32){
	         pickup=true;}}
	
	glutPostRedisplay();
}


int x2=30,y2=30;
float sx2=24,sy2=38.5;
float sx3=54.5;

int x3=30,y3=810;
float sx4=24,sy3=818.5;
float sx5=54.5;

int x4=323,y4=310;
float sx6=316,sy4=318.5;
float sx7=347;


void otherCars(){

	DrawSquare(x2, y2, 19, colors[RED]);
	DrawCircle(sx2 ,sy2 , radius, colors[BLACK]);
	DrawCircle(sx3 ,sy2 , radius, colors[BLACK]);
	
	DrawSquare(x3, y3, 19, colors[BLUE]);
	DrawCircle(sx4, sy3 , radius, colors[BLACK]);
	DrawCircle(sx5 ,sy3 , radius, colors[BLACK]);
	
	DrawSquare(x4, y4, 19, colors[PURPLE]);
	DrawCircle(sx6, sy4 , radius, colors[BLACK]);
	DrawCircle(sx7 ,sy4 , radius, colors[BLACK]);
	
	//DrawSquare(x5, y5, 19, colors[BLUE]);
	//DrawCircle(sx8, sy5 , radius, colors[BLUE]);
	//DrawCircle(sx9 ,sy5 , radius, colors[BLUE]);
	
	glutPostRedisplay();
	
	}

	
bool flag = true;
void moveCar() {
	
	if (x2 > 25 && flag) {
		x2 -= 10;
		sx2 -= 10;
		sx3 -= 10;
		if(x2 < 25)
			
			flag = false;
	}
	else if(x2 < 1018 && !flag) {
		x2 += 10;
		sx2 += 10;
		sx3 += 10;
		if(x2==xI && y2==yI){
		x2 -= 10;
		sx2 -= 10;
		sx3 -= 10;
		
		
		}
		if (x2 > 900)
			flag = true;
	}
	
	if (x3 > 65 && flag) {
		x3 -= 10;
		sx4 -= 10;
		sx5 -= 10;
		if(x2 < 65)
			
			flag = false;
	}
	else if(x3 < 1018 && !flag) {
		x3 += 10;
		sx4 += 10;
		sx5 += 10;
		if (x2 > 900)
			flag = true;
	}
	
	
	
	if (y4 > 300 && flag) {
		y4 -= 10;
		sy4 -= 10;
		if(y4 < 300)
			
			flag = false;

	}
	else if(y4 < 600 && !flag) {
		y4 += 10;
		sy4 += 10;
		if (y4 > 600)
			flag = true;
	}
}

bool passenger=true;
/*void passengers() {
	if (flag) {
		//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
			if(psngr)
			flag = false;

	}
	else if(y4 < 600 && !flag) {
	
		if (y4 > 600)
			flag = true;
	}
}	 



/*
 * Main Canvas drawing function.
 * */
bool menu = true;
bool sel_car=true;
bool red=true;
bool yellow=true;
bool rand1=true;

int psng_x=24, psng_y=27, psng_x1=24, psng_y1=76, psng_width=53;
int psng_x2=190, psng_y2=257, psng_x3=190, psng_y3=305, psng_width1=53;
int psng_x4=980, psng_y4=400, psng_x5=980, psng_y5=453, psng_width2=53;

void GameDisplay(){
	
	if(menu == true )
	{
		
		DrawRectangle(0,520,1000, 53, colors[WHITE]);
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glutPostRedisplay();
		
		
	}
	
	else{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	
	
	
	
	//DrawSquare(250, 250, 1000, colors[MISTY_ROSE]);
	//DrawRectangle(int sx, int sy, int width, int height, float *color);
	DrawRectangle(152,600, 53, 53, colors[BROWN]);  //obstacles
	DrawRectangle(430,500, 53, 53, colors[BROWN]);
	DrawRectangle(610,90, 53, 53, colors[BROWN]);
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine(650,730 ,650 ,783 ,55, colors[BLACK]);
	DrawLine(975,200 ,975 ,200 ,55 , colors[BLACK]);
	if(!pickup && xI>=psng_x-20 && xI<=psng_x+20 && yI>=psng_y-20 && yI<=psng_y+20 && drop){
		//void DrawRoundRect(float x, float y, float width, float height, float* color,float radius)
		DrawRoundRect(850,600, 53, 53, colors[PINK],53);}
	else if(pickup){
	DrawLine(psng_x, psng_y, psng_x1, psng_y1, psng_width, colors[BLACK]);}
	int cpsng_x=850, cpsng_y=600, cpsng_x1=53, cpsng_y1=53, cpsng_width=14;
	if(!pickup && drop){
	DrawRoundRect(cpsng_x,cpsng_y,cpsng_x1,cpsng_y1,colors[YELLOW],cpsng_width);}
	else if(!pickup && cpsng_x>=psng_x-20 && cpsng_x<=psng_x+20 && cpsng_y>=psng_y-20 && cpsng_y<=psng_y+20){
	DrawLine(psng_x, psng_y, psng_x1, psng_y1, psng_width, colors[BLACK]);}
	if(!drop){
	DrawLine(cpsng_x, cpsng_y, cpsng_x, cpsng_y+53, psng_width, colors[BLACK]);}
	
	if(!pickup && xI>=psng_x2-20 && xI<=psng_x2+20 && yI>=psng_y2-20 && yI<=psng_y2+20 && drop){
		//void DrawRoundRect(float x, float y, float width, float height, float* color,float radius)
		DrawRoundRect(850,600, 53, 53, colors[YELLOW],14);}
	else if(pickup){
	DrawLine(psng_x2, psng_y2, psng_x3, psng_y3, psng_width1, colors[BLACK]);}
	int cpsng_x2=450, cpsng_y2=600, cpsng_x3=53, cpsng_y3=53, cpsng_width1=14;
	if(!pickup && drop){
	DrawRoundRect(cpsng_x2,cpsng_y2,cpsng_x3,cpsng_y3,colors[YELLOW],cpsng_width1);}
	else if(!pickup && cpsng_x2>=psng_x2-20 && cpsng_x2<=psng_x2+20 && cpsng_y2>=psng_y2-20 && cpsng_y2<=psng_y2+20){
	DrawLine(psng_x2, psng_y2, psng_x1, psng_y1, psng_width, colors[BLACK]);}
	if(!drop){
	DrawLine(cpsng_x1, cpsng_y1-10, cpsng_x1, cpsng_y1+43, psng_width, colors[BLACK]);}
	//DrawLine(psng_x2, psng_y2, psng_x3, psng_y3, psng_width1, colors[BLACK]);
	
	
	if(pickup && xI!=psng_x3){
	DrawLine(psng_x4, psng_y4, psng_x5, psng_y5, psng_width1, colors[BLACK]);}
	
	DrawRectangle(51.9,102.99, 51.9, 500, colors[BLACK]); //buildings
	DrawRectangle(204.5,256.97, 51.9, 200, colors[BLACK]);
	DrawRectangle(356.6,409, 206, 75, colors[BLACK]);
	DrawRectangle(356.6,300, 53, 300, colors[BLACK]);
	DrawRectangle(764.63,150, 53, 300, colors[BLACK]);
	DrawRectangle(152,70, 206, 75, colors[BLACK]);
	DrawRectangle(152,695, 206, 75, colors[BLACK]);
	DrawRectangle(610,300, 53, 200, colors[BLACK]);
	DrawRectangle(508,600, 104, 130, colors[BLACK]);	
	DrawRectangle(916,100, 52, 670, colors[BLACK]);
	DrawRectangle(730,695, 200, 75, colors[BLACK]);
	DrawRectangle(407,70, 104, 130, colors[BLACK]); 
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	DrawString( 50, 800, "Score=0", colors[RED]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	double grd1=1;
	for(int i=0; i<21; i++){
	DrawLine(  0+grd1 , 0 , 0+grd1 , 1000 , 10 , colors[BLACK] );	
	grd1=grd1+50.91;
	}
	
	/* DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);*/
	otherCars();
	drawCar();
	glutSwapBuffers(); // do not modify this line..

}
}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	
	if (key== GLUT_KEY_LEFT){
	if((yI+19>=695 && yI<=695+75) && (xI + 32>=160 && xI<=152+206)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=600 && yI<=600+130) && (xI + 32>=515 && xI<=508+104)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=695 && yI<=695+75) && (xI + 32>=740 && xI<=730+200)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		
		else if((yI+19>=100 && yI<=100+670) && (xI + 32>=925 && xI<=925+52)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=695 && yI<=695+75) && (xI + 32>=738 && xI<=730+200)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=150 && yI<=150+300) && (xI + 32>=767 && xI<=763.63+53)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		
		else if((yI+19>=300 && yI<=300+200) && (xI + 32>=615 && xI<=610+53)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=150 && yI<=150+300) && (xI + 32>=767 && xI<=763.63+53)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=70 && yI<=70+130) && (xI + 32>=412 && xI<=407+104)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		
		else if((yI+19>=70 && yI<=70+75) && (xI + 32>=210 && xI<=152+206)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=103 && yI<=103+500) && (xI + 32>=56 && xI<=52+52)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=257 && yI<=257+200) && (xI + 32>=208 && xI<=204+52)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+19>=300 && yI<=300+300) && (xI + 32>=363 && xI<=357+53)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+32>=409 && yI<=409+75) && (xI + 32>=363 && xI<=357+206)){
		xI=xI+5;
		sx=sx+5;
		sx1=sx1+5;}
		else if((yI+32>=600 && yI<=600+53) && (xI + 32>=158 && xI<=152+57)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
		else if((yI+32>=500 && yI<=500+53) && (xI + 32>=438 && xI<=430+57)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
		else if((yI+32>=90 && yI<=90+53) && (xI + 32>=616 && xI<=610+57)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
	else{   xI -= 5;
		sx -= 5;
		sx1 -= 5;

	}}
	if (key== GLUT_KEY_RIGHT){
		if((yI+32>=695 && yI<=700+75) && (xI + 32>=152 && xI<=147+206)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=600 && yI<=600+130) && (xI + 32>=508 && xI<=503+104)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=695 && yI<=695+75) && (xI + 32>=730 && xI<=725+200)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		
		else if((yI+32>=100 && yI<=100+670) && (xI + 32>=916 && xI<=909+52)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=695 && yI<=695+75) && (xI + 32>=730 && xI<=725+200)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=150 && yI<=150+300) && (xI + 32>=763.63 && xI<=759+53)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		
		else if((yI+32>=300 && yI<=300+200) && (xI + 32>=610 && xI<=605+53)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=150 && yI<=150+300) && (xI + 32>=763.63 && xI<=758+53)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=70 && yI<=70+130) && (xI + 32>=407 && xI<=403+104)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		
		else if((yI+32>=70 && yI<=70+75) && (xI + 32>=152 && xI<=148+206)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=103 && yI<=103+500) && (xI + 32>=52 && xI<=45+52)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=257 && yI<=257+200) && (xI + 32>=204 && xI<=197+52)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=300 && yI<=300+300) && (xI + 32>=357 && xI<=353+53)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=409 && yI<=409+75) && (xI + 32>=357 && xI<=353+206)){
		xI=xI-5;
		sx=sx-5;
		sx1=sx1-5;}
		else if((yI+32>=600 && yI<=600+53) && (xI + 32>=152 && xI<=152+45)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
		else if((yI+32>=500 && yI<=500+53) && (xI + 32>=430 && xI<=430+45)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
		else if((yI+32>=90 && yI<=90+53) && (xI + 32>=610 && xI<=610+45)){
		xI=xI;
		sx=sx;
		sx1=sx1;}
		
		else{				
		xI += 5;
		sx += 5;
		sx1 += 5; 
	}}
	
	else if (key == GLUT_KEY_UP){
	if((yI+32>=690 && yI<=695+70) && (xI + 32>=152 && xI<=152+206)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=600 && yI<=600+125) && (xI + 32>=508 && xI<=508+104)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=695 && yI<=690+75) && (xI + 32>=730 && xI<=730+200)){
		yI=yI-5;
		sy=sy-5;}
		
		else if((yI+32>=100 && yI<=95+670) && (xI + 32>=916 && xI<=916+52)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=695 && yI<=690+75) && (xI + 32>=730 && xI<=730+200)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=150 && yI<=145+300) && (xI + 32>=763.63 && xI<=763.63+53)){
		yI=yI-5;
		sy=sy-5;}
		
		else if((yI+32>=300 && yI<=295+200) && (xI + 32>=610 && xI<=610+53)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=150 && yI<=145+300) && (xI + 32>=763.63 && xI<=763.63+53)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=70 && yI<=65+130) && (xI + 32>=407 && xI<=407+104)){
		yI=yI-5;
		sy=sy-5;}
		
		else if((yI+32>=70 && yI<=65+75) && (xI + 32>=152 && xI<=152+206)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=103 && yI<=98+500) && (xI + 32>=52 && xI<=52+52)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=257 && yI<=252+200) && (xI + 32>=204 && xI<=204+52)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=300 && yI<=295+300) && (xI + 32>=357 && xI<=357+53)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=409 && yI<=405+75) && (xI + 32>=357 && xI<=357+206)){
		yI=yI-5;
		sy=sy-5;}
		else if((yI+32>=590 && yI<=590+35) && (xI + 32>=152 && xI<=152+45)){
		yI=yI;
		sy=sy;}
		else if((yI+32>=490 && yI<=500+53) && (xI + 32>=430 && xI<=430+45)){
		yI=yI;
		sy=sy;}
		else if((yI+32>=80 && yI<=90+53) && (xI + 32>=610 && xI<=610+45)){
		yI=yI;
		sy=sy;}
			
	else{
		yI += 5;
		sy += 5;
	}}

	else if (key== GLUT_KEY_DOWN){ 
	if((yI+32>=695 && yI<=695+75) && (xI + 32>=152 && xI<=152+206)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=600 && yI<=605+130) && (xI + 32>=508 && xI<=508+104)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=695 && yI<=670+75) && (xI + 32>=730 && xI<=730+200)){
		yI += 5;
		sy += 5;
	}
		
		else if((yI+32>=100 && yI<=105+670) && (xI + 32>=916 && xI<=916+52)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=695 && yI<=700+75) && (xI + 32>=730 && xI<=730+200)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=150 && yI<=155+300) && (xI + 32>=763.63 && xI<=763.63+53)){
		yI += 5;
		sy += 5;
	}
		
		else if((yI+32>=305 && yI<=305+200) && (xI + 32>=610 && xI<=610+53)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=150 && yI<=155+300) && (xI + 32>=763.63 && xI<=763.63+53)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=70 && yI<=75+130) && (xI + 32>=407 && xI<=407+104)){
		yI += 5;
		sy += 5;
	}
		
		else if((yI+32>=75 && yI<=75+75) && (xI + 32>=152 && xI<=152+206)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=103 && yI<=108+500) && (xI + 32>=52 && xI<=52+52)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=257 && yI<=263+200) && (xI + 32>=204 && xI<=204+52)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=300 && yI<=305+300) && (xI + 32>=357 && xI<=357+53)){
		yI += 5;
		sy += 5;
	}
		else if((yI+32>=409 && yI<=414+75) && (xI + 32>=357 && xI<=357+206)){
		yI += 5;
		sy += 5;
	}
	else{
		yI -= 5;
		sy -= 5;
	}}}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	y = 840 - y;
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseClicked(int button, int state, int x, int y) {
	y = 840 - y;
	if (button == GLUT_LEFT_BUTTON && y<720 && y>520 ){ // dealing only with left button
			
			menu = false;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;}
	else if (button == GLUT_LEFT_BUTTON && y<520 && y>320 ){ // dealing only with left button
			sel_car = false;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;}
	
	
	
	else if (button == GLUT_LEFT_BUTTON && y<720 && y>520 ){ // dealing only with left button
			red = false;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;}
	else if (button == GLUT_LEFT_BUTTON && y<520 && y>320 ){ // dealing only with left button
			yellow = false;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;}
	else if (button == GLUT_LEFT_BUTTON && y<320 && y>120 ){ // dealing only with left button
			rand1 = false;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;}
	
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}


int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Shaheer Khan"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
