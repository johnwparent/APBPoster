Installing AutoPyBind11
=======================

AutoPyBind11 can be painlessly installed via a few simple methods.

AutoPyBind11 is a heavily Python based utility, allowing for easy, straightforward, installation.

Installing via Python
---------------------

AutoPyBind11 can be easily installed from PyPi via pip.

Alternatively, a more involved approach can be used when installing AutoPyBind11. To install AutoPyBind11, clone the `repo`_
into a desired directory.
From that point, to install AutoPyBind11 into the site packages of a given Python environment
``pip install -e <path to APB source tree root>``. This will allow AutoPyBind11 to be called from the Python interpreter.
Further instructions for direct use can be found under useage.


The next option is generally more appropriate for those attempting to integrate
AutoPyBind11 into a new or existing CMake project, who chose to manage the dependency on APB via CMake, and is essentially a CMake wrapper around the process described above.

Installing via CMake
--------------------

CMake provides `External Project`_, a utility that exposes the ability to manage the installation of an external project at build time.
Alternatively, for a configure time option, the `FetchContent`_ module can be utilized. After specifying either of those commands correctly in CMake, AutoPyBind11 can be loaded into the project
via ``find_package`` without issue. When AutoPyBind11 has been loaded into the project, it can be installed via

.. code-block:: CMake


    execute_process(
        COMMAND
            ${PYTHON_EXECUTABLE} -m pip install ${autopybind11_SOURCE_DIR}
    )

If installing during build time rather than config time is preferable, then the `Custom Command`_ CMake functionality can be used.


CMake Integration
-----------------
AutoPyBind11 vendors a set of CMake utilities designed to provide an easy, straightforward interface to drive AutoPyBind11 from CMake, the suggested route of execution.

In order to faciliate this, AutoPyBind11 provides a CMake config file to allow AutoPyBind11 to be discoverable by the `find_package` CMake utility. However in order to use the config file
CMake needs to be able to find and reference it. This means providing CMake the file location.

This can be done one of two ways. The more straight forward method is simply to provide CMake with the location of the AutoPyBind11 CMake Config explicity by adding the location to any of the CMake
variables that can be set by a project during the config step to faciliate package location. More information about these variables and how to set them can be found in the `CMake Documentation`_.

This approach, while straightforward and fine for inidivual projects/one off uses, does not lend itself to more complex/pervasive useaege or system installation. To 'install'
AutoPyBind11 CMake, AutoPyBind11's CMake files need to be copied to a filesystem location that CMake consistenly searches for packages to load. This can vary per system and per user setup.
To determine these locations for a give system, refer to the CMake docs. AutoPyBind11 provides a convenience feature to help with this. On install via Python, a console script is created that can be run to
install the CMake files. It can be executed by
..code-block:: python

    autopybind11-cmake --dir <path to install>




Requirements:
#############

Python versions 3.4 or later and CMake 3.15 or newer are required to run this tool. There are a number of other requirements, that will be satisfied automatically by setuptools during the installation process


.. _External Project: https://cmake.org/cmake/help/latest/module/ExternalProject.html
.. _FetchContent: https://cmake.org/cmake/help/latest/module/FetchContent.html
.. _repo: https://gitlab.kitware.com/autopybind11/autpybind11
.. _Custom Command: https://cmake.org/cmake/help/latest/command/add_custom_command.html
.. _Cmake Documentation: https://cmake.org/cmake/help/latest