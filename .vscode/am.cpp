#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

//0    1    1    2
//3    5    8    13
//21   34   55   89
//144  233  377  610
//Fibo[i][j]= a

int main()
{
	int a=0, c=1, i, j, Fibo[4][4];
	
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			Fibo[i][j]=a;
			cout<<" "<<Fibo[i][j]<<" ";
			c= a+c;
			a= c-a;
		}
		cout<<"\n";
	}
	
return 0;
}