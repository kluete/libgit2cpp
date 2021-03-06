#pragma once

#include <cstddef>

struct git_blob;
struct git_repository;
struct git_oid;

namespace git
{
    struct Blob
    {
        explicit Blob(git_blob *);
        Blob(git_oid const & oid, git_repository * repo);
        ~Blob();

        std::size_t     size()      const;
        const void *    content()   const;

        Blob& operator =    (Blob const &) = delete;
        Blob                (Blob const &) = delete;

        Blob(Blob &&);

    private:
        git_blob * blob_;
    };
}
