#include <iostream>
#include <string>
#include <vector>
int main() {
    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i) {
        int n;
        std::cin >> n;
        std::vector<int>num_req(n);
        for (int i = 0; i < n; ++i){
            int d;
            std::cin >> d;
            int arr[d];
            for (int i = 0; i < d; ++i){
                int x;
                std::cin>>x;
                arr[i] = x;
                num_req[x]++;
            }
            if(d==0){
                std::cout<<-1<<std::endl;
            }
            else{
                int ans = 0;
                float min = 2.0;
                for (int j = 0; j < d; ++j){
                    float temp = num_req[arr[j]];
                    temp /= (i+1);
                    if(temp <= min){
                        min = temp;
                        ans = arr[j];
                    }
                }
                if(ans==0){
                    std::cout<<-1<<std::endl;
                }
                else{
                    std::cout<<ans<<std::endl;
                    num_req[ans] = 20000;
                }
            }
        }

    }
    return 0;
}
//while (true) {
//    int m = (head + tail) / 2;
//    std::cout << m << std::endl;
//    std::string s;
//    std::cin >> s;
//    if (s == "CORRECT") break;
//    if (s == "TOO_SMALL")
//    head = m + 1;
//    else
//    tail = m - 1;
//    }

