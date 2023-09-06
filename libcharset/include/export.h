/* Control of exported symbols from libcharset.
   Copyright (C) 2005-2023 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#if @HAVE_VISIBILITY@ && BUILDING_LIBCHARSET
# define LIBCHARSET_DLL_EXPORTED __attribute__((__visibility__("default")))
#elif defined _MSC_VER && BUILDING_LIBCHARSET
/* When building with MSVC, exporting a symbol means that the object file
   contains a "linker directive" of the form /EXPORT:symbol.  This can be
   inspected through the "objdump -s --section=.drectve FILE" or
   "dumpbin /directives FILE" commands.
   The symbols from this file should be exported if and only if the object
   file gets included in a DLL.  Libtool, on Windows platforms, defines
   the C macro DLL_EXPORT (together with PIC) when compiling for a DLL
   and does not define it when compiling an object file meant to be linked
   statically into some executable.  */
# if defined DLL_EXPORT
#  define LIBCHARSET_DLL_EXPORTED __declspec(dllexport)
# else
#  define LIBCHARSET_DLL_EXPORTED
# endif
#else
# define LIBCHARSET_DLL_EXPORTED
#endif
