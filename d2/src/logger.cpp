#include "logger.h"

Logger::Logger(const char* logFile, LogLevel level)
{
    this->level = level;
    outstream.open(logFile, ofstream::out);
}

Logger::~Logger()
{
    cout<<"close";
    outstream.close();
}

void Logger::Debug(string msg)
{
    cout<<msg;
    outstream<<msg;
}

void Logger::Info(string msg)
{
}

void Logger::Warn(string msg)
{
}

void Logger::Error(string msg)
{
}
