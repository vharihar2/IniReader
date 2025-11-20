//
// $Id: vhutil_config_unique_keys.h,v 1.2 2025/11/20 04:46:37 venkatnarayan.h Exp venkatnarayan.h $
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

#include <map>

namespace vhutil_config {

bool readConfigFile(const std::string &filename, std::map<std::string, std::string> &kvs);
std::string trim(const std::string &str, const std::string &whitespace = " \t");

} // End of namespace vhutil_config
