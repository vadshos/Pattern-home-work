#include <iostream>
#include"Singelton.h"

int main()
{
   Logging* logs = Logging::getInstance();
   logs->addLog({"bad variabel",Log::Flag::Crunchify_FLAG_WARN});
   logs->addLog({ "xmemory",Log::Flag::Crunchify_FLAG_FATAL });
   logs->showLog();
}
