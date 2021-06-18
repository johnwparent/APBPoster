#include <string>

namespace pets {
class Pet {
public:
    Pet(std::string name) : name_(name) {}
    std::string name_;
    const std::string &name() { return name_; }
};
} // namespace pets

struct MixGL { int i; MixGL(int i) : i{i} {} };
struct MixGL2 { int i; MixGL2(int i) : i{i} {} };