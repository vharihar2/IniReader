//
// $Id: test_vhutil_config_unique_keys.cpp,v 1.3 2025/11/20 04:46:37 venkatnarayan.h Exp venkatnarayan.h $
/*
* Copyright (c) 2025, Venkatnarayan Hariharan, India. All Rights Reserved.
* Permission to use, copy, modify and distribute this software for
* educational, research, and not-for-profit purposes, without fee and without a
* signed license agreement, is hereby granted, provided that this paragraph and
* the following two paragraphs appear in all copies, modifications, and
* distributions.
*
* IN NO EVENT SHALL VENKATNARAYAN HARIHARAN BE LIABLE TO ANY PARTY FOR DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
* PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE.
*
* VENKATNARAYAN HARIHARAN SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT
* NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS PROVIDED "AS IS". SHIV
* NADAR UNIVERSITY HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
* ENHANCEMENTS, OR MODIFICATIONS.
*/
 
/*
Revision History:
Date          By                     Change Notes
------------  ---------------------- ------------------------------------------
Sep 2024      Venkat H.              Original
*/

#include <iostream>
#include "vhutil_config_unique_keys.h"

using namespace vhutil_config;

int main();

int main()
{
  std::map<std::string, std::string> kvs;
  if (!readConfigFile("test.ini", kvs))
    return 1;

  //Print out all the loaded key-value pairs
  for (auto const& x : kvs)
    std::cout << x.first << ':' << x.second << std::endl;
  
  return 0;
}

