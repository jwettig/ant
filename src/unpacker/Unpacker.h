#pragma once

#include <string>
#include <memory>
#include <list>

namespace ant {

class TDataRecord;

class Unpacker {

public:

    Unpacker() = delete;

    class Reader {
    public:
        virtual ~Reader() = default;
        virtual std::shared_ptr<TDataRecord> NextItem() noexcept = 0;
    };

    class Module : public Reader {
        friend class Unpacker;
    protected:
        virtual bool OpenFile(const std::string& filename) = 0;
    };

    // factory method to get a suitable unpacker module for the file
    static std::unique_ptr<Reader> Get(const std::string &filename);

    class Exception : public std::runtime_error {
        using std::runtime_error::runtime_error; // use base class constructor
    };
};

} // namespace ant
