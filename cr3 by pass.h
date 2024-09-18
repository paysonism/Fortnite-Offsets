void SigmaMigma() {
    auto previous_cr3 = mem::fetch_cr3();
    int counter = 0; 
    while (true)
    {
        if (!cache::gworld) {
            mem::fetch_cr3();
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    }
}



and on ur int main()
{
    std::thread funcThread(SigmaMigma);
    HANDLE threadHandle = funcThread.native_handle();
    threadHandle.Detach();
}
