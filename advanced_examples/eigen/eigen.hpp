#ifndef EIGEN_WRAP
#define EIGEN_WRAP

#include <Eigen/Cholesky>

using MatrixXdR = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

// Sets/resets a testing reference matrix to have values of 10*r + c, where r and c are the
// (1-based) row/column number.
template <typename M> void reset_ref(M &x) {
    for (int i = 0; i < x.rows(); i++) for (int j = 0; j < x.cols(); j++)
        x(i, j) = 11 + 10*i + j;
}

// Returns a static, column-major matrix
Eigen::MatrixXd &get_cm() {
    static Eigen::MatrixXd *x;
    if (!x) {
        x = new Eigen::MatrixXd(3, 3);
        reset_ref(*x);
    }
    return *x;
}
// Likewise, but row-major
MatrixXdR &get_rm() {
    static MatrixXdR *x;
    if (!x) {
        x = new MatrixXdR(3, 3);
        reset_ref(*x);
    }
    return *x;
}
// Resets the values of the static matrices returned by get_cm()/get_rm()
void reset_refs() {
    reset_ref(get_cm());
    reset_ref(get_rm());
}

// Returns element 2,1 from a matrix (used to test copy/nocopy)
double get_elem(Eigen::Ref<const Eigen::MatrixXd> m) { return m(2, 1); };


// Returns a matrix with 10*r + 100*c added to each matrix element (to help test that the matrix
// reference is referencing rows/columns correctly).
template <typename MatrixArgType> Eigen::MatrixXd adjust_matrix(MatrixArgType m) {
    Eigen::MatrixXd ret(m);
    for (int c = 0; c < m.cols(); c++)
        for (int r = 0; r < m.rows(); r++)
            ret(r, c) += 10*r + 100*c;  // NOLINT(clang-analyzer-core.uninitialized.Assign)
    return ret;
}

struct CustomOperatorNew {
    CustomOperatorNew() = default;

    Eigen::Matrix4d a = Eigen::Matrix4d::Zero();
    Eigen::Matrix4d b = Eigen::Matrix4d::Identity();

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
};
class ReturnTester {
    Eigen::MatrixXd mat = create();
public:
    ReturnTester() { }
    ~ReturnTester() { }
    static Eigen::MatrixXd create() { return Eigen::MatrixXd::Ones(10, 10); }
    static const Eigen::MatrixXd createConst() { return Eigen::MatrixXd::Ones(10, 10); }
    Eigen::MatrixXd &get() { return mat; }
    Eigen::MatrixXd *getPtr() { return &mat; }
    const Eigen::MatrixXd &view() { return mat; }
    const Eigen::MatrixXd *viewPtr() { return &mat; }
    Eigen::Ref<Eigen::MatrixXd> ref() { return mat; }
    Eigen::Ref<const Eigen::MatrixXd> refConst() { return mat; }
    Eigen::Block<Eigen::MatrixXd> block(int r, int c, int nrow, int ncol) { return mat.block(r, c, nrow, ncol); }
    Eigen::Block<const Eigen::MatrixXd> blockConst(int r, int c, int nrow, int ncol) const { return mat.block(r, c, nrow, ncol); }
};

#endif // EIGEN_WRAP
