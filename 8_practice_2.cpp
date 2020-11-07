#include <iostream>
class GlobalLogger
{
	int log_value;
public:
	GlobalLogger(int v = 0)
	{
		log_value = v;
	}
	int get_log_data()
	{
		return log_value;
	}
	void set_log_data(int v)
	{
		log_value = v;
	}
	//log_value�� �����ϴ� �Լ���
};
// Default initialization
GlobalLogger* global_Logger_ptr = 0; // ������ �������� �ʱ�ȭ
void Logger_User_A(void)
{
	// Initialization on first use
	if (!global_Logger_ptr) // ������ ���� 0�� ��� ==> �����Ǿ����� ���� ���
		global_Logger_ptr = new GlobalLogger; // ���ο� GlobalLogger��ü�� ����
	//GlobalLogger�� �����ϴ� ���� �ϳ��� �־ ����ϴ�. �������� ������ ��ȿ����
		global_Logger_ptr->set_log_data(1);
		std::cout << "Logger_User_A: log_data is " << global_Logger_ptr->get_log_data()
			<< '\n';
}
void Logger_User_B(void)
{
	if (!global_Logger_ptr)
		global_Logger_ptr = new GlobalLogger;
	global_Logger_ptr->set_log_data(2);
	std::cout << "Logger_User_B: log_data is " << global_Logger_ptr -> get_log_data() << '\n';
}
int main()
{
	if (!global_Logger_ptr)
		global_Logger_ptr = new GlobalLogger; 
	// ��ü �����Ҷ� �޸𸮰� �Ҵ� ��. => global_Logger != 0
	std::cout << "main: log_data is " << global_Logger_ptr->get_log_data() << '\n';
	Logger_User_A();
	Logger_User_B();
	
	// Q: �� ���α׷��� �����ϰ� �м��Ͻÿ�. � ������ �����ϴ°�?
	// A : Logger Value�� �����ϴ� ��ü�� �ϳ��� ����ѵ� �ǵ�ġ �ʰ� �������� ��ü�� ������ �� ����
	//		���� �ڵ忡�� �����Ͱ� ����Ǵ� �ڵ尡 ������ ������� global_Logger_ptr�� 0���� �ʱ�ȭ �� ��
	//		�ٽ� ������ ��쿡�� ��ü�� �߰������� ������ �ȴ�. �̷� ��� ��ȿ����
	//		=> �̱������� ����


}