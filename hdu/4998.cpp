#include<complex>
#include<cstdio>

const  double PI = acos(-1.L);
using namespace std;

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    complex<double> a = 1, b = 0;
    int n;
    scanf("%d", &n);
    while(n--) {
      double x, y, p;
      scanf("%lf%lf%lf", &x, &y, &p);
      b -= complex<double>(x, y);
      a *= complex<double>(cos(p), sin(p));
      b *= complex<double>(cos(p), sin(p));
      b += complex<double>(x, y);
    }
    double A = a.real(), B = a.imag(), C = b.real(), D = b.imag();
    double x = ((1-A)*C-B*D)/((1-A)*(1-A)+B*B);
    double y = ((1-A)*D+B*C)/((1-A)*(1-A)+B*B);
    double p = acos(A);
    if(fabs(sin(p)-B)>1e-7)
      p = PI+PI-p;
    printf("%.10lf %.10lf %.10lf\n", x, y, p);
  }
  return 0;
}