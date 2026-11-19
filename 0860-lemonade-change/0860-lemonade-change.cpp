class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        if(bills.size() == 1 && bills[0] != 5){
            return false;
        }

        int fiveCount = 0;
        int tenCount = 0;

        for(int i = 0; i < bills.size(); i++){
            
            if(bills[i] == 5){
                fiveCount++;
            }else if(bills[i] == 10){
                if(fiveCount > 0){
                    fiveCount--;
                    tenCount++;
                }else {
                    return false;
                }
            }else if(bills[i] == 20){

                if(fiveCount > 0 && tenCount > 0){
                    fiveCount--;
                    tenCount--;
                }else {
                    if(fiveCount >= 3){
                        fiveCount -= 3;
                    }else {
                        return false;
                    }
                }
            }
        }
        return true;

    }   
};