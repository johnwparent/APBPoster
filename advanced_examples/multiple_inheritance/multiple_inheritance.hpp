struct Base1a {
    Base1a(int i) : i(i) { }
    int foo() { return i; }
    int i;
};
struct Base2a {
    Base2a(int i) : i(i) { }
    int bar() { return i; }
    int i;
};
struct Base12a : Base1a, Base2a {
    Base12a(int i, int j) : Base1a(i), Base2a(j) { }
};