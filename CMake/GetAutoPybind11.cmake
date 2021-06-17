set(PYBIND11_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pybind11)

find_package(Python3 REQUIRED)
execute_process(COMMAND "${Python3_EXECUTABLE} -m pip install castxml")

include(FetchContent)
FetchContent_Declare(
    AutoPyBind11
    GIT_REPOSITORY https://gitlab.kitware.com/autopybind11/autopybind11.git
    GIT_TAG 3d9e30908ead769846f352da4ca6a900e9d2c056
)


FetchContent_MakeAvailable(AutoPyBind11)
execute_process(
    COMMAND ${PYTHON_EXECUTABLE} -m pip install -e ${autopybind11_SOURCE_DIR}
)
autopybind11_fetch_build_pybind11(PYBIND11_DIR ${PYBIND11_DIR})

include(${CMAKE_CURRENT_BINARY_DIR}/_deps/autopybind11-src/.gitlab/ci/eigen.cmake)
