.. _Useage:
AutoPyBind11 Useage
===================

AutoPyBind11's functionality can be used via two primary routes.

The first is directly through the Python interpreter.

AutoPyBind11 does not currently expose a user friendly API and it is recommended to use AutoPyBind11 via the provided CLI.
Additionaly the API is currently under fairly heavy development, and is not garunteed to be stable, and as such it is not recommended
to rely on the direct use of the API.

AutoPyBind11 does however, expose a rich CLI to drive the binding generation.
Running

.. code-block:: python

    python3 -m autopybind11 -h

after installation will bring up the list of CL options, and the associated manner in which they should be specified

.. code-block:: python


    usage: __main__.py [-h] [-o OUTPUT_DIR] -y YAML_PATH --module_name MODULE_NAME
        [-g CASTXML_PATH] [-cg CONFIG_DIR] -s {1,2} [-rs RSP_PATH]
        [-pm PM_FLAG] [-twf TWF_FLAG] [-ens ENS_FLAG]
        [-agns GNS_FLAG] [-stdexdec STDEXDEC_FLAG] [-aq AQ]
        [-td TD] [-exdec EXDEC] [-eds EDS_FLAG] [-ppw PW_FLAG]
        [-tpm TOP_MODULE] [--no_format]
        [--compiler_opts CLANG_OPTS]
        [--pass_eigen_by_ref EIGEN_REF]
        [--use_eigen_return_policy EIGEN_RET_POL]
        [--use_cxx_14 CXX14_FLAG]
        [--common_cpp_body_fmt COMMON_CPP_BODY_FMT]
        [--submodule_signature_fmt SUBMODULE_SIGNATURE_FMT]
        [--class_info_body_fmt CLASS_INFO_BODY_FMT]
        [--init_fun_signature_fmt INIT_FUN_SIGNATURE_FMT]
        [--init_fun_forward_fmt INIT_FUN_FORWARD_FMT]
        [--init_fun_forward_non_void_fmt INIT_FUN_FORWARD_NON_VOID_FMT]
        [--cppbody_fmt CPPBODY_FMT]
        [--class_module_cpp_fmt CLASS_MODULE_CPP_FMT]
        [--non_class_module_cpp_fmt NON_CLASS_MODULE_CPP_FMT]
        [--non_class_module_return_cpp_fmt NON_CLASS_MODULE_RETURN_CPP_FMT]
        [--member_func_fmt MEMBER_FUNC_FMT]
        [--constructor_fmt CONSTRUCTOR_FMT]
        [--member_func_arg_fmt MEMBER_FUNC_ARG_FMT]
        [--public_member_var_fmt PUBLIC_MEMBER_VAR_FMT]
        [--private_member_var_fmt PRIVATE_MEMBER_VAR_FMT]
        [--member_reference_fmt MEMBER_REFERENCE_FMT]
        [--overload_template_fmt OVERLOAD_TEMPLATE_FMT]
        [--wrap_header_fmt WRAP_HEADER_FMT]
        [--operator_fmt OPERATOR_FMT]
        [--call_operator_fmt CALL_OPERATOR_FMT]
        [--enum_header_fmt ENUM_HEADER_FMT]
        [--enum_val_fmt ENUM_VAL_FMT]
        [--tramp_override_fmt TRAMP_OVERRIDE_FMT]
        [--trampoline_def_fmt TRAMPOLINE_DEF_FMT]
        [--pybind_overload_macro_args_fmt PYBIND_OVERLOAD_MACRO_ARGS_FMT]
        [--copy_constructor_tramp_fmt COPY_CONSTRUCTOR_TRAMP_FMT]
        [--publicist_using_directives_fmt PUBLICIST_USING_DIRECTIVES_FMT]
        [--publicist_def_fmt PUBLICIST_DEF_FMT]
        [--module_init_fun_forward_fmt MODULE_INIT_FUN_FORWARD_FMT]
        [--module_init_fun_signature_fmt MODULE_INIT_FUN_SIGNATURE_FMT]
        [--submodule_init_fun_forward_fmt SUBMODULE_INIT_FUN_FORWARD_FMT]
        [--submodule_init_fun_signature_fmt SUBMODULE_INIT_FUN_SIGNATURE_FMT]
        [--submodule_init_fun_forward_non_void_fmt SUBMODULE_INIT_FUN_FORWARD_NON_VOID_FMT]
        [--submodule_init_fun_signature_return_fmt SUBMODULE_INIT_FUN_SIGNATURE_RETURN_FMT]
        [--repr_function_fmt REPR_FUNCTION_FMT]
        [--submodule_return SUBMODULE_RETURN]
        [--nullptr_arg_val_fmt NULLPTR_ARG_VAL_FMT]
        [--arg_val_cast_fmt ARG_VAL_CAST_FMT]
        [--module_local_fmt MODULE_LOCAL_FMT]
        [--keep_alive_fmt KEEP_ALIVE_FMT]
        [--generic_lambda_fmt GENERIC_LAMBDA_FMT]
        [--return_policy_fmt RETURN_POLICY_FMT]
        [--matrixDRef MATRIXDREF] [--shared_holder SHARED_HOLDER]
        [--unique_holder UNIQUE_HOLDER]
        [--attribute_fmt ATTRIBUTE_FMT]
        [--custom_ctor_fmt CUSTOM_CTOR_FMT]
        [--make_unique_fmt MAKE_UNIQUE_FMT]
        [--make_shared_fmt MAKE_SHARED_FMT]
        [--compose_unique COMPOSE_UNIQUE] [--conversion CONVERSION]
        [--generic_lambda_def_fmt GENERIC_LAMBDA_DEF_FMT]
        [--generic_return_fmt GENERIC_RETURN_FMT]
        [--move_fmt MOVE_FMT] [--make_tuple_fmt MAKE_TUPLE_FMT]
        [--template_setup_fn_fmt TEMPLATE_SETUP_FN_FMT]
        [--class_init_wrapper_fmt CLASS_INIT_WRAPPER_FMT]
        [--class_init_call_fmt CLASS_INIT_CALL_FMT]

        Args that start with '--' (eg. -o) can also be set in a config file (specified
        via -cg). The config file uses YAML syntax and must represent a YAML 'mapping'
        (for details, see http://learn.getgrav.org/advanced/yaml). If an arg is
        specified in more than one place, then commandline values override config file
        values which override defaults.

        optional arguments:
        -h, --help            show this help message and exit
        -o OUTPUT_DIR, --output OUTPUT_DIR
        -y YAML_PATH, --input_yaml YAML_PATH
            Path to input YAML file of objects to process
        --module_name MODULE_NAME
            Desired name of the output PyBind11 module
        -g CASTXML_PATH, --castxml-path CASTXML_PATH
            Path to castxml
        -cg CONFIG_DIR, --config-path CONFIG_DIR
            config file path
        -s {1,2}, --stage {1,2}
        -rs RSP_PATH, --input_response RSP_PATH
        -pm PM_FLAG, --private_members_as_fields PM_FLAG
        -twf TWF_FLAG, --use_template_wrapping_function TWF_FLAG
        -ens ENS_FLAG, --enforce_namespace_structure ENS_FLAG
        -agns GNS_FLAG, --apply_global_namespace GNS_FLAG
        -stdexdec STDEXDEC_FLAG, --expand_stl_declaration STDEXDEC_FLAG
        -aq AQ, --assumed_qualifiers AQ
        -td TD, --template_defaults TD
        -exdec EXDEC, --expand_declarations EXDEC
        -eds EDS_FLAG, --enable_doc_strings EDS_FLAG
        -ppw PW_FLAG, --print_python_warnings PW_FLAG
        -tpm TOP_MODULE, --top_python_module TOP_MODULE
            Name of module this python package will be added to
        --no_format           Do not attempt to use clang-format to format the
            output files
        --compiler_opts CLANG_OPTS
            Specify additional compiler arguments to be passed to
            Clang/LLVM via CastXML
        --pass_eigen_by_ref EIGEN_REF, -epbr EIGEN_REF
            Toogle the use of Eigen PBR via Eigen::Ref<MarixType>
        --use_eigen_return_policy EIGEN_RET_POL, -erp EIGEN_RET_POL
            Toggle use of return policy for returning Eigen types
        --use_cxx_14 CXX14_FLAG, -cxx14 CXX14_FLAG
            Enable cxx14 standard features, if turned off, cxx11
            is assumed
        --common_cpp_body_fmt COMMON_CPP_BODY_FMT
        --submodule_signature_fmt SUBMODULE_SIGNATURE_FMT
        --class_info_body_fmt CLASS_INFO_BODY_FMT
        --init_fun_signature_fmt INIT_FUN_SIGNATURE_FMT
        --init_fun_forward_fmt INIT_FUN_FORWARD_FMT
        --init_fun_forward_non_void_fmt INIT_FUN_FORWARD_NON_VOID_FMT
        --cppbody_fmt CPPBODY_FMT
        --class_module_cpp_fmt CLASS_MODULE_CPP_FMT
        --non_class_module_cpp_fmt NON_CLASS_MODULE_CPP_FMT
        --non_class_module_return_cpp_fmt NON_CLASS_MODULE_RETURN_CPP_FMT
        --member_func_fmt MEMBER_FUNC_FMT
        --constructor_fmt CONSTRUCTOR_FMT
        --member_func_arg_fmt MEMBER_FUNC_ARG_FMT
        --public_member_var_fmt PUBLIC_MEMBER_VAR_FMT
        --private_member_var_fmt PRIVATE_MEMBER_VAR_FMT
        --member_reference_fmt MEMBER_REFERENCE_FMT
        --overload_template_fmt OVERLOAD_TEMPLATE_FMT
        --wrap_header_fmt WRAP_HEADER_FMT
        --operator_fmt OPERATOR_FMT
        --call_operator_fmt CALL_OPERATOR_FMT
        --enum_header_fmt ENUM_HEADER_FMT
        --enum_val_fmt ENUM_VAL_FMT
        --tramp_override_fmt TRAMP_OVERRIDE_FMT
        --trampoline_def_fmt TRAMPOLINE_DEF_FMT
        --pybind_overload_macro_args_fmt PYBIND_OVERLOAD_MACRO_ARGS_FMT
        --copy_constructor_tramp_fmt COPY_CONSTRUCTOR_TRAMP_FMT
        --publicist_using_directives_fmt PUBLICIST_USING_DIRECTIVES_FMT
        --publicist_def_fmt PUBLICIST_DEF_FMT
        --module_init_fun_forward_fmt MODULE_INIT_FUN_FORWARD_FMT
        --module_init_fun_signature_fmt MODULE_INIT_FUN_SIGNATURE_FMT
        --submodule_init_fun_forward_fmt SUBMODULE_INIT_FUN_FORWARD_FMT
        --submodule_init_fun_signature_fmt SUBMODULE_INIT_FUN_SIGNATURE_FMT
        --submodule_init_fun_forward_non_void_fmt SUBMODULE_INIT_FUN_FORWARD_NON_VOID_FMT
        --submodule_init_fun_signature_return_fmt SUBMODULE_INIT_FUN_SIGNATURE_RETURN_FMT
        --repr_function_fmt REPR_FUNCTION_FMT
        --submodule_return SUBMODULE_RETURN
        --nullptr_arg_val_fmt NULLPTR_ARG_VAL_FMT
        --arg_val_cast_fmt ARG_VAL_CAST_FMT
        --module_local_fmt MODULE_LOCAL_FMT
        --keep_alive_fmt KEEP_ALIVE_FMT
        --generic_lambda_fmt GENERIC_LAMBDA_FMT
        --return_policy_fmt RETURN_POLICY_FMT
        --matrixDRef MATRIXDREF
        --shared_holder SHARED_HOLDER
        --unique_holder UNIQUE_HOLDER
        --attribute_fmt ATTRIBUTE_FMT
        --custom_ctor_fmt CUSTOM_CTOR_FMT
        --make_unique_fmt MAKE_UNIQUE_FMT
        --make_shared_fmt MAKE_SHARED_FMT
        --compose_unique COMPOSE_UNIQUE
        --conversion CONVERSION
        --generic_lambda_def_fmt GENERIC_LAMBDA_DEF_FMT
        --generic_return_fmt GENERIC_RETURN_FMT
        --move_fmt MOVE_FMT
        --make_tuple_fmt MAKE_TUPLE_FMT
        --template_setup_fn_fmt TEMPLATE_SETUP_FN_FMT
        --class_init_wrapper_fmt CLASS_INIT_WRAPPER_FMT
        --class_init_call_fmt CLASS_INIT_CALL_FMT

Each option and its functionality is detailed and documented futher and can be found under its section in this documentation.

It should be noted that the config file (documented elsewhere) can be utilized to control many of the variables listed above, significantly reducing the verbosity of the
CL interface. However, if an argument is specified by both the CL and a config file, the value of the argument specified on the CL will replace whatever is set by the config.
As such, using one or the other is recommended, although not enforced.

When using the CLI option to run AutoPyBind11 a call will need to be made per binding wrapper input file, which can quickly grow tedious, and is not particularly maintainable.

To ease this, AutoPyBind11 provides a number of CMake utilities to integrate AutoPyBind11 into a CMake project.

AutoPyBind11 provides an AutoPyBind11Config.cmake file for easy loading into a project via the `find_package`_ command. When AutoPyBind11 is loaded, it loads an number of convenient
CMake utility functions.

Prior to executing any actual biding generation with AutoPyBind11, AutoPyBind11 needs to either install, or be made aware of an existing PyBind11 installation. This can be done by calling::

    autopybind11_fetch_build_pybind([PYBIND_DIR <Path to PyBind11 or directory of desired install>]}

Once APB is aware of, or has installed, PyBind11, calls to generate binding code can be made. AutoPyBind11 provides a CMake function ``autopybind11_add_module`` whose signature is::

    autopybind11_add_module(<module name>
                            YAML_INPUT <location of wrapper yaml file>
                            [CONFIG_INPUT <location of config yaml file>]
                            DESTINATION <desired output directory for binding code and finished module libraries>
                            LINK_LIBRARIES <cmake targets or libraries that this binding code should link against/include or other python modules generated by APB with dependencies required by this module>
                            [INCLUDE_DIRS <space seperated list of extra include directories to be provided to the APB compiler>]
                            [GEN_ONLY]
                        )

``GEN_ONLY`` is an argument that should be specified in order to prevent APB from performing any building of the Python module library and instead stop short after generating the PyBind11 binding code.
More details can be found under the GEN_ONLY tab.


In addition to generating instructions for the build time generation and compilation of the binding code, a CMake target is created, named after the provided module name, that can in turn
be used to build other modules, or treated like any other CMake target.

.. _`find_package`: https://cmake.org/cmake/help/v3.20/command/find_package.html
