# Library MDF version 2.0

## Summary

The MDF library repository implements an interface against the ASAM Measurement Data File (MDF). 
It supports reading and writing of MDF files version 3 and 4. 
The release 2.0 of the project support reading and writing of MDF files up to version 4.2. 

The main project is a C++ static library and its used applications.
- **MDF Viewer**. Simple GUI application that list the contents of an MDF file. 
- **MDF .NET (C++/CLI) Assembly**. Basic reading of MDF files for .NET friends. 
- **MDF gRPC Server**. Microservice for reading and writing of MDF files. On request.
- **MDF Python Library**. Basic reading and writing for Python friends. On request or use the ASAMMDF library.

The library and its applications, compiles/runs on Windows, Linux and Mac operating system. 
The .NET library only runs on Windows operating system.

## Installation

[Windows Install (exe)](https://github.com/ihedvall/mdflib/releases/download/v2.0.%2C0/mdflib.exe)

## Building

Most project uses CMAKE for building. But mdflibrary_test_net need to build with Visual Studio.

The following third-party libraries are improted by [vcpkg](https://github.com/microsoft/vcpkg).
- ZLIB Library.
- EXPAT Library.
- Boost Library. Required if the GUI applications should be built. 
- WxWidgets Library. Required if the GUI applications should be built. 
- Google Test Library. Is required for running and build the unit tests.

The following third-party application need to be downloaded by yourself.
- Doxygen's application. Is required if the documentation should be built.



## License

The project uses the MIT license. See external LICENSE file in project root.

