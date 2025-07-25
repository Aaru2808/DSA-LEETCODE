class Solution {
public:
    string reverseWords(string s) {
        //1.reverse the whole string
        reverse(s.begin(),s.end());
        int i=0;
        int l =0,r=0;

        //2.i,l,r le lege uske baad ham i ko agee badhate jayege jab tk space nhi aa jata hai or r ko assign krte jayege
        int n=s.size();
        while(i<n){
            while(i<n&& s[i]!=' '){
                s[r++]=s[i++];

            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;

            }
            i++;
        }
        //3.jab space aa jayega tb hm l ot r tk phir se resver kr dege particular word
        //4.last me ham substr ke help se space ko hta dege jo ki last me hoga
        s= s.substr(0,r-1);
        return s;


        
    }
};