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
	//log_value를 관리하는 함수들
};
// Default initialization
GlobalLogger* global_Logger_ptr = 0; // 포인터 전역변수 초기화
void Logger_User_A(void)
{
	// Initialization on first use
	if (!global_Logger_ptr) // 포인터 값이 0일 경우 ==> 설정되어있지 않을 경우
		global_Logger_ptr = new GlobalLogger; // 새로운 GlobalLogger객체를 생성
	//GlobalLogger를 관리하는 것은 하나만 있어도 충분하다. 여러개가 있으면 비효율적
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
	// 객체 생성할때 메모리가 할당 됨. => global_Logger != 0
	std::cout << "main: log_data is " << global_Logger_ptr->get_log_data() << '\n';
	Logger_User_A();
	Logger_User_B();
	
	// Q: 이 프로그램을 실행하고 분석하시오. 어떤 문제가 존재하는가?
	// A : Logger Value를 관리하는 객체는 하나면 충분한데 의도치 않게 여러개의 객체가 생성될 수 있음
	//		현재 코드에는 포인터가 변경되는 코드가 없지만 예를들어 global_Logger_ptr을 0으로 초기화 한 후
	//		다시 실행할 경우에는 객체가 추가적으로 생성이 된다. 이럴 경우 비효율적
	//		=> 싱글톤으로 변경


}