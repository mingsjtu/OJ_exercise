#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <stdint.h>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

bool found;
unsigned _int64 res[201] = { 1,10,10000000000000000011,100,10,10000000000000000110,10000000000000000011,1000,10000000000011111111,10,10000000000000000001,10000000000000001100,1000000000000001,10000000000000001110,10000000000000000110,10000,10000000000000010101,10000000000111111110,10000000000000001111,100,10000000000000000011,1000000000000000010,10000000000000011111,10000000000000011000,100,10000000000000010,10000000000011111111,100000000000000100,1000000000000000111,10000000000000000110,10000000000000011111,100000,10000000000000011111,100000000000001010,10000000000000001110,10000000001111111100,10000000000000000101,10000000000000011010,10000000000000101,1000,10000000000000001111,100000000000001010,10000000000000011011,10000000000000000100,10000000000111111110,10000000000000101110,10000000000000000111,10000000000000110000,10000000000000011001,100,10000000000000101,100000000000000100,1000000000000000011,10000000001011111110,1000000000000000010,1000000000000001000,1000000000000011,10000000000000001110,10000000000000011,10000000000000001100,1000000000000011,10000000000001100110,10000000000011111111,1000000,10000000000000010,10000000000001011110,10000000000000010111,1000000000000010100,10000000000000011111,10000000000000001110,1000000000000100101,10000000011111111000,1000000000001,1000000000000000110,10000000000000001100,100000000000001100,1000000000000001,100000000000001010,10000000000001110011,10000,10000000000111111011,10000000000000101110,100000000000001101,1000000000000010100,100000000000001010,10000000000000101010,100000000000000101,1000000000000001000,1000000000000011011,10000000000111111110,1000000000000001,1000000000000011100,10000000000000011111,10000000000001010,10000000000000011010,10000000000001100000,10000000000001011111,10000000000000111010,10011111111111111111,100,1000000000000000001,100000000000001010,100000000000000001,1000000000000001000,100000000000001010,10000000000000000110,10000000000000110011,10000000011011111100,10000000000010000001,1000000000000000010,10000000000000000101,10000000000000010000,10000000000000001011,10000000000000110,10000000000000101110,10000000000000010100,10000000000111011111,100000000000000110,10000000000000101,10000000000000011000,10000000000000100101,10000000000000110,10000000001000110011,1000000000011100100,1000,10000000010111011110,1000000000000110101,10000000,10000000000001001,10000000000000010,10000000001000100001,10000000000001111100,1000000000001010001,1000000000000110,10000000001011111110,10000000000000101000,1000000000001,1000000000000110,10000000000000110001,100000000000000100,1000000000000101,10000000000001001010,1000000000000001,10000000111111110000,10000000000000001110,10000000000010,10000000000001010111,10000000000000001100,10000000000001111,10000000000000001100,10000000000010110011,1000000000000011000,10000000000110111111,10000000000000010,10000000000001100110,1000000000000010100,1000000000000101,1000000000001100010,1000000000000000011,100000,1000000000001101001,10000000001111111010,10000000000001101011,10000000000001101100,10000000000001011110,1000000000000011010,1000000000001001101,10000000000000101000,1000000000001100111,100000000000001010,10000000001001111111,1000000000000100100,1000000000000010111,1000000000000001010,100000000000000100,10000000000000010000,10000000000000011,10000000000000110110,1000000000000100111,10000000001111111100,10000000000000111,10000000000000010,1000000000000011,10000000000000111000,1000000000000000110,10000000000011110010,10000000000001000011,100000000000010100,10000000000011111111,10000000000000011010,10000000000011010011,10000000000011000000,10000000000010110001,1000000000011110,100000000000001010,10000000000001111100,100000000000111001,11011111111111111110,10000000000010100011,1000 };
int main()
{
	int n;
	while(cin>>n)
	{
		printf("%llu\n", res[n-1]);
	}
	return 0;
}
