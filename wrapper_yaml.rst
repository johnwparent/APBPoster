The Descriptor File:
====================

AutoPyBind11's interface is largely encompassed by a single `Yaml`_ file that describes that C++ code to be exposed as a Python module.

This descriptor file dictates to AutoPyBind11 which C++ components should be bound, their structure, and the files declaring these symbols, as well
as information about how to bind and represent these types on the Python side.

This is the most important, and really only required component of AutoPyBind11 specified by the user.


Selecting C++ Objects
######################
The setup for the C++ code to be wrapped is simple. Each C++ directory with content
to be wrapped should contain a file named ``wrapper_input.yml``.
This content should describe the classes, "free" functions
(functions that are not a part of a class), and non-typed enumerations.

This information follows a certain structure.  There are a few reserved keywords

+-----------------------------+---------------------------------+
|           Keyword           |      Expected Data              |
+=============================+=================================+
|          `files`            |  A set of C++ header files      |
|                             |  which contains the objects to  |
|                             |  be wrapped                     |
|                             |                                 |
|                             |  Placed Under:                  |
+-----------------------------+---------------------------------+
|         `namespaces`        |  A set of strings which are the |
|                             |  namespaces which contains the  |
|                             |  objects to be wrapped          |
|                             |                                 |
|                             |  Placed Under: `files`          |
|                             |                `namespaces`     |
+-----------------------------+---------------------------------+
|         `classes`           |  Descriptive information which  |
|                             |  describes the class object to  |
|                             |  be wrapped                     |
|                             |                                 |
|                             |  Placed Under: `files`          |
|                             |                `namespaces`     |
+-----------------------------+---------------------------------+
|         `functions`         |  Descriptive information which  |
|                             |  describes the function object  |
|                             |  to be wrapped                  |
|                             |                                 |
|                             |  Placed Under: `files`          |
|                             |                `namespaces`     |
+-----------------------------+---------------------------------+
|         `enums`             |  Descriptive information which  |
|                             |  describes the enumeration      |
|                             |  object to be wrapped           |
|                             |                                 |
|                             |  Placed Under: `files`          |
|                             |                `namespaces`     |
+-----------------------------+---------------------------------+

An skeleton of a properly formed YAML file can be seen below. To see additional
examples, see the `Tests` directory of the AutoPyBind11 repository.

.. parsed-literal::

    files:
      <file_name>:
        namespaces:
          <namespace>:
            classes:
              <class_name>:
                <class_data>
              <class_2_name>:
                <class_2_data>
            functions:
              <function_name>:
                <function_data>
        namespaces:
          <namespace_2>:
            enums:
              <enum_name>:
                <enum_data>

Each type of object within the reserved tags requires different pieces of information:

+-----------------------------+---------------------------------+
|           C++ Object        |      Required YAML pieces       |
+=============================+=================================+
|           Class             | inst: []                        |
|                             |   List of instantiation types   |
|                             |   for class.                    |
|                             |   Leave blank for non-templated |
+-----------------------------+---------------------------------+
|        Function             | is_template: <bool>             |
|                             |  "true" if function is template |
|                             |  "false" otherwise              |
|                             +---------------------------------+
|                             | inst: []                        |
|                             |   List of instantiation types   |
|                             |   for function, if is_template  |
|                             |   is true                       |
+-----------------------------+---------------------------------+
|        Enumeration          |  <No additional information>    |
+-----------------------------+---------------------------------+

An "empty" object, for example, the `simple` class or the enumeration `test`
in the following example are treated as non-templated objects::

  classes:
    simple:
  namespaces:
    first:
      enums:
        test:


Further information can be specified in a Yaml file, but this represents a bare bones example, which should be sufficent to prototype a Python representation of a C++ module.

In addition to the inst field that can be specified for templated types/functions, the wrapper supports a complex customization field that allows for fairly granular customization and
and alteration of the generated binding code objects. The customization is documented further at: __customization__



.. _`Yaml`: https://yaml.org/
