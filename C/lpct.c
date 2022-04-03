#include "lpct.h"

#ifdef _WIN32 /* Windows */

#include <windows.h>

  // The function to print text to the console with
  // certain color without line break
  void 
  prcolor(colors_t color, const char *msg)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    printf("%s", msg);
    SetConsoleTextAttribute(hConsole, white);
  }

  // The function to print text to the console
  // of a certain color with a line break
  void
  prcolorln(colors_t color, const char *msg)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    printf("%s\n", msg);
    SetConsoleTextAttribute(hConsole, white);
  }

  void 
  set_color(colors_t color)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
  }

  void 
  uncolor(void)
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, white);
  }

#else // Linux, Mac

  const char* 
  get_color(colors_t color)
  {
    switch(color)
    {
      case black:          return "\033[0;30m"; break;
      case red:            return "\033[0;31m"; break;
      case green:          return "\033[0;32m"; break;
      case yellow:         return "\033[0;33m"; break;
      case blue:           return "\033[0;34m"; break;
      case magenta:        return "\033[0;35m"; break;
      case cyan:           return "\033[0;36m"; break;
      case white:          return "\033[0;37m"; break;
      case bright_black:   return "\033[0;90m"; break;
      case bright_red:     return "\033[0;91m"; break;
      case bright_green:   return "\033[0;92m"; break;
      case bright_yellow:  return "\033[0;93m"; break;
      case bright_blue:    return "\033[0;94m"; break;
      case bright_magenta: return "\033[0;95m"; break;
      case bright_cyan:    return "\033[0;96m"; break;
      case bright_white:   return "\033[0;97m"; break;
      default:             return "\033[0m";    break;
    }
  }

  // The function to print text to the console with
  // certain color without line break
  void
  prcolor(colors_t color, const char *msg) 
  {
    printf("%s%s%s", 
        get_color(color),
        msg,
        "\033[0m");
  }

  // The function to print text to the console
  // of a certain color with a line break
  void 
  prcolorln(colors_t color, const char *msg) 
  {
    printf("%s%s%s\n", 
        get_color(color),
        msg,
        "\033[0m");
  }

  void
  get_colorstr(char *str, colors_t color, const char *msg)
  {
    sprintf(str, "%s%s%s", 
        get_color(color),
        msg,
        "\033[0m");
  }

  void 
  prcolorch(colors_t color, const char ch) 
  {
    printf("%s%c%s", 
        get_color(color),
        ch,
        "\033[0m");
  }

  void 
  prcolorchln(colors_t color, const char ch) 
  {
    printf("%s%c%s\n", 
        get_color(color),
        ch,
        "\033[0m");
  }

  void
  get_colorstrch(char *str, colors_t color, const char ch)
  {
    sprintf(str, "%s%c%s", 
        get_color(color),
        ch,
        "\033[0m");
  }

#endif
