#pragma once

extern "C"
{
#include <git2/strarray.h>
}

namespace git
{
    struct StrArray
    {
        explicit StrArray(git_strarray const & str_array)
            : str_array_(str_array)
        {}

        size_t count() const { return str_array_.count; }

        const char * operator [] (size_t i) const
        {
            return str_array_.strings[i];
        }

        ~StrArray()
        {
            git_strarray_free(&str_array_);
        }

    private:
        git_strarray str_array_;
    };
}
