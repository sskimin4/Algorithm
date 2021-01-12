class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> v;
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            v.push_back({intervals[i][0], intervals[i][1]});
        }
        int st, ed;
        sort(v.begin(), v.end());
        st = v[0].first;
        ed = v[0].second;
        for (int i = 1; i < v.size(); i++)
        {
            int s = v[i].first;
            int e = v[i].second;
            if (ed >= s)
            {
                if (ed < e)
                {
                    ed = e;
                }
            }
            else
            {
                vector<int> tmp;
                tmp.push_back(st);
                tmp.push_back(ed);
                ans.push_back(tmp);
                st = s;
                ed = e;
            }
        }
        vector<int> tmp;
        tmp.push_back(st);
        tmp.push_back(ed);
        ans.push_back(tmp);

        return ans;
    }
};