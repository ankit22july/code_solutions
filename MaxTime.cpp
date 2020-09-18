#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int getMaxDigitInRange(unordered_map <int, int> & hash_table, int range)
    {
        int i;
        
        for(i = range; i >= 0; i--)
        {
            if(hash_table.find(i) != hash_table.end() && hash_table[i] != 0)
            {
                hash_table[i] -= 1;
                break;
            }
        }
        
        return i;
    }
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string result;
        int time[4];
        int i;
        unordered_map <int, int> hash_table;
        
        //creating hash table
        for(int & i : arr)
        {
            if(hash_table.find(i) != hash_table.end())
            {
                hash_table[i] += 1;
            }
            else
            {
                hash_table[i] = 1;
            }
        }
        
        //identifying first digit 
        i = getMaxDigitInRange(hash_table, 2);
        if(i == -1)
            return result;
        else
            time[0] = i;
        
        //identifying second digit 
        if(time[0] == 2)
        {
            i = getMaxDigitInRange(hash_table, 3);
        }
        else
        {
            i = getMaxDigitInRange(hash_table, 9);
        }
        
        if(i == -1)
            return result;
        else
            time[1] = i;
        
        //identifying third digit
        i = getMaxDigitInRange(hash_table, 5);
        if(i == -1)
            return result;
        else
            time[2] = i;
        
        //identifying fourth digit
        i = getMaxDigitInRange(hash_table, 9);
        if(i == -1)
            return result;
        else
            time[3] = i;
        
        for(i = 0; i < 4; i++)
        {
            if(i == 2)
                result.append(":");
            result.append(to_string(time[i]));
        }
        
        return result;
    }
};
