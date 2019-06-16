#include <bits/stdc++.h>

using namespace std;


struct Location{
    string name;
    vector<pair<string, double> > dists;
};

struct Driver{
    string name, phone;
    double fare;
    double totalDriven;
    string carType;
    string carNumber;
    int maxPass;
    int curLocation;
    int fineCount;
    double fineSum;
    double rating;


};

Location locations[500];
Driver drivers[500];

vector<pair<int, int> > G[500];

map<string, int> nodeToLocation;

void genGraph(int n){
    srand(8979);

    for(int i = 1; i <= n; i++){
        string s = "";
        for(int j = 0; j < 4; j++){
            s += rand()%26 + 97;
        }
        cerr<<s<<endl;
        nodeToLocation[s] = i;
        locations[i].name = s;
    }


    G[1].push_back(make_pair(2, 10));
    G[2].push_back(make_pair(1, 10));

    set<pair<int, int> > edgeSet;


    for(int i = 3; i <= n; i++){
        int tmp1 = rand()%(n-1) + 1;
        int cost = rand()%30 + 1;
        G[i].push_back(make_pair(tmp1, cost));
        G[tmp1].push_back(make_pair(i, cost));
        edgeSet.insert(make_pair(tmp1, i));

    }


    for(int i=1; i <= n * 2; i++){
        int u = rand()%n + 1, v = rand()%n + 1;
        if (u > v){
            swap(u, v);
        }
        if (u == v || edgeSet.count(make_pair(u, v))){
            i--;
            continue;
        }
        edgeSet.insert(make_pair(u, v));
        int cost = rand()%30 + 1;
        G[u].push_back(make_pair(v, cost));
        G[v].push_back(make_pair(u, cost));

    }

    for(int i = 1; i <= n; i++){
        cerr<<i<<": ";
        for(int j=0; j < G[i].size(); j++){
            cerr<<G[i][j].first<<","<<G[i][j].second<<" ";
        }
        cerr<<endl;
    }

}




void genDrivers(int n){
    srand(9999);
    for(int i = 1; i <= n; i++){
        string s = "";
        for(int j = 0; j < 10; j++){
            s += rand()%26 + 97;
        }
        //cerr<<s<<endl;
        drivers[i].name = s;


        s = "";
        for(int j = 0; j < 4; j++){
            s += rand()%10 + '0';
        }

        drivers[i].phone = s;

        drivers[i].fare = rand();

        drivers[i].totalDriven = rand();

        if (i%2){
            drivers[i].carType = "Sedan";
            drivers[i].maxPass = 4;

        }
        else {
            drivers[i].carType = "SUV";
            drivers[i].maxPass = 6;
        }

        s = "";
        for(int j = 0; j < 6; j++){
            s += rand()%10 + '0';
        }

        drivers[i].carNumber = s;



    }



}





int main(){
    genGraph(100);






}
