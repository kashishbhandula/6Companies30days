class Solution
{
public:
    bool check(string str, int k)
    {
        // cout<<str<<" "<<k<<endl;
        int n = str.length();
        for (int i = k; i < n; i++)
        {
            // cout<<str[i]<<" "<<str[(i%k)]<<endl;
            if (str[i] != str[(i % k)])
                return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        string temp = "";
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (str1[i] != str2[j])
            {
                return "";
            }
            i++;
            j++;
        }
        if (n >= m)
        {
            temp = str1;
        }
        else
        {
            temp = str2;
        }

        int len = -1;
        string ans = "";

        int val = min(n, m);
        int mx = max(n, m);
        // cout<<temp<<" "<<val<<endl;
        // cout<<n<<" "<<m<<endl;
        for (int i = 1; i <= ceil(sqrt(val * 1.0)); i++)
        {
            // cout<<i<<endl;
            if (n % i == 0 && m % i == 0)
            {
                if (check(temp, i))
                {
                    if (len < i)
                    {
                        ans = temp.substr(0, i);
                        len = i;
                    }
                }
            }
            if (val % i == 0)
            {
                int num = val / i;
                // cout<<num<<endl;
                if (n % num == 0 && m % num == 0)
                {

                    if (check(temp, val / i))
                    {
                        if (len < num)
                        {
                            ans = temp.substr(0, val / i);
                            len = val / i;
                        }
                    }
                }
            }
        }
        return ans;
    }
};