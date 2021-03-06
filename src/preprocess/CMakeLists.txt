include_directories (./ "${PROJECT_SOURCE_DIR}/src/lib_interface")
set(CMAKE_INSTALL_MFC_LIBRARIES ON) 
include( InstallRequiredSystemLibraries )
#--------------#
#    SOURCES
#--------------#

set(PREPROCESS_SOURCE_FILES
		"computations.cpp"
        "tools/intersection_tri.cpp"
        "Preprocess.cpp")

#---------------------------------------#
#    DEPENDENCY & EXECUTABLE (OR LIB)
#---------------------------------------#

find_package(Boost COMPONENTS system filesystem regex REQUIRED)
link_directories( ${Boost_LIBRARY_DIRS} ) 

# Set Properties->General->Configuration Type to Application
# Creates spps with the listed sources
# Adds sources to the Solution Explorer
add_executable(preprocess ${PREPROCESS_SOURCE_FILES})

# Creates a folder "executables" and adds target
set_property(TARGET preprocess PROPERTY FOLDER "executables")

# Properties->Linker->Input->Additional Dependencies
target_link_libraries (preprocess lib_interface)

#--------------#
#    INSTALL
#--------------#


# Adds logic to INSTALL.vcproj to copy preprocess to destination directory
install (TARGETS preprocess
        RUNTIME DESTINATION meshing/tetgen)
if(WIN32)
	# Resolve symbolic link
	LIB_TO_DLL(${Boost_FILESYSTEM_LIBRARY_RELEASE} Boost_FILESYSTEM_LIBRARY_RELEASE_REAL)
	LIB_TO_DLL(${Boost_SYSTEM_LIBRARY_RELEASE} Boost_SYSTEM_LIBRARY_RELEASE_REAL)
	LIB_TO_DLL(${Boost_REGEX_LIBRARY_RELEASE} Boost_REGEX_LIBRARY_RELEASE_REAL)

	install (FILES
			${Boost_FILESYSTEM_LIBRARY_RELEASE_REAL}
			${Boost_SYSTEM_LIBRARY_RELEASE_REAL}
			${Boost_REGEX_LIBRARY_RELEASE_REAL}
				DESTINATION meshing/tetgen)
endif()

if( CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS )
    install( PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION meshing/tetgen COMPONENT System )
endif( CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS )