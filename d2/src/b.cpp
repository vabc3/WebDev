#include "logger.h"
#include <memory>
using namespace std;


int main()
{
    unique_ptr<Logger> log(new Logger("fp_d", DEBUG));
//   Logger* log = new Logger("dat");
    log->Debug("dbg!%d!",1-9);
    log->Info("dbg!%d!",1-9);
    log->Warn("dbg!%d!",1-9);
    log->Error("err!");
//   delete log;

    return 0;
}
