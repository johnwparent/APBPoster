Clang/LLVM Compiler Options
###########################

AutoPyBind11, as mentioned above, uses CastXML to parse the C++ AST generated
by provided C++ files. CastXML uses the Clang/LLVM compiler to accomplish this.
As such, options that can be specified on the CLang/LLVM command line, can be forwarded
to CastXML from AutoPybind11. To accomplish this the user has a few options.

From CMake:
%%%%%%%%%%%

A custom CMake target can be created, and the target property `APB_COMPILER_OPTIONS` set to a string
representation of Clang CL arguments such as ```-Wunused -Werror```.

From the command line:
%%%%%%%%%%%%%%%%%%%%%%

The autopybind11 command line argument ``--compiler-opts`` can be set to a string representation
of Clang compiler CL arguments much as the CMake example above.

From the config file:
%%%%%%%%%%%%%%%%%%%%%

The final option for setting Clang compiler CL options is via the config.yml input file provided
to APB.  Options should be set via the ``compiler_opts: -Wall -Werror`` mapping syntax
used by config.

These options are intended to provide more configurablity at the CastXML compiler stage,
particularly to supress unwanted output in large builds, or add extra garuntees from code that is
to be wrapper.
