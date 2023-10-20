
int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    int *a = new int[n_new];
    if(source != nullptr){
        if (n_new > n_old){
            for(unsigned int i = 0; i < n_old; i++){
                *(a+i) = *(source + i); 
            }  
            
        } else {
            for(unsigned int i = 0; i < n_new; i++){
                *(a+i) = *(source + i); 
            }
        }
        
        delete[] source;
    } else delete(source);
    return a;
}