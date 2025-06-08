#include "../utils/common.hpp"
string longestCommonPrefix(vector<string> &strs)
{
    int n=strs.size();
    if(n==1)
        return strs[0];
    string res=strs[0];
    for (int i = 1; i < n;i++){
        int j = 0;
        while(res[j]==strs[i][j]){
            j++;
        }
        if(j<res.size())
            res=res.substr(0, j);
    }
    return res;
}
