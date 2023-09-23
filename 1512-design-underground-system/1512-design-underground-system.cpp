class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> in;
    map<pair<string,string>,vector<int>> time;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int intime = in[id].second;
        string instation = in[id].first;
        time[{instation,stationName}].push_back(t-intime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto a = time[{startStation,endStation}];
        int sum = 0;
        int n = a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return double(sum)/double(n);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */