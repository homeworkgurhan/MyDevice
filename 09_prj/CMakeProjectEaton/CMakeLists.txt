# CMakeList.txt : CMake project for CMakeProjectEaton, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeProjectEaton")

set (CMAKE_CXX_STANDARD 20)


include_directories (
	"c:/_proj/eaton/04_code"
)

# Add source to this project's executable.
set (PROJECT_SRC "c:/_proj/eaton/04_code/main.cpp" "c:/_proj/eaton/04_code/DataReceiver.cpp")
add_executable (CMakeProjectEaton ${PROJECT_SRC})

# TODO: Add tests and install targets if needed.
