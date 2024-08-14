/*
 * @author  Georg Graßnick
 * @date 6/4/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ROTATINGFILESINK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ROTATINGFILESINK_HPP

#pragma once

#include <filesystem>
#include <fstream>
#include <optional>
#include <cstdint>

#include "logging/AbstractLoggingSink.hpp"

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class RotatingFileSink
     * @brief Logging sink which writes to a rotating set of files
     * @details The logger will write up to maxFileSize bytes to a single file.
     * If this limit is reached, it will rename the current log file and create a new file to write to.
     * Up to maxFileCount log files can exist at a certain point in time. The oldest one is deleted, if the count
     * limit is exceeded before rotating the files (i.e. renaming the files).
     *
     * Messages are not split across different log files. If a message does not fit into the current log file,
     * it will be written to the next file, after a rotation of the logfiles is performed.
     * Consequently, messages which are larger than mMaximumFileSize are not written to file at all!
     */
    class RotatingFileSink : public AbstractLoggingSink
    {
    private:
        /**
         * @brief The maximum count of logfiles to create
         */
        const std::uintmax_t maxFileSize;

        /**
         * @brief The maximum size of each log file (in bytes)
         */
        const std::uintmax_t maxFileCount;

        /**
         * @brief The prefix of the log files which are created
         * @details This includes the path to the file, as well as the
         * file name itself, without any extension
         */
        const std::filesystem::path filePrefix;

        /**
         * @brief The file extension which is added to created files
         */
        const std::filesystem::path fileExtension;

        /**
         * @brief The currently active filestream addressing the most recent logfile (with index 1)
         */
        std::unique_ptr<std::ofstream> currentFileStream;

        /**
         * @brief The size of the currently opened log file (in bytes)
         * @details Used to keep track of the size of the currently opened log file, so that there is no need
         * to check the actual file system on each message write.
         */
        std::uintmax_t currentLogFileSize;

        /**
         * @brief See create() for creation of RotatingFileSink instances
         * @details Do not expose constructor, as we might encounter exceptions when creating the std::ofstream
         * Offer a static Factory Method instead
         */
        RotatingFileSink(
                const std::uintmax_t maxFileSize,
                const std::uintmax_t maxFileCount,
                const std::filesystem::path& filePrefix,
                const std::filesystem::path& fileExtension);

        /**
         * @brief Utility function that constructs the path for log files of a particular index
         * @param index The index of the file (1 <= index <= maxFileCount)
         * @return The path for the file of the supplied index
         */
        [[nodiscard]] inline std::filesystem::path filePath(std::uintmax_t index) const;

        /**
         * @brief Opens/Creates currentFileStream on the file identified by filePath(1) and sets mCurrentFileSize
         * accordingly
         * @return In case of an internal error, it is propagated here
         */
        [[nodiscard]] virtual std::error_code open();

        /**
         * @brief Performs the rotation of logfiles once
         * @details The oldest logfile (index maxFileCount), if it exists, is deleted.
         * Every other file is renamed, by incrementing its index (e.e. "log1.log" -> "log2.log").
         * open() is called to create a new logfile at index 1
         * @return In case of an internal error, it is propagated here
         */
        [[nodiscard]] virtual std::error_code rotateFiles();

    protected:
        /**
         * @see AbstractLoggingSink::doWriteMessage()
         */
        virtual void doWriteMessage(const std::string& message) override;

        /**
         * @see AbstractLoggingSink::doFlush()
         */
        virtual void doFlush() override;

        /**
         * @see semodia::controlengine::native::osal::tasking::BasicTaskLoopTask::iterate()
         */
        virtual void iterate() override;

    public:
        /**
         * @brief Creates a RotatingFileSink instance
         * @details The files will be named
         * "filePrefix + index + fileExtension", where 1 <= index <= maxFileCount
         * @param error If an error occurred during initialization the caller can track what exactly went wrong
         * @param maxFileSize The maximum size of each individual file (in bytes)
         * @param maxFileCount The maximum count of concurrently existing files
         * @param filePrefix the prefix of the files to be created, this includes the path to the file, as well as the
         * file name itself, without any extension
         * @param fileExtension The file extension which is added to created files
         * @return If the creation was successful, returns a std::optional containing the created object,
         * else std::nullopt is returned, see error for details in that case
         */
        static std::optional<std::shared_ptr<RotatingFileSink>> create(
            std::error_code& error,
            const std::uintmax_t maxFileSize,
            const std::uintmax_t maxFileCount,
            const std::filesystem::path& filePrefix,
            const std::filesystem::path& fileExtension);

        virtual ~RotatingFileSink();

        /**
         * @brief Disable copy constructor
         * @details The state of the underlying filestream is not trivially copyable and would produce weird behaviour
         */
        RotatingFileSink(RotatingFileSink& other) = delete;

        /**
         * @brief Disable assignment operator
         * @details The state of the underlying filestream is not trivially copyable and would produce weird behaviour
         */
        RotatingFileSink operator=(RotatingFileSink& other) = delete;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_ROTATINGFILESINK_HPP
