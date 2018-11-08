#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

const int NUMCOL = 3;
const int NUMROW = 36;

void fileArray (ifstream &fin, int array[NUMROW][NUMCOL]){
	for (int row=0;row<NUMROW;row++){
		for (int col=0;col<3;col++){
			fin>>array[row][col];
			//cout << array[row][col]; 
		}
	}
}

dataAvg (int data1[NUMROW][NUMCOL], int data2[NUMROW][NUMCOL], int data3[NUMROW][NUMCOL], double avg[NUMROW][NUMCOL], double best[3])
{
	for (int d3Row=0; d3Row<NUMROW; d3Row++){
		for (int d2Row=0; d2Row<NUMROW; d2Row++){
			if (data3[d3Row][0]==data2[d2Row][0]&&data3[d3Row][1]==data2[d2Row][1]){
				for (int d1Row=0; d1Row<NUMROW; d1Row++){
					if (data2[d2Row][0]==data1[d1Row][0]&&data2[d2Row][1]==data1[d1Row][1]){
						avg[d3Row][0]=data3[d3Row][0];
						avg[d3Row][1]=data3[d3Row][1];
						avg[d3Row][2]=((double)data3[d3Row][2]+data2[d2Row][2]+data1[d1Row][2])/3;
						if (avg[d3Row][2]>best[2]){
							best[0]=avg[d3Row][0];
							best[1]=avg[d3Row][1];
							best[2]=avg[d3Row][2];
						}
					}
				}
			}
		}
	}
}
void outputData(double coffeeAvg[NUMROW][NUMCOL])
{
	cout << "Temperature" << setw(13) << "Coarseness" << setw(9) << "Score\n";
	for (int row = 0; row < NUMROW; row++)
	{
		cout << coffeeAvg[row][0] << setw(13) << coffeeAvg[row][1];
		cout << setw(15) << setprecision(1) << fixed << coffeeAvg[row][2] <<setprecision(0) <<endl;
	}
}


int rowOrColSum(double coffeeData[NUMROW][NUMCOL], bool row, int index, int 
&bestTemp)
{	
	double bestTempScore=0;
	double tempScore[9]={0};
	int sum = 0;
	if (!row)
	{
		for (int colNum = 0; colNum < NUMCOL; colNum++)
			sum += coffeeData[index][colNum];
	}
	else
	{
		for (int rowNum = 0; rowNum < NUMROW; rowNum++){  //sum each column
			sum += coffeeData[rowNum][index];
			for (int temp=91;temp<100;temp++){ //find average score for each temp
				if (temp==coffeeData[rowNum][0]){
					tempScore[temp-91]+=coffeeData[rowNum][2];
				}
			}
		}
		for (int temp=0;temp<9;temp++){
			if (tempScore[temp]>bestTempScore){
				bestTemp=temp+91;
			}
		}
		
	}
	return sum;
}
		
		
int main()
{
	ifstream fin1("coffee1.txt");
	ifstream fin2("coffee2.txt");
	ifstream fin3("coffee3.txt");
	int bestTemp=0;
	int coffeeData1[NUMROW][NUMCOL] = {0};
	int coffeeData2[NUMROW][NUMCOL] = {0};
	int coffeeData3[NUMROW][NUMCOL] = {0};
	double coffeeAvg[NUMROW][NUMCOL] = {0};
	double bestCombo[3]={0};
	fileArray(fin1,coffeeData1);
	fileArray(fin2,coffeeData2);
	fileArray(fin3,coffeeData3);
	dataAvg(coffeeData1,coffeeData2,coffeeData3,coffeeAvg,bestCombo);
	outputData(coffeeAvg);
	int sumRow1=rowOrColSum(coffeeAvg,true,1,bestTemp);
	cout << "Best coffee combination is " << bestCombo[0] << " degrees at ";
	cout << "coarseness "<<bestCombo[1] <<" with a score of "<< bestCombo[2];
	cout << endl;
	cout << "Best temperature overall is " << bestTemp << endl;
	fin1.close();
	fin2.close();
	fin3.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}
