#include <iostream>
#include <omp.h>


using namespace std;

int main(int argc, char** argv) {

    int n, i;
    double soma = 0.0, x, pi, deltax;
    

    cout << "Digite o numero de intervalos: ";
    cin >> n;

    deltax = 1.0/(n);

    #pragma omp parallel 
    {

        double x;
        double soma_local = 0;

        #pragma omp for
        for(int i = 0; i < n; i++)
        {
            x = (i + 0.5) * deltax;
            soma_local = soma_local + 4.0 / (1.0 + x * x);
        }
        
        #pragma omp critical
        {
            soma += soma_local;
        }

    }
    pi = deltax * soma;

    cout << "O valor de PI é " << pi << " "; 


    return 0;    
}
