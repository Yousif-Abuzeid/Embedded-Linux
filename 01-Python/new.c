#include <stdio.h>


void print_even(int x){
    if(!(x&0x00000001)){
        printf("Even\n");
    }else{
        printf("ODD\n");
    }
}
struct employee{
    char firstName[20];
    char secondName[20];
    char x;
    int salary;
    char y;
    int age;
    
    char gender;
    
};
#define hello(x) (!((x)& (x-1)));
#define u8Temp (6)
void swap(int *var1, int *var2) {
  if (*var2 != *var1) {
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
  }
}

int main(void) {

   int arr[] = {10,20,30,40,50};
   int * ptr=arr;
   *(ptr++)+=123;
   printf("%d   %d",*ptr,*(ptr+1));

    return 0;
}
