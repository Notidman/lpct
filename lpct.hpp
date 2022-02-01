#ifndef LPCT_HPP
#define LPCT_HPP

/*|+----------------------------------------------------------------------+|*\
 *|   LibName: LPCT // Cross-platform library for printing colored text    |*
 *|   License: MIT Licensed Library                                        |*
 *|   Author: Notidman                                                     |*
\*|+---------------------------------| LPCT |-----------------------------+|*/


namespace lpct {

  #include <iostream>
  #ifdef _WIN32 // Windows

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


    #include <windows.h>

    // The function to print text to the console with
    // certain color without line break
    template < typename __T >
    void color(colors color, const __T& msg)
    {
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

      SetConsoleTextAttribute(hConsole, static_cast<int>(color));
      std::cout << msg;
      SetConsoleTextAttribute(hConsole, 7);
    }

    // The function to print text to the console
    // of a certain color with a line break
    template < typename __T >
    void colorln(colors color, const __T& msg)
    {
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

      SetConsoleTextAttribute(hConsole, static_cast<int>(color));
      std::cout << msg << std::endl;
      SetConsoleTextAttribute(hConsole, 7);
    }

  #else // Linux, Mac

    enum class colors
    {
      black = 0,
      red = 1,
      green = 2,
      yellow = 3,
      blue = 4,
      magenta = 5,
      cyan = 6,
      white = 7,
      bright_black = 8,
      bright_red = 9,
      bright_green = 10,
      bright_yellow = 11,
      bright_blue = 12,
      bright_magenta = 13,
      bright_cyan = 14,
      bright_white = 15,
    };

    namespace detail
    {
      const char* get_color(colors color)
      {
        switch(color)
        {
          case colors::black:          return "\033[0;30m"; break;
          case colors::red:            return "\033[0;31m"; break;
          case colors::green:          return "\033[0;32m"; break;
          case colors::yellow:         return "\033[0;33m"; break;
          case colors::blue:           return "\033[0;34m"; break;
          case colors::magenta:        return "\033[0;35m"; break;
          case colors::cyan:           return "\033[0;36m"; break;
          case colors::white:          return "\033[0;37m"; break;
          case colors::bright_black:   return "\033[0;90m"; break;
          case colors::bright_red:     return "\033[0;91m"; break;
          case colors::bright_green:   return "\033[0;92m"; break;
          case colors::bright_yellow:  return "\033[0;93m"; break;
          case colors::bright_blue:    return "\033[0;94m"; break;
          case colors::bright_magenta: return "\033[0;95m"; break;
          case colors::bright_cyan:    return "\033[0;96m"; break;
          case colors::bright_white:   return "\033[0;97m"; break;
          default:                     return "\033[0m";    break;
        }
      }
    } // namespace detail

    // The function to print text to the console with
    // certain color without line break
    template < typename __T >
    void color(colors color, const __T& msg) {
      std::cout << detail::get_color(color) << msg << "\033[0m";
    }

    // The function to print text to the console
    // of a certain color with a line break
    template < typename __T >
    void colorln(colors color, const __T& msg) {
      std::cout << detail::get_color(color) << msg << "\033[0m" << std::endl;
    }

  #endif

} // namespace lpct

#endif // LPCT_HPP
