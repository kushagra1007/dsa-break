class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
        return false;

        int l = s.length();

        for(int r=0 ; r<l ; ++r){
            rotate(s.begin() , s.begin() + 1 , s.end());
            if( s == goal)
            return true;
        }
        return false;
    }
};