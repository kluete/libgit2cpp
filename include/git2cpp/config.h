#pragma once

#include <string>

struct git_config;

namespace git
{
    struct Config
    {
        explicit Config(std::string const & filename);
        ~Config();

        struct no_such_key_error : std::exception
        {
            explicit no_such_key_error(std::string key)
                : key_(std::move(key))
            {}

            virtual const char * what() const noexcept override
            {
                return "no such key in config";
            }

            std::string const & key() const { return key_; }

        private:
            std::string key_;
        };

        std::string operator[] (const char * key) const;

        int get_int(const char * key) const;

        Config              (Config const &) = delete;
        Config& operator =  (Config const &) = delete;

    private:
        git_config * cfg_;
    };
}
