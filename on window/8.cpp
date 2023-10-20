#include<iostream>

void generate_random_array(int arr[],int n, int m){
    
    for(int i = 0; i < n ; i++)
        arr[i] = rand() % m;
}
void choice_sort(int arr[], int n){
    for(int i = 0; i < n ; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[i], arr[j]);
            }
        }

    }
    for(int i = 0; i < n ; i++){
        std::cout << arr[i] << '\t'; 
    }
}
void insert_sort(int arr[], int n){
    for(int i = 1; i < n; i++){//sorted
        int t = arr[i];
        for(int j = i-1; j > 0; j--){// sorting
            if(t < arr[j]){
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }

    }
    for(int i = 0; i < n ; i++){
        std::cout << arr[i] << '\t'; 
    }
}
void counting_sort(int A[], int n){
    int counter[1000] = {0};
    for(int i = 0; i< n; i++){
        counter[A[i]] += 1;
    }
    int x = 0;
    for(int j = 0; j < 1000; j++){
        for(int i = 0; i < counter[j]; j++){
            A[x] = j;
            x++;
        }
    }
     for(int i = 0; i < n ; i++){
        std::cout << A[i] << '\t'; 
    }
}


int main()
{
    int n = 100;
    int arr[n];
    generate_random_array(arr, n, 1000);
    choice_sort(arr, n);
    std::cout<< '\n';
    insert_sort(arr, n);
    std::cout<< '\n';
    counting_sort(arr, n);
    //radix_sort(arr, n); 

    return 0;
}