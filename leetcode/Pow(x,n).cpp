Solution 1:class Solution {public:    double pow(double x, int n) {        unsigned m = abs((double)n);        double ret = 1;        for ( ; m; x *= x, m >>= 1) {            if (m & 1) {                ret *= x;            }        }        return (n < 0) ? (1.0 / ret) : (ret);    }};Solution 2:double pow(double x, int n) {    if (n == 0) return 1.0;    // Compute x^{n/2} and store the result into a temporary    // variable to avoid unnecessary computing    double half = pow(x, n / 2);    if (n % 2 == 0)        return half * half;    else if (n > 0)        return half * half * x;    else        return half * half / x; nΪ����}