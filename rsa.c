#include<stdio.h> 
#include<math.h> 
// Returns gcd of a and b 
int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
int modInverse(int c, int b)
{
    for (int x = 1; x < b; x++)
        if (((c%b) * (x%b)) % b == 1)
            return x;
}
  
// Code to demonstrate RSA algorithm 
int main() 
{ 
    // Two random prime numbers 
    double p = 7; 
    double q = 11; 
  
    // First part of public key: 
    double n = p*q; 
  
    // Finding other part of public key. 
    // e stands for encrypt 
    double e = 13; 
    double phi = (p-1)*(q-1);
    printf("phi = %lf",phi);
    while (e < phi) 
    { 
        // e must be co-prime to phi and 
        // smaller than phi. 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    } 
  
    // Private key (d stands for decrypt) 
    // choosing d such that it satisfies 
    // d*e = 1 + k * totient 
   // int k = 2;  // A constant value 
   // double d = (1 + (k*phi))/e;
  // double d = fmod(pow(e,-1),phi);
   // printf("%lf",d);
   double d;
   d = modInverse(13,phi);
   printf("\n d = %lf",d);
    // Message to be encrypted 
    double msg = 5; 
    printf("\n Message data = %lf", msg); 
    // Encryption c = (msg ^ e) % n 
    double c = pow(msg, e); 
    c = fmod(c, n); 
    printf("\n Encrypted data = %lf", c); 
    // Decryption m = (c ^ d) % n 
    printf("\n c = %lf",c);
    printf("\n d = %lf",d);
    printf("\n n = %lf",n);
    double m = pow(c, d); 
    printf("\n m = %lf",m);
    double a;
    a = fmod(m, n);
    printf("\n Original Message Sent = %lf", a); 
    return 0; 
}