#include <stdio.h>
int GV = 100;// Global variable
void Local() {
    auto int LV = 5;//local Varible
    printf("Value of local Varible is: %d\n", LV);
}

void Static() {
    static int SV = 10;//Static Varible
    SV++;
    printf("Value of Static Varible is : %d\n", SV);
}

void Register() {
    register int RV = 15;//Redister Varible 
    printf("Value of Register Varible is : %d\n",RV);
}

int main() {
    printf("Global Variable is : %d\n",GV);
    
    Local();
    Static();
    Register();
    
    return 0;
}

