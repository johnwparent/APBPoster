Templated Classes
#################

Templated classes are instantiated and bindings are generated based off the
instantiation types provided in the ``wrapper_input.yml`` . These instantiation
strings are used to generate a ``wrapper.hpp`` file.  This file, written by
AutoPyBind11 and used as the sole input to CastXML, contains the C++ code which
instantiates the templated classes and functions.

Templated Class Names
%%%%%%%%%%%%%%%%%%%%%

Class names in Python are then associated with the class in a manner such as
'class_name_double'.  To produce a custom name in Python that can dynamically
denote a type, Python Lambda functions are used. In place of a string based
name, a lambda defines functionally the custom name and schema for indicating
type and location of type indicator.

A good example of this for classes with single and double template parameters
can be found at ``tests/custom_names/wrapper_input.yaml`` in the AutoPyBind11 repository.

In order to have your lambda read by the yaml parser it must be defined
in ``wrapper_input.yml`` in the form:

'lambda <var name>: "any strings must have a double quote to be read as strings
and not literals" <rest of function>'
The '' is required to surround the entire lambda function.

If a lambda function is not optimal for use, a list of custom class names will
also be accepted in the form [custom name,different_custom_name]

The only requirements for this list is that there must be an equal number of
custom names to the number of type instatiations desired. If there is not, some
classes may not end up being wrapped.

Notes on Templates
%%%%%%%%%%%%%%%%%%%
The argument a custom naming lambda accepts is a Python list consisting of
strings listing each type parameter in a template.
e.x.  `["double", "float", "int"]` in an instance where a templated class has
three parameters.

For an example of a correctly written object, see the directories below `Tests`.
Each folder contains a valid YAML file and is used when the test is executed.
