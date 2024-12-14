#include <iostream>
#include <cstdlib>
using namespace std;
enum TypeOf { SmallLatare = 1, CapetalLatar = 2, num = 3, Specialchar = 4 };
int random(int from, int to) {
	int num = rand() % (to - from + 1) + from;
	return num;
}
int HowManyKeys() {
	cout << "Please enter how Many Key you need to generated\n";
	int num;
	cin >> num;
	return num;
}
char TypeOfRandom(TypeOf Type) {
	switch (Type) {
	case TypeOf::CapetalLatar:
		return char(random(65, 90));
		break;
	case TypeOf::SmallLatare:
		return char(random(97, 122));
		break;
	case TypeOf::num:
		return char(random(48, 57));
		break;
	case TypeOf::Specialchar:
		return char(random(33, 47));
		break;
	}



}
string GenerateWord(TypeOf type, short int lengthOfWord) {
	string word = "";
	for (int i = 0; i < lengthOfWord; i++) {
		word += TypeOfRandom(TypeOf::CapetalLatar);
	}
	return word;
}
string GenerateKey(short int LengthOfKey) {
	string key = "";
	key = GenerateWord(TypeOf::CapetalLatar, 4) + "-";
	key += GenerateWord(TypeOf::CapetalLatar, 4) + "-";
	key += GenerateWord(TypeOf::CapetalLatar, 4) + "-";
	key += GenerateWord(TypeOf::CapetalLatar, 4);
	return key;
}
void GenerateKeys(short int NumOfKey) {
	for (int i = 1; i <= NumOfKey; i++) {
		cout << "Key [" << i << "]" << GenerateKey(4) << endl;
	}
}

int main() {
	GenerateKeys(HowManyKeys());


	return 0;
}