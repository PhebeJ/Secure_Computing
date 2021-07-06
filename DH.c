#include<stdio.h>
#include<math.h>
int power(int x, int y, int p) 
{ 
    int res = 1;    
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0) 
    { 
         
        if (y % 2 == 1) 
            res = (res*x) % p; 
 
        
         y = y/2; 
        x = (x*x) % p; 
    } 
    return res; 
} 
 
// C program to demonstrate Diffie-Hellman algorithm
int main()
{
    int p = 23;        
    int g = 5;        
 
    int pvtA, pvtB;    
    int pubA, pubB;    
    pvtA = rand();
    pubA = power(g, pvtA, p);
 
    
    pvtB = rand();
    pubB = power(g, pvtB, p);
 
    
    int keyA = power(pubB, pvtA, p);
    int keyB = power(pubA, pvtB, p);
 
    printf("Alice's Secret Key is %d\nBob's Secret Key is %d", keyA, keyB);
 
    return 0;
}
