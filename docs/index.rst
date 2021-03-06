.. AutoPyBind11 documentation master file, created by
   sphinx-quickstart on Mon Jun 21 00:33:31 2021.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to AutoPyBind11's documentation!
========================================

A C++ to Python interoperability convenience tool.


AutoPyBind11 is a lightweight python based tool designed to simplify the process of generating and maintaining Python bindings for C++.

AutoPyBind11 takes C++ source code and associated, user generated, descriptor files, and produces `PyBind11`_ binding code, which are then compiled into
libraries containing a Python module representation of the provided C++.


`PyBind11`_ is a C++ header only library that supports the binding and exposure of C++ code to Python.

This tree serves as partial documentation and a tutorial for the use of AutoPyBind11, and the source code can be found `here`_

AutoPyBind11 is an active and ongoing effort, and as of the writing of this document, there is no extant stable version, and API/useage details are apt to change with minimal warning.


AutoPyBind11 provides as close to a complete coverage of PyBind11's features as is possible, and more covereage is being added consistently.

.. image:: https://mybinder.org/badge_logo.svg
 :target: https://mybinder.org/v2/gh/johnwparent/APBPoster.git/master


.. toctree::
   :maxdepth: 2
   :caption: Get Started:

   installing
   useage
   wrapper_yaml

.. toctree::
   :maxdepth: 2
   :caption: Advanced:

   config_file
   customization
   compiler_options
   keep_alive
   module_structure
   pass_by_ref
   templated_classes





Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`



.. _Here: https://gitlab.kitware.com/autopybind11/autopybind11

.. _PyBind11: https://github.com/pybind/pybind11