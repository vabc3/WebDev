#include "logger.h"
#include <memory>
using namespace std;


int main()
{
    unique_ptr<Logger> log(new Logger("fp_d"));
//   Logger* log = new Logger("dat");
    log->Debug("dbg!!");
    log->Error("err!");
//   delete log;

    return 0;
}
