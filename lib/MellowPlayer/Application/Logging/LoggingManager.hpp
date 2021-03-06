#pragma once

#include "ILoggerFactory.hpp"
#include "LoggingMacros.hpp"
#include <map>
#include <memory>

namespace MellowPlayer::Application
{
    class LoggingManager
    {
    public:
        LoggingManager(const LoggingManager& other) = delete;
        LoggingManager(LoggingManager&&) = default;
        LoggingManager& operator=(const LoggingManager&) = delete;
        LoggingManager& operator=(LoggingManager&&) = default;

        static LoggingManager& initialize(ILoggerFactory& loggerFactory, const LoggerConfig& defaultConfig = LoggerConfig());
        static LoggingManager& initialize(ILoggerFactory& loggerFactory, LogLevel logLevel);
        static LoggingManager& instance();

        static ILogger& logger();
        static ILogger& logger(const std::string& name);
        static ILogger& logger(const std::string& name, const LoggerConfig& loggerConfig);

        void setDefaultLogLevel(LogLevel logLevel);

    private:
        LoggingManager(ILoggerFactory& loggerFactory, const LoggerConfig& defaultConfig);

        bool loggerExists(const std::string& name);
        ILogger& getExistingLogger(const std::string& name);
        ILogger& createNewLogger(const std::string& name, const LoggerConfig& loggerConfig);

        ILoggerFactory& loggerFactory_;
        std::map<std::string, std::unique_ptr<ILogger>> loggersMap_;
        LoggerConfig defaultLoggerConfig_;

        static std::unique_ptr<LoggingManager> instance_;
    };
}
