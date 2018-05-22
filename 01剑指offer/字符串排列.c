void PermutationHelp(vector<string> &ans, int k, string str) //遍历第k位的所有可能
{
    if(k == str.size() - 1)
        ans.push_back(str);
    unordered_set<char> us;  //记录出现过的字符
    sort(str.begin() + k, str.end());  //保证按字典序输出
    for(int i = k; i < str.size(); i++)
    {
        if(us.find(str[i]) == us.end()) //只和没交换过的换
        {  
            us.insert(str[i]);
            swap(str[i], str[k]);
            PermutationHelp(ans, k + 1, str);
            swap(str[i], str[k]);  //复位
        }
    }
}
 
vector<string> Permutation(string str) {
    vector<string> ans;
    PermutationHelp(ans, 0, str);
    return ans;
}
