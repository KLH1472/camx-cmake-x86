//=================================================================================================
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//=================================================================================================

//=================================================================================================
// @file  nativetestlog.cpp
// @brief Implementation of logging methods
//=================================================================================================

#include "nativetestlog.h"
#include <stdarg.h>
#include "log/log.h"

namespace tests {

    NativeTestLog NTLog;
    const char* currentTestSuiteName;
    const char* currentTestCaseName;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor for ChiFeature2Log
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    NativeTestLog::NativeTestLog()
    {
        // Set default log level to debug and above messages
        m_eLogLevel = eDebug;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Helper function for logging
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string NativeTestLog::GetMSGPrefixString(
        verboseSeverity severity)  ///< [in] severity level
    {
        switch (severity)
        {
        case eStandard:     return "[=====] ";
        case eEntry:        return "[ENTRY] ";
        case eExit:         return "[ EXIT] ";
        case eDebug:        return "[DEBUG] ";
        case eInfo:         return "[ INFO] ";
        case ePerformance:  return "[ PERF] ";
        case eUnsupported:  return "[UNSUP] ";
        case eWarning:      return "[ WARN] ";
        case eError:        return "[ERROR] ";
        default:
            return "Severity Unsupported";
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the logging level
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int NativeTestLog::SetLogLevel(
        verboseSeverity level)
    {
        switch (level)
        {
        case eEntry:        m_eLogLevel = eEntry;
            break;
        case eExit:         m_eLogLevel = eExit;
            break;
        case eDebug:        m_eLogLevel = eDebug;
            break;
        case eInfo:         m_eLogLevel = eInfo;
            break;
        case ePerformance:  m_eLogLevel = ePerformance;
            break;
        case eUnsupported:  m_eLogLevel = eUnsupported;
            break;
        case eWarning:      m_eLogLevel = eWarning;
            break;
        case eError:        m_eLogLevel = eError;
            break;
        default:
            return eStandard;
        }
        return 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the logging level
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void NativeTestLog::SetTestName(const char* suiteName, const char* caseName)
    {
        currentTestSuiteName = suiteName;
        currentTestCaseName = caseName;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Print the message to console and logcat
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void NativeTestLog::Log(verboseSeverity severity, const char* file, int line, const char* mFormat, ...)
    {
        std::string fullMessage;
        char message[NT_STRLEN_MAX];
        va_list args;
        va_start(args, mFormat);
        vsnprintf(message, NT_STRLEN_MAX - 1, mFormat, args);
        va_end(args);

        const char* pFileName = strrchr(file, '/');
        pFileName = pFileName ? pFileName + 1 : file;

        fullMessage = GetMSGPrefixString(severity) + message;

        fprintf(stdout, "%s:%d %s\n", pFileName, line, fullMessage.c_str());
    }
}
