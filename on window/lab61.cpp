
    unsigned int count_total_mice_amount(Cat* cats, unsigned int n){
        unsigned int result = 0;
        for (int i = 0; i < n; i++) {
            result += (cats+i) -> mice_caught;
            
        }
        return result;
    };

