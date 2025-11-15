#include "raiz.h"

double raiz(double n) {
    if (n < 0) return -1; 
    if (n == 0 || n == 1) return n;
    
    double precisao = 0.0001;
    double r = 0;
    double a = n;
    
    while ((a - r) > precisao) {
        double m = (r + a) / 2;
        if (m * m <= n) {
            r = m;
        } else {
            a = m;
        }
    }
    return r;
}
