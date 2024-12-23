#include <bits/stdc++.h>
#include <cmath>

int main() {
    const int barrels = 240; 
    const int slaves = 5;    

    int poisonedBarrel;
    std::cout << "Введите номер отравленной бочки (1-240): ";
    std::cin >> poisonedBarrel;

    if (poisonedBarrel < 1 || poisonedBarrel > barrels) {
        std::cout << "Некорректный номер бочки!" << std::endl;
        return 1;
    }

 
    std::vector<int> deadSlaves(slaves, 0);

    
    for (int i = 0; i < slaves; ++i) {
        if (poisonedBarrel & (1 << i)) { 
            deadSlaves[i] = 1; 
        }
    }

 
    std::cout << "Через 24 часа умерли рабы: ";
    for (int i = 0; i < slaves; ++i) {
        if (deadSlaves[i]) {
            std::cout << (i + 1) << " "; 
        }
    }
    std::cout << std::endl;

  
    int identifiedBarrel = 0;
    for (int i = 0; i < slaves; ++i) {
        if (deadSlaves[i]) {
            identifiedBarrel |= (1 << i); 
        }
    }

    std::cout << "Определено, что отравленная бочка: " << identifiedBarrel << std::endl;

    return 0;
}