#include<iostream>
#include<cassert>
#include<vector>
#include<array>

int find_path(int n_pos,int m_pos){
    assert(n_pos > 0 and m_pos > 0);
    if(n_pos == 1 || m_pos == 1)
        return 1;
    else{
        std::vector<std::vector<int>> coor;
        coor.resize(n_pos);
        for(int i = 0; i< n_pos; i++){
            coor[i].resize(m_pos);
        }
        for(int i  = 1; i < n_pos; i++){
            coor[i][0] = 1;
        }
        for(int j  = 1; j < m_pos; j++){
            coor[0][j] = 1;
        }        
        for(int i  = 1; i < n_pos; i++){
            for(int j = 1; j < m_pos; j++){
                coor[i][j] = coor[i-1][j] + coor[i][j-1];
            }
        }
        int result = coor[n_pos-1][m_pos-1];
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