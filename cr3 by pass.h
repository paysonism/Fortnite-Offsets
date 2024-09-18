void cr3_loop()
{
    while (true)
    {
        mem::fetch_cr3();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}




and on ur int main()
{
                    std::thread funcThread(SigmaMigma);
            HANDLE threadHandle = funcThread.native_handle();
}
