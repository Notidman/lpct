#pragma once
#ifndef LPCT_H
#define LPCT_H

/*|+----------------------------------------------------------------------+|*\
 *|   LibName: LPCT // Cross-platform library for printing colored text    |*
 *|   License: MIT Licensed Library                                        |*
 *|   Author: Notidman                                                     |*
\*|+---------------------------------| LPCT |-----------------------------+|*/

#include <stdio.h>


typedef enum colors
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
} colors_t;

#ifdef _WIN32 /* Windows */

#include <windows.h>

  // The function to print text to the console with
  // certain color without line break
  void 
  prcolor(colors_t color, const char *msg);

  // The function to print text to the console
  // of a certain color with a line break
  void
  prcolorln(colors_t color, const char *msg);

  void 
  set_color(colors_t color);

  void 
  uncolor(void);

#else // Linux, Mac

  const char* 
  get_color(colors_t color);

  // The function to print text to the console with
  // certain color without line break
  void
  prcolor(colors_t color, const char *msg);

  // The function to print text to the console
  // of a certain color with a line break
  void 
  prcolorln(colors_t color, const char *msg); 

  void
  get_colorstr(char *str, colors_t color, const char *msg);

  void 
  prcolorch(colors_t color, const char ch); 

  void 
  prcolorchln(colors_t color, const char ch);

  void
  get_colorstrch(char *str, colors_t color, const char ch);

#endif

#endif /* LPCT_H */
