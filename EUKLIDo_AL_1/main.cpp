#include <stdio.h>  
#include <string.h>  

void twinprime(int n);

int main()  
{  
    // declare an integer variable  
    int num;  
    printf (" Enter the last number to get twin prime numbers: ");  
    scanf (" %d", &num);      
    // call twinprime() function  
    twinprime( num); // pass num as an argument  
    return 0;  
}  
void twinprime (int n)  
{  
    int j;  
    /* here we create a unsigned char array 'prime[]' and initialize all its entries as true. */  
    unsigned char prime[n + 1]; // declaration of the unsigned char prime[] array     
    memset (prime, 1, sizeof(prime));     
    // use for loop to iterate over a certain range  
    for ( j = 2; (j * j) <= n; j++)  
    {  
        // if the condition of prime[j] remains true, it is a prime  
        if (prime [j] == 1)  
        {  
            int i = 0;  
            // update the multiples of j  
            for (i = (j * 2); i <= n; i += j)      
                prime[i] = 0;  
        }  
      }         
      // now check for twin prime numbers and print the twin primes     
      for ( j = 2; j <= (n - 2); j++)  
      {  
        if (prime[j] && prime[j + 2])  
            printf (" \n The twin prime numbers: (%d, %d) ", j, j +2);        
       }   
}   