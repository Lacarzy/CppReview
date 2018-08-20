#include<iostream>
#include"Game.h"
using namespace std;
int main() {

	Game game1("PUBG", 99.0, "FPS", 13.0);
	Game game2=Game("MHW", 319.0, "RPG", 30.0);
	double totalprice = game1 + game2;
	cout << totalprice << endl;
	cout << game1 * 10<<endl;
	cout << 2 * game2<<endl;
	cout << game1 << game2;
	if (game1 == game2) {
		cout << "Two game are the same"<<endl;
	}
	else
	{
		cout << "Two different game"<<endl;
	}
	system("pause");
}