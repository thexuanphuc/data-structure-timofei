#include<iostream>
#include<cassert>
#include<vector>

int find_path(int n_pos,int m_pos){
    assert(n_pos > 0 and m_pos > 0);
    if(n_pos == 1 || m_pos == 1)
        return 1;
    else{
        int* coor = new int[n_pos*m_pos];
        for(int i = 0; i< n_pos; i++){
            coor[i*m_pos + 0] = find_path(i+1,1);
        }
        for(int j = 0; j< m_pos; j++){
            coor[0*n_pos + j] = find_path(1,j+1);
        }
        /*int i = 1;
        int j = 1;
        while(i < n_pos && j < m_pos){
            coor[ i*m_pos + j] = coor[(i-1)*m_pos + j] + coor[i*m_pos + j-1];
            i++;
            j++;
        }*/
        std::vector<std::vector<int>> A;
        A.size();   



        for(int i  = 1; i < n_pos; i++){
            for(int j = 1; j < m_pos; j++){
                coor[ i*m_pos + j] = coor[(i-1)*m_pos + j] + coor[i*m_pos + j-1];
            }
        }
        int result = coor[(n_pos -1)* m_pos + m_pos - 1];
        delete [] coor;
        return result;
    }
}
 
int main()
{
    std::cout<<"which position u want to proceed: ";
    int i_pos, j_pos;
    std::cin>>i_pos>>j_pos;

    std::cout<< "there are "<<find_path(i_pos,j_pos)<< "to go to "<< i_pos << ", " << j_pos <<'\n';


    return 0;
}