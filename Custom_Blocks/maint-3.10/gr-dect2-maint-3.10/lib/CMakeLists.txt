# Copyright 2011,2012,2016,2018,2019 Free Software Foundation, Inc.
#
# This file was generated by gr_modtool, a tool from the GNU Radio framework
# This file is a part of gr-dect2
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

list(APPEND dect2_sources
    phase_diff_impl.cc
    packet_decoder_impl.cc
    packet_receiver_impl.cc
)

set(dect2_sources "${dect2_sources}" PARENT_SCOPE)
if(NOT dect2_sources)
    MESSAGE(STATUS "No C++ sources... skipping lib/")
    return()
endif(NOT dect2_sources)

add_library(gnuradio-dect2 SHARED ${dect2_sources})
target_link_libraries(gnuradio-dect2 gnuradio::gnuradio-runtime volk)
target_include_directories(gnuradio-dect2
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    PUBLIC $<INSTALL_INTERFACE:include>
  )
set_target_properties(gnuradio-dect2 PROPERTIES DEFINE_SYMBOL "gnuradio_dect2_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-dect2 PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-dect2)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

# If your unit tests require special include paths, add them here
#include_directories()
# List all files that contain Boost.UTF unit tests here
list(APPEND test_dect2_sources
)
# Anything we need to link to for the unit tests go here
list(APPEND GR_TEST_TARGET_DEPS gnuradio-dect2)

if(NOT test_dect2_sources)
    MESSAGE(STATUS "No C++ unit tests... skipping")
    return()
endif(NOT test_dect2_sources)

foreach(qa_file ${test_dect2_sources})
    GR_ADD_CPP_TEST("dect2_${qa_file}"
        ${CMAKE_CURRENT_SOURCE_DIR}/${qa_file}
    )
endforeach(qa_file)
