#include <stdio.h>
#define CRT_SECURE_NO_WARNINNGS
int checkEvenParity(short res);
int pack4Chars2Int(char c1, char c2, char c3, char c4);
void main() {
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = 'd';
	int res = pack4Chars2Int(c1, c2, c3, c4);
	unsigned char tmp = 0;
	tmp |= res;
	printf("%d\n", tmp);
	res >>= 8;
	tmp = 0;
	tmp |= res;
	printf("%d\n", tmp);
	res >>= 8;
	tmp = 0;
	tmp |= res;
	printf("%d\n", tmp);
	res >>= 8;
	tmp = 0;
	tmp |= res;
	printf("%d\n", tmp);
	
	
	printf("The value retunred from 15 is :%d\n", checkEvenParity(15));
	printf("The value retunred from 15 is :%d\n", checkEvenParity(8));

}
//1.
int pack4Chars2Int(char c1, char c2, char c3, char c4) {
	unsigned int mask = 0;
	char arr[4] = { c1,c2,c3,c4 };
	mask |= arr[0];
	for (int i = 1; i < 4; i++) {
		mask <<= 8;
		mask |= arr[i];
	}
	return mask;
}

//2.
int checkEvenParity(short res) {
	short mask = 1;
	int cnt = 0;
	for (int i = 0; i < 16; i++) {
		(res & mask) ? ++cnt : 0;
		mask <<= 1;
	}
	if (cnt % 2 == 0) {
		return 1;
	}
	else return 0;
}