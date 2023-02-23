#include "core/libcamera_app.hpp"
#include <hubs_logging/logging.h>
#include <sstream>
#define LOG(level, text)                                                                                               \
	do                                                                                                                 \
	{                                                                                                                  \
		auto logger = hubs::get_or_create_logger("libcamera-app");                                                                     \
		if (LibcameraApp::GetVerbosity() >= level)																		\
		{																											\
			auto logger = hubs::get_or_create_logger("libcamera-app");              \
			std::stringstream ss;                      \
			ss << text;									\
			if(level > 1)																				\
				SPDLOG_LOGGER_DEBUG(logger, ss.str());											\
			else																							\
				SPDLOG_LOGGER_INFO(logger, ss.str());														\
		}                                                                            \
	} while (false)
#define LOG_ERROR(text) \
	do \
	{ \
		std::stringstream ss; \
		ss << text; \
		SPDLOG_LOGGER_ERROR(hubs::get_or_create_logger("libcamera-app"), ss.str()); \
	} while (false);
	
