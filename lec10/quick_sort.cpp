#include<iostream>

void print_array(double* Array, int n){
    for (int i = 0; i < n; i++ ){
        std:: cout << Array[i] <<' ';
    }
    std::cout<<'\n';
}

/* merged sort*/
void merge_sort(double* Array, int arrya_size){
    if(arrya_size <= 1) return;
    /*if(arrya_size == 2){
        if(*(Array) > !(Array+1)){
            int t = *(Array);
            *(Array) = *(Array+1);
            *(Array+1) = t;
        }
    }else */
    if(arrya_size >= 2){
        int middle = arrya_size / 2;
        merge_sort(Array, middle);
        merge_sort(Array + middle, arrya_size - middle); 
        double* tem_arr = new double[arrya_size];

        for(int i = 0; i < arrya_size; i++){
            tem_arr[i] = Array[i];
        }
        int i = 0;
        int j = middle;
        int k = 0;
        while(k < arrya_size){
            if(i >= middle){
                Array[k++] = tem_arr[j++]; 
            }else if(j >= arrya_size){
                Array[k++] = tem_arr[i++]; 
            }else if(tem_arr[i] <= tem_arr[j]){
                Array[k++] = tem_arr[i++];  
            }else Array[k++] = tem_arr[j++]; 
        }
        delete []tem_arr;
    }
}
void quick_sort2(double* Array, int arrya_size){
    if(arrya_size <= 1)
        return;
    else{
        int left_length = 0;
        int right_length = 0;
        double key = Array[0];

        for(int i = 1; i< arrya_size - right_length; i++){
            if(Array[i] < key){
            std::swap(Array[i], Array[left_length]);
            left_length +=1;
            }else if(Array[i] > key){
                right_length +=1;
                std::swap(Array[i], Array[arrya_size - right_length]);
                i -= 1;
            }
        }
        for(int i = left_length; i < arrya_size - right_length;i++){
            Array[i] = key;
        }
        quick_sort2(Array, left_length);
        quick_sort2(Array + arrya_size - right_length, right_length);
    }    
}


void fill_up_array(double* Array, int n){
    for (int i = 0; i < n; i++ ){
        Array[i] = rand()% 20+1;
    }
}

int main()
{
    int n;
    std::cin >> n;
    double* Array = new double[n];
    fill_up_array(Array, n);
    print_array(Array,n);
    //std::cout<< "quick sort 1 is:"<< '\n';
    //quick_sort1(Array,n);
    std::cout<< "quick sort 12 is:"<< '\n';
    quick_sort2(Array,n);
    print_array(Array,n);

    delete[] Array;
    std::cout<< '\n';

    return 0;
}