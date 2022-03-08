// { dg-do run { target c++14 } }

// Copyright (C) 2013-2021 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <string>
#include <testsuite_hooks.h>

#ifdef _GLIBCXX_USE_CHAR8_T
using std::u8string;
#else
using u8string = std::string;
#endif

void
test01()
{
  using namespace std::literals::string_literals;

  std::string planet = "Mercury"s;
#ifdef _GLIBCXX_USE_WCHAR_T
  std::wstring wplanet = L"Venus"s;
#endif
  u8string u8planet = u8"Mars"s;
  std::u16string u16planet = u"Jupiter"s;
  std::u32string u32planet = U"Saturn"s;

  VERIFY( planet == std::string("Mercury") );
#ifdef _GLIBCXX_USE_WCHAR_T
  VERIFY( wplanet == std::wstring(L"Venus") );
#endif
  VERIFY( u8planet == u8string(u8"Mars") );
  VERIFY( u16planet == std::u16string(u"Jupiter") );
  VERIFY( u32planet == std::u32string(U"Saturn") );
}

int
main()
{
  test01();
}
