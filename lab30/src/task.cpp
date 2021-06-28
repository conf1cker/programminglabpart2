

#include "task.h"

void ShowMap(const map<string, set<string>>& m3){
    std::for_each(m3.begin(), m3.end(), [&](const std::pair<string, set<string>>& pair){
        auto iter = pair.first;
        cout.width(20);
        cout << iter << ": ";
        cout.width(5);
        for(const auto &elem: pair.second){
            if (m3.rbegin()->first == pair.first && pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ".";
            } else if(pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ";";
            } else{
                cout << elem << ", ";
            }
        }
        cout << endl;
    });
}

void ExcellentTask()
{
    map<string, set<string>> m1, m2, m3;

    m1 = {
            { "Ukraine", { "Kharkiv", "Kiev" } },
            { "Russia", { "Moscow", "Belgorod" } },
            { "Belarus", { "Minsk", "Bobruysk" } },
    };
    m2 = {
            { "Poland", {  "Warsaw" } },
            { "Russia", { "St. Petersburg" } },
            { "Ukraine", { "Kharkiv", "Zaporizhya" } },
    };
    m3 = m1;

    std::for_each(m2.begin(), m2.end(), [&](const std::pair<string, set<string>>& pair){
        auto iter = m3.find(pair.first);
        if(iter == m3.end()){
            m3.insert(pair);
        } else{
            iter->second.insert(pair.second.begin(), pair.second.end());
        }
    });

    cout.width(12);
    cout << "Map 1:" << endl;
    ShowMap(m1);
    cout << endl;

    cout.width(12);
    cout << "Map 2:" << endl;
    ShowMap(m2);
    cout << endl;

    cout.width(12);
    cout << "Result map:" << endl;
    ShowMap(m3);
    cout << endl;

}