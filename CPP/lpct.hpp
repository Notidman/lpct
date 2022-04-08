#pragma once
#ifndef LPCT_HPP_WDMFRBIW
#define LPCT_HPP_WDMFRBIW




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
    end = 666,
  };

  enum class colors_type
  {
    bg = 0,
    fg = 1,
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
  set_color(colors color)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
  }

  void 
  uncolor()
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(colors::white));
  }

#else // Linux, Mac

    namespace detail
    {
      template < typename TypeString > TypeString
      get_color(colors color, colors_type type)
      {
        if ( type == colors_type::bg )
        {
          switch(color)
          {
            case colors::black:          return TypeString("\033[0;40m"); break;
            case colors::red:            return TypeString("\033[0;41m"); break;
            case colors::green:          return TypeString("\033[0;42m"); break;
            case colors::yellow:         return TypeString("\033[0;43m"); break;
            case colors::blue:           return TypeString("\033[0;44m"); break;
            case colors::magenta:        return TypeString("\033[0;45m"); break;
            case colors::cyan:           return TypeString("\033[0;46m"); break;
            case colors::white:          return TypeString("\033[0;47m"); break;
            case colors::bright_black:   return TypeString("\033[0;100m"); break;
            case colors::bright_red:     return TypeString("\033[0;101m"); break;
            case colors::bright_green:   return TypeString("\033[0;102m"); break;
            case colors::bright_yellow:  return TypeString("\033[0;103m"); break;
            case colors::bright_blue:    return TypeString("\033[0;104m"); break;
            case colors::bright_magenta: return TypeString("\033[0;105m"); break;
            case colors::bright_cyan:    return TypeString("\033[0;106m"); break;
            case colors::bright_white:   return TypeString("\033[0;107m"); break;
            case colors::end:            return TypeString("\033[0m");    break;
          }
        }
        else
        {
          switch(color)
          {
            case colors::black:          return TypeString("\033[0;30m"); break;
            case colors::red:            return TypeString("\033[0;31m"); break;
            case colors::green:          return TypeString("\033[0;32m"); break;
            case colors::yellow:         return TypeString("\033[0;33m"); break;
            case colors::blue:           return TypeString("\033[0;34m"); break;
            case colors::magenta:        return TypeString("\033[0;35m"); break;
            case colors::cyan:           return TypeString("\033[0;36m"); break;
            case colors::white:          return TypeString("\033[0;37m"); break;
            case colors::bright_black:   return TypeString("\033[0;90m"); break;
            case colors::bright_red:     return TypeString("\033[0;91m"); break;
            case colors::bright_green:   return TypeString("\033[0;92m"); break;
            case colors::bright_yellow:  return TypeString("\033[0;93m"); break;
            case colors::bright_blue:    return TypeString("\033[0;94m"); break;
            case colors::bright_magenta: return TypeString("\033[0;95m"); break;
            case colors::bright_cyan:    return TypeString("\033[0;96m"); break;
            case colors::bright_white:   return TypeString("\033[0;97m"); break;
            case colors::end:            return TypeString("\033[0m");    break;
          }
        }
      }
    } // namespace detail


    template < typename TypeString, colors color, colors_type type > 
    struct Printer
    {
      // The function to print text to the console with
      // certain color without line break
      static constexpr void
      print_color_string(const TypeString& msg) 
      {
        std::cout 
          << detail::get_color<TypeString>(color, type) 
          << msg 
          << detail::get_color<TypeString>(colors::end, type);
      }

      // The function to print text to the console
      // of a certain color with a line break
      static constexpr void
      print_color_stringln(const TypeString& msg) 
      {
        std::cout 
          << detail::get_color<TypeString>(color, type) 
          << msg 
          << detail::get_color<TypeString>(colors::end, type)
          << std::endl;
      }

      static constexpr TypeString
      get_color_line(const TypeString& msg)
      {
        return 
          detail::get_color<TypeString>(color, type) 
          + msg
          + detail::get_color<TypeString>(colors::end, type);
      }

      static constexpr TypeString
      get_color_ch(char ch)
      {
        return
          detail::get_color<TypeString>(color, type) 
          + ch
          + detail::get_color<TypeString>(colors::end, type);
      }

      };


#endif

} // namespace lpct

#endif /* end of include guard: LPCT_HPP_WDMFRBIW */
