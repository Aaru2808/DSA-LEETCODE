class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string token;
        string result="";
        int n= result.length();
        while(ss>>token){
            result=token+" "+result;
        }
        if(!result.empty() && result.back()==' '){
             result.pop_back();

        }
        return result;

      
    } 
    
};