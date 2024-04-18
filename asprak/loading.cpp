#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	float koor = 0;
	int r = 9;
	cin >> r;

	while (1)
	{
		system("cls");
		if (koor == 6)
		{
			koor = 0;
		}
		koor += 0.1;
		for (int y = r; y >= -r; y--)
		{
			for (int x = -r; x <= r; x++)
			{
				cout << setw(2);
				//				c = x*x+y*y;
				//				z = (x-a)*(x-a)+y*y;
				if (x * x + y * y <= r * (r - 1) && (x) * (x) + y * y >= r * (r - 4) && (x - sin(koor) * r) * (x - sin(koor) * r) + (y - cos(koor) * r) * (y - cos(koor) * r) >= r * (r - 6))
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
}
