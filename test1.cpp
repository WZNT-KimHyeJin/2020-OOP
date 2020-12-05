#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void consolePrint(string messsage);

void printSepLine() {
	for (int i = 0; i < 3; i++) {
		cout << "---------------------------";
	}
	cout << "\n";
}
void readVec(vector<string> vec, int start) {
	int count = 0;
	try {
		while (1) {
			if (start >= (int)vec.size()) {
				consolePrint("this is the last page!");
				break;
			}
			if (count == 20) {
				break;
			}
			cout.width(2);
			cout << start + 1;
			cout << " | " << vec[start] << endl;
			start++;
			count++;
		}
	}
	catch (const std::out_of_range) {
	}
}


//singleTone�� ����Ͽ� �ֻ��� class�� �����Ѵ�.
class top 
{
private:
	vector<string> finalVector;
	static top *t_instance;
	
public:
	void set_vec(vector<string> new_vec) {
		this->finalVector = new_vec;
	}
	static top *instance()
	{
		if (!t_instance) {
			t_instance = new top;
		}
		return t_instance;
	}
	vector<string> get_vec()
	{
		return this->finalVector;
	}
};

top* top::t_instance = 0;

class copyTop : public top{
private : 
	vector<string> c_vector;
	static copyTop* ct_instance;

public:
	vector<string> get_vec() {
		return this->c_vector;
	}
	void set_vec(vector<string> new_vec) {
		this->c_vector = new_vec;
	}
	static copyTop* instance()
	{
		if(!ct_instance) {
			ct_instance = new copyTop;
		}
		return ct_instance;
	}
};
copyTop* copyTop::ct_instance = 0;



