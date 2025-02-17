# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

set(gsm_freedesktop_path ${GR_PKG_DATA_DIR}/gr-gsm/freedesktop)

install(
   FILES
   gsm-livemon.desktop
   DESTINATION ${gsm_freedesktop_path}
   COMPONENT "gr-gsm"
)

find_program(HAVE_XDG_UTILS xdg-desktop-menu)

if(UNIX AND HAVE_XDG_UTILS)
    set(SRCDIR ${CMAKE_INSTALL_PREFIX}/${gsm_freedesktop_path})
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/gsm_setup_freedesktop.in
        ${CMAKE_CURRENT_BINARY_DIR}/gsm_setup_freedesktop
    @ONLY)
    install(
        PROGRAMS
        ${CMAKE_CURRENT_BINARY_DIR}/gsm_setup_freedesktop
        DESTINATION ${GR_PKG_LIBEXEC_DIR}
        COMPONENT "gr-gsm"
    )
endif(UNIX AND HAVE_XDG_UTILS)
