#include "logger.h"
#include <time.h>
#include <string.h>

const char Logger::LogStr[4][255] = { "DEBUG", "INFO", "WARN", "ERROR"};
const char Logger::LogCol[4][255] = { "35", "33", "32", "31" };

Logger::Logger(const char* logFile, LogLevel level)
{
    this->outputLevel = level;
    outstream.open(logFile, ofstream::out);
}

Logger::~Logger()
{
    outstream.close();
}

void Logger::Debug(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    writeLog(DEBUG, fmt, ap);
    va_end(ap);
}

void Logger::Info(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    writeLog(INFO, fmt, ap);
    va_end(ap);
}

void Logger::Warn(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    writeLog(WARN, fmt, ap);
    va_end(ap);
}

void Logger::Error(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    writeLog(ERROR, fmt, ap);
    va_end(ap);
}

void Logger::writeLog(LogLevel level, const char* fmt, va_list ap)
{
    if (this->outputLevel > level)
        return;

    char buf[255];
    vsprintf(buf, fmt, ap);

    string msg(buf);
    time_t tim;
    time(&tim);
    char* times = ctime(&tim);
    times[strlen(times)-1]=' ';
    string timeStr(times);
    cout<<timeStr<<"\033[01;"<<LogCol[level]<<"m"<<LogStr[level]<<"\033[00m "<<msg<<endl;
}
