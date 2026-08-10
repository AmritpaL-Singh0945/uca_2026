#include <stdio.h>

int check(int n, int* population, int k, double max_load) {
    int required_clinics = 0;
    for (int i = 0; i < n; i++) {
        int clinics = population[i] / max_load;
        
        if (clinics * max_load < population[i]) {
            clinics = clinics + 1;
        }
        
        if (clinics == 0) {
            clinics = 1;
        }
        
        required_clinics = required_clinics + clinics;
    }
    
    if (required_clinics <= k) {
        return 1;
    } else {
        return 0;
    }
}

double getMinMaxLoad(int n, int* population, int k) {
    double low = 0.0;
    double high = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (population[i] > high) {
            high = population[i];
        }
    }
    
    for (int i = 0; i < 100; i++) {
        double mid = low + (high - low) / 2.0;
        if (check(n, population, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    return high;
}

int main() {
    int n = 3;
    int population[] = {200, 20, 50};
    int k = 5;
    
    double result = getMinMaxLoad(n, population, k);
    printf("%.2f\n", result);
    
    return 0;
}