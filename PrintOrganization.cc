#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>

using namespace std;

vector<string> file = { "Alice,,5",
"Bob,Alice,3",
"Carol,Bob,2",
"David,Bob,3",
"Eve,Alice,2",
"Ferris,Eve,1"};

class Organization {
    struct Employee {
        vector<Employee*> subs;
        string name;
        int itemSold;
        int itemSoldSum;
        Employee(string n): name(n) {itemSoldSum = itemSold = 0;};
    };
    Employee* ceo;
public:
    int calculateSoldSum(Employee* em) {
        em->itemSoldSum = em->itemSold;
        for(Employee* sub : em->subs) {
            em->itemSoldSum += calculateSoldSum(sub);
        }
        return em->itemSoldSum;
    }
    
    void build() {
        unordered_map<string, Employee*> nameMap;
        for(int ind = 0; ind < file.size(); ind++) {
            string info = file[ind];
            int start = 0;
            int end = 0;
            while(info[end] != ',') end++;
            string subName = info.substr(start, end-start);
            start = end = end+1;
            while(info[end] != ',') end++;
            string bossName = info.substr(start, end-start);
            int itemSold = stoi(info.substr(end+1));
            
            //build
            if(nameMap.find(subName) == nameMap.end()) 
                nameMap[subName] = new Employee(subName);
            nameMap[subName]->itemSold = itemSold;
            if(bossName == "") {
                this->ceo = nameMap[subName];
            } else {
                if(nameMap.find(bossName) == nameMap.end())
                    nameMap[bossName] = new Employee(bossName);
                nameMap[bossName]->subs.push_back(nameMap[subName]);
            }
        }
        if(this->ceo) {
            calculateSoldSum(ceo);
        }
    }
    
    void print() {
        printEmployee(ceo, 0);
    }
    
    void printEmployee(Employee* em, int level) {
        cout <<string(level,' ') << em->name <<" " <<em->itemSoldSum<<endl;
        for(Employee* sub: em->subs) {
            printEmployee(sub, level+2);
        }
    }
};


int main() {
    Organization org;
    org.build();
    org.print();
    return 0;
}
