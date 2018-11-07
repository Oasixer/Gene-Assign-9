#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

const int NUMCOL = 3;
const int NUMROW = 36;

void outputData(int coffeeAvg[NUMROW][NUMCOL])
{
	cout << "Temperature" << setw(13) << "Coarseness" << setw(9) << "Score\n";
	for (int row = 0; row < NUMROW; row++)
	{
		cout << coffeeData[row][0] << setw(13) << coffeeData[row][1];
		cout << setw(15) << coffeeData[row][2] << endl;
	}
}


void rowOrColSum(int coffeeData[NUMROW][NUMCOL], bool row, int index)
{
	int sum = 0;
	if (row == true)
	{
		for (int colNum = 0; colNum < NUMCOL; colNum++)
			sum += coffeeData[index][colNum];
	}
	else
	{
		for (int rowNum = 0; rowNum < NUMROW; rowNum++)
			sum += coffeeData[numRow][index];
	}
}
		
		*/
int main()
{
	ifstream fin1("coffee1.txt");
	ifstream fin2("coffee2.txt");
	ifstream fin3("coffee3.txt");
	
	int coffeeData1[NUMROW][NUMCOL] = {0};
	int coffeeData2[NUMROW][NUMCOL] = {0};
	int coffeeData3[NUMROW][NUMCOL] = {0};
	double coffeeAvg[NUMROW][NUMCOL] = {0};
	
	
	fin.close();*/
	system("PAUSE");
	return EXIT_SUCCESS;
}
	
		
