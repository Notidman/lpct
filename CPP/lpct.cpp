#include "lpct.hpp"

namespace lpct {

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
      const char* 
      get_color(colors color)
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
