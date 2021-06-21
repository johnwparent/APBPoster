Installing AutoPyBind11
=======================

AutoPyBind11 can be painlessly installed via a few simple methods.

AutoPyBind11 is a heavily Python based utility, allowing for easy, straightforward, installation.

As of the writing of this documentation, installation via PyPi is a work in progress, but is not currently available.
However, Pip can still drive the installation of APB.

There are two avenues to install AutoPyBind11 on a system.

Alternatively, a more Python based approach can be used when installing AutoPyBind11. To install AutoPyBind11, clone the `repo`_
into a desired directory.
From that point, to install AutoPyBind11 into the site packages of a given Python environment
``pip install -e <path to APB source tree root>``. This will allow AutoPyBind11 to be called from the Python interpreter.
Further instructions for direct use can be found under useage.


The next option is generally more appropriate for those attempting to integrate
AutoPyBind11 into a new or existing CMake project, who chose to manage the dependency on APB via CMake, and is essentially a CMake wrapper around the process described above.

CMake provides `External Project`_, a utility that exposes the ability to manage the installation of an external project at build time.
Alternatively, for a configure time option, the `FetchContent`_ module can be utilized. After specifying either of those commands correctly in CMake, AutoPyBind11 can be loaded into the project
via ``find_package`` without issue. When AutoPyBind11 has been loaded into the project, it can be installed via

.. code-block:: CMake


    execute_process(
        COMMAND
            ${PYTHON_EXECUTABLE} -m pip install ${autopybind11_SOURCE_DIR}
    )

If installing during build time rather than config time is preferable, then the `Custom Command`_ CMake functionality can be used.


Requirements:

Python versions 3.4 or later and CMake 3.15 or newer are required to run this tool. There are a number of other requirements, that will be satisfied automatically by setuptools during the installation process


.. _External Project: https://cmake.org/cmake/help/v3.20/module/ExternalProject.html
.. _FetchContent: https://cmake.org/cmake/help/v3.20/module/FetchContent.html
.. _repo: https://gitlab.kitware.com/autopybind11/autpybind11
.. _Custom Command: https://cmake.org/cmake/help/v3.20/command/add_custom_command.html
