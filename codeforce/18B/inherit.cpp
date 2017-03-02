#include <iostream>
#include <string>

using namespace std;

class Point{
	int x, y;
public:
	Point(){ x = 0, y = 0;}
	Point(int x, int y){
		this-> x = x;
		this-> y = y;
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
protected:
	void move(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class ColorPoint : public Point{
	string color;
public:
	ColorPoint(){
		color = "BLACK";
	}
	ColorPoint(int x, int y, string color ="BLACK") : Point(x, y){
		this-> color = color;
	}
	void setPoint(int x, int y){
		move(x, y);
	}
	void show(){
		cout<<color<<endl;
	}
};

int main(){


	return 0;
}