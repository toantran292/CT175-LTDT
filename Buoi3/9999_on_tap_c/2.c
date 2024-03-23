#include <stdio.h>

int check(int n){
  if(n % 400 == 0) return 1;
  if(n % 4 == 0 && n % 100 != 0) return 1;
  return 0;
}

int main(){
  int n; scanf("%d", &n);
  if(check(n)){
    printf("NHUAN");
  } else {
    printf("THUONG");
  }
}
