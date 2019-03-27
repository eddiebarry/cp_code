#include <iostream>
#include <string>

int main() {
    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i) {
        int x;
        std::cin >> x;
        int constant = 0;
        bool a_1 = false;
        bool a_2 = false;
        bool a_3 = false;
        bool a_4 = false;
        bool a_5 = false;
        bool a_6 = false;
        bool a_7 = false;
        bool a_8 = false;
        bool a_9 = false;
        while(true){
            std::cout<<2<<" "<<2+constant<<std::endl;
            int a_i,a_j;
            std::cin>>a_i>>a_j;
            if(a_i==2&&a_j==2+constant){
                a_5=true;
            }
            if(a_i==2&&a_j==2+constant+1){
                a_6=true;
            }
            if(a_i==2&&a_j==2+constant-1){
                a_4=true;
            }
            
            ///////////////
            if(a_i==3&&a_j==2+constant){
                a_2=true;
            }
            if(a_i==3&&a_j==2+constant+1){
                a_3=true;
            }
            if(a_i==3&&a_j==2+constant-1){
                a_1=true;
            }
            
            //
            if(a_i==1&&a_j==2+constant){
                a_8=true;
            }
            if(a_i==1&&a_j==2+constant+1){
                a_9=true;
            }
            if(a_i==1&&a_j==2+constant-1){
                a_7=true;
            }
            if(a_1&&a_2&&a_3&&a_4&&a_5&&a_6&&a_7&&a_8&&a_9){
                constant+=3;
                a_1 = false;
                a_2 = false;
                a_3 = false;
                a_4 = false;
                a_5 = false;
                a_6 = false;
                a_7 = false;
                a_8 = false;
                a_9 = false;
            }
            
            if(a_i==0&&a_j==0){
                break;
            }
            
        }
    }
    return 0;
}
