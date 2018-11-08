//Kaelan Moffett-Steinke
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
class Fraction{
	private:
		int numerator;
		int denominator;
		
	public:
		Fraction(){ //default constructor
			numerator=0;
			denominator=1;
		}
		
		Fraction(int num, int den){ //data constr
			numerator=num;
			denominator=den;
		}
		
		int getNum()const{
			return numerator;
		}
		
		int getDen()const{
			return denominator;
		}
		
		void setNum(int num){
			numerator=num;
		}
		
		void setDen(int den){
			if (den)
				denominator=den;
			else
				cout << "Cannot divide by zero";
		}
		
		double approx(int precision){
			return ((double)round(((double)numerator/denominator)*pow(10,precision)))/pow(10,precision);
		}			
		
		bool isExactlySame(Fraction const & other)const{
			return (numerator==other.getNum() && denominator==other.getDen());
		}
};
int main()
{
	Fraction frac1(1,3), frac2;
	cout << "1/3 approximated to 4 digits is " << frac1.approx(4) << endl;
	cout << "The default fraction is " << frac2.getNum()<<"/"<<frac2.getDen()<<endl;
	frac2.setNum(1);
	frac2.setDen(3);
	if (frac1.isExactlySame(frac2)){
		cout << frac1.getNum()<<"/"<<frac1.getDen()<<" = ";
		cout << frac2.getNum()<<"/"<<frac2.getDen();
	}
}
