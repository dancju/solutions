#include<iostream>
#include<cmath>
using namespace std;

struct circle {
	int x;
	double y;
};

circle data[1000];
int n, r;

int main() {
	scanf("%d%d", &n, &r);
	for(int i = 0; i<n; i++)
		scanf("%d", &data[i].x);
	for(int i = 0; i<n; i++) {
		double y;
		y = r;
		for(int j = 0; j<i; j++) {
			if(abs(data[i].x - data[j].x)<=r+r) {
				double _ = data[j].x-data[i].x;
				_ = sqrt(4*r*r-_*_)+data[j].y;
				y = max(y, _);
			}
		}
		if(i)
			putchar(' ');
		printf("%.8lf", y);
		data[i].y = y;
	}
	putchar('\n');
	return 0;
}
