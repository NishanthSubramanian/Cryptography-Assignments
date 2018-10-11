#include <iostream>
#include <fstream>

using namespace std;

int main() {

ifstream fin;
fin.open("caesar_cipher_text.txt", ios::in);
int count[26] = {0};
char current_char,s ;
int number_of_lines = 0;
while(!fin.eof()){
    fin.get(current_char);
		if (isalpha(current_char)){
            count[current_char-'a']++;
        }
}
int max = count[0];
int max1 = 0,i;
for(i=0;i<26;i++)
{
    if(count[i]>max)
        {
            max = count[i];
            max1 = i;
        }
}
char most_freq = 'a' + max1;
//u is most frequent
//Since e is the most frequent alphabet
int shift = 'e' - 'u' + 26;
fin.close();
fin.open("caesar_cipher_text.txt", ios::in);
	while (!fin.eof() ) {
    
	fin.get(current_char);
		if (isalpha(current_char)){
			if(current_char+shift > 'z')
                {
                    s = current_char+shift-26;
                    cout << s;
                }
                else
                {
                    s= current_char+shift;
                    cout << s;
                }
		}
        else
        {
            cout << current_char;
        }
	}

}