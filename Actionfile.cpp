#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;

int map[8][8][5];


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// North returns 1, East returns 2, South returns 3; West returns 4; An error returns 0;
void print(string x){
	std::cout << x+" \n";
}

int attack(){
	return rand() % 10 + 1;
}


int move(string i){
	if (i == "north"){
		return 1;
	}
	if (i == "east"){
		return 2;
	}
	if (i == "south"){
		return 3;
	}
	if (i == "west"){
		return 4;
	}
	else{
		return 0;
	}
}

int action(string userInput){
	if(userInput == "move"){
		
		print("What direction would you like to move?");
		string input;
		cin >> input;
		return move(input);
	
}
	if(userInput == "look"){
		return 5;
	}
	if(userInput == "attack"){
		return 6;
	}
	if(userInput == "use"){
		return 7;
	}
	if(userInput == "help"){
		return 8;
	}
	if(userInput == "take"){
		return 9;
	}
	
else return 0;
}


void getInstructions(){
	print("Use these words to complete actions:");
	print("look");
	print("attack");
	print("move");
	print("use");
	print("help");
	print("take");
	print(" ");

}

int checkSquare(int n,int x, int y, int z){
	if(n == 1){
		if(map[x + 1][y][z] == 1){
		return 0;
		}
		else return 1;
	}
	if(n == 2){
		if(map[x][y+1][z] == 1){
		return 0;
		}
		else return 2;
	}
	if(n == 3){
		if(map[x][y-1][z] == 1){
			return 0;
		}
		else return 3;
	}
	if(n == 4){
		if(map[x][y-1][z] == 1){
			return 0;
		}
		else return 4;
	}
}


int main(int argc, char** argv) {
	
	int x = 1;
	int y = 1;
	int z = 0;
	int input = 0;
	int score = 0;
	int hunger = 0;
	int health = 100;
	
	// Level 1 boundaries
	map[0][0][0] = 1;
	map[0][1][0] = 1;
	map[0][2][0] = 1;
	map[0][3][0] = 1;
	map[0][4][0] = 1;
	map[0][5][0] = 1;
	map[0][6][0] = 1;
	map[0][7][0] = 1;
	map[1][0][0] = 1;
	map[2][0][0] = 1;
	map[3][0][0] = 1;
	map[4][0][0] = 1;
	map[5][0][0] = 1;
	map[6][0][0] = 1;
	map[7][0][0] = 1;
	map[1][7][0] = 1;
	map[2][7][0] = 1;
	map[3][7][0] = 1;
	map[4][7][0] = 1;
	map[5][7][0] = 1;
	map[6][7][0] = 1;
	map[7][7][0] = 1;
	map[7][6][0] = 1;
	map[7][5][0] = 1;
	map[7][4][0] = 1;
	map[7][3][0] = 1;
	map[7][2][0] = 1;
	map[7][1][0] = 1;
	map[7][0][0] = 1;
	
	//Level 1 monster locations, use even values
	map[1][3][0] = 4;
	map[2][5][0] = 2;
	map[3][2][0] = 2;
	map[5][6][0] = 2;
	map[5][4][0] = 2;
	
	//level 1 treasure locations, use odd values, not one
	map[1][2][0] = 3;
	map[3][1][0] = 5;
	map[6][1][0] = 7;
	map[1][6][0] = 9;
	
	/*------------------------------------------------------*/
	//Level 2 boundaries
	map[0][0][1] = 1;
	map[0][1][1] = 1;
	map[0][2][1] = 1;
	map[0][3][1] = 1;
	map[0][4][1] = 1;
	map[0][5][1] = 1;
	map[0][6][1] = 1;
	map[0][7][1] = 1;
	map[1][0][1] = 1;
	map[2][0][1] = 1;
	map[3][0][1] = 1;
	map[4][0][1] = 1;
	map[5][0][1] = 1;
	map[6][0][1] = 1;
	map[7][0][1] = 1;
	map[1][7][1] = 1;
	map[2][7][1] = 1;
	map[3][7][1] = 1;
	map[4][7][1] = 1;
	map[5][7][1] = 1;
	map[6][7][1] = 1;
	map[7][7][1] = 1;
	map[7][6][1] = 1;
	map[7][5][1] = 1;
	map[7][4][1] = 1;
	map[7][3][1] = 1;
	map[7][2][1] = 1;
	map[7][1][1] = 1;
	map[7][0][1] = 1;
	
	//Level 2 Monster, use even
	map[1][3][1] = 4;
	map[2][5][1] = 2;
	map[3][2][1] = 2;
	map[5][6][1] = 2;
	map[5][4][1] = 2;
	
	//level 2 treasure, use odds
	map[1][2][1] = 3;
	map[3][1][1] = 5;
	map[6][1][1] = 7;
	map[1][6][1] = 9;
	
	
	
	while(true){
		
		if(x == 5 && y == 5){
			cout << "You reached the end!!!\n";
			z++;
			x = 1;
			y = 1;
		}
		if(hunger == 10){
			cout << "You Keel over from starvation\n";
		}
		
		if(map[x][y][z] % 2 == 0 && map[x][y][z] != 0)
		{
			cout << "Theres a slavering beast here\n\n";
		}
		if((map[x][y][z] % 2) != 0 && map[x][y][z] != 1)
		{
			cout << "Theres a pile of gold here\n\n";
		}
		cout << "SCORE: " << score << "\n";
		cout << "HEALTH: " << health << "\n";
		cout << "HUNGER: " << hunger << "\n\n";
		
		
		//Basic Movement
		
		string userInput;
		getInstructions();
		print("Make your move");
		cin >> userInput;
		system("cls");
		if(userInput == "move"){
			input = action(userInput);
			if(checkSquare(input, x, y, z) == 0){
				cout << "You cant go that way";
				cout << "Test";
			}
			else
			{
			if(checkSquare(input, x, y, z) == 1)
			{
				y++;
				cout << "\nMoving North";
			}
			if(checkSquare(input, x, y, z) == 2)
			{
				x++;
				cout << "\nMoving East";
			}
			if(checkSquare(input, x, y, z) == 3)
			{
				y--;
				cout << "\nMoving South";
			}
			if(checkSquare(input, x, y, z) == 4)
			{
				x--;
				cout << "\nMoving West";
			}
		}
	}
	
	if(userInput == "attack" && map[x][y][z] % 2 == 0){
		if(attack() >= map[x][y][z]){
			cout << "You Kill the Beast";
			score += map[x][y][z] * 100;
			map[x][y][z] = 0;
		}
		else{
		 cout << "You whiff";
		 health -= (map[x][y][z] / 2) * 10;
		 }
	}
	if(userInput == "take" && map[x][y][z] % 2 != 0){
		cout << "You pocket as many coins as you can\n";
		score += map[x][y][z] * 100;
		map[x][y][z] = 0;
	}
		cout << " X "<< x << " Y " <<  y << " Z " << z;
		print(" ");
	
	if(userInput == "wait")
	{
		if(health < 100){health += 10;}
		hunger += 1;
	}	
		
	}
	
	return 0;

}


