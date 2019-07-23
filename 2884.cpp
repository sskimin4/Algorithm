#include<iostream>
#include<cstdio>
using namespace std;
void calculate_time(int hour, int min) {
	if (min - 45 >= 0) {
		printf("%d %d\n", hour, min - 45);
	}
	else {
		if (hour == 0)
			hour = 24;
		printf("%d %d\n", hour-1, min + 15);
	}
}
int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);
	calculate_time(hour, min);
}