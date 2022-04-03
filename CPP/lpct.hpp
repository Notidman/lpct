#pragma once
#ifndef LPCT_HPP
#define LPCT_HPP

/*|+----------------------------------------------------------------------+|*\
 *|   LibName: LPCT // Cross-platform library for printing colored text    |*
 *|   License: MIT Licensed Library                                        |*
 *|   Author: Notidman                                                     |*
\*|+---------------------------------| LPCT |-----------------------------+|*/

#include <iostream>

namespace lpct {
  
  enum class colors
  {
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    yellow = 6,
    white = 7,
    bright_black = 8,
    bright_blue = 9,
    bright_green = 10,
    bright_cyan = 11,
    bright_red = 12,
    bright_magenta = 13,
    bright_yellow = 14,
    bright_white = 15,
  };
  
#ifdef _WIN32 // Windows
  
  
#include <windows.h>

  // The function to print text to the console with
  // certain color without line break
  template < typename TypeString > void 
  prcolor(colors color, const TypeString& msg)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    std::cout << msg;
    SetConsoleTextAttribute(hConsole, static_cast<int>(colors::white));
  }

  // The function to print text to the console
  // of a certain color with a line break
  template < typename TypeString > void 
  prcolorln(colors color, const TypeString& msg)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    std::cout << msg << std::endl;
    SetConsoleTextAttribute(hConsole, static_cast<int>(colors::white));
  }

  void 
  set_color(colors color);

  void 
  uncolor();

#else // Linux, Mac

    namespace detail
    {
      const char* 
      get_color(colors color);
    } // namespace detail

    // The function to print text to the console with
    // certain color without line break
    template < typename TypeString > void
    prcolor(colors color, const TypeString& msg) 
    {
      std::cout << detail::get_color(color) << msg << "\033[0m";
    }

    // The function to print text to the console
    // of a certain color with a line break
    template < typename TypeString > void 
    prcolorln(colors color, const TypeString& msg) 
    {
      std::cout << detail::get_color(color) << msg << "\033[0m" << std::endl;
    }

    template < typename TypeString > TypeString
    get_colorstr(colors color, TypeString&& msg)
    {
      return detail::get_color(color) + msg + "\033[0m";
    }

#endif

} // namespace lpct

#endif // LPCT_HPP
