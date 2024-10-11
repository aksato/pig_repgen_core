from conan import ConanFile
from conan.tools.cmake import cmake_layout

class MesonQtInjaConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("inja/3.4.0")
        self.requires("sqlitecpp/3.3.2")

    def layout(self):
        cmake_layout(self)