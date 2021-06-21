Configuring AutoPyBind11
========================

AutoPyBind11 has a number of configurable options, settings, and binding code blocks that can be set/changed by a user via configuration.

The user has two options for specifiying these settings, either via the CLI, or via a configuration file using `Yaml`_ syntax(recommended).


The `Useage`_ section lists the number of CL options provided by AutoPyBind11 to configure the tool's function, and they range from toggling features
to specifying code blocks to use for specific components of the binding code. This section will cover each option for configuring AutoPyBind11, it's options, and
the variying methods for specifiying each option.



When specifiying options via the CL, the options can be set as you would a typical CL option for a Python program, however, there are many options and a number of these options are long, multi-line strings
neither of which allow for a clean, manageable CLI exeperience. The Yaml file approach is the recommended approach for specifying a number of these options.

The configuration yaml file itself is an optional CL option, and as mentioned in the useage section, options can be specified in both the config file and the CL, but CL options will
overwrite whatever is specified by the YAML. If an option is specified by the config file, it does not need to be included in the CLI and vice versa. If the CMake interface is chosen, then the
CLI cannot be used at all, and in order to configure AutoPyBind11, the ``CONFIG_INPUT`` argument to the ``autopybind11_add_module`` command must be provided the location of a config file.


Option list:

+------------------------------+---------------------------------------+
|     Options                  | Useage and Meaning                    |
+==============================+=======================================+
| enforce_namespace_structure  | ``False`` to place all found          |
|                              |   objects at the module level.        |
|                              | ``True`` will enforce the             |
|                              |   C++ namespace structure on the      |
|                              |   Python Code.                        |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              | enforce_namespace_structure: true     |
+------------------------------+---------------------------------------+
| private_members_as_fields    | ``False`` to bind getters and         |
|                              | setters as normal.                    |
|                              | ``True`` to bind                      |
|                              | the corresponding private member      |
|                              | variables as public members.          |
|                              |                                       |
|                              | See `Pybind11's Documentation`_       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |     private_members_as_fields: true   |
|                              |                                       |
+------------------------------+---------------------------------------+
| enable_doc_strings           | ``False`` to not supply doc           |
|                              | strings from the C++ code             |
|                              | ``True`` to pass C++ comments         |
|                              | from the source code as doc           |
|                              | strings to the Python code.           |
|                              |                                       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |    enable_doc_strings: false          |
|                              |                                       |
+------------------------------+---------------------------------------+
| expand_declarations          | ``False`` to limit output of          |
|                              | binding code to as minimally          |
|                              | verbose output as possible,           |
|                              | ``True`` (default) to produce         |
|                              | binding code with declarations        |
|                              | fully expanded by compiler.           |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |    expand_declarations: False         |
+------------------------------+---------------------------------------+
| expand_stl_declarations      | ``False`` to reduce binding code      |
|                              | of stl declarations to minimal        |
|                              | verbosity, removing any expansion     |
|                              | of default params                     |
|                              | ``True`` to allow stl default         |
|                              | and fully expanded declarations       |
|                              | in binding code.                      |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |  expand_stl_declarations: False       |
+------------------------------+---------------------------------------+
| apply_global_namespace       | ``False`` to remove all instances     |
|                              | of the global namespace qualifier     |
|                              | ``True`` to allow the GNS to          |
|                              | persist.                              |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |  apply_global_namespace: False        |
+------------------------------+---------------------------------------+
| assumed_qualifiers           | Default is an empty list.             |
|                              | Add scoping qualifier to list to      |
|                              | remove qualifier(including GNS)       |
|                              | from the binding output.              |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |   assumed_qualifiers: ["First"]       |
+------------------------------+---------------------------------------+
| template_defaults            | Default is an empty list              |
|                              | Each entry in list specifies a        |
|                              | templated type with default           |
|                              | parameters and for each template      |
|                              | parameter a value of 1 or 0           |
|                              | indicating whether or not that        |
|                              | param will be included in the         |
|                              | binding output. References to         |
|                              | params are done in order and all      |
|                              | parameters must be specified.         |
|                              +---------------------------------------+
|                              | Useage :                              |
|                              |  template_defaults:"Eigen::Ref|1,0,0" |
+------------------------------+---------------------------------------+
|  use_cxx_14                  | Toggle cxx14 compiler dependent       |
|                              | features such as ``make_unique`` or   |
|                              | ``make_shared``. Default is true      |
|                              | Can be disabled if only cxx11         |
|                              | features are available.               |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |   use_cxx_14: True                    |
+------------------------------+---------------------------------------+
| pass_eigen_by_ref            | Eigen types are passed to/from C++    |
|                              | via potentially expensive copy        |
|                              | operations. PyBind11 supports         |
|                              | Eigen::Ref semantics to facilitate    |
|                              | passing Eigen types by thin reference.|
|                              | Default is True                       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |   pass_eigen_by_ref: False            |
+------------------------------+---------------------------------------+
| use_eigen_return_policy      |  PyBind11 has the concept of return   |
|                              |  policies that dictate how objects    |
|                              |  return to Python are handled. Eigen  |
|                              |  types returned by l-value ref are    |
|                              |  copied. Enabling this option ensures |
|                              |  return values are referenced instead.|
|                              |  Default:  True                       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |    use_eigen_return_policy: True      |
|                              |                                       |
+------------------------------+---------------------------------------+
| compiler_opts                | AutoPyBind11 uses LLVM-Clang via      |
|                              | CastXML to compile C++ files before   |
|                              | generating the binding code. Specify  |
|                              | arguments to pass to the compiler.    |
|                              |                                       |
|                              | Default: None                         |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |   compiler_opts: -Werror -Wunintialize|
|                              |                                       |
+------------------------------+---------------------------------------+
|  print_python_warnings       | AutoPyBind11 uses Pygccxml under the  |
|                              | hood. This option supresses warnings  |
|                              | raised by pygccxml.                   |
|                              | Default: True                         |
|                              |                                       |
|                              |                                       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |    print_python_warnings: False       |
|                              |                                       |
+------------------------------+---------------------------------------+
|  no_format                   | AutoPyBind11 leverages clang-format   |
|                              | to format the output files containing |
|                              | the binding code. This option disables|
|                              | or enables the use of clang-format.   |
|                              | Default: False                        |
|                              |                                       |
|                              |                                       |
|                              +---------------------------------------+
|                              | Useage:                               |
|                              |    no_format: True                    |
+------------------------------+---------------------------------------+

.. _`Yaml`: https://yaml.org/
.. _`PyBind11's Documentation`: https://pybind11.readthedocs.io/en/stable/classes.html#instance-and-static-fields