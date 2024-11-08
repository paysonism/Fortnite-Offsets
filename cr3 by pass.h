#include <thread> // if u dont include this this_thread will be a error
void cr3_loop()
{
	for (;;)
	{
		mem::fetch_cr3();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


and on ur int main()
{
std::thread([&]() { for (;;) { cr3_loop(); } }).detach();
}
