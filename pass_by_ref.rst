.. _pass_by_ref:

pass_by_ref
###########

Often in C++, for a multitude of reasons, variables are passed by reference. This is largely supported
by pybind11 and Autopybind11, however, certain Python types such as `int` and `string` are immutable
and thus cannot be truly passed by reference. To circumnavigate this issue, classes and free functions
that use pass-by-ref idioms should specify ```pass_by_ref:True``` to Autopybind's wrapper input yaml file.
Autopybind11 will then capture ALL class/ff methods using reference arguments and pass ALL variables passed by ref
back to Python alongside any true return values from the C++ interface. These values will be composed into a tuple
object before being passed back to Python. So a function declaration

.. code-block:: c++

  int add(int &a, const int b);

would return in Python as

.. code-block:: python

  (a, return_value) = add(a,b)

Where any value in a c++ signature denoted as a reference value, would in included, in the order specified
in the signature, in the tuple passed back to Python

