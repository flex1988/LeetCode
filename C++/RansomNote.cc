class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int* dict = (int*)calloc(26, sizeof(int));

        int len_m = magazine.size();
        for (int i = 0; i < len_m; i++) {
            dict[magazine[i] - 'a']++;
        }
        int len_r = ransomNote.size();
        for (int i = 0; i < len_r; i++) {
            int t = --dict[ransomNote[i] - 'a'];
            if (t < 0) return false;
        }
        return true;
    }
};
