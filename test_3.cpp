#include<iostream>
#include <fstream>
#include<vector>
#include <string>

using namespace std;

vector<string> fileRnS(vector<string> prevVec) { // file Read and store (at vector)


	string word;
	string saveLine;	//파일에서 읽어 올 문장을 저장하는 문자열
	vector<string> returnVec; //return 할 vector

	int maxSize = 75; 
	int count = 0; 
	int lastSpace = 0; // space가 있을 경우 index 저장.
	int wordNumCheck = 0; // maxSize를 넘어가지 않게 체크
	
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

	char* line;	//파일에서 읽어 올 문장을 저장하는 문자열
	int maxSize = 75; // 한 줄당 최대 크기

	vector<string> vec; // 파일에서 읽어 온 문자열들을 저장할 vextor
	int lastSpace = 0; // 엔터가 있을 경우 index 저장.

	line = new char[76]; // 출력할 한 줄

	if (ifile.is_open()) {
		int count = 0; // vector의 index를 파악하기 위한 counting value
		int wordNumCheck = 0; // maxSize를 넘어가지 않게 체크

		while (!ifile.eof()) {

			ifile.get(line[wordNumCheck]); // 파일에서 한 글자씩 읽어와서 임시 저장 문자열인 line 에 할당한다.
			wordNumCheck++; // line의 index 수를 counting 하기 위함 변수
			if (line[wordNumCheck - 1] == ' ') { // 이후에 개행을 위해 마지막 공백의 index+1 위치를 저장한다.
				lastSpace = wordNumCheck;
			}
			if (wordNumCheck == maxSize) { // line에 저장할 수 있는 문자의 크기가 최대가 되었을 때
				char save; // 개행을 위해 저장할 다음 문자
				ifile.get(save);

				if (line[maxSize - 1] == ' ') { // line의 마지막 ==' ' ==> pass
					line[maxSize - 1] = '\0'; // 문자열이 끝났음을 표시
					vec.push_back(line); // vector의 마지막에 line을 추가한다.

					line = new char[75]; // 임시 저장 배열을 초기화 한다.
					line[0] = save; // 초기화 이후 미리 저장했던 다음 문자를 배열 가장 처음에 저장.
					wordNumCheck = 1; // index 수정
					continue; //진행
				}
				else if (save == ' ') {
					line[maxSize] = '\0';
					vec.push_back(line);
					line = new char[75]; // 배열 초기화
					wordNumCheck = 0;
					continue;
				}
				else { // 처리해야 할 경우
					int saveSize = 75 - lastSpace; // 잘린 단어의 앞부분 길이
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

vector<string> fileLineToWord(string fileName) { //단어단위로 벡터에 저장
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
	vector<string> infoVec; // 파일에 대한 정보를 저장하고 있을 vector를 생성한다.
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
