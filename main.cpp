#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    int N, M; //N人参加面试，M张船票
    if(argc==3){
        N = stoi(argv[1]);
        M = stoi(argv[2]);
    }else {
        cout << "请输入面试人数:" << endl;
        cin >> N;
        cout << "请输入船票数量:" << endl;
        cin >> M;
    }
    cout<<"现在进行随机分发船票..."<<endl;
    cout<<"面试人数一共"<<N<<"人, "<<"船票数量一共"<<M<<"张."<<endl;
    vector<int> arr = {};
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution<int> distr(1, N);

    cout<<"distr.min="<<distr.min()<<"; distr.max="<<distr.max()<<endl;

    for(int i=0;i<M;i++) {
        while(true) {
            int tmp = distr(eng);
            bool not_repeat = true;
            for (int j = 0; j < arr.size(); j++) {
                if (tmp == arr[j]) {
                    not_repeat = false;
                    break;
                }
            }
            if (not_repeat) {
                arr.push_back(tmp);
                break;
            }
        }
    }
    cout<<"恭喜以下编号的面试者获得船票: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}