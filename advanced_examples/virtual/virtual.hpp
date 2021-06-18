#include <string>


class ExampleVirt  {
public:
    ExampleVirt(int state) : state(state) { }
    ExampleVirt(const ExampleVirt &e) : state(e.state) {  }
    ExampleVirt(ExampleVirt &&e) : state(e.state) {  }
    virtual ~ExampleVirt() {  }

    virtual int run(int value) {
        return state + value;
    }

    virtual bool run_bool() = 0;
    virtual void pure_virtual() = 0;

    // Returning a reference/pointer to a type converted from python (numbers, strings, etc.) is a
    // bit trickier, because the actual int& or std::string& or whatever only exists temporarily, so
    // we have to handle it specially in the trampoline class (see below).
    virtual const std::string &get_string1() { return str1; }
    virtual const std::string *get_string2() { return &str2; }

private:
    int state;
    const std::string str1{"default1"}, str2{"default2"};
};