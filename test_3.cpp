#include<iostream>
#include <fstream>
#include<vector>
#include <string>

using namespace std;

vector<string> fileRnS(vector<string> prevVec) { // file Read and store (at vector)


	string word;
	string saveLine;	//���Ͽ��� �о� �� ������ �����ϴ� ���ڿ�
	vector<string> returnVec; //return �� vector

	int maxSize = 75; 
	int count = 0; 
	int lastSpace = 0; // space�� ���� ��� index ����.
	int wordNumCheck = 0; // maxSize�� �Ѿ�� �ʰ� üũ
	
	while (true)
	{
		if (count >= prevVec.size()) {
			returnVec.push_back(saveLine);
			break;
		}
		word = prevVec[count++] + " ";

		wordNumCheck += word.length();

		if (wordNumCheck >= 75) {
			returnVec.push_back(saveLine);
			saveLine = word;
			wordNumCheck = word.length();
		}
		else {
			saveLine += word;
		}

	}

	return returnVec;
}

vector<string> fileRnS(string fileName) { // file Read and store (at vector)
	ifstream ifile;
	//ifile.open("test_copy.txt");
	ifile.open(fileName);

	char* line;	//���Ͽ��� �о� �� ������ �����ϴ� ���ڿ�
	int maxSize = 75; // �� �ٴ� �ִ� ũ��

	vector<string> vec; // ���Ͽ��� �о� �� ���ڿ����� ������ vextor
	int lastSpace = 0; // ���Ͱ� ���� ��� index ����.

	line = new char[76]; // ����� �� ��

	if (ifile.is_open()) {
		int count = 0; // vector�� index�� �ľ��ϱ� ���� counting value
		int wordNumCheck = 0; // maxSize�� �Ѿ�� �ʰ� üũ

		while (!ifile.eof()) {

			ifile.get(line[wordNumCheck]); // ���Ͽ��� �� ���ھ� �о�ͼ� �ӽ� ���� ���ڿ��� line �� �Ҵ��Ѵ�.
			wordNumCheck++; // line�� index ���� counting �ϱ� ���� ����
			if (line[wordNumCheck - 1] == ' ') { // ���Ŀ� ������ ���� ������ ������ index+1 ��ġ�� �����Ѵ�.
				lastSpace = wordNumCheck;
			}
			if (wordNumCheck == maxSize) { // line�� ������ �� �ִ� ������ ũ�Ⱑ �ִ밡 �Ǿ��� ��
				char save; // ������ ���� ������ ���� ����
				ifile.get(save);

				if (line[maxSize - 1] == ' ') { // line�� ������ ==' ' ==> pass
					line[maxSize - 1] = '\0'; // ���ڿ��� �������� ǥ��
					vec.push_back(line); // vector�� �������� line�� �߰��Ѵ�.

					line = new char[75]; // �ӽ� ���� �迭�� �ʱ�ȭ �Ѵ�.
					line[0] = save; // �ʱ�ȭ ���� �̸� �����ߴ� ���� ���ڸ� �迭 ���� ó���� ����.
					wordNumCheck = 1; // index ����
					continue; //����
				}
				else if (save == ' ') {
					line[maxSize] = '\0';
					vec.push_back(line);
					line = new char[75]; // �迭 �ʱ�ȭ
					wordNumCheck = 0;
					continue;
				}
				else { // ó���ؾ� �� ���
					int saveSize = 75 - lastSpace; // �߸� �ܾ��� �պκ� ����
					char store[20];
					for (int i = lastSpace; i < 75; i++) {
						store[i - lastSpace] = line[i];
					}
					store[saveSize] = '\0';
					line[lastSpace] = '\0';
					vec.push_back(line);

					line = new char[75];
					for (int i = 0; i < saveSize; i++) {
						line[i] = store[i];
					}
					line[saveSize] = save;
					wordNumCheck = saveSize + 1;
					continue;

				}
			}
		}
		line[wordNumCheck] = '\0';
		vec.push_back(line);
	}
	ifile.close();
	return vec;
}

vector<string> fileLineToWord(string fileName) { //�ܾ������ ���Ϳ� ����
	string allContext;
		ifstream ifile;
		ifile.open(fileName);

		vector<string> returnVec;
		if (ifile.is_open()) {
			getline(ifile, allContext);
			ifile.close();

			vector<char> file_read(allContext.begin(), allContext.end());
			file_read.push_back('\0');
			char* ptr = &file_read[0];
			char* words = strtok(ptr, " ");

			int count = 0;
			while (words != NULL){
				
				returnVec.push_back(words);
				words = strtok(NULL, " ");
			}
			return returnVec;
		}
		else {
			cout << "Unable to open file";
		}
}

vector<string> vectorToWord(vector<string> lineVector) {
	int count = 0;
	vector<string> wordsVec;
	while(true)
	{
		if (count >= lineVector.size()) {
			break;
		}
		else {
			string line = lineVector[count];
			int lineSize = line.length();
			char* charLine = 0;
			charLine = new char[lineSize + 1];

			strcpy(charLine, line.c_str());
			charLine[lineSize] = '\0';

			char* word = strtok(charLine, " ");
			while (word != NULL) {
				wordsVec.push_back(string(word));
				word = strtok(NULL, " ");
			}
			count++;
		}

	}
	return wordsVec;
}
int main() {
	vector<string> infoVec; // ���Ͽ� ���� ������ �����ϰ� ���� vector�� �����Ѵ�.
	string fileName = "test_copy_1.txt";
	infoVec = fileRnS(fileName);
	/*
	for (int i = 0; i < infoVec.size(); i++) {
		cout << i + 1 << " : " << infoVec[i] << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	vector<string> wordVec = fileLineToWord(fileName);
	*/
	/*
	for (int i = 0; i < wordVec.size(); i++) {
		cout << "| " << wordVec[i];
	}
	cout << "\n------------------------------------------------------------------" << endl;
	*/
	/*
	vector<string> wordToLineVec = fileRnS(wordVec);
	for (int i = 0; i < wordToLineVec.size(); i++) {
		cout << i + 1 << " : " << wordToLineVec[i] << endl;
	}
	*/
	vector<string> wordsDate = vectorToWord(infoVec);
	for (int i = 0; i < wordsDate.size(); i++) {
		cout << i + 1 << " : " << wordsDate[i] << endl;

	}
}
