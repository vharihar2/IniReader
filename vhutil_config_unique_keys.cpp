//
// $Id: vhutil_config_unique_keys.cpp,v 1.2 2025/11/20 04:46:37 venkatnarayan.h Exp venkatnarayan.h $
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

#include "vhutil_config_unique_keys.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::string;
using std::istringstream;
using std::getline;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::ifstream;
using std::istringstream;

namespace vhutil_config {

bool readConfigFile(const string &filename, map<string, string> &kvs)
{
  ifstream ifs_file(filename);
  if (!ifs_file.is_open()) {
    cout << "-E-: Error opening '" << filename << "'" << endl;
    return false;
  }

  string line;
  while (getline(ifs_file, line))
  {
    line = trim(line);
    if (line[0] == '#') continue;  //Skip comments

    istringstream is_line(line);
    string key;
    if (getline(is_line, key, '='))
    {
      key = trim(key);
      string value;
      if (getline(is_line, value)) 
        value = trim(value);

        //value may have #, in case there are in-line comments. Check for it.
        size_t pos = value.find("#");
        if (pos != string::npos) {
          string value2 = value.substr(0, pos);
          value = trim(value2);
        }

        pair<map<string, string>::iterator, bool> retval;
        retval = kvs.insert(pair<string, string>(key, value));
        if (!retval.second)
          cout << "-W-: Key '"<< key << "' already exists, value '" << value
                                                    << "' ignored." << endl;
    }
  }

  return true;
}

string trim(const string &str, const string &whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}

} // End of namespace vhutil_config
