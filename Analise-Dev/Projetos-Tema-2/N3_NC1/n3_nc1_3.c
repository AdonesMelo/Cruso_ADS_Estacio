#include <stdio.h>
 
int main() {
    double numero_preciso = 3.141592653589793;
    double numero_mto_preciso = 3.14159265358979323846;
 
    printf("Número preciso (double): %.15f\n", numero_preciso);
    printf("Número muito preciso (long double): %.21f\n", numero_mto_preciso);
 
    return 0;
}