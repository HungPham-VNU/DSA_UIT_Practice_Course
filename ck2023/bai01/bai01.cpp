#include <iostream>
#include <string>
using namespace std;

struct Word {
	string Text;
	string Definition;
};

void Input(Word[], int);
void SaveData(Word[], int);
void Sort(Word[], int);


int main()
{
	Word* dictionary = new Word[1500];
	int n;
	cin >> n;
	Input(dictionary, n);
	Sort(dictionary, n);
	SaveData(dictionary, n);
	delete[] dictionary;
}

void Input(Word dictionary[], int n) {
	Word temp;
	for (int i = 0; i < n; i++)
	{
		getline(cin >> ws, temp.Text);
		dictionary[i].Text = temp.Text;
		getline(cin >> ws, temp.Definition);
		dictionary[i].Definition = temp.Definition;
	}
}

void SaveData(Word dictionary[], int n) {
	for (int i = 0; i < n; i++) {
		cout << dictionary[i].Text << ' ' << dictionary[i].Definition << '\n';
	}
}

//insertion sort
void Sort(Word d[], int n) {
	for (int i = 1; i < n; i++) {
		if (d[i].Text < d[i - 1].Text) 
		{
			int j = i;
			while (j > 0 && d[j].Text < d[j - 1].Text)
			{	
				swap(d[j], d[j - 1]);
				j--;
			}
		}
	}
}