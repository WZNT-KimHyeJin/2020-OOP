#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void fileRNP() {
	ifstream ifile;
	ifile.open("test_copy.txt");
	//ifile.open("a.txt");

	char* line;
	//string allText;
	int maxSize = 75;
	vector<string> vec; // 75����Ʈ�� �ڸ� ���ڿ��� ����
	int lastSpace=0; // ���Ͱ� ���� ��� index ����.

	line = new char[76]; // ����� �� ��
	if (ifile.is_open()) {
		cout << "������ �����մϴ�" << endl;
		int count = 0;
		int wordNumCheck = 0; // maxSize�� �Ѿ�� �ʰ� üũ

		while (!ifile.eof()) {


			ifile.get(line[wordNumCheck]);
			//getline(ifile, allText);
			wordNumCheck++;
			//cout << "�߰��� �� : " << line[wo]

			if (line[wordNumCheck-1] == ' ') {
				lastSpace = wordNumCheck;
			}
			if (wordNumCheck == maxSize) { // wordNumCheck == 75
				char save;
				ifile.get(save); //line[75]

				if (line[maxSize - 1] == ' ') { // line�� ������ ==' '
					line[maxSize] = '\0';
					vec.push_back(line);
					cout << count++ << " | " << line << endl;
					line = new char[75]; // �ʱ�ȭ
					line[0] = save; // �ٹٲ� ���Ŀ� ���� �տ� �� ����.
					wordNumCheck = 1; // index ����
					continue;
				}
				else if (save == ' ') {
					line[maxSize] = '\0';
					vec.push_back(line);
					cout << count++ << " | " << line << endl;
					line = new char[75]; // �迭 �ʱ�ȭ
					wordNumCheck = 0;
					continue;
				}
				else {
					int saveSize = 75 - lastSpace; // �߸� �ܾ��� �պκ� ����
					char store[20];
					for (int i = lastSpace; i < 75; i++) {
						store[i-lastSpace] = line[i];
					}
					store[saveSize] = '\0';
					line[lastSpace] = '\0';
					vec.push_back(line);
					cout << count++ << " | " << line << endl;
					line = new char[75];
					for (int i = 0; i < saveSize; i++) {
						line[i] = store[i];
					}
					line[saveSize] = save;
					wordNumCheck = saveSize+1;
					continue;

				}
				cout << wordNumCheck - 1 << "��° lline ����" << line << endl;

			}
		}
	}
	else {
		cout << "������ ã�� �� �����ϴ�." << endl;
	}

	ifile.close();

}

int main() {
	fileRNP();
}