////////////////////////////////////////////��� ���� �޼ҵ� /////////////////////////////////////////////


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
vector<string> fileWtoL(vector<string> prevVec) {


	string word;
	string saveLine;	//���Ͽ��� �о� �� ������ �����ϴ� ���ڿ�
	vector<string> returnVec; //return �� vector

	int maxSize = 75;
	int count = 0;
	int lastSpace = 0; // space�� ���� ��� index ����.
	int wordNumCheck = 0; // maxSize�� �Ѿ�� �ʰ� üũ

	while (true)
	{
		if (count >= (int)prevVec.size()) {
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
		while (words != NULL) {

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
	while (true)
	{
		if (count >= (int)lineVector.size()) {
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

class fileAction {

public :
	static fileAction* doingAct(char* userInput);
	virtual void doFileAction() = 0;

};

class file_insert : public fileAction {
private:
	vector<string> inputVec = copyTop::instance()->get_vec();
public:
	void doFileAction() {

	}
};

class file_delete : public fileAction {
private:
	vector<string> deleteVec = copyTop::instance()->get_vec();
public:
	void doFileAction() {

	}
};

class file_search : public fileAction {
private:
	vector<string> searchVec = copyTop::instance()->get_vec();
public:
	void doFileAction() {

	}
};

class file_change : public fileAction {
private:
	vector<string> unChangeVec = copyTop::instance()->get_vec();
	vector<string> changingVec;
	vector<string> changedVec;
	//char* word1 = NULL;
	//char* word2 = NULL;
	string word1 ;
	string word2;

	vector<string> wordVec;
	
public:
	void doFileAction() {
		wordVec = vectorToWord(unChangeVec);
		for (int i = 0; i < (int)wordVec.size(); i++) {
			if (wordVec[i] == word1) {
				changingVec.push_back(word2);
			}
			else {
				changingVec.push_back(wordVec[i]);
			}
		}
		changedVec = fileWtoL(changingVec);
		readVec(changedVec,0);
		
	}
	void setWord1(string newWord1) {
		this->word1 = newWord1;
	}
	void setWord2(string newWord2) {
		this->word2 = newWord2;
	}
	
};
class file_Save_Quit : public fileAction {
private:
	vector<string> saveVec = copyTop::instance()->get_vec();
public:
	void doFileAction() {
		top::instance()->set_vec(copyTop::instance()->get_vec());
		consolePrint("����� ���� ������ ���� �� ���� �մϴ�.");
	}
};

//������ ���� ���� �ڵ� : �ǵ��� ����
class file_page : public fileAction {

private:
	vector<string> fileReadVec = copyTop::instance()->get_vec();
	int startingPoint = 0;
	static file_page* file_instance;
	char check_mode = ' ';
	
public :
	void setMode(char mode) {
		this->check_mode = mode;
	}
	char getMode() {
		return this->check_mode;
	}
	void doFileAction(){
		if (check_mode == 'n') { //nextPage
			this->startingPoint += 20;
			readVec(fileReadVec, startingPoint);
		}
		else if(check_mode=='p'){//prevpage
			this->startingPoint -= 20;
			readVec(fileReadVec, startingPoint);
		}
	}
	static file_page* instance() {
		if (!file_instance) {
			file_instance = new file_page;
		}
		return file_instance;
	}
	
};
file_page* file_page::file_instance = 0;

/////////////////////////////////////��� ���� �޼ҵ�/////////////////////////////////////



//vec -> word

void consolePrint(string message) {
	cout << message << endl;
	printSepLine();
}
void controller() {
	char userInput[10];
	cout <<"n:���� ������, p:���� ������, i:����, d:����, c:����, s:ã��, t:���� �� ����" << endl;;
	printSepLine();
	consolePrint(" ");
	while (1) {

	cout << "�Է�:";
	cin >> userInput;
	printSepLine();
	fileAction* currentAction = fileAction::doingAct(userInput);
	currentAction->doFileAction();
	if (userInput[0] == 't') {
		break;
	}

	cout << "n:���� ������, p:���� ������, i:����, d:����, c:����, s:ã��, t:���� �� ����" << endl;;
	printSepLine();
	
	}
}


fileAction* fileAction::doingAct(char* userInput) {
	if (userInput[0] == 'n') {
		//file_page* fg = new file_page;
		//fg->setMode(userInput[0]);
		file_page::instance()->setMode(userInput[0]);
		return file_page::instance();
	}
	else if (userInput[0] == 'p') {
		//file_page* fg = new file_page;
		//fg->setMode(userInput[0]);
		file_page::instance()->setMode(userInput[0]);
		return file_page::instance();
	}
	else if (userInput[0] == 't') { // ����
		return new file_Save_Quit;
	}
	else if (userInput[0] == 'c') {//change
		//c(word1, word2)
		string inputValue(userInput); //c(word1,word2)
		string subVal = inputValue.substr(2,inputValue.size()-3);
		//word1,word2

		char* val2ch = new char[subVal.size() + 1];
		strcpy(val2ch, subVal.c_str());
		val2ch[subVal.size()] = '\0';
		//word1,word2 => string -> char*
		
		string storeInputs = (string)strtok(val2ch, ",");
		// word1/ word2

		file_change* fc = new file_change;
		fc->setWord1(storeInputs);
		storeInputs = (string)strtok(NULL, ",");
		fc->setWord2(storeInputs);
		return fc;

	}
}

void outFile(vector<string> vec, string fileName) {
	ofstream ofile;
	ofile.open(fileName);
	for (int i = 0; i < (int)vec.size(); i++) {
		ofile << vec[i] + " ";
	}
	ofile.close();
}
int main() {
	vector<string> infoVec; // ���Ͽ� ���� ������ �����ϰ� ���� vector�� �����Ѵ�.
	string FILENAME = "test_copy_1.txt";
	infoVec = fileRnS(FILENAME); // ���Ͽ��� �о� �� vector ���� �����Ѵ�.
	top::instance()->set_vec(infoVec);
	copyTop::instance()->set_vec(top::instance()->get_vec());
	readVec(copyTop::instance()->get_vec(),0);
	controller();
	//controller("This is the first Page. What do you want to do?");
}
