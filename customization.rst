Customize Output
#####################

Customization of the output of AutoPyBind11 can occur at two levels:
at the code level and at the object level.

Object Customization
%%%%%%%%%%%%%%%%%%%%

Each C++ object also has an optional ``customization`` field. This allows for
additional customization of the Python object generated. For example, to
customize the Python name of a C++ class, the ``name`` sub-field can be used::

  classes:
    Foo:
      file: Foo.hpp
      customization:
        name: Foobar

The above would name the C++ class ``Foo`` as ``Foobar`` on the Python side.

If generating a python package that may have naming conflicts with another
package, the ``module local`` option can be turned on.  This is done simply
by specifying the ``module_local`` field in ``customization`` i.e. ::

  classes:
    Foo:
      file: Foo.hpp
      customization:
        module_local

For the total list of what can be customized, see the following table:

+-----------------------------+---------------------------------+
|     Customization Key       |          Description            |
+=============================+=================================+
|        module_local         | No "value" given, the presence  |
|                             | of the flag will trigger the    |
|                             | addition                        |
|                             +---------------------------------+
|                             | Example:                        |
|                             |                                 |
|                             |    customization:               |
|                             |      module_local               |
|                             |                                 |
+-----------------------------+---------------------------------+
|        keep_alive           | Adds ``py::keep_alive`` to the  |
|                             | PyBind11 code for the object    |
|                             |                                 |
|                             | See keep_alive section below    |
|                             | for more information            |
+-----------------------------+---------------------------------+
|        name                 | A string to denote the class    |
|                             | on the Python side              |
|                             |                                 |
|                             +---------------------------------+
|                             | Example:                        |
|                             |                                 |
|                             |   customization                 |
|                             |     name: free_templ_add        |
|                             |                                 |
|                             |                                 |
+-----------------------------+---------------------------------+
|        custom_enum_vals     | Pairs of strings, the first     |
|                             | the name of the value in C++,   |
|                             | followed by the desired name    |
|                             | in Python                       |
|                             |                                 |
|                             +---------------------------------+
|                             | Example:                        |
|                             |                                 |
|                             |    customization:               |
|                             |      custom_enum_vals:          |
|                             |        val1: One                |
|                             |        val2: Second             |
+-----------------------------+---------------------------------+
|        export_enum_vals     | Adds ``.export_values()``       |
|                             | function call to the end of the |
|                             | binding of an enumeration       |
|                             |                                 |
|                             |                                 |
|                             +---------------------------------+
|                             | Example:                        |
|                             |    customization:               |
|                             |      export_enum_vals           |
+-----------------------------+---------------------------------+
| All Enum Customization                                        |
+---------------------------------------------------------------+
| In addition to the above syntax, enum cuztomization can all   |
| be specified under the same field names ``enums``             |
|                                                               |
+-----------------------------+---------------------------------+
|         skiplist            | Members to be excluded          |
|                             | from the generated binding code |
|                             +---------------------------------+
|                             | Example:                        |
|                             |                                 |
|                             |   customization:                |
|                             |     skiplist:                   |
|                             |       member_functions:         |
|                             |                                 |
|                             |       member_variables:         |
|                             |                                 |
|                             |       operators:                |
|                             |                                 |
+-----------------------------+---------------------------------+
|      custom_holder_type     | Example:                        |
|                             |                                 |
|                             |   customization:                |
|                             |       custom_holder_type:       |
|                             |         "std::shared_ptr<{}>"   |
+-----------------------------+---------------------------------+
|      attributes             | Add an attribute to Python side |
|                             | that is not present in C++ code |
|                             |                                 |
|                             +---------------------------------+
|                             | Example:                        |
|                             |   customization:                |
|                             |       attributes:               |
|                             |         "__custAtt__": "Att1"   |
|                             |         "__custAtt2__": "Att2"  |
+-----------------------------+---------------------------------+
|      pass_by_ref            | Enable pass by reference for    |
|                             | Python immutable types          |
|                             |                                 |
|                             +---------------------------------+
|                             | Example:                        |
|                             |     customization:              |
|                             |         pass_by_ref:  True      |
|                             |                                 |
+-----------------------------+---------------------------------+
|      namespace              | The namespace/module structure  |
|                             | an object should belong to      |
|                             |                                 |
|                             | More more info and examples     |
|                             | refer to module_structure       |
|                             | section                         |
+-----------------------------+---------------------------------+
|    method_inst              | Handles the instantiating of    |
|                             | templated members               |
|                             |                                 |
|                             | The syntax follows templating   |
|                             | for the general class case      |
|                             +---------------------------------+
|                             | customization:                  |
|                             |   method_inst:                  |
|                             |     simpleTemplate: [float, int]|
|                             |     simple: [[float,float]]     |
|                             |                                 |
|                             |                                 |
+-----------------------------+---------------------------------+

