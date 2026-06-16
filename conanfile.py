from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain, cmake_layout
from shutil import which


class Dragon2Conan(ConanFile):
    name = "dragon2"
    version = "3.1.0"
    package_type = "application"

    settings = "os", "arch", "compiler", "build_type"
    requires = (
        "gsl/2.7.1",
        "cfitsio/4.4.0",
    )

    generators = "VirtualBuildEnv"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        fortran_compiler = which("ifx") or which("ifort")
        if fortran_compiler:
            tc.cache_variables["CMAKE_Fortran_COMPILER"] = fortran_compiler.replace("\\", "/")
        tc.generate()
