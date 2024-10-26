#include <fmt/format.h>

class KafkaException : public std::exception
{
public:
    template <class Args> KafkaException(const std::string &what, Args &&args...) : message_(fmt::format(what, args)){};

    const char *what() const noexcept override { return message_.data(); }

private:
    std::string message_{};
};