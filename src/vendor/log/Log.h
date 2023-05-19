#include <string>

#define LOGGING_DEFINE_EXTENDED_OUTPUT_TYPE
#include "logging/logging.h"
using namespace ::logging;

// logging levels can be disabled at compile time
//LOGGING_DISABLE_LEVEL(::logging::Error);
//LOGGING_DISABLE_LEVEL(::logging::Trace);
//LOGGING_DISABLE_LEVEL(::logging::Warning);
//LOGGING_DISABLE_LEVEL(::logging::Info);

LOGGING_DEFINE_OUTPUT( ::logging::config::FileLogType )

#define LOG_OBJ   logging::detail::Logger<logging::Void, logging::loggingReturnType>::logging()

#define LOG(TYPE) log::emit<TYPE>()
#define ENDL      log::endl
