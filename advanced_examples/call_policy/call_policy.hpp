
class Child {
public:
    Child() {  }
    Child(const Child &) = default;
    Child(Child &&) = default;
    ~Child() {  }
};

class Parent {
public:
    Parent() {  }
    Parent(const Parent& parent) = default;
    ~Parent() {  }
    void addChild(Child *) { }
    Child *returnChild() { return new Child(); }
    Child *returnNullChild() { return nullptr; }
};