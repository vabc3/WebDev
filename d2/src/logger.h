#include <iostream>
#include <fstream>

using namespace std;

enum LogLevel
{
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger
{
public:
    Logger(const char *logFile = NULL, LogLevel level = INFO);
    ~Logger();
    void Debug(const char *fmt, ...);
    void Info(const char *fmt, ...);
    void Warn(const char *fmt, ...);
    void Error(const char* fmt, ...);
private:
    static const char LogStr[4][255];
    static const char LogCol[4][255];
    bool colorOutput;
    ofstream outstream;
    LogLevel outputLevel;
    void writeLog(LogLevel level, const char *fmt, va_list ap);
};
