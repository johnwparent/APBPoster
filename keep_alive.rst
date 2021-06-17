keep_alive
^^^^^^^^^^

For all objects, the keep_alive customization is a dictionary with pairs of
lists to describe the additions. Each object should have the name of the
function as the "key" object.  For a class constructor, this is the name
of the class.

The paired lists which contain the actual data are ``num_arguments`` and
``pairings``.  The num_arguments should be an integer which is the number of
arguments for the version of the function that should receive the
``keep_alive`` tag.  For the ``pairings`` list, each entry should be a list of
strings which corresponds directly to the number of arguments found in the
same index.
This string should contain the two reference values separated by a semicolon.

For example::

  customization:
    keep_alive:
      simple:
        num_arguments: [1, 2]
        pairings: [["1;2"],["1;2","1;3"]]

This will expect two instances of the function ``simple``: one with a single
argument, one with two arguments. The single argument will tranform "1;2" into
``py::keep_alive<1,2>()`` when the function is written.
The two argument version will tranform ["1;2","1;3"]] into
``py::keep_alive<1,2>(), py::keep_alive<1,3>()`` when the function is written.

