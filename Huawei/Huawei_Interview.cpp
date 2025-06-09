#include<bits/stdc++.h>
using namespace std;


using Cell = variant<int,string>;

using Row = vector<Cell>;

using Table= vector <Row>;

struct SortCriteria{
    int colIND;
    bool ascending;
};

bool CustomComp( Row row1,Row &row2, vector<SortCriteria> &criteria){
    for(auto & criIT:criteria){
        Cell &cell1=row1[criIT.colIND];
        Cell &cell2=row2[criIT.colIND];

        if (cell1!=cell2){
            if(criIT.ascending){ 
                return cell1<cell2;
            }else return cell1 > cell2;
        }
    }
    return false;
}



void sortTable(Table &table,vector<SortCriteria>&criteria){
    sort(table.begin(),table.end(),[&](Row &row1,Row &row2){
        return CustomComp(row1,row2,criteria);
    });
}

void PrintTable(Table& table){
    for(auto& row :table ){
        for(auto & cell : row){
            cout<<get<string>(cell)<<" ";
        }
        cout <<endl;
    }
}

void costumop(int x; string s){
    int i;cin >>i;
    
}

int main(){
    Table table={{"42","apple","15"},{"15","banana","12"}};
    vector<SortCriteria> cri={{0,true},{1,false}};

    cout <<"Origin Table"<<endl;
    PrintTable(table);

    sortTable(table,cri);

    PrintTable(table);
    return 0;
}