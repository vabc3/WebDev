#include <iostream>
#include <fstream>

using namespace std;

enum LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    Logger(const char* logFile = NULL, LogLevel level = INFO);
    ~Logger();
    void Debug(string msg);
    void Info(string msg);
    void Warn(string msg);
    void Error(string msg);
private:
    bool colorOutput;
    ofstream outstream;
    LogLevel level;
};
