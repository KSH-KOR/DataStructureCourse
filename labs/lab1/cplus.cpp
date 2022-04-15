#if 0
    #include <stdio.h>
    #define N 40

    void sum(int d[], int n, int* p) {
        *p = 0;
        for(int i = 0; i < n; ++i) 
            *p = *p + d[i];
    } 

    int main(int argc, char *argv[]) {
        int total = 0;
        int data[N];

        for(int i = 0; i < N; ++i) 
            data[i] = i;
        
        sum(data, N, &total);  // total - pass-by-pointer
        printf("Total is %d\n", total);
        return 0;
    }
#else 
    
#include <iostream>

void sum(int arr[], const int N, int& total){
  for(int i=0;i<N;i++) total+=arr[i];
}

int main(int argc, char *argv[]) {
  const int N = 40;
  int *data = new(std::nothrow) int[N];;
  if(!data) throw std::invalid_argument( "Memory allocation failed\n" );
  int total=0;

  for(int i=0;i<N;i++) data[i] = i;
  sum(data, N, total);

  delete[] data;

  std::cout << "Total is " << total << std::endl;

  return 0;
}


#endif