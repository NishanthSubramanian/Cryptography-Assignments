#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
vector<double> dv;
int et;
double i_c(string s)
{
    int i, j, k;
    int sum = 0;
    int n = s.length();
    if (n == 1)
        return 0;
    int count[26] = {0};
    for (i = 0; i < n; i++)
    {
        count[s[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
        sum += count[i] * (count[i] - 1);
    double sumf = double(sum) / ((double)(n * (n - 1)));
    return sumf;
}

void compute_ic(vector<string> v)
{
    int i;
    double sum, avg;
    for (i = 0; i < v.size(); i++)
    {
        double ic = i_c(v[i]);
        sum += ic;
    }
    avg = sum / v.size();
    dv.push_back(avg);
}
int findmax(vector<double> dv)
{
    int i;
    double max = -1;
    int max_index;
    for (i = 0; i < dv.size(); i++)
    {
        if (dv[i] > max)
        {
            max = dv[i];
            max_index = i;
        }
    }
    return max_index;
}
double letfreq[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};
double compute_chi_sq(string s)
{
    int i;
    double sum = 0;
    int cnt[26] = {0};
    for (i = 0; i < s.length(); i++)
    {
        cnt[s[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        double ex = s.length() * letfreq[i];
        double numer = pow((cnt[i] - ex), 2);
        double ch = numer / ex;
        sum += ch;
    }
    return sum;
}
string caesar(string s)
{
    int i, j;
    for (i = 0; i < s.length(); i++)
    {
        s[i] += 1;
    }
    return s;
}

int findmin(vector<double> v)
{
    int min_index, i, j;
    double min = v[0];
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] <= min)
        {
            min = v[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{
    int i, j, k;
    char current_char;
    string s = "BPUVFSKODAHMPVGRJMPKAYSSOPNAJMPKAYSWRTQBIRAKMTGAEKBUGYMRNEHPFHDBBXEKRROVQJSUWWBCQGVMPHTYZSCPZGIVXNRHFVLWMQWRDURBAIXTDOWSQKBNBHPQLROVBPNAPMLVHPPMLVHPSPBODAHMPVGNHIIGLRBXQJZGVEPNHSSPFMDUIQXPAVFHXPHZOPMNZAHWXPCZWGOQNEUEKKRZGAEGQROWXDHBHMZGKRAIKVRNFIQJNFSAEKBUVESGMBZMCGKVYIXKQFIRIKFUHAXVDEZEKFRBWPJKMRFEIUDGQIIGLRBXZQLRGMKEZGSKLTHRGSCDHBHMZCMQOFFQSVQJRTSUSVZCMOSHFXHQSHXONAUJLWQGMTBUNSGTEGQRZMHGAVCWMJDESLVFQBGTEGQRZMQJNFDLBTDNBHXVLBGTEGQRPMLVHPORACAVCXFEDYSQBPSFFIXESFKMQJDNQLLVGRFMKUNZSQXPMRFPFMDSFIPJVNHIOUTAZMDJSNBHPQHYOVBWRRRJLTFECAFPFCZEKVRFOQBCRCZEKVRCFSAWBRCBVIDAHLXVHFVMDJKLFINWHESHYAZYZXEGKVJMKINEUEKKRZGIUKRGSHLPSUWWBCQGVLROZAPIFPFFIWBCKYHLBCUNWPXDKRBEQWQNZVBUNHFGBUHARMCHDESRQOZABIOHNEPIQVDEZMSKMTCRBCQGVEQKSFWRFVHNZWQCFRHLFUDNFXEYZFGSYGZHHMCWKNBHCWKYCJKCSHFEITDFCYOEDFHLXVVRSZBPBNBRLVCRGGOKARPYQCRGWQBRZFGIAFTRHSFPBESEPGCCCTRNZGWSKVGRFINWHESQBPSBTVBUNHFGBUGNGEIUNOSIKKMPFIXUDQORAPNJHLBETEFIKVRVHYXVHBBMPUNJCVPVSUOXTGBNBRLVRHFIIARNMXECSSCVEQVZIGEVHZSABYNHZHYGZOZIQQTFSXEGRRFIPQTEQIPCRGVIVCQRQSKVHAISRUKLRMPCOCSEOKMTTVLOSUSIXTSUIWBQEAOXRTZYFIPQTEQIPUGBIPADDPOVBHTYZCMNZABIACMQSBBETGSHFVHFQSJRKRHIIAVECRDVNPIXQJDSCVBUSNGXOGDFOVBVGRYIVQORFEQQQBTRXVTEOPZABYSJLTDFHGRVSVBKJCXPOYPGSUSTLQQFWXRCSVCRLHCECYDJSVBGOGZFSHEGZGWRDVDZDIOCSHFIRPRGOFIGRROWLPRHBGBTSNWROCHATEINEYCSAFDPFIXUDQOKOKBHZXRTZYEYXNHGMSOVGRKSOUSBBIDNNOOPTCQZWRDYGVQLFUBBATIGSRZCKQSNQGBRSNPPBHNEHLBGWVGXBPBRCJIKERCRBCQGVJLTFVJMKIZOSXQGQNBHEGZYHLVNHSSXLQTETYQWQRUIKGQNHMLPRJSEINRUCYIFTAWXBYHGVXXMDFCQBRKRRKBCABIXMTDISRQKNACJLWQRBZFTNAAIKVVVHLIGRFORAUZSSYPGNSBEQWQNZVBUNHFGBU";
    int count = s.length();
    for (i = 2; i < 10; i++)
    {
        vector<string> v;
        for (j = 0; j < i; j++)
        {
            string str;
            k = j;
            while (s[k] != '\0' && k < count)
            {
                str.push_back(s[k]);
                k += i;
            }
            v.push_back(str);
        }
        compute_ic(v);
    }
    int key_length = findmax(dv) + 2;
    cout << "Key length is " << key_length << endl;
    string key;
    vector<string> vct;
    for (j = 0; j < key_length; j++)
    {
        string q;
        k = j;
        while (s[k] != '\0' && k < count)
        {
            q.push_back(s[k]);
            k += key_length;
        }
        vct.push_back(q);
    }
    int p;
    char r;
    for (i = 0; i < key_length; i++)
    {
        vector<double> chi;
        string temp = vct[i];
        for (j = 0; j < 26; j++)
        {
            chi.push_back(compute_chi_sq(vct[i]));
            for (k = 0; k < vct[i].length(); k++)
            {
                if (vct[i][k] - 1 < 'A')
                {
                    vct[i][k] = vct[i][k] - 1 + 26;
                }
                else
                {
                    vct[i][k] = vct[i][k] - 1;
                }
            }
        }
        key[i] = 'A' + findmin(chi);
    }
    cout << "Key is ";
    for (i = 0; i < key_length; i++)
        cout << key[i];
    cout << endl;
    return 0;
}