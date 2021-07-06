
enum UnscopedEnum {
    EOne = 1,
    ETwo,
    EThree
};

enum class ScopedEnum {
    Two = 2,
    Three
};

enum Flags {
    Read = 4,
    Write = 2,
    Execute = 1
};

class ClassWithUnscopedEnum {
public:
    enum EMode {
        EFirstMode = 1,
        ESecondMode
    };

    static EMode test_function(EMode mode) {
        return mode;
    }
};